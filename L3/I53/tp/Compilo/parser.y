// -*- mode: bison -*-
%{
  #include <stdio.h>
  #include <ctype.h>
  #include <unistd.h>
  #include "asa.h"
  #include "ts.h"
  extern int yylex();
%}

%union {
	int nb;
	struct asa * noeud;
	char id[256];
};

%define parse.error verbose

%token	ALGO ENTREE DEBUT VAR FIN NON SI ALORS SINON FSI TQ FAIRE FTQ AFFICHER
%token	SUPEG INFEG NONEG
%token	NL//Nouvelle ligne
%token	<nb> NB
%token	<id> ID

%type	<noeud>         CODE
%type	<noeud>         ENTREES ENTREE LECTURES LECTURE
%type	<noeud>         INSTRUCTIONS INSTRUCTION
%type	<noeud>         VARIABLE AFFECTATION AFFICHAGE
%type	<noeud>         DECLARATION EXP

%right AFFECT
%left OU
%left ET
%left NE '='
%left '<' IE '>' SE
%left '+' '-'
%left '*' '/' '%'
%right NON INCR DECR

%start PROG

//Gramaire
%%

PROG: ALGO ID NL CODE                                   { fichier_sortie($2); codegen($4); nettoyage($4); };
CODE: ENTREES NL DEBUT NL INSTRUCTIONS NL FIN           { $$ = creer_noeudCode($1, $5); };
DECLARATION: ID                                         { $$ = creer_feuilleDeclaration($1); };

ENTREES: ENTREE LECTURES                        { $$ = $2; }
       | ENTREE                                 { $$ = NULL; }

LECTURES: LECTURE LECTURES                      { $$ = creer_noeudInstruction($1, $2); }
        | LECTURE                               { $$ = $1; }
;

LECTURE: DECLARATION                            { $$ = creer_noeudEntree($1); };

INSTRUCTIONS: INSTRUCTIONS NL INSTRUCTION       { $$ = creer_noeudInstruction($1, $3); }
            | INSTRUCTION                       { $$ = $1; }
;

INSTRUCTION: VARIABLE                           { $$ = $1; }
           | AFFECTATION                        { $$ = $1; }
           | AFFICHAGE                          { $$ = $1; }
           | TQ EXP FAIRE NL INSTRUCTIONS NL FTQ {$$= creer_noeudTQ($2,$5);}
           | SI EXP ALORS NL INSTRUCTIONS NL FSI {$$= creer_noeudSI($2,$5);}
           | SI EXP ALORS NL INSTRUCTIONS NL SINON NL INSTRUCTIONS NL FSI {$$= creer_noeudSIN($2,$5,$9);}
;

VARIABLE:       VAR DECLARATION                                                 { $$ = $2; };
AFFECTATION:    ID AFFECT EXP                                                   { $$ = creer_noeudAffectation($1, $3); };
AFFICHAGE:      AFFICHER EXP                                                    { $$ = creer_noeudAffichage($2); };


EXP : NB                            { $$ = creer_feuilleNb($1); }
    | ID                            { $$ = creer_feuilleId($1); }
    | EXP '+' EXP                   { $$ = creer_noeudOp('+', $3, $1); }
    | EXP '-' EXP                   { $$ = creer_noeudOp('-', $3, $1); }
    | EXP '*' EXP                   { $$ = creer_noeudOp('*', $3, $1); }
    | EXP '/' EXP                   { $$ = creer_noeudOp('/', $3, $1); }
    | EXP '%' EXP                   { $$ = creer_noeudOp('%', $3, $1); }
    | EXP OU EXP                    { $$ = creer_noeudOp('|', $3, $1); }
    | EXP ET EXP                    { $$ = creer_noeudOp('&', $3, $1); }
    | EXP '=' EXP                   { $$ = creer_noeudOp('=', $3, $1); }
    | EXP '<' EXP                   { $$ = creer_noeudOp('<', $3, $1); }
    | EXP '>' EXP                   { $$ = creer_noeudOp('>', $3, $1); }
    | EXP IE EXP                    { $$ = creer_noeudOp('{', $3, $1); }
    | EXP SE EXP                    { $$ = creer_noeudOp('}', $3, $1); }
    | EXP NE EXP                    { $$ = creer_noeudOp('~', $3, $1); }
    | '-' EXP                       { $$ = creer_noeudUnop('-', $2); }
    | NON EXP                       { $$ = creer_noeudUnop('!', $2); }
    | INCR EXP                      { $$ = creer_noeudUnop('i', $2); }
    | DECR EXP                      { $$ = creer_noeudUnop('d', $2); }
    | '(' EXP ')'                   { $$ = $2; }
;

%%

int main( int argc, char * argv[] ) {
	extern FILE *yyin;
	if (argc == 1){
		fprintf(stderr, "aucun fichier fournie\n");
		return 1;
	}
	yyin = fopen(argv[1],"r");
	switch(yyparse()){
		case 1:
			yyerror("echec du parsing");
		case 2:
			yyerror("echec du parsing: épuisement de la mémoire");
		default:
			break;
	}
	return 0;
}
