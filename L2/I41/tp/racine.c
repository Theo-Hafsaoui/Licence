#include <stdio.h>

int racine(i){
    int c=0;int s=1;
    while (s<=i)
    {
        c++;
        s=s+2*c+1;
    }
   return c ;
}

int main()
{
    int i;
    printf("nb :");
    scanf("%d",&i);
    i=racine(i);
    printf("%d\n",i);
}
