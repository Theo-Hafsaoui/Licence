#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct {
  uint n;
  int *t;
} liste;

void affiche(liste L){
    int n=L.n;
    int *a=L.t;
    printf("tab =[");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n]);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//copie les n valeurs de la sous-liste L[i,i+n−1] 
//dans la sous-liste Y[j,j+n−1]. 

void Copier(liste X, uint i, liste Y, uint j, uint n){
    for (int k = 0; k < n; k++)
    {
        Y.t[j+k]=X.t[i+k];
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Fusionne les sous liste L[p:q] et L[q:r] dans la sous liste
//L[p:r]+ el famoso merge sort

void Fusionner(liste L, uint p, uint q, uint r){
    uint t1[q-p+1];liste G ={(q-p+1),t1};
    uint t2[r-q];liste D ={(r-q),t2};
    Copier(L,p,G,0,(q-p+1));
    Copier(L,q+1,D,0,(r-q));
    affiche(G);
    affiche(D);
    int i=0;int j=0; int k=p;
    while (i<D.n && j<G.n)
    {
        if (G.t[i]>D.t[j])
        {
            L.t[k]=D.t[j];
            j++;
        }
        else{
            L.t[k]= G.t[i];
            i++;
        }
        k++;
    }
    Copier(G,i,L,k,(G.n-i));
}

void TriFusion(liste L, uint p, uint r){
    int q;
    if (p<r)
    {
        q=(p+r)/2;
        TriFusion(L,p,q);
        TriFusion(L,q+1,r);
        Fusionner(L,p,q,r);
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char const *argv[])
{
    uint t[]={8,3,4,2,1,9,7,5,6};liste L ={8,t};
    TriFusion(L,0,8);
    affiche(L);
    return 0;
}
