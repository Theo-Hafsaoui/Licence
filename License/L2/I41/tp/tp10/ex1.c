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

void swapp(int *t,int i,int j){
    int temp=t[i];
    t[i]=t[j];
    t[j]=temp;
}

void tamtam(int *t,int ip,int ie){
    int is=2*ip;
    if ((is<ie)&&(t[is+1]>t[is]))
    {
        is++;
    }
    if ((is<=ie)&&(t[ip]<t[is]))
    {
        swapp(t,is,ip);
        tamtam(t,is,ie);
    }
}

void Entasser(int *t, uint n){
    int i =n/2-1;
    while (i>0)
    {
        tamtam(t,i,n);
        i--;
    }
}


int main(int argc, char const *argv[])
{
    int t[]={1,3,2,4};
    Entasser(t,4);
    affiche(t,4);
    return 0;
}
