#include "test_utils.h"
#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations++;
// stats.nbComparisons++;

int Comparaison(T_elt e1, T_elt e2) {
	return e1-e2;
}


T_data RechercheDicho (T_data d, int n) {
	int Debut = 0, Fin = n - 1, Milieu;
	int Test;
	T_elt * A = d.pElt; // Le tableau à trier 
	T_elt e = d.elt; // L'élément recherché

	while (Debut <= Fin) {
		stats.nbComparisons++;
		Milieu = (Debut + Fin) / 2;
		Test = Comparaison(e , A[Milieu]);
		stats.nbComparisons++;
		if (Test == 0)
			return genData(0,&(A[Milieu])); // On renvoie l'adresse de l'elt trouvé 
		stats.nbComparisons++;
		if (Test < 0)
			Fin = Milieu - 1;
		else
			Debut = Milieu + 1;
	}
	stats.nbComparisons++;
	return genData(0,NULL);	/* e n’est pas dans T : on renvoie l'adresse NULL */
}

T_data RechercheDicho_rec (T_data d, int n) {
	// données : 
	// pElt : début du tableau, 
	// elt : elt cherché 
	// n : taille du tableau 
	int debut = 0, fin = n-1, milieu;
	int test;
	T_elt * A = d.pElt; // Le tableau à trier
	T_elt e = d.elt; // L'élément recherché

	// ordre de récurrence ?  
	// cas de base :
	stats.nbComparisons++;
	if (debut > fin) return genData(0,NULL); // e n’est pas dans T : on renvoie l'adresse NULL
	// cas général :
	milieu = (debut + fin) / 2;
	test = Comparaison(e , A[milieu]);
	stats.nbComparisons++;
	if (test == 0) return genData(0,&(A[milieu])); // On renvoie l'adresse de l'elt trouvé
	stats.nbComparisons++;
	if (test < 0) return RechercheDicho_rec(genData(d.elt,A), milieu); // cas récursif 1
	else return RechercheDicho_rec(genData(d.elt,&(A[milieu+1])), n-milieu-1); // cas récursif 2

	return genData(0,NULL);
}








