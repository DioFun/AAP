#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/traces.h"
#include "../include/check.h"

#include "queue_cld.h"

#define RAYON_COUNT 3

typedef struct {
    int id;
    T_queue content;
} T_rayon;

void showMenu();
void scanline(char **pStr, int size); // Fonction de lecture d'une ligne de texte.
void init(T_rayon **rayons);
void addProduct(T_rayon *rayons, int rayonId, char *name);

int main(int argc, char **argv) {
    WHOAMI();

    // HR();
    // printf("-> Test module elt\n\n");

    // T_elt elt1 = genElt("elt1", 1);
    // T_elt elt2 = genElt("elt2", 2);

    // printf("%s\n", toString(elt1));
    // printf("%s\n", toString(elt2));
    // printf("%d\n", getCat(elt1));
    // printf("%d\n", getId(elt1));

    // HR();
    // printf("-> Test module queue\n\n");

    // T_queue q = newQueue();
    // showQueue(q);
    // enqueue(&q, elt1);
    // showQueue(q);
    // enqueue(&q, elt2);
    // showQueue(q);
    // printf("%d\n", count(q));
    // T_elt c = dequeue(&q);
    // showQueue(q);
    // printf("%s\n", toString(c));
    // printf("%s\n", toString(top(q)));
    // showQueue(q);

    // HR();
    printf("-> Implémentation du programme principal.\n\n");
    HR();
    T_rayon *rayons = NULL;
    while (1) {
        showMenu();
        char *input = malloc(sizeof(char)*100);
        printf("Votre choix : ");
        scanf("%100s", input);
        printf("Lecture : %s\n", input);
        if (strlen(input)>1) {
            printf("L'entrée saisie n'est pas valide.\n");
            continue; // On affiche à nouveau le menu.
        }
        switch (input[0]) {
            case '1':
                printf("-> Initialisation des rayons.\n");
                init(&rayons);
                break;
            case '2':
                printf("Ajout d'un produit.\n");
                printf("Identifiant rayon : ");
                scanf("%100s", input);
                int rayonId = atoi(input);
                printf("Nom du produit : ");
                scanf("%100s", input);
                printf("Lecture : %s\n", input);
                addProduct(rayons, rayonId, input);
                printf("Produit ajouté.\n");
                break;
            case '3':
                printf("Suppression d'un article d'un rayon.\n");
                printf("Identifiant rayon : ");
                scanf("%100s", input);
                rayonId = atoi(input);
                dequeue(&(rayons[rayonId-1001].content));
                printf("Article supprimé.\n");
                break;
            case '4':
                printf("Suppression d'un article par identifiant.\n");
                printf("Identifiant article : ");
                scanf("%100s", input);
                int articleId = atoi(input);
                
                break;
            case '5':
                printf("Affichage d'un rayon.\n");
                printf("Identifiant rayon : ");
                scanf("%100s", input);
                rayonId = atoi(input);
                showQueue(rayons[rayonId-1001].content);
                break;
            case '6':
                printf("Nombre d'articles dans les rayons.\n");
                for (int i = 0; i < RAYON_COUNT; i++){
                    printf("Rayon %d : %d\n", 1001+i, count(rayons[i].content));
                }                
                break;
            case '7':
                printf("Ajout par fichier.\n");
                break;
            case '8':
                return 0;
            default:
                printf("L'entrée saisie n'est pas valide.\n");
                break;
        
        }

    }
    return 0;
}


void showMenu() {
    HR();
    printf("Menu d'action sur les rayons et produits :\n");
    printf("1. Initialiser les rayons\n");
    printf("2. Ajouter un produit\n");
    printf("3. Supprimer l'article d'un rayon\n");
    printf("4. Supprimer un article par identifiant\n");
    printf("5. Afficher un rayon\n");
    printf("6. Nombre d'articles dans les rayons.\n");
    printf("7. Ajout par fichier.\n");
    printf("8. Quitter\n");
}

void scanline(char **pStr, int size) {
    char *str = *pStr;
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < size-1) {
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    *pStr = str;
}

void init(T_rayon **pR) { // Fonction d'initialisation ou de réinitialisation.
    *pR = realloc(*pR, sizeof(T_rayon) * RAYON_COUNT);
    CHECK_IF(*pR, NULL, "init : allocation failed.");
    for (int i = 0; i < RAYON_COUNT; i++) {
        (*pR)[i].id = 1000+i+1;
        (*pR)[i].content = newQueue();
    }
    printf("Rayons initialisés.\n");
}

void addProduct(T_rayon *rayons, int rayonId, char *name) {
    printf("Ajout d'un produit.\n");
    T_elt elt = genElt(name, rayonId);
    enqueue(&(rayons[rayonId-1001].content), elt);
}

