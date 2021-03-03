#include <stdio.h>

int main(){
    int n,cpt;
    printf("enter a number");
    scanf("%d",&n);
    cpt=0;
    do{
        n=n/10;
        cpt++;
    }while (n!=0);
    printf("ther is %d, number",cpt);
}