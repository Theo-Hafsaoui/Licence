#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  uint n;        
  int *valeurs;
} tliste;

void MinMax(int *l, int *min, int *max,int n){
    *min=l[0];
    *max=l[0];
    for (int i = 0; i < n; i++)
    {
        if(l[i]<*min){
            *min=l[i];
        }
        if(l[i]>*max){
            *max=l[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    int l[5]={1,2,3,4,5};
    int min;int max;
    MinMax(l,&min,&max,5);
    printf("min =%d et max =%d",min ,max);
    return 0;
}
