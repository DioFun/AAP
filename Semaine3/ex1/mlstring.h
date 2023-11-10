#define MAXLEN 10
typedef char T_mlstring[MAXLEN];

int mlstringLen(const T_mlstring mls);
void mlstringCat (T_mlstring mls_dest, const T_mlstring mls_src);
char *  toMlstring(const char * s);
char *  mlstringDup(const T_mlstring);