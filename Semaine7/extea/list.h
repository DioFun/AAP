#include "elt.h" // T_elt 

#ifndef _LIST_H_
#define _LIST_H_
// #include "test_utils.h"

typedef struct node T_node;

// Structure for T_data
typedef struct {
    T_elt elt;
    T_node** pElt;
} T_data;

// Structure for the node
struct node {
    T_data data;
    T_node* pNext;
};

// Typedef for T_list
typedef T_node* T_list;

T_node * addNode (T_data e, T_node * n);
void showList(T_list l);
void freeList(T_list l);
T_elt getFirstElt(T_list l);
T_list removeFirstNode(T_list l);
void showList_rec(T_list l);
void showList_inv_rec(T_list l);
void freeList_rec(T_list l);

#endif 


