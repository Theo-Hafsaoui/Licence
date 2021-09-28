#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned uint;
typedef unsigned char uchar;
typedef unsigned long ullong;


void affiche(int *a,int n){
    printf("tab =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void swap(int *t,int a,int b){
    int temp=t[a];
    t[a]=t[b];
    t[b]=temp;
}

void Tamiser(int *t,uint i,uint n){
    int ison=2*i;
    if ((ison+1<n) && (t[ison+2]>t[ison+1]))
    {
        i++;
    }
    if ((ison+1<=n)&&(t[i]<t[ison+1]))
    {
        swap(t,i,ison+1);
        Tamiser(t,ison,n);
    }
}

void enttaser(int *t,int n){
    int i=n/2-1;
    while (i>=0)
    {
        Tamiser(t,i,n-1);
        i--;
    }
}

void Heapsort(int *t,int n){
    enttaser(t,n);
    for (int i = 1; i < n; i++)
    {
        swap(t,0,n-i);
        Tamiser(t,0,n-i-1);
    }
    

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char const *argv[])
{
    
    int t[5]={3,8,2,9,1};
    swap(t,1,4);
    Heapsort(t,5);
    affiche(t,5);
    return 0;
}
