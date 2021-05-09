#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//calcule le pgcd (a,b) de deux entiers a et b
// saisis sur la ligne de commande.
/*
int pgcd(int a,int b){
    int r;
    while (b!=0)
    {
        r=b;
        b= a%b;
        a=r;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    int pg=pgcd(a,b);
    printf("pgcd = %d",pg);
    return 0;
}
*/

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
//motif

