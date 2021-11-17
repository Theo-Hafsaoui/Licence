%{
  /*Prologue*/
  #include <stdio.h>
  #include <string.h>
  int cpt=0;
  typedef struct list_symb {
    char *symb;
    int count;
    struct list_symb * suiv;
  } list_symb;
  list_symb head=0;
%}
BLANC    [ \t]
ENTIER   [0-9]
LIGNE    [\n]
LETTRE   [a-zA-Z]
MOT      {LETTRE}+
NB      {ENTIER}+
%%
{MOT} {
  inserer(yytext,&head);
      }
{LETTRE}
{LIGNE}
{NB}
.
%%
int inserer(char *nom , list_symb *ptr){
  if(head==0){
          
    return 1;
  }
}
int main(int argc, char *argv[]){
  if(argc>1){
    yyin = fopen(argv[1], "r");
  }
  yylex();
  printf("\nMot le plus long: %s, de longueur: %d at %d:%d\n", motlepluslong, longmax,y_max,x_max);
  printf("Il y a %d, nombre",cpt_int);
  return 0;
}
