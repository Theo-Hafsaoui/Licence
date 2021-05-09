#include <stdio.h>
#include <stdlib.h>
int main(){
    int x,x2;
    int *p;
    printf("x= ");
    scanf("%d",&x);
    x2=x*x;
    p=&x2;
    &x=p;
    printf("x**2= %d",x);
    
}