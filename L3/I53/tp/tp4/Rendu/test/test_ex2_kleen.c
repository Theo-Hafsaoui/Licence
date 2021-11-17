#include <stdio.h>
#include "../afd.h"
#include "../afn.h"
#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define reset "\e[0m"

int main(int argc, char *argv[]){
  afn X; afn Z;afd D; int c=1;
  char var1[]={97,0};
  char alpha[26]="";
  for (int i=0; i<26&& c; i++) {
    printf("test avec %s ", var1);
    printf("est la chaine %s\n", alpha);
    afn_char(&X,var1[0]);
    afn_kleene(&Z, X);
    afn_determinisation(Z, &D);
    int c1=afd_simul(alpha, D);
    afn_print(Z);
    if (c1) {
        printf(GRN "Valide\n" reset);
    }
    else {
        c=0;
        printf(RED "Invalide\n" reset);
    }
    alpha[i]=97;
    printf("########################\n");
  }
  char alpha2[]="bbbbbbbbbba";
  printf("test avec %s ", var1);
    printf("est la chaine %s\n", alpha2);
    afn_char(&X,var1[0]);
    afn_kleene(&Z, X);
    afn_determinisation(Z, &D);
    int c1=afd_simul(alpha, D);
    afn_print(Z);
    if (!c1) {
        printf(GRN "Faux donc ...Valide\n" reset);
    }
    else {
        c=0;
        printf(RED "Invalide\n" reset);
    }
    printf("########################\n");
  if (c) {
  printf(GRN "Tout les test sont correct\n" reset);
  }
  else {
    printf(RED "Erreur avec %s et la chaine %s" reset,var1, alpha);
  }
 return 0;
}
