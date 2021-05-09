#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void affiche(int *a,int n){
    printf("liste =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

void TrieInsertion(int*t,int n,int *cpt){
    int i;int temp;
    for (int j = 1; j < n; j++)
    {
        i=1;
        affiche(t, n);
        while ((j-i) >= 0 && t[(j-i)+1]<t[(j-i)])
        {
            temp=t[(j-i)];
            t[(j-i)]=t[(j-i)+1];
            t[(j-i)+1]=temp;
            i++;
            *cpt += 1;
        }
    } 
}
    

int main(int argc, char const *argv[])
{
    int l[]={5,4,3,2,1};
    printf("%d\n", l[-1]);
    affiche(l,5);
    int cpt=0;
    TrieInsertion(l,5,&cpt);
    affiche(l,5);
    printf("cpt=%d\n",cpt);
    return 0;
}
