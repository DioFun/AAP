#include <stdio.h>

// #define CLEAR2CONTINUE

#include "../include/traces.h" // DUMPHEAD, DUMPCHAR, ...

#define MAXLEN 10 

int main(int argc, char ** argv) { 
	int i = 0; 
	int tab1[MAXLEN] = {0}; 
	int tab[] = {10,20,30,40,50}; 
	char * p_c; 	// p_c pointe n'importe où
	char c = 'A'; 	// A vaut 65 
	

	int * p = NULL; 
// Il est conseillé d'initialiser systématiquement les pointeurs à NULL ! 
	


	CLRSCR(); 			
	WHOAMI(); 		
	
	CODE(char c = 'A');	
	CODE(char * p_c);

	DUMPHEAD();		// Légende des tableaux 
	DUMPCHAR(c); 	// Affichage d'un caractère 
	DUMPAD(p_c);	// Affichage d'un pointeur 

	HR();			
	NOTE1("Risque d'erreur de segmentation : p_c pointe n'importe où : %p...\n", p_c); 
	NOTE("Vouloir afficher ce qui se trouve à cet endroit n'a pas de sens\n");	

	DUMPHEAD();
	// DUMPCHAR(*p_c);	// TODO: A commenter : segmentation fault ! 

	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();	
	HR();		

	NOTE("Même si on parvient à lire ce qui se trouve à cet endroit\n");
	NOTE("Modifier ce qui se trouve à cet endroit pourrait provoquer une erreur d'exécution\n");
	CODE(*p_c = 'B');
	
	// correction
	// *p_c = 'B'; 	 	// TODO: A commenter : segmentation fault ! 


	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	
	CODE(p_c = &c);
	p_c = &c; 
	NOTE1("p_c pointe maintenant vers l'adresse de c : %p...\n", p_c);
	
	
	DUMPHEAD();
	DUMPCHAR(c);
	DUMPAD(p_c);
	DUMPCHAR(*p_c);
	
	/////////////////////////////////////////////////////////////////////////
	// Arithmétique des pointeurs
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	
	/////////////////////////////////////////////////////////////////////////
	// Quelle erreur s’affiche lors de la compilation d’une affectation 
	// contenant le nom d’un tableau à gauche (tab1 = …) ?
	/////////////////////////////////////////////////////////////////////////

	CODE(tab1 = tab);
	NOTE("main.c:28:8: error: assignment to expression with array type\n");

	// tab1 = tab; // TODO: A commenter pour voir l'erreur générée
	

	/////////////////////////////////////////////////////////////////////////
	// Vérifier que l’identificateur tab 
	// représente bien l’adresse de la première case du tableau 
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	printf("tab vaut %p\n", tab);
	printf("&(tab[0]) vaut %p\n", &(tab[0]));
	printf("&(tab) vaut %p\n", &tab); 

	/////////////////////////////////////////////////////////////////////////
	// Vérifier que tab+i représente bien 
	// l’adresse de la ième case du tableau
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	i = 3; 
	printf("tab vaut %p\n", tab);
	printf("tab+%d vaut %p\n", i, tab+i);
	printf("l'adresse de tab[%d] (ie &(tab[%d])) est %p\n", i,i,&(tab[i]));
	printf("la valeur de tab[%d] est %d\n", i,tab[i]);
	printf("la valeur de *(tab+%d) est %d\n", i, *(tab+i));
	

	/////////////////////////////////////////////////////////////////////////
	// Vérifier l’arithmétique des pointeurs 
	// en utilisant les notations *(p+i) et p[i]
	// Créer un tableau d’entiers
	// Initialiser le contenu des cases du tableau
	// Créer un pointeur pointant sur le début du tableau
	// Utiliser le pointeur pour afficher le contenu du tableau 
	// et les adresses de ses cases (format %p dans printf)
	// Utiliser les deux notations *(p+i) et p[i]
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();
	TOUCH_HERE("Ben là, c'est à vous !\n");

	printf("Manipulation d'un tableau d'entiers de %d cases\n", MAXLEN);
	
	// TODO : initialiser le tableau tab1 (tab1[i] = i)
	for (int i = 0; i < MAXLEN; i++) tab1[i] = i;	

	// TODO : Créer un pointeur pointant sur le début du tableau
	p = tab1;

	// TODO : Utiliser le pointeur pour afficher le contenu du tableau
	// TODO : Utiliser les deux notations *(p+i) et p[i]
	for (int i = 0; i<MAXLEN; i++) printf("i=%d, *(p+i)=%d et p[i]=%d (adresses : %p et %p)\n", i, *(p+i), p[i], p+i, &(p[i]));




}

