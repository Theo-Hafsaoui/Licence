#include <stdio.h>
#include <stdlib.h>
int main(){
    int x,x2;
    printf("x= ");
    scanf("%d",&x);
    x2=x;
    while (x!=1)
    {
        x2=x2*x2;
        x=x/2;
        if (x==2){x=1;}
    }
    printf("x2 = %d",x2);
}