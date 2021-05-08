#include <stdio.h>
#include <stdlib.h>


void Printaf(int *t,int n)
{
  printf("\n[%d",t[0]);
  for(int i = 1; i < n; i++)
  {
    printf(",%d",t[i]);
  }
  printf("]\n");

}


void copier(int * L, uint i,int * Y, uint j, uint n)
{
  for(int k = 0; k < n; k++)
  {
    L[i+k] = Y[k+j];
  }
}

void Fusionner(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;

/* create temp arrays */
int L[n1], R[n2];

/* Copy data to temp arrays L[] and R[] */
for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

/* Merge the temp arrays back into arr[l..r]*/
i = 0; // Initial index of first subarray
j = 0; // Initial index of second subarray
k = l; // Initial index of merged subarray
while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
    }
    else {
        arr[k] = R[j];
        j++;
    }
    k++;
}

/* Copy the remaining elements of L[], if there
are any */
while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
}

/* Copy the remaining elements of R[], if there
are any */
while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
}
}


void Tri_Fusion(int arr[], int l, int r)
{
  if (l < r) {
      // Same as (l+r)/2, but avoids overflow for
      // large l and h
      int m = l + (r - l) / 2;

      // Sort first and second halves
    Tri_Fusion(arr, l, m);
    Tri_Fusion(arr, m + 1, r);

      Fusionner(arr, l, m, r);
  }
}
void main()
{
  int n = 5;
  int L[5] = {1,3,4,2,0};
  int L1[5] = {3,2,5,1,2};
  Printaf(L,n);
  Tri_Fusion(L,0,n-1);
  Printaf(L,n);


}
