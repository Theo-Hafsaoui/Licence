/* -*- mode: flex-*- */
/*
 *        ,     \    /      ,        
 *       / \    )\__/(     / \       
 *      /   \  (_\  /_)   /   \      
 * ____/_____\__\@  @/___/_____\____ 
 *|             |\../|              |
 *|              \VV/               |
 *|              LEXER              |
 *|_________________________________|
 * |    /\ /      \\       \ /\    | 
 * |  /   V        ))       V   \  | 
 * |/     `       //        '     \| 
 * `              V                '
*/
%{
#include <string.h>
#include "parser.h"
%}

%option nounput
%option noinput
NB			-?[1-9][0-9]*|0
OP			[-+*/%<>=]
ID			[A-Za-z_][A-Za-z0-9_]*
COMMENTAIRE #.*\n
PAREN		[()]
BLANC		[\t ]+

%%

{COMMENTAIRE}
{BLANC}
\n+			{ return NL; }
{OP}			{ return yytext[0]; }
{PAREN}		{ return yytext[0]; }
">="			{ return SE; }
"<="			{ return IE; }
"!="			{ return NE; }
"++"			{ return INCR; }
"--"			{ return DECR; }
"<-"			{ return AFFECT; }

ALGO			{ return ALGO; }
ENTREE			{ return ENTREE; }
DEBUT			{ return DEBUT; }
VAR			{ return VAR; }
FIN\n?			{ return FIN; }

OU				{ return OU; }
ET				{ return ET; }
NON			{ return NON; }

SI				{ return SI; }
ALORS			{ return ALORS; }
SINON			{ return SINON; }
FSI			{ return FSI; }

TQ				{ return TQ; }
FAIRE			{ return FAIRE; }
FTQ			{ return FTQ; }

AFFICHER		{ return AFFICHER; }

{NB}			{ yylval.nb = atoi(yytext); return NB; }
{ID}			{ strcpy(yylval.id, yytext); return ID; }
.				{ fprintf(stderr, "[err lexer] caractere inconnu %c\n",yytext[0]); return 1;}

%%
