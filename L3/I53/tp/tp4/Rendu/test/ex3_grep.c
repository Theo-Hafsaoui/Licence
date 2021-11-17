#include <stdio.h>
#include "../afd.h"
#include "../afn.h"
#include "../compregex.h"
#include <stdlib.h>
#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define reset "\e[0m"


int main(int argc, char *argv[]){
  afn X; afn Y; afn Z;
  afn N;
  afd D;
  char *regex ;
  char *s ;
  int c=1;int c1;
  int c_l[]={1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,1};
  char test1[]="a"; char test2[]="bb"; char test3[]="cab";
  char* l_test[]={test1,test2,test3};
  char automa1[]="a"; char automa2[]="a+a"; char automa3[]="(a+a)";
  char automa4[]="(a+b)";char automa5[]="(c+a)";char automa6[]="(c+a).(c+a)";
  char automa7[]="(c+a).(c+a).b*";
  char* l_auto[]={automa1,automa2,automa3,automa4,automa5,automa6,automa7};
  int cpt=0;
  for (int i=0; i<7&&c; i++) {
    for (int j=0; j<3&&c; j++) {
      regex = l_auto[i];
      s = l_test[j];
      int n = strlen(regex);
      lex_unit *l = scanner(regex, n);
      N = parser(l, n);
      afn_determinisation(N, &D);
      c1=afd_simul(s, D);
      printf("Test avec le regex:%s et la chaine[%s]\n", regex, s);
      afn_print(N);
      if (c1==c_l[cpt]) {
        printf(GRN "Valide\n" reset);
      } else {
        c=0;
        printf(RED "Invalide\n" reset);
      }
      cpt++;
      printf("########################\n");
    }
 }
  if (c) {
  printf(GRN "Tout les test sont correct\n" reset);
  }
  else {
    printf(RED "Erreur avec le regex:%s et la chaine [%s]" reset,regex,s);
  }
 
  return 0;
}
