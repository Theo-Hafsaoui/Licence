#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned uint;

uint pairornot(uint n){
    if ((n%2)==0){
        return n/2;
    }
    else
    {
        return 3*n+1;
    } 
}

int main(){
    uint n=4563281;
    int i;
    while (n!=1)
    {
        printf("%d  %d\n",i,n);
        i++;
        n= pairornot(n);
    }
    
}
