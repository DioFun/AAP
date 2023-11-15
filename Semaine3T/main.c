#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"


int main() {
    T_sstring s = {"test", 4};
    printf("longueur : %d\n", sstringLen(s));
    T_sstring s1 = {"hello", 5};
    T_sstring s2 = {" world", 6};
    sstringCat(&s1,&s2);
    printf("concat s1 et s2 : %s de taille %d(%d)\n", s1.s, sstringLen(s1), s1.size);
    sstringCpy(&s1, &s2);
    printf("Cpy de s2 in s1 : %s de taille %d(%d)\n", s1.s, sstringLen(s1), s1.size);
    T_sstring s3 = {"hello", 5};
    printf("Cmp de s3 & s2 %d\n", sstringCmp(&s3, &s2));
    printf("Cmp de s3 & s3 %d\n", sstringCmp(&s3, &s3));
    printf("Cmp de s2 & s3 %d\n", sstringCmp(&s2, &s3));
    T_sstring s4 = toSstring("ceci est un test avec plus de 10 caractères.");
    printf("toSstring de s4 : %s de longueur %d(%d) \n", s4.s, sstringLen(s4), s4.size);
    T_sstring s5 = toSstring("test.");
    printf("toSstring de s5 : %s de longueur %d(%d) \n", s5.s, sstringLen(s5), s5.size);
    T_sstring s6 = sstringDup(s3);
    sstringCpy(&s3,&s2);
    printf("sstringDup de s3 : %s de longueur %d(%d) \n", s6.s, sstringLen(s6), s6.size);
    char *s10 = toString(s6);
    printf("toString de s6 : %s\n", s10);
    return 0;
}