#include <stdio.h>
#include <stdlib.h>
int main(){
    int t[]={1,211,4,7,98};
    int n=5;
    for (int i = 0; i < n; i++)
    {
       t[i]=-(t[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",t[i]);
    }
    
    
}