%{
#include <string.h>
#include "parser.h" 
%}
  
%option nounput
%option noinput

ALGO     ALGO
SI       SI
FSI      FSI
SINON    SINON
TQ       TQ
FTQ      FTQ
PLUS     +
EQUAL    =
MINUS    -
MODULO   %
END      [\n]
CHIFFRE  [-]?[1-9]+[0-9]*
LETTRE   [a-zA-Z]
ID      {LETTRE}+
  
%%

{CHIFFRE} { yylval.nb = atoi(yytext); return NB;}
{SI} {return SI;}
{FSI} {return FSI;}
{SINON} {return SINON;}
{TQ} {return TQ;}
{EQUAL} {return EQUAL;}
{FTQ} {return FTQ;}
{PLUS} {return PLUS;}
{MINUS} {return MINUS;}
{MODULO} {return MODULO;}
{END} {return END;}
{CHIFFRE} {return CHIFFRE;}
{ID} {return ID;}
.         { fprintf(stderr, "[err lexer] caractere inconnu %c\n",yytext[0]); return 1;}
%%
