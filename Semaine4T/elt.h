#define OPENING 0
#define CLOSING 1
#define FONCTION 0
#define TABLEAU 1
#define ARGUMENT 2
#define EXPRESSION 3
#define JSON 4

typedef struct {
	int size;
	char *open;
	char *close;
	unsigned char kind; // OPRENING or CLOSING
	unsigned char type;
} T_elt;

char * typeToString(int type);
int isDelimiter(char c[]);
T_elt toElt(const char str[]);
char * toString(T_elt elt);
int getSize(T_elt elt);
int getKind(T_elt elt);
int getType(T_elt elt);
void showBloc(T_elt elt, int indent);