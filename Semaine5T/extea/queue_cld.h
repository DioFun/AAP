#include "list.h"

#ifndef _QUEUE_CLD_H_
#define _QUEUE_CLD_H_

typedef struct queue {
    T_node * head;
    T_node * tail;
} T_queue;

T_queue newQueue();
void showQueue(T_queue q);
int isEmpty(T_queue q);
void enqueue(T_queue *q, T_elt e);
T_elt dequeue(T_queue *q);
T_elt top(T_queue q);
int count(T_queue q);

#endif