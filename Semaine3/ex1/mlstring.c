#include <stdlib.h>
#include <string.h>
#include "mlstring.h"
#include "../include/traces.h"
#include "../include/check.h"

int mlstringLen(const T_mlstring mls) {
    int i = 0;
    while (i<MAXLEN && mls[i]!='\0') {
        i++;
    }
    return i;
}

void mlstringCat(T_mlstring mls_dest, const T_mlstring mls_src) {
    int l = mlstringLen(mls_dest);
    int n = mlstringLen(mls_src);
    for(int i=0; i<n && i<MAXLEN-l-1; i++) {
        mls_dest[l+i] = mls_src[i];
    }
    mls_dest[n+l] = '\0';
}

char * toMlstring(const char * s) {
    char * ret = (char *) malloc(MAXLEN*sizeof(char));
    CHECK_IF(ret, NULL, "Impossible allocation in toMlstring");
    ret[0]='\0';
    mlstringCat(ret, s);
    return ret;
}

char * mlstringDup(const T_mlstring mls) {
    char * ret = (char *) malloc(MAXLEN*sizeof(char));
    CHECK_IF(ret, NULL, "Impossible allocation in mlstringDup");
    int l = mlstringLen(mls);
    for (int i=0; i<l; i++){
        ret[i]=mls[i];
    }
    ret[l] = '\0';
    return ret;
}
