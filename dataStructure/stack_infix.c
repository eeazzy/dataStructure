//
//  stack_infix.c
//  dataStructure
//
//  Created by 김현서 on 7/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
#define MAX_STACK_SIZE 100


typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// Ω∫≈√ √ ±‚»≠ «‘ºˆ
void init_stack(StackType *s)
{
    s->top = -1;
}

// ∞¯πÈ ªÛ≈¬ ∞À√‚ «‘ºˆ
int is_empty(StackType *s)
{
    return (s->top == -1);
}
// ∆˜»≠ ªÛ≈¬ ∞À√‚ «‘ºˆ
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}
// ª¿‘«‘ºˆ
void push(StackType *s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "Ω∫≈√ ∆˜»≠ ø°∑Ø\n");
        return;
    }
    else s->data[++(s->top)] = item;
}
// ªË¡¶«‘ºˆ
element pop(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Ω∫≈√ ∞¯πÈ ø°∑Ø\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}
// ««≈©«‘ºˆ
element peek(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "Ω∫≈√ ∞¯πÈ ø°∑Ø\n");
        exit(1);
    }
    else return s->data[s->top];
}
// ===== Ω∫≈√ ƒ⁄µÂ¿« ≥° =====

// ø¨ªÍ¿⁄¿« øÏº±º¯¿ß∏¶ π›»Ø«—¥Ÿ.
int prec(char op)
{
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
    }
    return -1;
}
// ¡ﬂ¿ß «•±‚ ºˆΩƒ -> »ƒ¿ß «•±‚ ºˆΩƒ
void infix_to_postfix(char exp[])
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);                    // Ω∫≈√ √ ±‚»≠
    for (i = 0; i<len; i++) {
        ch = exp[i];
        switch (ch) {
            case '+': case '-': case '*': case '/': case '%':
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
                printf("%c", pop(&s));
            push(&s, ch);
            break;
        case '(':    // øﬁ¬  ∞˝»£
            push(&s, ch);
            break;
        case ')':    // ø¿∏•¬  ∞˝»£
            top_op = pop(&s);
            // øﬁ¬  ∞˝»£∏¶ ∏∏≥Ø∂ß±Ó¡ˆ √‚∑¬
            while (top_op != '(') {
                printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:        // ««ø¨ªÍ¿⁄
            printf("%c", ch);
            break;
        }
    }
    while (!is_empty(&s))    // Ω∫≈√ø° ¿˙¿Âµ» ø¨ªÍ¿⁄µÈ √‚∑¬
        printf("%c", pop(&s));
}
//
int main(void)
{
    char *s = "5*(10+2)%2";
    printf("¡ﬂ¿ß«•Ω√ºˆΩƒ %s \n", s);
    printf("»ƒ¿ß«•Ω√ºˆΩƒ ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}

