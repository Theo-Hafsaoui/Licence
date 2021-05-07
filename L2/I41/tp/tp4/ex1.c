#include <stdio.h>
#include <math.h>
#include <string.h>

typedef unsigned int uint;
typedef long long ulong;
typedef unsigned char uchar;

double Power(float x, ulong n){
    double r=1;
    if (n==0)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        r=r*x;
    }
    return r;
}

void affiche(uchar *a,int n){
    printf("uchar =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}


double SM(float x, uint n){
    double r=1;
    while (n!=0)
    {
        r=r*r;
        n=n>>1;
        if ((n&1))
        {
            r=r*x;
        }
        
    }
    return r;
}

int main()
{
    int x;int n; int rs;
    printf("x= ");
    scanf("%d",&x);
    n=5000000;
    rs=SM(x,n);
    printf("%d",rs);
}
