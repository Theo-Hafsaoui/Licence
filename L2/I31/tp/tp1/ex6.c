#include <stdio.h>

void main()
{
    int x,y,m,d;
    scanf("%d", &x);

    y=(x/10000);
    m=(x-(y*10000))/100;
    d=(x-y*10000-m*100);

    printf("la date est le %d , %d, %d",y,m,d);


}
