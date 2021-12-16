%{
  #include <stdio.h>
  #include <ctype.h>
  #include <unistd.h>
  #include "asa.h"
  #include "ts.h"

  extern int yylex();
  
%}
//Token check
%union{
  int nb;
  int ID;
  struct asa * noeud;
  char id[16];
  //Les id ne peuvent pas faire plus de 16 charactere
 };

%define parse.error verbose
%token <chiffre> NB
%token <ID> ID
%token <SI> SI
%token <FSI> FSI
%token <SINON> SINON
%token <TQ> TQ
%token <FTQ> FTQ
%token <EQUAL> EQUAL
%token <PLUS> PLUS
%token <MINUS> MINUS
%token <MODULO> MODULO
%token <AFECTATION> AFECTATION
%token <END> END
%type <noeud> EXP 
%left '+'
%start PROG
%%
//Gramaire

PROG : EXP                 { codegen($1); }
;

INST: END
|VAR AFECTATION EXP
|EXP

EXP : NB                   { $$ = creer_feuilleNb(yylval.nb); }
| EXP '+' EXP              { $$ = creer_noeudOp('+', $1, $3); }
| EXP '-' EXP              { $$ = creer_noeudOp('-', $1, $3); }
| EXP '*' EXP              { $$ = creer_noeudOp('*', $1, $3); }
| EXP '/' EXP              { $$ = creer_noeudOp('/', $1, $3); }
| EXP '%' EXP              { $$ = creer_noeudOp('%', $1, $3); }
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

