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

int *permute(int *l,int n){
    int *save=(int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        save[i]=l[i];
    }
    
    int i;int i2;int temps;
    srand(time(NULL));
    i=rand()%n;
    i2=rand()%n;
    while (i2<=i)
    {
        i2=rand()%n;
    }
    temps=l[i];
    l[i]=l[i2];
    l[i2]=temps;
    return save;
}

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
triSelection(int*t,int n){
    int itemp; int temp;
    for (int i = 0; i < n; i++)
    {
        itemp=IdxMin(i,n);
        temp=t[i];
        t[i]=t[itemp];
        t[itemp]=temp;
    }
}

unsigned int fact(int n){
    unsigned int f=1;
    for (int i = 0; i < n; i++)
    {
        f=f*(n-i);
    }
    return f;
    

}

int main(int argc, char const *argv[])
{
    int *t;int min;
    int l[]={5,4,3,2,1};
    affiche(l,5);
    int cpt=0;
    min=IdxMin(l,1,4,&cpt);
    printf("imin=%d, cpt=%d\n",min,cpt);
    affiche(s,5);
    for (int i = 0; i < fact(5); i++)
    {
        s=permute(l,5);
        cpt=0;
        triSelection(t,5);
        print("%d  %d",i,cpt)
    }
    
    return 0;
}
