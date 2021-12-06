%{
  #include <stdio.h>
  #include <ctype.h>
  #include <unistd.h>
  #include "asa.h"
  #include "ts.h"

  extern int yylex();
  
%}

%union{
  int nb;
  struct asa * noeud;
 };

%define parse.error verbose
%token <nb> NB
%type <noeud> EXP 
%left '+'
%start PROG
%%

PROG : EXP                 { codegen($1); }
;

EXP : NB                   { $$ = creer_feuilleNb(yylval.nb); }
| EXP '+' EXP              { $$ = creer_noeudOp('+', $1, $3); }
;

%%

int main( int argc, char * argv[] ) {

  extern FILE *yyin;
  if (argc == 1){
    fprintf(stderr, "aucun fichier fournie\n");
    return 1;
  }
  yyin = fopen(argv[1],"r");
  yyparse();
  return 0;
}

