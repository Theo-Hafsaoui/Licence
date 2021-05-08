#include <stdio.h>
#include <stdlib.h>
int main(){
    int i2=0;int n=5;int i=0;int cpt=0;
    int t[]={1,2,4,7,98};
    int t1[]={11,211,411,711,981};
    int t2[n*2];
    while (i<n || i2<n ){
        if (t[i]<t1[i2])
        {
            t2[cpt]=t[i];
            i++;
        }
        else if (t[i]>=t1[i2])
        {
            t2[cpt]=t1[i2];
            i2++;
        }
        cpt++;
    }
    printf("[");
    for (int j = 0; j < n*2; j++)
    {
        printf("%d,",t2[j]);
    }
    printf("]");
}