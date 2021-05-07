#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {False=0,True}boul;
typedef unsigned long long ullong;
typedef unsigned char uchar;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex1

void affiche(uchar *a,int n){//Lecture naturel -> a[n-i]
    printf("tab =[");
    for (int i = 1; i < n; i++)
    {
        printf("%d,",a[n-i]);
    }
    printf("%d]\n",a[0]);
}

int Increment(uchar * t, uchar n, uchar b){
    for (int i = 0; i < n; i++)
    {
        if (t[i]!=b-1)
        {
            t[i]+=1;
            return i;
        }
        t[i]=0;
    }
    return n;
}

int TabIsNotNull(uchar *t,int n){
    for (int i = 0; i < n; i++)
    {
        if (t[i]!=0)
        {
            return 1;
        }
    }
    return 0;
}

void initTabNull(uchar *t,int n){
    for (int i = 0; i < n; i++)
    {
        t[i]=0;
    }
}

ullong test(uchar n, uchar b){//Prend en paremtre une valeur null
    uchar *t=(uchar*)malloc(n*sizeof(uchar));
    initTabNull(t,n);
    ullong s=0;
    do
    {
        s+= Increment(t,n,b);
        //affiche(t,n);
    } while (TabIsNotNull(t,n));
    return s;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex1
boul BeginWith(char *ch,char *bg){//bg ne peut pas etre plus grand que ch
    int lench=strlen(ch);
    int lenbg=strlen(bg);
    for (int i = 0; i < lench && i<lenbg; i++)
    {
       if (ch[i]!=bg[i])
       {
           return False;
       }
    }
    return True;
}

boul BienPar(char *ch){
    int n=strlen(ch);
    int cpt=0;
    for (int i = 0; i < n && cpt>=0; i++)
    {
        if (ch[i]=='(')
        {
            cpt++;
        }
        else if (ch[i]==')')
        {
            cpt--;
        }
    }
    printf("cpt=%d\n",cpt);
    return cpt==0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char const *argv[])
{
    //uchar t[5]={9,9,9,9,9};
    //Increment(t,5,10);
    //ullong Smodif=test(2,10);
    //printf("Le nombre de modif est = %lu",Smodif);
    //boul a= BeginWith(argv[1],argv[2]);
    boul a=BienPar(")2(+(3−1)");
    printf("%d",a);
    return 0;
}

