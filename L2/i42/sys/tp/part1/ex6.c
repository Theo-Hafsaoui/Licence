#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>


void affiche(uchar *a,int n){
    printf("uchar =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int t1[argv[1]]={};
    int t2[argv[1]]={};
    int r = rand();
    return 0;
}