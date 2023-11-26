#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

//#define DEBUG
#include "../include/check.h"

#include "elt.h" // T_elt 
#include "list.h" // prototypes 

// #define RECURSIVE
#define ITERATIVE

/*
typedef struct node {
	T_elt data;
	struct node *pNext;
} T_node, * T_list;
*/

static T_node * newNode(T_elt e) {
	// Créer une nouvelle cellule contenant l'élément e
	T_list p = (T_node *) malloc(sizeof(T_node));
	CHECK_IF(p, NULL, "newNode : allocation failed");
	p->data = e;
	p->pNext = NULL;
	return p;
}

T_node * addNode (T_elt e, T_node * n) {
	// Créer une maille (node), la remplir 
	// et l'accrocher en tête d'une liste existante (ou vide)
	// Renvoyer la nouvelle tête
	T_list node = newNode(e);
	node->pNext = n;
	return node;
}

void showList(T_list l) {
	// Afficher la liste en commençant par sa tête 
	// A faire en itératif 
	if (l==NULL) {
		printf("Liste vide !\n");
		return;
	}
	while (l != NULL) {
		printf("%s\n", toString(l->data));
		l=l->pNext;
	}
}

void freeList(T_list l) {
	// Libérer la mémoire de toutes les cellules de la liste l 
	// A faire en itératif
	assert(l!=NULL);
	T_list pAux;
	while (l != NULL) {
		pAux = l->pNext;
		free(l);
		l = pAux;
	}
}

T_elt getFirstElt(T_list l) {
	// Renvoyer l'élément contenu dans la cellule de tête de la liste
	assert(l!=NULL);
	return l->data; 
}

T_list removeFirstNode(T_list l) {
	// Supprimer la tête de la liste 
	// Renvoyer la nouvelle liste privée de sa première cellule
	assert(l!=NULL);
	T_list ret = l->pNext;
	free(l);
	return ret;
}

// A produire en version récursive (+ tard dans le sujet)

void showList_rec(T_list l) {
	// Afficher la liste en commençant par sa tête 
	// A faire en récursif 
	if (l==NULL) {
		printf("Liste vide !");
		return;
	}
	printf("%s\n", toString(l->data));
	if (l->pNext != NULL) {
		showList_rec(l->pNext);
	}
}

void showList_inv_rec(T_list l) {
	// Afficher la liste en commençant par sa queue 
	// A faire en récursif 
	if (l==NULL) {
		printf("Liste vide !");
		return;
	}
	if (l->pNext != NULL) {
		showList_inv_rec(l->pNext);
	}
	printf("%s\n", toString(l->data));
}

void freeList_rec(T_list l) {
	// Libérer la mémoire de toutes les cellules de la liste l 
	// A faire en récursif
	if (l==NULL) return;
	if (l->pNext != NULL) {
		freeList_rec(l->pNext);
	}
	free(l);
}

