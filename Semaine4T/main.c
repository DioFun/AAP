#include <stdio.h>
#include <stdlib.h>
// #include "elt.h"
#include "stack_cd.h"
#include "include/traces.h"

int main(int argc, char **argv) {
    WHOAMI();
    printf("Jeu d'essais \n"); // Jeu d'essais
    HR();
    printf("Test de la fonction typeToString\n"); // Test concernant la fonction typeToString
    printf("%s\n", typeToString(FONCTION));
    HR();
    printf("Test de la fonction isDelimiter\n"); // Test concernant la fonction isDelimiter
    printf("%d\n", isDelimiter("(a"));
    printf("%d\n", isDelimiter(")"));
    printf("%d\n", isDelimiter("]"));
    printf("%d\n", isDelimiter("["));
    printf("%d\n", isDelimiter("<"));
    printf("%d\n", isDelimiter(">"));
    printf("%d\n", isDelimiter("})"));
    printf("%d\n", isDelimiter("}"));
    HR();
    printf("Test des fonctions sur les T_elt\n"); // Test concernant les fonctions sur les T_elt

    T_elt e = toElt("})");
    printf("Pour '})' -> taille : %d, ouvrant : %s, fermant : %s, type : %s, kind : %d\n", e.size, e.open, e.close, typeToString(e.type), e.kind);
    char *s = toString(e);
    printf("toString : %s\n", s);
    showBloc(e, 0);

    e=toElt("(a");
    printf("Pour '(a' -> taille : %d, ouvrant : %s, fermant : %s, type : %s, kind : %d\n", e.size, e.open, e.close, typeToString(e.type), e.kind);
    s = toString(e);
    printf("toString : %s\n", s);
    showBloc(e, 1);
    
    free(s);
    s = NULL;

    HR();
    printf("Test de reconnaissance d'un texte saisie sur l'entrée standard\n"); // Test concernant la reconnaissance d'un texte saisie sur l'entrée standard

    char *str=malloc(2*sizeof(char));
    T_stack stack = newStack(5);

    char c1=getchar();
    char c2;
    int i = 0;
    
    while(c1 != '\n') {
        c2=getchar(); // le placer ici permet d'éviter de lire le caratère au bon moment et non pas avant d'en avoir besoin
        // printf("%c, %c\n", c1, c2 == '\n' ? ' ' : c2);
        str[0]=c1; str[1]=c2;
        c1=c2; // On lit le caractère suivant (permet d'éviter une répition de code dans le if suivant et à la fin de la boucle)
        i++;

        if (!isDelimiter(str)) continue;
        if (!isEmpty(&stack)) { // On vérifie de manière gloutone comment évaluer l'expression "))" soit en tant que deux fonctions ou une expression fermant(s)
            T_elt e1 = top(&stack);
            if (e1.type == FONCTION && e1.kind == OPENING && str[0] == ')') {
                str[1] = ' ';
            }
        }
        T_elt e = toElt(str);
        if (e.size == 2) { // Si le délimiteur est de taille 2, on lit les caractères suivants
            c2=getchar();
            c1=c2;
            i++;
        }
        if (e.kind == OPENING) { // On ouvre un bloc en cas de caracètre ouvrant
            showBloc(e, stack.sp);
            push(e, &stack);
        } else { // en cas de caractère fermant
            if (isEmpty(&stack)) { // On vérifie que la pile n'est pas vide
                printf("Erreur : caractère %d : tentative de fermeture d'un délimiteur qui n'est pas ouvert.\n", i);
                exit(1);
            }
            T_elt e1 = pop(&stack);
            if (e1.type != e.type) { // On vérifie le bon parenthèsage et on affiche l'erreur si besoin
                printf("Erreur : caractère %d : mauvais délimiteur trouvé ! On attendait le(s) délimiteur(s) suivant(s) : %s", i, typeToString(e1.type));
                for (int j=0; j<stack.sp; j++) {
                    e1 = pop(&stack);
                    printf(", %s", typeToString(e1.type));
                }
                printf(".\n");
                exit(1);
            }
            showBloc(e, stack.sp);
        }
    }
    if (!isEmpty(&stack)) { // On vérifie que la pile est vide
        e = pop(&stack); // On pop avant pour avoir les virgules bien placées
        printf("Erreur : expression non terminée ! On attendait le(s) délimiteur(s) suivant(s) : %s", typeToString(e.type));
        for (int j=0; j<stack.sp; j++) {
            e = pop(&stack);
            printf(", %s", typeToString(e.type));
        }
        printf(".\n");
        exit(2);
    }

    freeStack(&stack); // On libère la mémoire
    free(str); 
    str = NULL;

}