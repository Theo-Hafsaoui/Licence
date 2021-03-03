#include <stdio.h>

void main()
{
    int a,c,k;
    char b;
    scanf("%d%c%d",&a,&b,&c);
    printf("%d, %d\n",a,c);
    printf("%c\n",b);

    switch (b)
    {
    case '+':
        printf("%d\n",a+c);
        break;
    case '*':
        printf("%d\n",a*c);
        break;
    case '-':
        printf("%d\n",a-c);
        break;
    default:
        printf("hmmm erreur");
        break;
    }


}
