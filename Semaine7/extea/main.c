#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "merge_sort.h"
#include "elt.h"
#include "test_utils.h"

#define MAX_LGTH 10000

// Ajouter ici les prototypes des fonctions à testerv
T_data merge_sort(T_data d, int n);
// mode, label, x, checkOrder 
T_mode m[] = {
	{MODE_LIST_ORDONNE, "ordonne", 0, 1}, 
	{MODE_LIST_ALEATOIRE, "aleatoire", 0, 1}, 
	{MODE_LIST_INVERSE, "inverse", 0, 1}
};

int main () {
    srand((unsigned int)time(NULL));
    outputPath = "extea/output";
    T_list l = NULL;
    l = addNode(genData(5, NULL), l);
    l = addNode(genData(18, NULL), l);
    l = addNode(genData(9, NULL), l);
    l = addNode(genData(1, NULL), l);
    l = addNode(genData(2, NULL), l);
    l = addNode(genData(3, NULL), l);
    generatePNG(l, "extea/output/graph/initial_list.dot");
    system("dot extea/output/graph/initial_list.dot -T png -o extea/output/graph/initial_list.png");
    showList(l);
    printf("\n");
    merge_sort(genData(0, &l), MAX_LGTH);
    generatePNG(l, "extea/output/graph/merge_sort_end.dot");
    showList(l);
    printf("\n");
    freeList(l);
    l = NULL;
    Test_Fn("Merge sort list", merge_sort, &l, MAX_LGTH, m[MODE_LIST_ALEATOIRE]);
    Test_FnV2("Merge sort list", merge_sort, &l, MAX_LGTH, m[MODE_LIST_ALEATOIRE]);
    return 0;
}