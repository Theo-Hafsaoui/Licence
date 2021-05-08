#include <stdio.h>
#include <stdlib.h>
void split(){}

int main(){
    int l[]={54,67,32,45,89,32};
    int l2[]={5,2,3,5};
    l[1]=&l2;
    printf("[");
    for(int i=0;i<6;i++){
        printf("%d ",l[i]);
    }
    printf("]");
}