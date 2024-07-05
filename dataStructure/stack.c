//
//  stack.c
//  day2
//
//  Created by 김현서 on 6/25/24.
//

#include <stdio.h>
#include <stdlib.h> // exit코드 사용

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

int main(void) {
    StackType s;
    init_stack(&s);
    int res;
    
    push(&s,1); push(&s,2); push(&s,3);
    res = pop(&s);
    printf("POP value = %d\n",res);
    printf("POP value = %d\n",pop(&s));
    
    push(&s,10); push(&s,20); push(&s,30);
    
    print_stack(&s);
}

