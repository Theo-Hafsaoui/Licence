#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned uint;
typedef unsigned char uchar;
typedef unsigned long ullong;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void affiche(uint *a,int n){//Lecture naturel -> a[n-i]
    printf("tab =[");
    for (int i = 1; i < n; i++)
    {
        printf("%d,",a[n-i]);
    }
    printf("%d]\n",a[0]);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex1fonction tnombre I2N(int n, uint b) qui
//convertit un entier en nombre multiprécision
//en base b. 

typedef struct {
  uint n;
  uint* t;
} tnombre;

uint* In2bin(float a,uint b, int *len){
  int i=0;
  int sv=a;
  while (a>1)
  {
    a=a/2;//calcule la taille a en base B
    i++;
  }
  *len=i;
  uint *t= (uint*) calloc(*len,sizeof(uint));
  for (int j = 0; j < i; j++)
  {
    t[j]=sv%2;//Calcule a en base B
    sv/=2;
  }
  return t;
}

tnombre I2N(int n, uint b){
  int len; tnombre mp;
  uint *t=In2bin(n,b,&len);
  mp.t = t;
  mp.n = len;
  return mp;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex2 Fonction Factorielle
ullong Factorielle(int n){
  ullong res=1;
  for (int i = 0; i < n; i++)
  {
    res=res*(n-i);
  }
  return res;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex3 convertie de str vers mp et reciproquement

tnombre S2N(char *ch){
  tnombre mp;
  int len =strlen(ch);
  uint *t=(uint*) calloc(len,sizeof(uint));
  for (int i = len-1; i >= 0; i--)
  {
    t[i]=(ch[i])-48;
  }
  mp.t=t;
  mp.n=len;
  return mp;
}

char* N2S(tnombre mp){
  int len =mp.n;
  char *ch=(char*) calloc(len,sizeof(char));
  for (int i = len-1; i >= 0; i--)
  {
    ch[i]=(mp.t[i])+48;
  }
  ch[len+1]='\0';
  return ch;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex4 adition et multipliction multiprecision

tnombre Addition(tnombre A, tnombre B, uint b){
  tnombre res;tnombre temp;
  if (B.n>A.n)//A sera le plus grand des deux
  {
    temp=B;
    B=A;
    A=B;
  }
  uint cpt=A.n;
  if (A.n==B.n)
  {
    cpt++;
  }
  uint *t=(uint*) calloc(cpt,sizeof(uint));
  int i=0;int r=0;
  while (i<B.n)
  {
    t[i]=A.t[i]+B.t[i]+r;
    affiche(t,cpt);
    if (t[i]>=b)
    {
      r=1;
      t[i]-=b;
    }
    else{
      r=0;
    }
    i++;
  }
  while (i<cpt)
  {
    affiche(t,cpt);
    t[i]=A.t[i]+r;
    if (t[i]>=b)
    {
      r=1;
      t[i]-=b;
    }
    else{
      r=0;
    }
    i++;
  }
  res.n=cpt;
  res.t=t;
  return res;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char const *argv[])
{
  //int len ;
  //tnombre mp=I2N(124, 2);
  //affiche(mp.t,7);
  //printf("len=%d",mp.n);
  //ullong res=Factorielle(atoi(argv[1]));
  //printf("fact=%lu",res);
  tnombre mpc1=S2N("110");
  tnombre mpc2=S2N("111");
  tnombre res=Addition(mpc1,mpc2,2);
  affiche(res.t,res.n);
  



  return 0;
}
