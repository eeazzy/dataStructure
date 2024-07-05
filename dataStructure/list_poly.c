//
//  list_poly.c
//  dataStructure
//
//  Created by 김현서 on 7/4/24.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {  // 개수, 지수
    int coef;
    int expon;
    struct ListNode *link;
} ListNode;

typedef struct ListType { // 리스트 정보 저장
    int size;
    ListNode *head; // 리스트 시작
    ListNode *tail; // 리스트 끝
} ListType;

ListType* create(){
    ListType *p = (ListType *)malloc(sizeof(ListType));
    p->size = 0; // 초기화
    p->head = p->tail = NULL;
    return p;
}

void insert_node(ListType *plist, int coef, int expon){
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->coef = coef; temp->expon = expon;
    temp->link = NULL;
    if(plist->tail == NULL){
        plist->head = plist->tail = temp;
    }else{
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

void poly_add(ListType *plist1,ListType *plist2,ListType *plist3){
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;
    int sum;
    
    while (a != NULL && b != NULL) {
        if(a->expon == b->expon){
            sum = a->coef + b->coef;
            insert_node(plist3, sum, a->expon);
            a = a->link; b = b->link;
        }
        else if(a->expon < b->expon){ // b의 차수가 더 크면
            insert_node(plist3, b->coef, b->expon);
            b = b->link;
        }else{ // a의 차수가 더 크면
            insert_node(plist3, a->coef, a->expon);
            a = a->link;
        }
    }
    
    for( ;a!=NULL;a = a->link){
        insert_node(plist3, a->coef, a->expon);
    }
    for( ;b!=NULL;a = b->link){
        insert_node(plist3, b->coef, b->expon);
    }
}

void poly_print(ListType *plist){
    ListNode *p = plist->head;

    printf("식 = ");
    for (;p!=NULL; p = p->link) {
        printf("%d^%d + ", p->coef, p->expon);
    }
    printf("\n");
}

int main(void)
{
    ListType *list1, *list2, *list3;

    list1 = create();
    list2 = create();
    list3 = create();

    insert_node(list1, 3, 12);
    insert_node(list1, -1, 10);
    insert_node(list1, 2, 8);
    insert_node(list1, 1, 0);

    insert_node(list2, 8, 12);
    insert_node(list2, 10, 6);
    insert_node(list2, 5, 3);
    

    poly_print(list1);
    poly_print(list2);

    poly_add(list1, list2, list3);
    poly_print(list3);

    free(list1); free(list2); free(list3);
}


