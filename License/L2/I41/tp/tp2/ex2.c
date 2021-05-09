#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned uint;

void TriSelection(int* l, uint n){
    int min=0;int temp;
    int i2=0;
    while (i2<n)
    {
        min=i2;
        for (int i = i2+1; i < n; i++)
        {
            if (l[i]<l[min]){
                min=i;
            }
        }
        temp=l[i2];
        l[i2]=l[min];
        l[min]=temp;
        i2++;
    }
}

int main(){
    int l[5]={5,4,3,2,1};
    int n= 5;
    printf("l= [");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", l[i]);
    }
    printf("]\n");
    TriSelection(&l,n);
    printf("l= [");
    for (int i = 0; i < n; i++)
    {
        printf("%d,", l[i]);
    }
    printf("]\n");
    
}