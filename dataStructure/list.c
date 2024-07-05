//
//  list.c
//  dataStructure
//
//  Created by 김현서 on 7/2/24.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {

    element data;

    struct ListNode *link;

}ListNode;



ListNode * insert_first(ListNode *head, element value) {

    ListNode *p = (ListNode *) malloc(sizeof(ListNode));

    p->data = value;

    p->link = head;

    head = p;

    return head;

}

void print_list(ListNode *head) {

    for (ListNode *p = head; p != NULL; p = p->link)

        printf("%d->", p->data);

    printf("\n");

}

ListNode * delete_first(ListNode *head) {

    ListNode *removed;

    if (head == NULL) return NULL;

    removed = head;

    head = head->link;

    free(removed);

    return head;

}

ListNode * search_list(ListNode *head, element value){
    ListNode *p = head;
    while (p != NULL) {
        if(p->data == value){ return p; }
        p = p->link;
    }
    return NULL;
}

ListNode * concat_list(ListNode *head1, ListNode *head2){
    if(head1 == NULL) { return head2; }
    else if (head2 == NULL) { return head1; }
    else{
        while(head1->link == NULL){
            -- head1->link ;
        }
        head1->link = head2;
        return head1;
    }
}

int main(void) {

    ListNode *head1, *head2;
    
    head1 = insert_first(head1, 30);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 10);
    
    head2 = insert_first(head2, 60);
    head2 = insert_first(head2, 50);
    head2 = insert_first(head2, 40);
    
    ListNode *head3 = concat_list(head1, head2);
    print_list(head3);
}
