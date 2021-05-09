#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Calcule power du tp3

double NaifPower(float x,uint n){
    double res=1;
    for (int i = 0; i < n; i++)
    {
        res*=x;
    }
    return res;
}

double SMpower(float x,uint n){
    double res=1;
    while (n>0)
    {
        n = n >> 1;
        if (n & 1)
        {
            res = res * res;
        }
        res = res * x;
    }
    return res;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//ex1

float Eval_Naif(float *t, uint n, float a,int *cpt){
    float res=0;
    for (int i = 0; i < n; i++)
    {
        res+=t[i]*NaifPower((a),(n-i-1));
    }
    return res;
}

float Eval_SM(float *t, uint n, float a,int *cpt){
    float res=0;
    for (int i = 0; i < n; i++)
    {
        res+=t[i]*SMpower((a),(n-i-1));
    }
    return res;
}

float Eval_Horner(float *t, uint n, float a,int *cpt){
    float r=t[0];
    for (int i = 1; i < n; i++)
    {
        r=(r*a)+t[i];
    }
    return r;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char const *argv[])
{
    float t[4]={3,5,7};
    float res;int cpt=0;
    res=Eval_Horner(t,3,2,&cpt);
    printf("le polynome =%f\n",res);
    
    return 0;
}
