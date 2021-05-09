#include <stdio.h>
int main(){
    int a,s,i,m;
    printf("enter nb:\n");
    s=0;
    i=0;
    do
    {
        i++;
        scanf("%d",&a);
        s+=a;
    } while (a!=-1);
    m=s/i;
    printf("moy=%d",m);
}