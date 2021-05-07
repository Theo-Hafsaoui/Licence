#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void Printaf(int *t,int n)
{
  printf("\n[%d",t[0]);
  for(int i = 1; i < n; i++)
  {
    printf(",%d",t[i]);
  }
  printf("]");
  printf("\n");

}

int *S2L(char *chr)
{

  int cpt = strlen(chr);
  int * N;
  N = (int *)malloc((cpt)*sizeof(int));

  for (int i = 0; i < cpt ; i++)
  {

    N [i] = chr[cpt-1-i]-48;

  }

  return N;


}


char *L2S(int * N, int n)
{
  char * chr;
  chr = (char *)malloc((n)*sizeof(char));

  for (int i = 0; i < n ; i++)
  {

    chr [i] = N[n-1-i]+48;

  }

  return chr;


}

void main(int argc, char **argv)
{
  int * Temp;
  //int *A  = S2L(argv[1]);
  //int *B  = S2L(argv[2]);
  //int nA = strlen(argv[1]);
  //int nB = strlen(argv[2]);
  int A[] ={1,2,3};
  int B[] ={1,2};
  int nA = 3;
  int nB = 2;

  Printaf(A,nA);
  Printaf(B,nB);
  int temp = nA;
  nA = nB;
  nB = temp;
  Temp = A;
  A = B;
  B = Temp;


  //swap(A,B,nA,nB);
  Printaf(A,nA);
  Printaf(B,nB);
}
