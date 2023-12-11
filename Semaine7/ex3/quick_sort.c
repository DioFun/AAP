#include<stdio.h>
#include "test_utils.h"
#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

int Partitionnement (T_elt t [], int g, int d); 

int comparer(T_elt e1, T_elt e2) {
	TOUCH_HERE("Ben là, c'est à vous ! \n");	
}

int comparerP(const void * pe1, const void * pe2) {
	stats.nbComparisons ++;
	return comparer(* (T_elt *) pe1, * (T_elt *) pe2); 
}

void echanger(T_elt t[], int i1, int i2) {
	TOUCH_HERE("Ben là, c'est à vous ! \n");
}


//void Tri_rapide( T_elt t[], int debut, int fin) {
T_data quickSort(T_data d, int n) {
	TOUCH_HERE("Ben là, c'est à vous ! \n");
}

//void Tri_rapide à l'aide de qsort 
T_data quickSort_libc(T_data d, int n) {
	TOUCH_HERE("Ben là, c'est à vous ! \n");
}


int Partitionnement (T_elt t [], int g, int d){ 
	int pg=g , pd=d-1; // On utilise g et d comme « pointeurs » qui se déplacent
	// On choisit le dernier élément comme pivot
	
	int pivot = d;
	
	// le pivot est maintenanent placé à la fin 
	if (pivot != d)
		echanger(t,d,pivot);


	while (pg<pd) {
		// On déplace pg et pd jusqu’à trouver des valeurs incohérentes % pivot

		while ( (pg<pd) &&  (comparer(t[pg],t[d]) <=0) ) {pg++ ;	stats.nbComparisons ++;}
		while ( (pg<pd) && (comparer(t[pd],t[d])>0) ) {pd-- ; stats.nbComparisons ++;}

		// Comment compter correctement ? On utilise une fonction de comparaison...
		if (pg < pd) {
			echanger(t,pg,pd); 
			pg++ ; pd-- ; 
		}
	}
	if (comparer(t[pg],t[d]) <= 0) pg++ ;  
		echanger(t, pg, d) ;

	return pg ; 
}



