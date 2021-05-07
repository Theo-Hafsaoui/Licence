
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef unsigned long long ullong;
typedef unsigned int uint;

void Printaf(uint *t,int n)
{
  printf("\n[%u",t[0]);
  for(int i = 1; i < n; i++)
  {
    printf(",%u",t[i]);
  }
  printf("]\n");

}

uint * Genperm(uint n)
{
  time_t tim;
  uint * T;
  uint temp;
  int alea;

  //srand((unsigned)time(&tim));
  //std::srand(std::time(0));
  T = (uint *)malloc((n)*sizeof(uint));
  for(int i = 0;i < n; i++)
  {
    T[i] = i+1;
  }

  //Printaf(T,n);

  for(int i = 0;i < n;i++)
  {
    alea = rand()%(n-i)+i;    //int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
    //printf("%d\n",alea);

    temp = T[i];
    T[i] = T[alea];
    T[alea] = temp;


  }

  return T;

}

uint IdxMin(uint *T, int a, int b)
{
  int i_min = a;
  for(int i = a; i < b;i++)
  {
    if (T[i] < T[i_min])
    {
      i_min = i;
    }
  }
  return i_min;
}

ullong TriSelection(uint *T,int n)
{
  uint temp;
  ullong cpt = 0;
  int i_min;

  for (int i = 0; i < n; i++)
  {
    i_min = IdxMin(T,i,n);
    temp = T[i];
    T[i] = T[i_min];

    T[i_min] = temp;

    cpt += n-i;
  }
  //Printaf(T,n);
  //  printf("%llu\n",cpt);
  return cpt;

}


ullong TriBulles(uint *T, int n)
{
  uint tmp;
  ullong cpt;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n-1-i; j++)
    {
      if(T[j] > T[j + 1])
      {
        cpt += 1;
        tmp = T[j];
        T[j] = T[j+1];
        T[j+1] = tmp;
      }
    }

  }


  //Printaf(T,n);
  //printf("%llu\n",cpt);
  return cpt;

}

ullong Inserer(uint *T,int i)
{
  ullong cpt = 0;
  uint tmp;
  while((i > 0) && (T[i] < T[i-1]))
  {
    cpt ++;
    tmp = T[i];
    T[i] = T[i-1];
    T[i-1] = tmp;
    i--;

  }
  return cpt;

}

ullong TriInsertion(uint *T, int n)
{
  uint tmp;
  ullong cpt = 0;
  for(int i = 1; i < n ; i++)
  {
    cpt += Inserer(T,i);
  }
  //Printaf(T,n);
  //printf("%llu\n",cpt);
  return cpt;

}




void main(int argc,char **argv)
{
  int n = 100;
  int N = atoi(argv[1]);
  uint *T;
  uint *t1 = (uint *)malloc((n)*sizeof(uint));
  uint *t2 = (uint *)malloc((n)*sizeof(uint));
  uint *t3 = (uint *)malloc((n)*sizeof(uint));

  FILE *fsel = fopen("tri_sel","w");
  FILE *fbul = fopen("tri_bul","w");
  FILE *fins = fopen("tri_ins","w");
  ullong cpt = 0;
  for (int i = 5;i < N;i++)
  {
  //int n = atoi(argv[1]);
  T = Genperm(n);
  //uint *T = Genperm(n);
  //uint *t1 = (uint *)malloc((n)*sizeof(uint));
  //uint *t2 = (uint *)malloc((n)*sizeof(uint));
  //uint *t3 = (uint *)malloc((n)*sizeof(uint));


  Printaf(T,100);
  memcpy(t1,T,sizeof(unsigned int)*n);
  memcpy(t2,T,sizeof(unsigned int)*n);
  memcpy(t3,T,sizeof(unsigned int)*n);
  //Printaf(T,n);
  //Printaf(t1,n);
  //Printaf(t2,n);
  //Printaf(t3,n);
  //Printaf(P,n);
  //Printaf(T,n);
  cpt = TriSelection(t1,n);
  fprintf(fsel,"%d %llu\n",i,cpt);
  //Printaf(P,n);
  cpt = TriBulles(t2,n);
  fprintf(fbul,"%d %llu\n",i,cpt);

  //Printaf(P,n);
  cpt = TriInsertion(t3,n);
  fprintf(fins,"%d %llu\n",i,cpt);
  //free(T);
  //free(t1);
  //free(t2);
  //free(t3);
}
free(T);
free(t1);
free(t2);
free(t3);
}
