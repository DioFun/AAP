#include <stdio.h>
#include "test_utils.h"
#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_data hanoi(T_data d, int n) {
	// data : 
	// n : nombre de disques à déplacer 
	// d.pElt[0] : num. tige départ 
	// d.pElt[1] : num. tige arrivée
	// d.pElt[2] : num. tige intermediaire
	// On utilisera un tableau trié 
	// Contiendra 0,1,2 : passer de la tige 0 à la tige 1

	// si d.elt vaut 1, il faut afficher des messages
	// si d.elt = 0 : ne rien afficher 

	// Attention : on ne peut réutiliser le même tableau 
	// pour passer les paramètres QUE si on sauvegarde les paramètres
	// reçus dans des variables locales à chaque fonction 
	// sitôt qu'on les reçoit 

	T_elt origine = d.pElt[0]; 
	T_elt destination = d.pElt[1]; 
	T_elt intermediaire = d.pElt[2]; 
	
	TOUCH_HERE("Ben là, c'est à vous ! \n");	

	// ordre de récurrence ?  
	// cas de base :
	// cas général : 

	return genData(0,NULL);
}
