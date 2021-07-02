#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int fact(int n){
    if (n==0)
    {
        return 1;
    }
    else{
        return n * fact(n-1);
    }
}

int conv(int n,int b){
    int t;
    if (n==0)
    {
        return t;
    }
    else{
        return (n%b+10*conv(n/b,b));
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char const *argv[])
{
    //printf("fact =%d",fact(5));
    printf("5 en bin =%d",conv(2,2));
    return 0;
}
