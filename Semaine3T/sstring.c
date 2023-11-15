#include <stdlib.h>
#include <string.h>
#include "sstring.h"

int sstringLen(T_sstring ss) {
    return ss.size;
}

void sstringCat (T_sstring * ss_dest, const T_sstring * ss_src) {
    int n = sstringLen(*ss_dest);
    int l = sstringLen(*ss_src);
    int i;
    for (i = 0; i<l && i<MAXLEN-n-1; i++) {
        (*ss_dest).s[n+i] = (*ss_src).s[i];  
        (*ss_dest).size++;
    } 
    (*ss_dest).s[n+i] = '\0';
}

void sstringCpy (T_sstring * ss_dest, const T_sstring * ss_src) {
    int l = sstringLen(*ss_src);
    for (int i = 0; i<l; i++) {
        (*ss_dest).s[i] = (*ss_src).s[i];
    }
    (*ss_dest).s[l] = '\0';
    (*ss_dest).size = l;
}

int sstringCmp (const T_sstring * ss1, const T_sstring * ss2) {
    int i = 0;
    while (((*ss1).s[i] != '\0') && ((*ss1).s[i] == (*ss2).s[i])) {
        i++;
    }
    return ((*ss1).s[i] == (*ss2).s[i]) ? 0 : (*ss1).s[i] - (*ss2).s[i];
}

T_sstring  toSstring(const char * s) {
    T_sstring ret;
    int i;
    for (i = 0; i < MAXLEN - 1 && s[i] != '\0'; ++i) {
        ret.s[i] = s[i];
    }
    ret.s[i] = '\0';
    ret.size = i;
    return ret;
}


T_sstring  sstringDup(T_sstring ss) {
    T_sstring ret;
    sstringCpy(&ret, &ss);
    return ret;
}

char * toString(T_sstring ss) {
    char * ret = (char *) malloc(MAXLEN*sizeof(char));
    int i;
    for (i = 0; ss.s[i] != '\0'; i++) {
        ret[i] = ss.s[i];
    }
    ret[i] = '\0';
    return ret;
}