#include "compregex.h"
#include "afd.h"
#include "afn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static lex_unit *reg;
static int pos;

// transforme un regex en une chaîne d'unités lexicales
lex_unit *scanner(char *s, int len)
{
	lex_unit *lchain = calloc(len, sizeof(lex_unit));
	lex_unit lex;
	for (int i = 0; i < len; ++i) {
		if IS_ALPHABET
			(s[i])
				lex.t = CHAR;
		else if IS_NUMBER
			(s[i])
				lex.t = NB;
		else if (s[i] == '.' || s[i] == '+')
			lex.t = BINOP;
		else if (s[i] == '*')
			lex.t = UNOP;
		else if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			lex.t = OUV;
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			lex.t = FER;
		else {
			fprintf(stderr, "%c: caractère inconnu\n", s[i]);
			exit(EXIT_FAILURE);
		}
		lex.c = s[i];
		lchain[i] = lex;
	}
	return lchain;
}

/* transforme une chaîne d'unités lexicales en AFN */
afn parser(lex_unit * s, int len)
{
	reg = s;
	pos = len - 1;
	return regex();
}

afn regex()
{
	afn C, R;
	C = concat();
	if (reg[pos].t == BINOP && reg[pos].c == '+') {
		pos--;
		afn_union(&R, regex(), C);
	} else
		R = C;
	return R;
}

afn concat()
{
	afn K, R;
	K = kleene();
	if (reg[pos].t == BINOP && reg[pos].c == '.') {
		pos--;
		afn_concat(&R, concat(), K);
	} else
		R = K;
	return R;
}

afn kleene()
{
	afn A;
	if (reg[pos].t == UNOP && reg[pos].c == '*') {
		pos--;
		afn_kleene(&A, repeat());
	} else {
		A = repeat();
	}
	return A;
}

afn repeat()
{
	afn A, N;
	int n;
	if (reg[pos].t == FER && reg[pos].c == '}') {
		pos--;
		afn_init(&A, 1, ALPHABET, INT_ETAT(0), INT_ETAT(0));
		if (reg[pos].t == NB) {
			n = reg[pos].c - '0';
			pos--;
		} else {
			fprintf(stderr, "%d\t%c: nombre attendu\n", pos, reg[pos].c);
			exit(EXIT_FAILURE);
		}
		if (reg[pos].t != OUV || reg[pos].c != '{') {
			fprintf(stderr, "%d\t%c: accolade ouvrante attendue\n", pos,
					reg[pos].c);
			exit(EXIT_FAILURE);
		}
		pos--;
		N = set();
		for (int i = 0; i < n; ++i)
			afn_concat(&A, A, N);
	} else {
		A = set();
	}
	return A;
}

afn set()
{
	afn A, N;
	if (reg[pos].t == FER && reg[pos].c == ']') {
		pos--;
		if (reg[pos].t != CHAR) {
			fprintf(stderr, "%d\t%c: caractère attendu\n", pos,
					reg[pos].c);
			exit(EXIT_FAILURE);
		}
		afn_char(&A, reg[pos].c);
		pos--;
		while (reg[pos].t == CHAR) {
			N = base();
			afn_union(&A, A, N);
		}
		if (reg[pos].t != OUV || reg[pos].c != '[') {
			fprintf(stderr, "%d\t%c: crochet ouvrant attendue\n", pos,
					reg[pos].c);
			exit(EXIT_FAILURE);
		}
		pos--;
	} else {
		A = base();
	}
	return A;
}

afn base()
{
	afn A;
	if (reg[pos].t == FER && reg[pos].c == ')') {
		pos--;
		A = regex();
		if (reg[pos].t == OUV && reg[pos].c == '(') {
			pos--;
			return A;
		} else {
			fprintf(stderr, "%d\t%c: parenthèse ouvrante attendue\n", pos,
					reg[pos].c);
			exit(EXIT_FAILURE);
		}
	} else if (reg[pos].t == CHAR)
		afn_char(&A, reg[pos].c);
	else {
		fprintf(stderr,
				"%d\t%c: non-légal (doit être un caractère ou une expression entre parenthèses)\n",
				pos, reg[pos].c);
		exit(EXIT_FAILURE);
	}
	pos--;
	return A;
}
