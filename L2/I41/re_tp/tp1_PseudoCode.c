#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {False=0,True}boul;
typedef unsigned uint;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex1
boul Palindindin(const char *ch){
    int n=strlen(ch);
    for (int i = 2; i < n/2; i++)
    {
        if (ch[i]!=ch[n-i])
        {
            return False;
        }
    }
    return True;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex2

void affiche(int *a,int n){
    printf("tab =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

void swapp(int *t,int a,int b){
    int temp=t[a];
    t[a]=t[b];
    t[b]=temp;
}

int i_max(int s,int *t,int n){
    int max=s;
    for (int i = s+1; i < n; i++)
    {
        if (t[i]>t[max])
        {
            max=i;
        }
    }
    return max;
}

void SelectSort(int *t,int n){
    int max;
    for (int i = 0; i < n; i++)
    {
        max = i_max(i,t,n);
        swapp(t,i,max);
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex3

uint PairOrNotBe(uint n){
    if (n%2==0)
    {
        return n/2;
    }
    return 3*n+1;
}

uint SireAccuse(uint n){
    int i=0;
    while (n!=1)
    {
        //printf("%d    u%d\n",n,i);
        n=PairOrNotBe(n);i++;
    }
    //printf("%d    u%d\n",n,i);
    return i;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char const *argv[])
{
    const char * ch=argv[1];
    boul tbool= Palindindin(ch);
    int t[5]={5,4,8,2,1,};
    SelectSort(t,5);
    affiche(t,5);
//    int s;
//    for (int i = 1; i < 1000; i++)
//    {
//        s=SireAccuse(i);
//        printf("%d      %d\n",i,s);
//    }
//    
//    return 0;
}
