#ifndef _ARTICLE_H_
#define _ARTICLE_H_
typedef struct {
	int id;
    char *name;
    int cat;
} T_elt;

T_elt genElt(char *name, int cat);
char *toString(T_elt elt);
int getCat(T_elt elt);
int getId(T_elt elt);
#endif