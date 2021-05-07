#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define LECTURE    1
#define ECRITURE   2
#define EXECUTION  4
typedef int droits;
void afficheDroit(droits d) {
  if (d&LECTURE) printf("r");
     else printf("-");
  if (d&ECRITURE) printf("w");
     else printf("-");
  if (d&EXECUTION) printf("x");
     else printf("-");
  printf("\n");
}
 
int main(int argc, char **argv) {
  /* Affiche les droits en lecture seule */
  afficheDroit(1);
 
  /* Affiche les droits en lecture et execution */
  afficheDroit(7);
 
  /* Affiche les droits passes en parametre */
  if (argc > 1) afficheDroit(atoi(argv[1]));
}