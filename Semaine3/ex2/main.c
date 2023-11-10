#include <stdio.h>
#include <string.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h"  

//#define DEBUG
#include "../include/check.h"  


int main(int argc, char ** argv, char ** envp) {

	CLRSCR(); 
	WHOAMI(); 
	
	char * nom; 
	int numero; 

	if (argc == 3) {
		nom = argv[1];
		numero = atoi(argv[2]);
	} else {
		int i = 0;
		while(envp[i] != NULL && strstr(envp[i], "USER") == NULL) {
			i++;
		}
		nom = strchr(envp[i],'=')+1;
		numero = getuid();
	}

	printf("Hello %s %d !\n", nom, numero);

	/////////////////////////////////////////////////////////////////////////
	// Produire un programme baptisé “hello” saluant les rois de France 
	// dont le nom et le numéros sont passés en ligne de commandes
	// En cas d’absence d’arguments, 
	// on saluera l’utilisateur courant (variable d’environnement $USER) 
	// et son uid (renvoyé par la fonction getuid) 
	/////////////////////////////////////////////////////////////////////////
	
	return 0;
}
