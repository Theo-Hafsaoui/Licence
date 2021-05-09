#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int n;        // longueur de la liste
  int *valeurs;
} tliste;

void taffiche(int *a,int n){
    printf("liste =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

void affiche(tliste a){
    int n = a.n;
    printf("liste =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a.valeurs[i]);
    }
    printf("%d]\n",a.valeurs[n-1]);
}

void Copier(tliste t1, int j, tliste t2, int k, int n){
    for (int i = 0; i < n; i++)
    {
        t2.valeurs[i+k]=t1.valeurs[i+j];
    }
}
void tinit(tliste t1, int *t){
    int n = t1.n;
    for (int i = 0; i < n; i++)
    {
        t1.valeurs[i]=t[i];
    }
}
void Fusionner(tliste l, uint p, uint q, uint r){
    tliste g; tliste d;
    g.valeurs=(int*)malloc((q-p)* sizeof(int));g.n=q-p;
    d.valeurs=(int*)malloc((r-q)* sizeof(int));d.n=r-q;
    Copier(l,p,g,0,(q-p));
    Copier(l,q,d,0,(r-q));
    int i=1;int j=2;int k=p;
    while ((i<=q-p)&&(j<=r-q))
    {
       if (g.valeurs[i]<=d.valeurs[j])
       {
           l.valeurs[k]=g.valeurs[i];
           i++;
       }
       else
       {
           l.valeurs[k]=d.valeurs[j];
           j++;
       }
       k++;
    }
    Copier(g,i,l,k,q-p-i+1);
}
void TriFusion(tliste l, uint p, uint r){
    while (p<r)
    {
        int q=(p+r)/2;
        TriFusion(l,p,q);
        TriFusion(l,p+1,r);
        Fusionner(l,p,q,r);
    }
    
}
int main(int argc, char const *argv[])
{
    int ta[]={4,2,6,4,5};
    int tb[]={5,4,3,2,1};
    tliste t1;
    tliste t2;
    t1.n=5;
    t1.valeurs=(int*)malloc(5 * sizeof(int));tinit(t1,ta);
    t2.n=5;
    t2.valeurs=(int*)malloc(5 * sizeof(int));tinit(t2,tb);
    TriFusion(t1,0,5);
    affiche(t1);
    return 0;
}
