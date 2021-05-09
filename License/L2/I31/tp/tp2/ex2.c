#include <stdio.h>

int main(){
    int n,j;
    j=1;
    printf("nb = ");
    scanf("%d", &n);
    while (j<n){
        j=j*2;
    }
    printf("le carre sup est %d \n",j);
    return j;
}
