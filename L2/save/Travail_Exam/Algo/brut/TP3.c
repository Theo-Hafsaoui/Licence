#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef enum {FAUX = 0, VRAI = 1} tbool;
typedef unsigned long long ullong;
typedef unsigned char uchar;

uchar Increment(uchar * A, uchar n, uchar b){
  int i = 0;
  int som = 0;
  int nb = 0;
  while(i < n){
    som = A[i]+1;
    nb += 1;
    if( som < b){
      A[i] = som;
      return nb;
    }
    else{
      A[i] = 0;
    }
    i++;


  }

  return nb;
}
/*
  void main(){

    uchar  a[] = {1,1,1,1,1};
    uchar n = 5;
    uchar base = 2;

    for(int i = 0;i < n; i++){
      printf("%hhu",a[i]);
    }
    printf("\n");

    printf("\n%hhu\n\n",Increment(a,n,base));
    for(int i = 0;i < n; i++){
      printf("%hhu",a[i]);
    }
    printf("\n");


  }
  */
  ullong test(uchar n, uchar b){
    uchar t[n];
    int i = 0;
    ullong som = 0;
    int j;
    ullong p = pow(b,n);
    printf("\n");
    for(; i < p; i++){
      j = Increment(t,n,b);
      som += j;
      printf("%d\n",j);
    }
    return som;
  }

tbool CommencePar(char * mot, char * deb){
  int lm = strlen(mot);
  int ld = strlen(deb);
  int cp = 0;
  if (ld>lm)
    return 0;
  for(int i; i<ld;i++){
    cp +=1;
    if(deb[i] != mot[i]){
      printf("\ncp = %d\n",cp);
      return 0;}
  }
  printf("\ncp = %d\n",cp);
  return 1;




}
/*
void main(){
  char * m = "coucoucoucoucoucou";
  char * d = "cou";
  printf("\n%d\n",CommencePar(m,d));
}
*/
tbool BienParenthesee(char * expr){
  int cpt = 0;
  int cp = 0;
  int i = 0;
  while(expr[i] != '\0'){

    if (expr[i] == '('){
      cpt -=1;
    }
    else if (expr[i] == ')'){
      cpt +=1;

    }
    if(cpt > 0)
      printf()
      return 0;
    }
    if (cpt == 0)
      return 1;
    return 0;


  }

}
