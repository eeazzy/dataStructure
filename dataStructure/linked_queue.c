//
//  linked_queue.c
//  dataStructure
//
//  Created by 김현서 on 7/5/24.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode{
    element data;
    struct QueueNode *link;
}QueueNode;

typedef struct{
    QueueNode *front;
    QueueNode *rear;
}LinkedQueueType;

void init(LinkedQueueType *q){
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType *q){
    return q->front == NULL;
}

void print_queue(LinkedQueueType *q){
    QueueNode *p = q->front;
    for(;p!=NULL;p = p->link){
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

void enqueue(LinkedQueueType *q, element data){
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = data; temp->link = NULL;
    
    if(is_empty(q)){
        q->front = temp; q->rear = temp;
    }else{
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(LinkedQueueType *q){
    QueueNode *temp = q->front;
    element item;
    
    if(is_empty(q)){
        printf("큐 비워져있음\n");
        exit(1);
    }else{
        item = temp->data;
        q->front = temp->link;
        if(q->front == NULL){ // 마지막 노드를 없앨 때
            q->rear = NULL;
        }
        free(temp);
    }
    return item;
}

int main(void){
    LinkedQueueType queue;
    init(&queue);
    
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    
    print_queue(&queue);
    
    element item = dequeue(&queue);
    printf("삭제 : %d\n",item);
    
    print_queue(&queue);
    
}
