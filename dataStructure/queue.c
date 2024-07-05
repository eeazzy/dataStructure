//
//  queue.c
//  dataStructure
//
//  Created by 김현서 on 6/28/24.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear; //삭제, 삽입
}QueueType;

void init_queue(QueueType *q){
    q->front = 0;
    q->rear = 0;
}

int is_full(QueueType *q){
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int is_empty(QueueType *q){
    return q->front == q->rear;
}

void enqueue(QueueType *q,element item){
    if(is_full(q)){
        printf("큐 포화\n");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        printf("큐 공백\n");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void queue_print(QueueType *q){
    for (int i = 0; i<MAX_QUEUE_SIZE; i++) {
        if (i <= q->front || i> q->rear)
            printf("   | ");
        else
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}

int main(void){
    QueueType q;

    init_queue(&q);
    enqueue(&q,10); queue_print(&q);
    enqueue(&q,20); queue_print(&q);
    enqueue(&q,30); queue_print(&q);
    
    dequeue(&q); queue_print(&q);
    
    enqueue(&q,40); queue_print(&q);
    dequeue(&q); queue_print(&q);
    
}
