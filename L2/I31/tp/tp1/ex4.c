#include <stdio.h>

void main()
{
    int x,y,m;
    scanf("%d", &x);
    scanf("%d", &y);
    m=0;

    (x>y)? (m=x):(m=y);
    printf("%d, est le max", m);


}
