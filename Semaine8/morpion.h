
#ifndef MORPION_H
#define MORPION_H

enum T_couleur {VIDE, NOIR, BLANC};

typedef struct {
    enum T_couleur plateau[9][9];
    enum T_couleur nextPlayer;
    enum T_couleur superMorpion[9];
} T_morpion;

char * toString(enum T_couleur couleur);
char * toSymbole(enum T_couleur couleur);
T_morpion newGame();
void showGame(T_morpion game);
int play(T_morpion *morpion, int game, int box);
enum T_couleur isSubgameFinished(T_morpion * game, int i);
enum T_couleur isMainGameFinished(T_morpion game);
void blur(T_morpion * game, int i, enum T_couleur couleur);

#endif