#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long Factorielle(unsigned char n)
{
  if ((n == 0) ||(n== 1))
  {
    return 1;
  }
  else
  {

    return (Factorielle(n-1)*n);
  }

}
void Printaf(unsigned int *t,int n)
{
  printf("\n[%d",t[0]);
  for(int i = 1; i < n; i++)
  {
    printf(",%d",t[i]);
  }
  printf("]");
  printf("\n");

}


unsigned int *S2L(char *chr)
{

  int cpt = strlen(chr);
  unsigned int * N;
  N = (unsigned int *)malloc((cpt)*sizeof(unsigned int));

  for (int i = 0; i < cpt ; i++)
  {

    N [i] = chr[cpt-1-i]-48;

  }

  return N;


}


char *L2S(unsigned int * N, int n)
{
  char * chr;
  chr = (char *)malloc((n)*sizeof(char));

  for (int i = 0; i < n ; i++)
  {

    chr [i] = N[n-1-i]+48;

  }

  return chr;


}



unsigned int *Addition(unsigned int *A, int nA,unsigned int *B, int nB, unsigned int base )
{
  int i = 0;
  unsigned int * C;
  unsigned int retenue;
  C = (unsigned int *)malloc((nA+1)*sizeof(unsigned int));

  while (i < nB)
  {
    C[i] = A[i] + B[i] + retenue;
    if (C[i] >= base)
    {
      retenue = 1;
      C[i] = C[i] - base;
    }
    else
    {
      retenue = 0;
    }
    i++;
  }

  while(i < nA)
  {
    C[i] = A[i] + retenue;

    if (C[i] >= base)
    {
      retenue = 1;
      C[i] = C[i] - base;
    }
    else
    {
      retenue = 0;
    }
    i++;
  }
  if (retenue > 0)
  {
    C[i] = retenue;
  }
  else{
    //free(C[i]);
  }
  return C;
}







unsigned int *Multiplication(unsigned int *A, int nA,unsigned int *B, int nB, unsigned int base )
{
  int i = 0;
  int j;
  unsigned int * C;
  unsigned int retenue;
  C = (unsigned int *)malloc((nA+nB)*sizeof(unsigned int));

  while(i < nA)
  {
    retenue = 0;
    j = 0;
    while(j < nB)
    {
      C[i+j] = C[i+j] + A [i] * B[j] + retenue;
      retenue = C[i+j]/base;
      C[i+j] = C[i+j]%base;
      j ++;
    }
    if (retenue > 0)
    {
      C[i+j] = retenue;
    }
    i++;
  }
  return C;

}

void main(int argc, char **argv)
{
  //printf("%s %s %s",argv[1],argv[2],argv[3]);
  int nA = strlen(argv[1]);
  int nB = strlen(argv[2]);
  unsigned int* A = S2L(argv[1]);
  unsigned int* B = S2L(argv[2]);
  unsigned int base = atoi(argv[3]);
  Printaf(A,nA);
  Printaf(B,nB);
  unsigned int * S = Addition(A,nA,B,nB,base);
  unsigned int * P = Multiplication(A,nA,B,nB,base);
  //Printaf(S,nA+1);
  //Printaf(P,nA+nB);

  //printf("La somme est %s\n",L2S(S,nA));
  printf("La somme est %s\nLe produit est %s\n",L2S(S,nA+1),L2S(P,nA+nB));


}
