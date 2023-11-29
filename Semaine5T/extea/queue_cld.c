#include <stdio.h>
#include <stdlib.h>
#include "queue_cld.h"

T_queue newQueue() {
    return (T_queue) {NULL, NULL};
}


void showQueue(T_queue q) {
    printf("Queue: ");
    showList(q.head);
    printf("\n");
}

int isEmpty(T_queue q) {
    return q.head == NULL;
}

void enqueue(T_queue *q, T_elt e) {
    T_list node = addNode(e, NULL);
    if (!isEmpty(*q)){
        (*q).tail->pNext = node;
    } else {
        (*q).head = node;
    }
    (*q).tail = node;
}

T_elt dequeue(T_queue * q) {
    T_list ret = q->head;
    q->head = q->head->pNext;
    return getFirstElt(ret);
}

T_elt top(T_queue q) {
    return getFirstElt(q.head);
}

int count(T_queue q) {
    int count = 0;
    T_node * p = q.head;
    while (p!=NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

int count_rec(T_queue q) {
    if (q.head == NULL) {
        return 0;
    } else {
        return 1 + count_rec((T_queue) {q.head->pNext, q.tail});
    }
}