#include <stdio.h>
#define NAME_SIZE 14 // déclaration de NAME_SIZE

// Déclaration des fonctions
int checksum(char string[], int nbr);

// Fonction principale
int main () {
    char name_array[] = "DROUETBAPTISTE";
    printf("%i\n", checksum(name_array, NAME_SIZE));
    return 0;
}

// Fait la somme modulo 256 d'un tableau de caractères string possèdant nbr éléments.
int checksum(char string[], int nbr) {
    char sum = 0;
    for(int i = 0; i<nbr; i++) {
        char letter = string[i];
        sum+=letter;
        sum%=256;
    }
    return sum;
}