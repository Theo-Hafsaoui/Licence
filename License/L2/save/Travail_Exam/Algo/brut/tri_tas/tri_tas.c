#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef unsigned int uint;

int *generate_perms(int n)
{
    int *perms = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        perms[i] = i + 1;

    struct timespec spec;
    clock_gettime(0, &spec);
    srand(spec.tv_nsec);
    for (int i = 0; i < n; i++)
    {
        int index = rand() % n;
        int tmp = perms[i];
        perms[i] = perms[index];
        perms[index] = tmp;
    }

    return perms;
}
void swap(*int T,uint a, uint b)
{
  int temp = T[a];
  T[a] = T[b];
  T[b] = temp;
}

void Tamiser(int *T, uint ipere,uint ifin)
{

  //int ifils = (2*(ipere+1))-1;
  int ifils = 2*ipere + 1
  if((ifils < ifin) && (T[ifils+1] > T[ifils]))
  {
    ifils ++;
  }
  if((iflis < ifin) && (T[ipere] < T[ifils]))
  {
    swap(T,ifils,ifin);
    Tamiser(T,ifils,ifin);
  }
}


void Entasser(int *T,uint n)

{
  for(int i = n / 2 - 1; i >= 0; i--)
  {
    Tamiser(T,n,i);
  }
}

void Tri_Tas(int *T,uint n)
{
  Entasser(T,n);

  for(int i = n-1; i > 0; i--)
  {
    swap(T,i,0);
    Tamiser(T,i,0);

  }
