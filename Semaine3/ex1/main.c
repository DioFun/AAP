#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define CLEAR2CONTINUE
#include "../include/traces.h" // DUMPHEAD, DUMPCHAR, ...
#include "mlstring.h"
/*
Produire un module de gestion de chaînes de caractères
* Vos chaînes devront être déclarées comme un type T_mlstring, représentant un tableau de MAXLEN caractères AU PLUS 
* Votre module sera composé d’un fichier source et d’un fichier d’entête
* Un fichier principal permettra de tester les fonctions de votre module
* Implémenter les fonctions suivantes : 

int mlstringLen(const T_mlstring mls);
void mlstringCat (T_mlstring mls_dest, const T_mlstring mls_src);
char *  toMlstring(const char * s);
char *  mlstringDup(const T_mlstring);

*/

int main(int argc, char ** argv) { 


	CLRSCR(); 			
	WHOAMI(); 
	T_mlstring mls1 = "hello "; 
	T_mlstring mls2 = "world"; 
	char * s, * s3; 
	
	printf("mls1 vaut %s (taille %d)\n", mls1, mlstringLen(mls1));	
	printf("mls2 vaut %s (taille %d)\n", mls2, mlstringLen(mls2));
	
	mlstringCat (mls1, mls2); 
	printf("mls1 vaut %s (taille %d)\n", mls1, mlstringLen(mls1));

	s = toMlstring("Salut les amis !"); 
	printf("s vaut %s (taille %d)\n", s, mlstringLen(s));
	// free(s); 
	
	s3 = mlstringDup(s); 
	free(s);
	printf("s3 vaut %s (taille %d)\n", s3, mlstringLen(s3));
	free(s3); 
	

}

