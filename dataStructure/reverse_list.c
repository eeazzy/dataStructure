//
//  reverse_list.c
//  dataStructure
//
//  Created by 김현서 on 7/12/24.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode* insert_first(ListNode *head, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));    //(1)
    p->data = value;                    // (2)
    p->link = head;   //(3)
    head = p;    //(4)
    return head;
}

void print_list(ListNode *head){
    for (ListNode *p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

ListNode* reverse(ListNode *head){
    ListNode *p, *q, *r;

    p = head; // 역순으로 만들 리스트
    q = NULL; // 역순으로 만들 노드
    while (p != NULL) {
        r = q; // r은 역순이 된 리스트
                       
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

int main(void){
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = reverse(head1);
    print_list(head2);
    return 0;
}
