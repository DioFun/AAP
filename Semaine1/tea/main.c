#include <stdio.h>
#include <stdlib.h>
#include "../include/traces.h" 

void countChars(int t[]);
void showStats (int t[]);
int * newArray(int size);

int main(int argc, char ** argv) {
    CLRSCR();
	WHOAMI(); 

    // int occurrences[29] = {0};
    int * occurrences = newArray(29); // 7.
printf("Adresse du tableau renvoyé par la fonction malloc : %p\n", &occurrences);

    countChars(occurrences);
	showStats(occurrences);

    printf("Dans la fonction main :\n");
    printf("    Adresse mémoire de la variable occurrences : %p\n", &occurrences);
    printf("    Adresse de la première case du tableau occurrences : %p\n", &(occurrences[0]));
    printf("    Valeut de l'expression occurrences : %d\n", occurrences);
}


void countChars(int t[]) {
    int inWord = 0;
    char c;
    while ( ( c = getchar() ) != EOF) {

        switch(c) {
            case '\n' : 
                t[26]++;

            case ' ' : 

            case '\t' : 
                t[27]++;
                if (inWord) {
                    t[28]++;
                    inWord = 0;
                }
                break;

            default : 
                inWord = 1;
                if (c>='a' && c<='z') {
                    t[c-'a']++;
                } else if (c>='A' && c<='Z') {
                    t[c-'A']++;
                }
                t[27]++; 
        }
    }
}

// void showStats (int t[]) { 
void showStats (int * t) { // 2.
    printf("/==========================================================\\\n");
    printf("|    Stat    |    Nombre    |      t+i     |    * (t+i)    |\n");
    printf("|==========================================================|\n");
    printf("| Nb Lignes  |    %6d    |%p|       %3d     |\n", t[26], t+26, * (t+26));
    printf("| Nb Carac   |    %6d    |%p|       %3d     |\n", t[27], t+27, * (t+27));
    printf("| Nb Mots    |    %6d    |%p|       %3d     |\n", t[28], t+28, * (t+28));
    for (int i = 0; i<26; i++) {
        printf("|     %c      |    %6d    |%p|       %3d     |\n", i+'A', t[i], t+i, * (t+i));
    }
    printf("\\==========================================================/\n");

    printf("size of int : %d\n", sizeof(int));

    HR();
    printf("Dans la fonction showStats :\n");
    printf("    Valeur de la variable t : %d\n", t);
    printf("    Adresse de la variable t : %p\n", &t);

}

// 4.

// int * newArray(int size) {
//     int t[size] = {0};
//     return &t;
// }

// 6.

int * newArray(int size) {
    return (int *)malloc(sizeof(int)*size);
}
