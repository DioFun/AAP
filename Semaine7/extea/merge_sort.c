#include "merge_sort.h"
#include <assert.h>

T_node * merge (T_node * l1, T_node * l2) { // l1 et l2 sont des listes triées
    T_node * l = NULL;
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    stats.nbComparisons++;
    if (l1->data.elt < l2->data.elt) {
        l = l1;
        l->pNext = merge(l1->pNext, l2); stats.nbOperations++;
    } else {
        l = l2;
        l->pNext = merge(l1, l2->pNext); stats.nbOperations++;
    }
    return l;
}

T_data merge_sort(T_data d, int n) { // n est inutile ici mais nécessaire pour l'interface
    T_list * l = d.pElt;
    stats.nbComparisons++;
    if ((*l) == NULL || (*l)->pNext == NULL) { // On verifie si la liste est vide ou si elle ne contient qu'un seul élément
        if ((*l) != NULL) stats.nbComparisons++;
        return genData(0, l);   // On retourne la liste
    } 
    T_node * l1 = *l; stats.nbOperations++; // On initialise l1 à la tête de la liste
    T_node * l2 = (*l)->pNext; stats.nbOperations++; // On initialise l2 à l'élément suivant de la liste
    while (l2 != NULL) { // On parcourt la liste jusqu'à ce que l2 soit NULL
        l2 = l2->pNext; stats.nbOperations++;
        if (l2 != NULL) {
            l1 = l1->pNext; stats.nbOperations++;
            l2 = l2->pNext; stats.nbOperations++;
        }
    }
    l2 = l1->pNext; stats.nbOperations++;
    l1->pNext = NULL; stats.nbOperations++;
    l1 = *l; stats.nbOperations++;
    merge_sort(genData(0, &l1), n);
    merge_sort(genData(0, &l2), n);
    (*l) = merge(l1, l2); stats.nbOperations++;
    return genData(0, l);
}

void generatePNG(const T_list l, const char *filename) { // Génère un fichier .dot
    FILE *file = fopen(filename, "w");
    assert(file != NULL);

    // Header commun du fichier
    fprintf(file, "digraph liste {\ngraph [\nrankdir = \"LR\"\n]\nnode [\nfontname = \"Arial bold\"\nfontsize = \"14\"\nfontcolor = \"red\"\nstyle = \"rounded, filled\"\nshape = \"record\"\nfillcolor = \"grey90\"\ncolor = \"blue\"\nwidth = \"2\"\n]\nedge [\ncolor = \"blue\"\n]\n");

    // Parcours de la liste
    T_node *current = l;
    int id = 1;

    while (current != NULL)
    {
        fprintf(file, "\"ID_%04d\" [label = \"{%s | <next> %s}\"];\n", id, toString(current->data.elt), (current->pNext == NULL) ? "NULL" : "");

        if (current->pNext != NULL)
        {
            fprintf(file, "\"ID_%04d\" : next -> \"ID_%04d\";\n", id, id + 1);
        }

        current = current->pNext;
        id++;
    }

    fprintf(file, "}\n");

    fclose(file);
}