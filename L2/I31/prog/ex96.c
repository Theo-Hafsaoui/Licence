#include <stdio.h>
#include <stdlib.h>
int main(){
    int t[10]={1,8,3,5,4};
    int max,n;
    n=10;
    max=t[0];
    for (int i = 0; i < n; i++)
    {
        if (t[i]>max)
        {
            max=t[i];
        }
        
    }
    printf("max= %d",max);
    
}