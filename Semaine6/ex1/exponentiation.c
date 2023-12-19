#include "test_utils.h"
#include "../include/traces.h"
#include <stdio.h>

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_data Puissance(T_data d , int n) {
	T_elt Result;
	T_elt x = d.elt; 

	if (n == 0) return genData(1, NULL);
	if (n==1) return genData(x, NULL);
		
	for (Result = x; n > 1; n--) {
		stats.nbOperations++;
		Result *= x;
	}
	return genData(Result, NULL);
}

T_data Puissance_rec(T_data d , int n) {
	T_elt x = d.elt;
	T_data r;

	// TOUCH_HERE("Ben là, c'est à vous ! \n");
	// ordre de récurrence ?  
	// cas de base :
	if (n==0) return genData(1, NULL);
	if (n==1) return genData(x, NULL);
	// cas général : 
	r = Puissance_rec(d, n-1);
	stats.nbOperations++;
	return genData(x*(r.elt), NULL);
}