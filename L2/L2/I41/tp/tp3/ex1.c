#include <stdio.h>
#include <math.h>

typedef enum{False=0,True} boul;
typedef long long ulong;
typedef unsigned char uchar;

uchar Increment(uchar * a, int n, int b){
    int i=0 ;int c=1;uchar ca[n];int m;
    while (i<n && c)
    {
        if (a[i]==(b-1))
        {
            ca[i]=0;
            a[i+1]=(a[+1]+1);
            i++;
            while (a[i]==(b))
            {
                ca[i]=0;
                a[i]=0;
                a[i+1]=(a[i+1]+1);
                i++;
            }
            c=0;
        }
        else
        {
            ca[i]=(a[i]+1);
            c=0;
            i++;
        }
    m=i;    
    while (i<n)
    {
        ca[i]=a[i];
        i++;
    }
    *a=*ca;
    return m;
    }
}

ulong test(uchar *n, int b){
    ulong p = pow(n,b);
    printf("%d",p);

}

affiche(uchar *a,int n){
    printf("uchar =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

int main(int argc, char const *argv[])
{
    int m=0;
    uchar a[5]={9,9,9};
    m=Increment(a,3,10);
    affiche (a,4);
    printf("\n m=%d",m);
    test(a,2);
    return 0;
}