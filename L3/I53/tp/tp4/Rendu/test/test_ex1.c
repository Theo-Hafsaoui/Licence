#include <stdio.h>
#include "../afd.h"
#include "../afn.h"
#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define reset "\e[0m"

int main(int argc, char *argv[]){
  afn U;afd D;char var[]={96,0};int c=1;
  for (int i=0; i<26 && c; i++) {
  var[0]++;
  printf("test avec %s\n", var);
  afn_char(&U,var[0]);
  afn_print(U);
	afn_determinisation(U, &D);
  if (afd_simul(var, D)&& var[0]==i+97) {
    printf(GRN "Valide\n" reset);
  } else {
    c=0;
    printf(RED "Invalide\n" reset);
  }
  printf("########################\n");
  } 
  if (c) {
  printf(GRN "Tout les test sont correct\n" reset);
  }
  else {
    printf(RED "Erreur avec %s" reset,var);
  }


 return 0;

}
