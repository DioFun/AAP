#include <assert.h> // assert

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

#include "stack_cs.h" // type et protypes liés à T_stack

#ifdef IMPLEMENTATION_STATIC_CONTIGUOUS

// Nouvelles fonctions à réaliser pour l'exercice 3 /////////////////////////

T_elt pop(T_stack *p) {
	// Cette opération extrait de la pile, l’élément au sommet, 
	// modifiant ainsi son état
	T_elt aux; 
	assert(p!=NULL);
	assert(p->sp>0);
	aux=p->data[--p->sp];
	return aux; 	
}

T_elt top(const T_stack *p) {
	// Cette opération permet d’accéder à l’élément en sommet de pile
	T_elt aux; 
	assert(p!=NULL);
	assert(p->sp>0);
	aux = p->data[p->sp-1];
	return aux; 
}

void push(T_elt e, T_stack *p) {
	// Opération consistant à empiler un élément e
	// sur la pile modifiant ainsi son état
	assert(p!=NULL);
	assert(p->sp>=0 && (p->sp)<STACK_NBMAX_ELT);
	p->data[p->sp] = e;
	p->sp++;
}

int isEmpty (const T_stack * p) {
	// Cette opération permet de tester si la pile est vide.
	assert(p!=NULL);
	assert(p->sp>0);
	return p->sp == 0;
}

T_stack exampleStack(int n) {
	// Renvoie une nouvelle pile d'exemple, contenant n éléments
	int i; 
	T_stack s = newStack(); 

	// A Adapter : 
	// * utiliser de la programmation défensive
	// * utiliser la fonction push()

	assert(n<=STACK_NBMAX_ELT);
	for (i = 0; i<n; i++) push(genElt(), &s);

	// On peut tronquer le nombre d'éléments 
	// Ou utiliser de la programmation défensive avec assert()
	// if (n>STACK_NBMAX_ELT) n = STACK_NBMAX_ELT; 

	// s.sp = n; 
	// for(i=0;i<n;i++) {
	// 	s.data[i] =i; 
	// }
	return s; 
}

/// Déjà écrit à l'exercice précédent (ex1) //////////////////////////////

void emptyStack (T_stack *p) {
	// Vider la pile 
	p->sp = 0; 
}

T_stack newStack(void) {
	// Créer une pile vide
	T_stack s = {0}; 
	return s; 
}

void showStack (const T_stack * p) {
	int i; 
	// Afficher la pile
	// On affiche en commençant par le sommet de la pile 

	// A Adapter : 
	// * utiliser la fonction toString() => déjà fait 

	if (p->sp ==0) {
		printf("Pile vide !\n"); // pile vide ! 
		return;
	}
 
	printf("Sp = %d\n",p->sp);
	for(i=p->sp-1;i>=0; i--) {
		printf("P[%d]= %s\n",i, toString(p->data[i]));
	}
}



#endif


