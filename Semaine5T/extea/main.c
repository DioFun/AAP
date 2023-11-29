#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/traces.h"
#include "../include/check.h"

#include "queue_cld.h"
#include "article.h"

#define RAYON_COUNT 3

typedef struct {
    int id;
    T_queue content;
} T_rayon;

void showMenu();
void scanline(char **pStr, int size); // Fonction de lecture d'une ligne de texte.
void init(T_rayon **rayons);
void addProduct(T_rayon *rayons);
void deleteFirstProduct(T_rayon *rayons);
void deleteProductById(T_rayon *rayons);
void addFromFile(T_rayon *rayons);

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
        showMenu(); // On affiche le menu.
        char *input = malloc(sizeof(char)*100); 
        printf("Votre choix : ");
        scanf("%100s", input);
        printf("Lecture : %s\n", input);
        if (strlen(input)>1) { // On vérifie que l'entrée saisie est valide.
            printf("L'entrée saisie n'est pas valide.\n");
            continue; // On affiche à nouveau le menu.
        }
        switch (input[0]) { // On exécute l'action correspondante.
            case '1':
                printf("-> Initialisation des rayons.\n");
                init(&rayons);
                break;
            case '2':
                printf("Ajout d'un produit.\n");
                addProduct(rayons);
                printf("Produit ajouté.\n");
                break;
            case '3':
                printf("Suppression du premier article d'un rayon.\n");
                deleteFirstProduct(rayons);
                printf("Article supprimé.\n");
                break;
            case '4':
                printf("Suppression d'un article par identifiant.\n");
                deleteProductById(rayons);
                break;
            case '5':
                printf("Affichage des rayons.\n");
                for (int i = 0; i < RAYON_COUNT; i++){
                    printf("Rayon %d : ", 1001+i);
                    showList_rec(rayons[i].content.head);
                    printf("\n");
                }
                break;
            case '6':
                printf("Nombre d'articles dans les rayons.\n");
                for (int i = 0; i < RAYON_COUNT; i++){
                    printf("Rayon %d : %d\n", 1001+i, count_rec(rayons[i].content));
                }                
                break;
            case '7':
                printf("Ajout par fichier.\n");
                addFromFile(rayons);
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


void showMenu() { // Fonction d'affichage du menu.
    HR();
    printf("Menu d'action sur les rayons et produits :\n");
    printf("1. Initialiser les rayons\n");
    printf("2. Ajouter un produit\n");
    printf("3. Supprimer le premier article d'un rayon\n");
    printf("4. Supprimer un article par identifiant\n");
    printf("5. Afficher un rayon\n");
    printf("6. Nombre d'articles dans les rayons.\n");
    printf("7. Ajout par fichier.\n");
    printf("8. Quitter\n");
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

void addProduct(T_rayon *rayons) { // Fonction d'ajout d'un produit.
    printf("Identifiant rayon : ");
    int rayonId;
    scanf("%d", &rayonId);
    printf("Nom du produit : ");
    char input[100];
    scanf("%100s", input); // %[^\n]
    T_elt elt = genElt(strdup(input), rayonId); 
    enqueue(&(rayons[rayonId-1001].content), elt); 
}

void deleteFirstProduct(T_rayon *rayons) { // Fonction de suppression du premier produit d'un rayon.
    printf("Identifiant rayon : ");
    int rayonId;
    scanf("%d", &rayonId);
    if (rayonId < 1001 || rayonId > 1000+RAYON_COUNT) { // On vérifie que l'identifiant est valide.
        printf("L'identifiant du rayon n'est pas valide.\n");
        return;
    } 
    if (isEmpty(rayons[rayonId-1001].content)) { // On vérifie que le rayon n'est pas vide.
        printf("Le rayon est vide.\n");
        return;
    }
    dequeue(&(rayons[rayonId-1001].content)); // On supprime le premier élément du rayon.
}


void deleteProductById(T_rayon *rayons) { // Fonction de suppression d'un produit par identifiant.
    printf("Identifiant rayon : ");
    int rayonId;
    scanf("%d", &rayonId);
    if (rayonId < 1001 || rayonId > 1000+RAYON_COUNT) { // On vérifie que l'identifiant est valide.
        printf("L'identifiant du rayon n'est pas valide.\n");
        return;
    }
    if (isEmpty(rayons[rayonId-1001].content)) { // On vérifie que le rayon n'est pas vide.
        printf("Le rayon est vide.\n"); 
        return;
    }
    printf("Identifiant produit : ");
    int productId;
    scanf("%d", &productId);
    T_queue *q = &(rayons[rayonId-1001].content);
    T_node *p = q->head;
    T_node *prev = NULL;
    while (p != NULL) { // On parcourt la liste.
        if (getId(p->data) == productId) { // Si l'identifiant du produit est trouvé.
            if (prev == NULL) { // Si le produit est en tête de liste.
                q->head = p->pNext; // On met à jour la tête de liste.
            } else { // Si le produit n'est pas en tête de liste.
                prev->pNext = p->pNext; // On met à jour le pointeur de la cellule précédente.
            } 
            free(p); // On libère la mémoire de la cellule.
            printf("Produit supprimé.\n"); // On affiche un message de confirmation.
            return;
        } 
        prev = p; // On met à jour le pointeur de la cellule précédente.
        p = p->pNext; // On passe à la cellule suivante.
    }
    printf("Le produit n'a pas été trouvé.\n"); // Si on arrive ici, le produit n'a pas été trouvé.
    return;
}

void addFromFile(T_rayon *rayons) { // Fonction d'ajout de produits à partir d'un fichier.
    printf("Nom du fichier : ");
    char fileName[100];
    scanf("%100s", fileName);
    FILE *file = fopen(fileName, "r"); // On ouvre le fichier en lecture seule.
    if (file == NULL) { // On vérifie que le fichier a bien été ouvert.
        printf("Le fichier n'a pas pu être ouvert.\n");
        return;
    }
    char line[100];
    while (fgets(line, 100, file) != NULL) { // On lit le fichier ligne par ligne.
        char name[100];
        int cat;
        sscanf(line, "%d %[^\n]", &cat, name); // On extrait les données de la ligne.
        printf("Ajout de %s dans le rayon %d.\n", name, cat);
        T_elt elt = genElt(strdup(name), cat); // On génère l'élément.
        enqueue(&(rayons[cat-1001].content), elt); // On ajoute l'élément au rayon correspondant.
    }
    fclose(file); // On ferme le fichier.
    printf("Ajout terminé.\n");
}