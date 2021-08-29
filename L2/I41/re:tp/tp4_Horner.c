#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned uint;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex1

double NaifPower(float x,uint n){
    double res=1
    for (int i = 0; i < n; i++)
    {
        res*=x;
    }
    return res;
}

double SMpower(float x,uint n){
    doubler res=1;
    while (n>0)
    {
        n = n >> 1;
        if (n & 1)
        {
            res = res * res;
        }
        res = res * x;
    }
   return res;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char const *argv[])
{
    float x=atoi(argv[1]);
    uint n=atoi(argv[2]);
    //double r=NaifPower(x,n);
    double r=SMpower(x,n);
    printf("x**n=%f",r);
    return 0;
}

    

