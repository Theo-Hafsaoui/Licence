#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned int uint;

void affiche(int *a,int n){
    printf("liste =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

void swap(uint *arr, uint i, uint j) {//youssef
    uint tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

uint fact(int n){
    if (n==0)
    {
        return 1;
    }
    else
        return(n*fact(n-1));
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Renvoie une permutation jusqua n

uint *GenPerm(uint n){
    uint *t=(uint*) calloc(n,sizeof(uint));
    srand(time(NULL));int idx;
    for (int i = 0; i < n; i++)
    {
        t[i]=i;
    }
    for (int i = 0; i < n; i++)
    {
        idx=rand()%n;
        swap(t,i,idx);
    }
    return t;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Trie selection
int IdxMin(int *t, uint a, uint b,int *cpt){
    int Imin=a;
    for (int i = a; i <= b; i++)
    {
        *cpt=*cpt+1;
        if (t[i]<t[Imin])
        {
            Imin=i;
        }
    }
    return Imin;
                   
}
void triSelection(int*t,int n,int *cpt){
    int itemp; int temp;
    for (int i = 0; i < n; i++)
    {
        itemp=IdxMin(t,i,n,cpt);
        temp=t[i];
        t[i]=t[itemp];
        t[itemp]=temp;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// trie bubule
void TriBubule(int*t,int n,int *cpt){
    int j;int temp;
    for (int i = 0; i < n; i++)
    {
        for (int i2 = 0; i2 < n; i2++)
        {
            *cpt=*cpt+1;
            if (t[i]<t[i2])
            {
            temp=t[i];
            t[i]=t[i2];
            t[i2]=temp;
            }
        }
    }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//trie insertion
void TrieInsertion(int*t,int n,int *cpt){
    int i;int temp;int cpt1;
    for (int j = 1; j < n; j++)
    {
        i=1;
        while ((t[(j-i)+1]<t[(j-i)])&&(j-i>=0))
        {
            temp=t[(j-i)];
            t[(j-i)]=t[(j-i)+1];
            t[(j-i)+1]=temp;
            i++;
            *cpt+=1;
        }
    }
}
    
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char const *argv[])
{

    //int *s;int min;
    //int l[]={5,4,3,2,1};
    //affiche(l,5);
    //int cpt=0;
    //TrieInsertion(l,5,&cpt);
    //affiche(l,5);
    //printf("cpt=%d\n",cpt);
    //return 0;
    //uint *t=GenPerm(2);
    //affiche(t,2);
    //int n =fact(5);
    //printf("n=%d\n",n);
}
