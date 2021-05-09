#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int N = 7;
int cpt_n = 0;
int cpt_h = 0;
int cpt_sm = 0;
double SM(float x,uint n)
  {
  double r = x;
  double p = 1;
  for(;n >0;n = n/2)
  {

    if (n%2)
      p = p*r;
      cpt_sm += 1;
    r = r*r;
    cpt_sm += 1;
  }
  return p;
}
double Power(float x, uint n)
    {double p = 1;
    for(int i = 0;i < n;i++ )
    {
      p *= x;
      cpt_n += 1;
    }
    return p;
}
void Printaf(float *t,int n)
{
  printf("\n[%f",t[0]);
  for(int i = 1; i < n; i++)
  {
    printf(",%f",t[i]);
  }
  printf("\n");

}
float *Creer_Poly(unsigned long n){
  time_t tim;
  float *poly = (float *)malloc(n*sizeof(float));
  srand((unsigned)time(&tim));
  for(int i = 0; i < n;i++)
  {
    poly[i] = rand()%9 + 1;
  }
  return poly;
}


float Eval_Naif(float *P,int n,float x)
{
  int i = 1;
  float r = P[0];
  float a = x;
  while(i < n){
    r = r + P[i]*Power(x,i);
    cpt_n += 1;
    i++;
  }
  return r;
}

float Eval_SM(float *P,int n,float x)
{
  int i = 1;
  float r = P[0];
  while(i < n)
  {
    r = r + P[i]*SM(x,i);
    cpt_n += 1;

    i++;
  }
  return r;
}

float Eval_Horner(float *P,int n,float x)
{
  int i = 0;
  float r = 0;
  while(i < n)
  {
    r = r * x + P[n-1-i];
    cpt_h += 1;
    i++;

  }
  return r;
}
int main(){
  float *poly;
  float nn,nh,nsm;
  //Printaf(poly,N);

  FILE *fn = fopen("courbe_naif","w");
  FILE *fsm = fopen("courbe_SM","w");
  FILE *fh = fopen("courbe_Horner","w");

  //printf(" \nnaif : %f   SM : %f   Horner : %f\n",Eval_Naif(poly,N,5),Eval_SM(poly,N,5),Eval_Horner(poly,N,5));
  //printf("naif : %d   SM : %d   Horner : %d\n",cpt_n,cpt_sm,cpt_h);
  for(int i = 1; i < 50;i++)
  {
    poly = Creer_Poly(i);
    nsm = Eval_SM(poly,i,3);
    nh = Eval_Horner(poly,i,3);
    nn = Eval_Naif(poly,i,3);
    fprintf(fn,"%f %d\n",nn,cpt_n);
    fprintf(fh,"%f %d\n",nh,cpt_h);
    fprintf(fsm,"%f %d\n",nsm,cpt_sm);
    cpt_h = 0;
    cpt_n = 0;
    cpt_sm = 0;

  }



  fclose(fn);
  fclose(fh);
  fclose(fsm);
  free(poly);
}
