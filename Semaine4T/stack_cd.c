#include <assert.h>
#include "include/check.h"
#include "include/traces.h"
#include "stack_cd.h"
#define STACK_THRESHOLD 5

T_stack newStack(int size) {
	T_stack s;
	s.nbMaxElt = size;
	s.data = (T_elt *) malloc(size*sizeof(T_elt));
	CHECK_IF(s.data, NULL, "Allocation failed ! (newStack)");
	return s; 
}

void freeStack (T_stack *p) {
	free(p->data);
	p->data = NULL;
}

void push(T_elt e, T_stack *p) {
	if (p->sp==p->nbMaxElt) {
		p->nbMaxElt+=STACK_THRESHOLD;
		p->data = (T_elt *) realloc(p->data, p->nbMaxElt*sizeof(T_elt));
		CHECK_IF(p->data, NULL, "Re-allocation failed ! (push)");
	}
	p->data[p->sp] = e;
	p->sp++;
}

void showStack (const T_stack * p) {
	int i; 

	if (p->sp ==0) {
		printf("Pile vide !\n");
		return;
	}
 
	printf("Sp = %d\n",p->sp);
	for(i=p->sp-1;i>=0; i--) {
		T_elt e = p->data[i];
		printf("taille : %d, ouvrant : %s, fermant : %s, type : %s, kind : %d\n", e.size, e.open, e.close, typeToString(e.type), e.kind);
		// on a modifié la façon d'afficher les élements lors du showstack
	}
}

T_elt pop(T_stack *p) {
	assert(p != NULL); 
	assert(p->sp > 0); 
	return p->data[--p->sp];
}

T_elt top(const T_stack *p) {
	assert(p != NULL);
	assert(p->sp > 0);
	return p->data[p->sp-1];
}

int isEmpty (const T_stack * p) {
	assert(p!=NULL);
	if (p->sp == 0) return 1; 
	else return 0;
	
}