#include "afn.h"

#define IS_ALPHABET(X) ((X >= 'A' && X <= 'Z') || (X >= 'a' && X <= 'z'))
#define IS_NUMBER(X) (X >= '0' && X <= '9')

enum type { CHAR, NB, BINOP, UNOP, OUV, FER };

typedef struct {
	enum type t;
	char c;
} lex_unit;

lex_unit* scanner(char *s, int len);
afn parser(lex_unit * s, int len);

afn regex();
afn concat();
afn kleene();
afn repeat();
afn set();
afn base();
