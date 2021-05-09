#include <stdio.h>
int main()
{
    int s,i,j;
    printf("somme de nombre jusquq ?");
    scanf("%d",&j);
    i=0;
    s=0;
    for (i;i<j;i++){
        s=s+i*i;
    }
    printf("res=%d",s);
    return s;

}