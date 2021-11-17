%{
  /*Prologue*/
  #include <stdio.h>
  #include <string.h>
  int longmax = 0;
  int x_pos=0;
  int y_pos=0;
  int x_max;int y_max;
  int cpt_int=0;
  char motlepluslong[256];
%}
%option nounput
%option noinput
/*Définitions*/
BLANC    [ \t]
ENTIER   [0-9]
LIGNE    [\n]
LETTRE   [a-zA-Z]
MOT      {LETTRE}+
NB      {ENTIER}+

%%

{LETTRE} {x_pos++;}
{MOT} { x_pos++;
  if (yyleng > longmax){
    longmax = yyleng;
    x_max=x_pos+1;
    y_max=y_pos;
    strcpy(motlepluslong, yytext);
    printf("\n%s at %d:%d",yytext,y_pos,x_pos);
  }
}
{BLANC} {x_pos++;}
{LIGNE} {x_pos=0;y_pos++;}
{NB} {cpt_int++;}
.

%%
int main(int argc, char *argv[]){
  if(argc>2){
    yyin = fopen(argv[1], "r");
  }
  yylex();
  printf("\nMot le plus long: %s, de longueur: %d at %d:%d\n", motlepluslong, longmax,y_max,x_max);
  printf("Il y a %d, nombre",cpt_int);
  return 0;
} 
