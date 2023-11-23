#include <stdio.h> // sprintf
#include <string.h> // strdup
#include <stdlib.h>

//#define CLEAR2CONTINUE
#include "include/traces.h" 

#include "elt.h"

char * typeToString(int type) {
	switch (type)
	{
	case FONCTION:
		return "fonction";
	case TABLEAU:
		return "tableau";
	case ARGUMENT:
		return "argument";
	case EXPRESSION:
		return "expression";
	case JSON:
		return "json";
	}
	return "unknown";
}

int isDelimiter(char c[]) {
	return (c[0] == '(' || c[0] == ')' || c[0] == '[' || c[0] == ']' || c[0] == '<' || c[0] == '>' || (c[0] == '}' && strlen(c)>1 && c[1] == ')'));
}

T_elt toElt(const char str[]){
	T_elt elt;
	if (str[0] == '(' || str[0] == '[' || str[0] == '<') {
		elt.kind = OPENING;
	} else {
		elt.kind = CLOSING;
	}
	
	if ((str[0] == '(' && strlen(str) == 2 && str[1]=='(') || (str[0] == ')' && strlen(str) == 2 && str[1]==')')) {
		elt.type = EXPRESSION;
		elt.size = 2;
		elt.open = "((";
		elt.close = "))";
	} else if ((str[0] == '(' && strlen(str) == 2 && str[1]=='{') || (str[0] == '}' && strlen(str) == 2 && str[1]==')')) {
		elt.type = JSON;
		elt.size = 2;
		elt.open = "({";
		elt.close = "})";
	} else if (str[0] == '(' || str[0] == ')') {
		elt.type = FONCTION;
		elt.size = 1;
		elt.open = "(";
		elt.close = ")";
	} else if (str[0] == '[' || str[0] == ']') {
		elt.type = TABLEAU;
		elt.size = 1;
		elt.open = "[";
		elt.close = "]";
	} else if (str[0] == '<' || str[0] == '>') {
		elt.type = ARGUMENT;
		elt.size = 1;
		elt.open = "<";
		elt.close = ">";
	}
	return elt;
}

char * toString(T_elt elt) {
	char *str = malloc(elt.size+1);
	sprintf(str, "%s", elt.kind == OPENING ? elt.open : elt.close);
	return str;
}

int getSize(T_elt elt) {
	return elt.size;
}

int getKind(T_elt elt) {
	return elt.kind;
}

int getType(T_elt elt) {
	return elt.type;
}

void showBloc(T_elt elt, int indent){
	int i;
	for (i=0; i<indent; i++) {
		printf("    ");
	}
	printf("%c%s\n", elt.kind == OPENING ? '+' : '-', typeToString(elt.type));
}