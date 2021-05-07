#include <stdio.h>
#include <stdlib.h>



typedef struct{
  int n;
  int *arr;
} list;


void minmax(list L,int *min, int *min)
{
  *min = L.arr[0];
  *max = *min;
  for(int i = 0; i < L.n;i++)
  {
    if (*min < L.arr[i])
      *min = L.arr[i];
    if (*max < L.arr[i])
      *max = L.arr[i];
  }

list Histogramme(Liste L,int min)
{
  int max = 0;
  minmax(L,&min,&max);
  int * t;
  int n = max-min+1;
  t = calloc(n,sizeof(int));
  for(int i = 0; i < n; i++)
  {
    t[L[i-min]]++;
  }
  list H = {n,t};
  return H;
}

void denomb(Liste L)
{
  int min;
  list H = Histogramme(L,min);
  int k = 0;
  for(int i ; i < H.n; i++)
  {
    for(int j = 0; j < H.arr[i];j++)
    {
      L.arr[k] = i+min;
      k++;
    }
  }
}
