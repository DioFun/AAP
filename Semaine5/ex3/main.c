#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

#define MAXDISCS 10

void hanoi(char startCol, char destCol, char byCol, int nbDiscs); 

int main(int argc, char ** argv) {
	int i, nb; 
	
	CLRSCR();
	WHOAMI(); 

	// Comment faire passer 3 disques de la colonne A vers la colonne C ? 
	for(i=0;i<MAXDISCS;i++) {
		printf("Déplacement de %d disque(s) de A vers C :\n",i);
		nb = hanoi('A', 'C', 'B', i); 
		printf("Nombre de déplacements nécessaires pour déplacer %d disque(s) : %d\n",i, nb);
		ENTER2CONTINUE();
	}


	return 0;
}

int hanoi(char startCol, char destCol, char byCol, int nbDiscs) {
	/////////////////////////////////////////////////////////////////////////
	// TODO: afficher les actions permettant de faire passer nbDiscs
	// de la colonne startCol à la colonne destCol
	// en respectant les contraintes suivantes : 
	// déplacer un disque à la fois
	// ne jamais poser un disque sur un disque plus petit que lui
	
	// La fonction doit renvoyer le nombre d'opérations effectuées
	/////////////////////////////////////////////////////////////////////////
	
	assert(nbDiscs>0);

	TOUCH_HERE("Ben là, c'est à vous ! \n");
	
	// Ordre de la récurrence ? 
	// Cas de base 
	// Cas général 

}





