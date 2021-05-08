#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Réalise le tri par insertion
//des valeurs placées sur la ligne de
//commande en écrivant la fonction tri. 
/*
void affiche(int *a,int n){
    printf("tab =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

int i_max(int st,int *t,int n){
    int max=st;
    for (int i = st+1; i < n; i++)
    {
        if (t[i]>t[max])
        {
            max=i;
        }
    }
    return max;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void SelectionSort(int *t,int n){
    int temp_max;
    for (int i = 0; i < n; i++)
    {
        temp_max=i_max(i,t,n);
        swap(&t[i],&t[temp_max]);
    }
}


int main(int argc, char const *argv[])
{
    //~~~~~~~~~~~~~~~~~~~~
    //transforme l'entree std en tableau
    int t[argc-1];
    for (int i = 1; i < argc; i++)
    {
        t[i-1]=atoi(argv[i]);
    }
    affiche(t,argc-1);
    //~~~~~~~~~~~~~~~~~~~~
    SelectionSort(t,argc-1);
    affiche(t,argc-1);
    return 0;
}
*/
//Intersection de deux ensemble
/*

void affiche(int *a,int n){
    printf("tab =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

//O(n**2+n)
int *Intersection(int *a,int*b,int an,int bn){
    if (an<bn)
    {
        int*temp;
        temp=a;
        a=b;
        b=a;
    }
    int cpt=0;//cpt sera la longeur du tableau dynamique
    for (int i = 0; i < an; i++)
    {
        for (int j = 0; j < bn; j++)
        {
            if (a[i]==b[j])
            {
                a[cpt]=a[i];//pas de risque d'ecrasment car i>=cpt
                cpt++;
            }
        }
    }
    int *inter=(int*) calloc(cpt,sizeof(int));
    for (int i = 0; i < cpt; i++)
    {
        inter[i]=a[i];
    }
    return inter;
}

int main(int argc, char const *argv[])
{
    int a[5]={1,2,3,4,5};
    int b[3]={4,1,5};
    int*t=Intersection(a,b,5,3);
    affiche(t,3);
}
*/

//Fusion

/*void affiche(int *a,int n){
    printf("tab =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

int* fusion(int*a,int*b,int an,int bn){
    int i=0;int j=0;
    int*t=(int*) calloc((an+bn),sizeof(int));
    while (i<=an&&j<=bn)
    {
        if (a[i]<b[j])
        {
            t[i+j]=a[i];
            i++;
        }
        else
        {
            t[i+j]=b[j];
            j++;
        }
    }
    return t;
}


int main(int argc, char const *argv[])
{
    int a[4]={1,1,3,5};
    int b[3]={2,4,7};
    int*t=fusion(a,b,4,3);
    affiche(t,7);
    return 0;
}*/
