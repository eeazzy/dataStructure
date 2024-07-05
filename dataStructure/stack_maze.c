//
//  stack_maze.c
//  dataStructure
//
//  Created by 김현서 on 6/27/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAZE_SIZE 5

#define MAX_STACK_SIZE 50

char maze[MAZE_SIZE][MAZE_SIZE];

typedef struct{
    short r;
    short c;
}element;

typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item){
    if(is_full(s)){
        printf("스택 포화 에러\n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

element pop(StackType *s){
    if(is_empty(s)){
        printf("스택 공백 에러\n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}

element peek(StackType *s){
    if(is_empty(s)){
        printf("스택 공백 에러\n");
        exit(1);
    }
    else{
        return s->data[s->top];
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
    printf("\n");
    for(int r=0;r<MAZE_SIZE;r++){
        for(int c=0;c<MAZE_SIZE;c++){
            printf("%c",maze[r][c]);
        }
        printf("\n");
    }
}

void push_loc(StackType *s, int r, int c){
    if(r < 0 || c < 0) return;
    if(maze[r][c] != '1' && maze[r][c] != '.'){
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

element entry;

void init_maze(){ // 미로 생성
    srand(time(NULL));
    
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == 0 || i == MAZE_SIZE - 1 || j == 0 || j == MAZE_SIZE - 1) {
                maze[i][j] = '1'; // 모든 경계를 벽('1')으로 초기화
            } else {
                maze[i][j] = (rand() % 4 != 0) ? '0' : '1'; // 75%의 확률로 길 생성
            }
        }
    }
    // rand() %((최댓값-최솟값)+1)+최솟값
    int start = rand() % (MAZE_SIZE-2) + 1; // 1 ~ MAZE_SIZE-2 범위
    maze[start][0] = 'e';
    
    int end = rand() % (MAZE_SIZE-2) + 1;
    maze[end][MAZE_SIZE-1] = 'x';
    
    // 미로 생성 후 랜덤 위치에 폭탄 설치
    int bomb_r = rand() % (MAZE_SIZE - 2) + 1;
    int bomb_c = rand() % (MAZE_SIZE - 2) + 1;
    maze[bomb_r][bomb_c] = 'b';
    
    entry.r = start;
    entry.c = 0;
    
    printf("미로가 생성되었습니다\n");
}

int count_open_paths(char maze[MAZE_SIZE][MAZE_SIZE]) {
    int count = 0;
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j] == '0') {
                count++;
            }
        }
    }
    return count;
}

int main(void){
    char input;
    int r,c;
    StackType s;
    
    init_maze();
    init_stack(&s);
    
    element here = entry;
    
    maze_print(maze);
    
    while(1){
        // 현재 위치를 스택에 추가
        push_loc(&s, here.r, here.c);
        
        printf("이동 입력>> ");
        input = getchar(); // 키보드 입력
        getchar(); // 엔터키 무시
        
        switch (input) {
            case 'w': // 위
                r = here.r - 1;
                c = here.c;
                break;
            case 'a': // 왼
                r = here.r;
                c = here.c - 1;
                break;
            case 's': // 아래
                r = here.r + 1;
                c = here.c;
                break;
            case 'd': // 오
                r = here.r;
                c = here.c + 1;
                break;
            default:
                printf("잘못된 입력입니다. w, a, s, d 중 하나를 입력하세요.\n");
                continue;
        }
        
        // 이동할 수 있는지 확인
        if (r < 0 || r >= MAZE_SIZE || c < 0 || c >= MAZE_SIZE || maze[r][c] == '1') {
            printf("이동할 수 없습니다.\n");
            continue;
        }
        
        here. r = r; here.c = c; // 이동
        
        // 폭탄 확인
        if (maze[here.r][here.c] == 'b') {
            printf("실패! 폭탄이 터졌습니다.\n");
            break;
        }
        
        // 출구에 도달했는지 확인
        if (maze[here.r][here.c] == 'x') {
            printf("성공! 미로를 탈출했습니다.\n");
            printf("점수 : %d\n",count_open_paths(maze));
            break;
        }
        
        maze[here.r][here.c] = '.'; // 이동 표시
        maze_print(maze);
        
        // 현재 미로에서 이동 가능한 경로(`0`)가 없는지 확인
        if (count_open_paths(maze) == 0) {
            printf("실패! 이동할 수 있는 경로가 더 이상 없습니다.\n");
            break;
        }
    }
    
    return 0;
}

