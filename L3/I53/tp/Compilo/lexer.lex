%{
#include <string.h>
#include "parser.h" 
%}
  
%option nounput
%option noinput

ALGO     ALGO
DEBUT    DEBUT
FIN      FIN
SI       SI
FSI      FSI
SINON    SINON
VAR      VAR
TQ       TQ
FTQ      FTQ
PLUS     +
EQUAL    =
MINUS    -
MODULO   %
END      [\n]
CHIFFRE  [-]?[1-9]+[0-9]*|0
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
{ID} {yyval.id= ID, return ID;}
.         { fprintf(stderr, "[err lexer] caractere inconnu %c\n",yytext[0]); return 1;}
%%
