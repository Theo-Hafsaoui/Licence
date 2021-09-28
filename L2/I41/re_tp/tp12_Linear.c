#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  uint n;        
  int *valeurs;
} tliste;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void affiche(uint *a,int n){//Lecture naturel -> a[n-i]
    printf("tab =[");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n]);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex1 Trie lineaire


void MinMax(int *l, int *min, int *max,int n){
    *min=l[0];
    *max=l[0];
    for (int i = 0; i < n; i++)
    {
        if(l[i]<*min){
            *min=l[i];
        }
        if(l[i]>*max){
            *max=l[i];
        }
    }
}

tliste histograme(tliste l){
    int min;int max;
    MinMax(l.valeurs,&min,&max,l.n);
    int *t=(int*) calloc((max-min),sizeof(int));
    for (int i = 0; i < l.n; i++)
    {
        t[l.valeurs[i]-min]++;
    }
    tliste res;res.valeurs=t;res.n=max-min;
    return res;
    
}

void Linearsort(tliste l){
    int min;int max;
    MinMax(l.valeurs,&min,&max,l.n);
    tliste hist=histograme(l);
    affiche(hist.valeurs,hist.n-1);
    int i=0;int j=0;
    for (int i = 0; i < l.n; i++)
    {
        if (hist.valeurs[j]>0)
        {
            l.valeurs[i]=j+min;
            hist.valeurs[j]--;
        }
        else{
            j++;
            i--;
        }
    }
    }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char const *argv[])
{
    int l[5]={6,2,7,2,5};
    tliste l1;l1.valeurs=l;l1.n=5;
    Linearsort(l1);
    affiche(l1.valeurs,l1.n-1);
    return 0;
}
