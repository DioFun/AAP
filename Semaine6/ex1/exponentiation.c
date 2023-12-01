#include "test_utils.h"
#include "../include/traces.h"
#include <stdio.h>

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_data Puissance(T_data d , int n) {
	T_elt Result;
	T_elt x = d.elt; 

	if (n == 0) {
		stats.nbComparisons++;
		return genData(1, NULL);
	}
	for (Result = x; n > 1; n--) {
		stats.nbComparisons++;
		stats.nbOperations++;
		Result *= x;
	}
	stats.nbComparisons++;
	return genData(Result, NULL);
}

T_data Puissance_rec(T_data d , int n) {
	T_elt x = d.elt;

	TOUCH_HERE("Ben là, c'est à vous ! \n");

	// ordre de récurrence ?  
	// cas de base :
	// if (n==0) return genData();
	// cas général : 

	return genData(0, NULL);
}


