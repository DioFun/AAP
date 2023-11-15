#define MAXLEN 10

typedef struct {
    char s[MAXLEN];
    int size; 
} T_sstring;

int sstringLen(T_sstring ss);
void sstringCat (T_sstring * ss_dest, const T_sstring * ss_src);
void sstringCpy (T_sstring * ss_dest, const T_sstring * ss_src);
int sstringCmp (const T_sstring * ss1, const T_sstring * ss2);
T_sstring  toSstring(const char * s);
T_sstring  sstringDup(T_sstring ss);
char * toString(T_sstring ss);