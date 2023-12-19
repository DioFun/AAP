#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morpion.h"
#include <assert.h>

T_morpion newGame() {
    T_morpion game = (T_morpion) {{}, BLANC, {}};
    return game;
}

char * toString(enum T_couleur couleur) {
    switch (couleur) {
        case NOIR:
            return "NOIR";
        case BLANC:
            return "BLANC";
        default:
            return "VIDE";
    }
}

char * toSymbole(enum T_couleur couleur) {
    switch (couleur) {
        case NOIR:
            return "N";
        case BLANC:
            return "B";
        default:
            return ".";
    }
}

void showGame(T_morpion game) {
    printf("game.nextPlayer = %s\n", toSymbole(game.nextPlayer));
    for (int i = 0; i < 9; i++) {
        if (i == 0) {
            printf("/ - - - | - - - | - - - \\ \n");
        }
        if (i == 3 || i== 6) {
            printf("| - - - | - - - | - - - |\n");
        }
        printf("| %s %s %s | %s %s %s | %s %s %s |\n", toSymbole(game.plateau[i/3*3][i%3*3]), toSymbole(game.plateau[i/3*3][i%3*3+1]), toSymbole(game.plateau[i/3*3][i%3*3+2]), toSymbole(game.plateau[i/3*3+1][i%3*3]), toSymbole(game.plateau[i/3*3+1][i%3*3+1]), toSymbole(game.plateau[i/3*3+1][i%3*3+2]), toSymbole(game.plateau[i/3*3+2][i%3*3]), toSymbole(game.plateau[i/3*3+2][i%3*3+1]), toSymbole(game.plateau[i/3*3+2][i%3*3+2]));
        if (i == 8) {
            printf("\\ - - - | - - - | - - - /\n");
        } 
    }
}

int play(T_morpion * morpion, int game, int box) {
    assert (game >= 0 && game < 9 && box >= 0 && box < 9);
    if (morpion->plateau[game][box] == VIDE) {
        morpion->plateau[game][box] = morpion->nextPlayer;
        if (morpion->nextPlayer == NOIR) {
            morpion->nextPlayer = BLANC;
        } else {
            morpion->nextPlayer = NOIR;
        }
        return 1;
    }
    return 0;
}

enum T_couleur isSubgameFinished(T_morpion * game, int i) {
    assert (i >= 0 && i < 9);
    enum T_couleur * jeu = game->plateau[i];
    enum T_couleur winner = VIDE;
    if (jeu[0] != VIDE && jeu[0] == jeu[1] && jeu[1] == jeu[2]) {
        winner = jeu[0];
    }
    if (jeu[3] != VIDE && jeu[3] == jeu[4] && jeu[4] == jeu[5]) {
        winner = jeu[3];
    }
    if (jeu[6] != VIDE && jeu[6] == jeu[7] && jeu[7] == jeu[8]) {
        winner = jeu[6];
    }
    if (jeu[0] != VIDE && jeu[0] == jeu[3] && jeu[3] == jeu[6]) {
        winner = jeu[0];
    }
    if (jeu[1] != VIDE && jeu[1] == jeu[4] && jeu[4] == jeu[7]) {
        winner = jeu[1];
    }
    if (jeu[2] != VIDE && jeu[2] == jeu[5] && jeu[5] == jeu[8]) {
        winner = jeu[2];
    }
    if (jeu[0] != VIDE && jeu[0] == jeu[4] && jeu[4] == jeu[8]) {
        winner = jeu[0];
    }
    if (jeu[2] != VIDE && jeu[2] == jeu[4] && jeu[4] == jeu[6]) {
        winner = jeu[2];
    }
    if (winner != VIDE) {
        blur(game, i, winner);
        game->superMorpion[i] = winner;
        return winner;
    }
    return VIDE;
}

void blur(T_morpion * game, int i, enum T_couleur couleur) {
    assert (i >= 0 && i < 9);
    enum T_couleur * jeu = game->plateau[i];
    for (int j = 0; j < 9; j++) {
        jeu[j] = couleur;
    }
}

enum T_couleur isMainGameFinished(T_morpion game) {
    enum T_couleur * jeu = game.superMorpion;
    if (jeu[0] != VIDE && jeu[0] == jeu[1] && jeu[1] == jeu[2]) {
        return jeu[0];
    }
    if (jeu[3] != VIDE && jeu[3] == jeu[4] && jeu[4] == jeu[5]) {
        return jeu[3];
    }
    if (jeu[6] != VIDE && jeu[6] == jeu[7] && jeu[7] == jeu[8]) {
        return jeu[6];
    }
    if (jeu[0] != VIDE && jeu[0] == jeu[3] && jeu[3] == jeu[6]) {
        return jeu[0];
    }
    if (jeu[1] != VIDE && jeu[1] == jeu[4] && jeu[4] == jeu[7]) {
        return jeu[1];
    }
    if (jeu[2] != VIDE && jeu[2] == jeu[5] && jeu[5] == jeu[8]) {
        return jeu[2];
    }
    if (jeu[0] != VIDE && jeu[0] == jeu[4] && jeu[4] == jeu[8]) {
        return jeu[0];
    }
    if (jeu[2] != VIDE && jeu[2] == jeu[4] && jeu[4] == jeu[6]) {
        return jeu[2];
    }
    return VIDE;
}
