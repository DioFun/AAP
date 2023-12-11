#include <string.h>
#include <stdio.h>
#include "test_utils.h"
#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

void fusionner(T_elt t [], int d, int m, int f); 

T_data fusionSort(T_data d, int n){
    T_elt *t = d.pElt;
    int debut = 0;
    int fin = n - 1;
    int milieu;

    if (debut < fin)
    {
        milieu = (debut + fin) / 2;
        fusionSort(genData(0, t + debut), milieu + 1);
        fusionSort(genData(0, t + milieu + 1), fin - milieu);
        fusionner(t, debut, milieu, fin);
    }
	return 
}

void fusionner(T_elt t [], int d, int m, int f) {
	T_elt aux[f - d + 1]; // !! Allocation dynamique sur la pile (standard C99) 
	int i, j, k;
	

	memcpy(aux, &t[d], (f - d + 1) * sizeof(T_elt));	// Copie des données à fusionner

	i = 0; j = m - d + 1; k = 0;
	while (i <= m - d && j <= f - d) {
		if (aux[i] <= aux[j]) 	{
			t[d + k++] = aux[i++];	// aux[i] est plus petit : on le place dans t 
		}
		else {
	 		t[d + k++] = aux[j++];	// aux[j] est plus petit : on le place dans t 
		}
	}
	for (; i <= m - d; t[d + k++] = aux[i++]); // le reste du tableau gauche
	for (; j <= f - d; t[d + k++] = aux[j++]); // le reste du tableau droit
}



