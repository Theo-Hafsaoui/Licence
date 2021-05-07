#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

ulong fact(ulong n){
    ulong s=1;
    for (int i = 0; i < n; i++)
    {
        s=s*(n-i);
    }
    return s;
}


uint *S2L(char *chaine,uint *t){
    int len=strlen(chaine);char tmp;
    for (int i = -1; i < len; i++)
    {
        t[i]=((chaine[len-i])-48);
    }
    return t;
}

affiche(uint *a,int n){
    printf("uchar =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

int main(int argc, char const *argv[])
{
    printf("\n-----------------\n");
    char c[] = "432";
    uint t[3];
    S2L(c,t);
    affiche(t,3);
    return 0;
}
