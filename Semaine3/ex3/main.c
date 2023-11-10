#include <stdio.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

#define DEBUG
#include "../include/check.h"  

#define MAXLEN 10
#define MAXNAME 10

int main(int argc, char ** argv) {

	char * nom = NULL; 
	FILE * fp = NULL; 
	char buffer[MAXLEN]; 
	char filename[MAXNAME]; 	 
	int i=0; 

	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	// Produire un programme permettant de créer un fichier 
	// pour y stocker les caractères saisis sur l’entrée standard
	// Le chemin du fichier doit être passé en ligne de commande
	// En cas d’absence ou de manque de droits, signaler l’erreur sur stdout
	// Si le fichier existe déjà, on crée un autre fichier en le numérotant 
	// La lecture de l’entrée standard doit employer la fonction fgets
	// Lire 10 caractères à la fois 
	/////////////////////////////////////////////////////////////////////////
	
	
} 

