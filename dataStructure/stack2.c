//
//  stack2.c
//  day2
//
//  Created by 김현서 on 6/26/24.
//

#include <stdio.h>
#include <stdlib.h> // exit코드 사용
#include <string.h>

#define MAX_STACK_SIZE 5

typedef int element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

// 스택 초기화
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
        exit(1); //void가 아니여서 무언가를 반환해야 함 -> 프로그램 종료함
    }
    else{
        return s->data[(s->top)--];
    }
}

// 삭제하지 않고 값 뽑기
element peek(StackType *s){
    if(is_empty(s)){
        printf("스택 공백 에러\n");
        exit(1);
    }
    else{
        return s->data[s->top];
    }
}

void print_stack(StackType *s){
    for(int i=s->top;i>=0;i--){
        printf("%2d ",s->data[i]);
    }
    printf("\n");
}

int check_matching(const char *in){
    StackType s;
    char ch, open_ch;
    int n = strlen(in);
    init_stack(&s);
    
    for(int i=0;i<n;i++){
        ch = in[i]; //글자 넣기
        switch (ch) {
            case '{': case '[': case '(':
                push(&s, ch);
                break;
            case '}': case ']': case ')':
                if(is_empty(&s)) return 0;
                else{
                    open_ch = pop(&s);
                    if((open_ch == '(' && ch != ')') ||
                       (open_ch == '[' && ch != ']') ||
                       (open_ch == '{' && ch != '}')) {
                        return 0;
                    }
                    break;
                }
        }
    }
    if(!is_empty(&s)) return 0;
    return 1;
}

int main(void) {
    char *p = "{( ))";
    
    if(check_matching(p) == 1){
        printf("%s: 검사 성공\n",p);
    }else{
        printf("%s: 검사 실패\n",p);
    }
}


