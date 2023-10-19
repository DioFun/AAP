#include <stdio.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

#define MAXTAB 26

#define STEP_1 1
#define STEP_2 2
#define STEP_3 3
#define STEP_4 4

void etape1(void); 
void etape2(void); 
void etape3(void);
void etape4(void);

int main(int argc, char ** argv) {
	int step=STEP_1; 

	CLRSCR();
	WHOAMI(); 

	// TODO: Cas d'étude : tout est écrit dans la trame de séance 
	// https://docs.google.com/document/d/1ihFH-VOprs5WL-XV5YdAZapjQ33m9CLxb3fWEp1U7b0/edit?usp=sharing
	
	// TOUCH_HERE("Ben là, c'est à vous ! Liberté totale ! \n");
	// PROMPT("Les fichiers d'exemple sont dans le sous-répertoire extraits\n");

	if (argc>1) step = atoi(argv[1]);
	
	switch(step){
		case STEP_1 :
			printf("Etape 1\n");	 
			etape1();
		break;
		case STEP_2 : 
			printf("Etape 2\n");
			etape2();
		break;
		case STEP_3 :
			printf("Etape 3\n");
			etape3();
		break;
		case STEP_4 :
		default :
			printf("Etape 4\n");
			etape4();
	}


	return 0;
}

void etape1(void) {
	/////////////////////////////////////////////////////////////////////////
	// Etape 1 : Compléter l’exemple ci-dessus de façon à 
	// comptabiliser les caractères, 
	// ainsi que les lignes tapées au clavier par l’utilisateur.
	/////////////////////////////////////////////////////////////////////////

	char c ; 
	int nbChars = 0;
	int nbLines = 0;

	printf("Saisir des caractères au clavier (Ctrl+D) pour terminer\n");

	while ( ( c = getchar() ) != EOF) {
		nbChars++;
		if (c == '\n') nbLines += 1;
	}
	printf("Nombre de caractères : %d\n", nbChars);
	printf("Nombre de lignes : %d\n", nbLines);


}

void etape2(void) {
	/////////////////////////////////////////////////////////////////////////
	// De façon à ne pas trop compliquer les traitements, 
	// on considérera qu’un mot est une séquence de caractères
	// encadrée de séparateurs et dans un premier temps, 
	// seuls trois séparateurs seront pris en compte : 
	// le saut de ligne, l’espace et le caractère de tabulation ('\t' ).
	// Modifier le programme précédent de manière à ce qu’il compte 
	// également les mots du texte tapé au clavier, en gardant à l’esprit
	// qu’il ne faut pas modifier le nombre de mots lorsqu’on lit 
	// une séquence de séparateurs.
	// Utiliser la structure de contrôle switch
	/////////////////////////////////////////////////////////////////////////

	char c ; 
	int nbLines = 0;
	int nbChars = 0;
	int nbWords = 0;

	printf("Saisir des caractères au clavier (Ctrl+D) pour terminer\n");

	while ( ( c = getchar() ) != EOF) {

		printf("Caractère lu : '%c'\n",c);

		switch(c) {
			case '\n' : 
				nbLines++;

			case ' ' : 

			case '\t' : 
				nbChars++;
				nbWords++;
				break;

			default : 
				nbChars++; 
		}
	}

}

void etape3(void) {
	/////////////////////////////////////////////////////////////////////////
	// Compléter le programme précédent de façon à afficher 
	// en plus des résultats précédents : 
	// le nombre total de caractères alphabétiques,
	// un tableau présentant le nombre d’occurrences 
	// de chaque caractère alphabétique, ainsi que sa fréquence 
	// (rapport entre le nombre d’occurrences d’un caractère alphabétique 
	// sur le nombre total de caractères alphabétiques).
	/////////////////////////////////////////////////////////////////////////

}

void etape4(void) {
	/////////////////////////////////////////////////////////////////////////
	// Refactoriser le programme précédent de façon à réaliser 
	// les mêmes traitements, en utilisant des fonctions à développer : 
	// * Une fonction countChars servira lire les caractères au clavier 
	// et à remplir le tableau d'occurrences passé en paramètre 
	// * Une fonction showStats servira à afficher le tableau d'occurrences 
	// passé en paramètre 
	// * Est-il possible de créer et d’utiliser une fonction newArray 
	// pour créer un tableau dont la taille est passée en paramètre 
	// et le renvoyer après l’avoir initialisé ? 
	/////////////////////////////////////////////////////////////////////////


}
