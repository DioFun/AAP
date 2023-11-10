#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 10
//#define CLEAR2CONTINUE
#include "../include/traces.h" 

void test_aveCesar(void); 
void test_dyhCesar(void);
void test_cesar(void); 
void test_rot13(void); 

char * aveCesar(const char *);
char * dyhCesar(const char *);
char * cesar(const char *, const int);
char * rot13(const char *);

// TODO : aveCesar() retourne le résultat du chiffrement de la chaîne de caractères transmise en paramètre
// TODO : dyhCesar() retourne le résultat du déchiffrement de la chaîne de caractères transmise en paramètre
// TODO : cesar() retourne le résultat du chiffrement de la chaîne de caractères transmise en paramètre en appliquant le décalage passé en paramètre
// TODO : rot13() retourne le résultat du chiffrement de la chaîne de caractères transmise en paramètre en appliquant un décalage de 13 rangs

int main (int argc , char * argv [])
{
	int n = 0;
	char ligne [MAXLEN + 1] = "";

	CLRSCR();
	WHOAMI(); 
	
	// test_aveCesar(); 
	// test_dyhCesar(); 
	// test_cesar();
	test_rot13(); 

	// TODO : Commande shell de chiffrement-déchiffrement
 
	return 0;
}

void test_aveCesar (void) {
	printf ("%s\n", aveCesar ("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf ("%s\n", aveCesar ("TU QUOQUE MI FILI"));
	printf ("%s\n", aveCesar ("VENI VIDI VICI"));
	printf ("%s\n", aveCesar ("XIBX GXZQX BPQ"));
	printf ("%s\n", aveCesar ("PF SFP MXZBJ MXOX YBIIRJ"));
}

char* aveCesar(const char * str) {
	char * ret = strdup(str);
	for (int i = 0; i < strlen(str); i++){
		if (ret[i] >= 'A' && ret[i]<='Z') ret[i] = 'A' + (((ret[i]-'A')+3) % 26);
	}
	return ret;
}

void test_dyhCesar (void) {
	printf ("%s\n", dyhCesar ("DEFGHIJKLMNOPQRSTUVWXYZABC"));
	printf ("%s\n", dyhCesar ("VDWRU \nDUHSR \nWHQHW \nRSHUD \nURWDV"));
	printf ("%s\n", dyhCesar ("GHPR GHV PDXA GHV PRWV"));
	printf ("%s\n", dyhCesar ("YDH YLFWLV"));
}

char* dyhCesar(const char * str) {
	char * ret = strdup(str);
	for (int i = 0; i < strlen(str); i++){
		if (ret[i] >= 'A' && ret[i]<='Z') ret[i] = 'A' + (((ret[i]-'A')+23) % 26);
	}
	return ret;
}

void test_cesar(void) {
	printf ("%s\n", cesar ("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3));
	printf ("%s\n", cesar ("TU QUOQUE MI FILI", 3));
	printf ("%s\n", cesar ("VENI VIDI VICI", 3));
	printf ("%s\n", cesar ("XIBX GXZQX BPQ", 3));
	printf ("%s\n", cesar ("PF SFP MXZBJ MXOX YBIIRJ", 3));
	printf ("\n");
	printf ("%s\n", cesar ("DEFGHIJKLMNOPQRSTUVWXYZABC", -3));
	printf ("%s\n", cesar ("VDWRU \nDUHSR \nWHQHW \nRSHUD \nURWDV", -3));
	printf ("%s\n", cesar ("GHPR GHV PDXA GHV PRWV", -3));
	printf ("%s\n", cesar ("YDH YLFWLV", -3));
}

char * cesar(const char * str, const int n) {
	char * ret = strdup(str);
	for (int i = 0; i < strlen(str); i++){
		if (ret[i] >= 'A' && ret[i]<='Z') ret[i] = 'A' + (((ret[i]-'A')+n) % 26);
	}
	return ret;
}

void test_rot13(void) {
	char * indication = "P'rfg fba svyf"; 
	char * decoded; 

	printf("Un homme vous montre un portrait et dit : « Je n’ai pas de frère ni de sœur, mais le père de cet homme est le fils de mon père. » Qui est représenté par le portrait ?\n");
	decoded = rot13(indication); 
	printf("La réponse est : %s\n",decoded);
	printf("rot13(rot13(%s)) = %s\n",indication, rot13(rot13(indication)));
}


char * rot13(const char * str) {
	char * ret = strdup(str);
	for (int i = 0; i < strlen(str); i++){
		if (ret[i] >= 'A' && ret[i]<='Z') ret[i] = 'A' + (((ret[i]-'A')+13) % 26);
	}
	return ret;
}