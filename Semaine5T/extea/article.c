#include <stdio.h> // sprintf
#include <string.h> // strdup
#include <stdlib.h>

#include "article.h"

T_elt genElt(char * name, int cat) {
    int static id = 0; // On utilise une variable static pour que l'id soit différent pour chaque élément.
    T_elt elt;
    elt.name = name;
    elt.cat = cat;
    elt.id = id;
    id++; // On incrément l'id pour le prochain élément.
    return elt;
}

char *toString(T_elt elt) {
    char *str = malloc(sizeof(char) * 100);
    sprintf(str, "elt(%s, %d, %d)", elt.name, elt.cat, elt.id);
    return str;
}

int getCat(T_elt elt) {
    return elt.cat;
}

int getId(T_elt elt) {
    return elt.id;
}