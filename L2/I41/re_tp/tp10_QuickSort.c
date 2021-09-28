#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct {
  uint n;
  int *t;
} liste;

void swap (int *t, uint i, uint j) {
  uint tmp = t[i];
  t[i] = t[j];
  t[j] = tmp;
}

void affiche(liste L){
    int n=L.n;
    int *a=L.t;
    printf("tab =[");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n]);
}
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//copie les n valeurs de la sous-liste L[i,i+n−1] 
//dans la sous-liste Y[j,j+n−1]. 
// ./tp5_Multiprecision.c

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//renvoie la valeur q assurant le bon partitionnement
// de la sous-liste L[p,r] avec la sous-liste L[q+1,r] 
//dans la sous-liste L[p,r]. + Quick sort

int Partionner(liste t, uint p, uint r){
  int x=t.t[p];
  int i=p;
  int j=r;
  while (t.t[j]>x)
  {
    j--;
  }
  while (i<j)
  {
    swap(t.t,i,j);
    do
    {
      j--;
    } while (t.t[j]>x);
    do
    {
      i++;
    } while (t.t[i]<x);
  }
  return j;
}

void TriRapide(liste L, uint p, uint r){
  if (p<r)
  {
    q=Partionner(L,p,r);
    TriRapide(L,p,q);
    TriRapide(L,q+1,r);
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char const *argv[])
{
  uint t[]={8,3,4,2,1,9,7,5,6};liste L ={8,t};
  TriRapide(L,0,8);
}
