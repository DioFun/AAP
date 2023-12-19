#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"


int main() {
    T_morpion game = newGame();
    showGame(game);
    while (1) {
        printf("joueur suivant : %s\n", toString(game.nextPlayer));
        int gameChoice, box;
        printf("jeu ? ");
        scanf("%d", &gameChoice);
        printf("case ? ");
        scanf("%d", &box);
        if (gameChoice < 0 || gameChoice > 8 || box < 0 || box > 8) {
            printf("jeu ou case invalide\n");
            continue;
        }
        if (play(&game, gameChoice, box) ==0 ) {
            printf("case déjà occupée\n");
            continue;
        }
        enum T_couleur win = VIDE;
        printf("win = %d\n", win);
        printf("win = %d\n", isSubgameFinished(&game, gameChoice));
        if ((win = isSubgameFinished(&game, gameChoice)) != VIDE) {
            printf("sous-jeu %d terminé; Le vainqueur est le joueur %s !\n", box, toString(win));
            if ((win = isMainGameFinished(game)) != VIDE) {
                printf("partie terminée. Le vainqueur est le joueur %s\n", toString(win));
                break;
            }
        }
        showGame(game);
    }
}