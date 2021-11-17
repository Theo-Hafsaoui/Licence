#include "afn.h"
#ifdef PARSER_H
#define PARSER_H


//
//Exp-> term rest_e
//rest_e -> + term rest_e
//          |&
//term-> facteur rest_t
//rest_t -> .facteur rest_t
//          |&
//facteur -> ALPHA
//            |(Expression)
//            |Expression*

Prend en paramètre une liste d'unités lexicales
renvoie une nouvelle liste d'unités lexicales postfixé
char* rpn(char**);
char* expr(char**);
int term(char**);
int factor(char**);
int rest_e(char**);
int rest_t(char**);



#endif
