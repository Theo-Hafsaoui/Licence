#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


double Power(float x, ulong n,int *cpt){
    double r=1;
    if (n==0)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        r=r*x;
        *cpt=*cpt +1;
    }
    return r;}

void reverse(float *t,int n){
    float tmp;int i =0;
    while(i<n-1)
    {
        tmp=t[i];
        t[i++]=t[n];
        t[n--]=tmp;
    }
}

float EvalN(float *p, float a,int n,int *cpt){
    float res=p[0];
    float atemp =a;
    for (int i = 1; i < n; i++)
    {
        res = res + p[i]*Power(a,i,cpt);
    }
    return res;
}

double SM(float x, uint n,int *cpt)
{
	double res = 1;
	while(n != 0)
	{
		if (n & 1)
			res *= x;
            *cpt=*cpt+1;
		x *= x;
        *cpt=*cpt+1;
		n >>= 1;
	}
	return res;
}

void swapp(float *a,float *b){
    float temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

float EvalSM(float *p, float a,int n,int *cpt){
    float res=p[0];
    float atemp =a;
    for (int i = 1; i < n; i++)
    {
        res = res + p[i]*SM(a,i,cpt);
    }
    return res;}

float EvalH(float *p, float a,int n,int *cpt){
    int res=0;
    for (int i = 1; i < n+1; i++)
    {
        res = res*a+p[n-i];
        *cpt=*cpt+1;
    }
    return res;
}

float *CP(float *t,uint n){
    srand(time(NULL));
    float temp;
    for (int i = 0; i < n; i++)
    {
        temp=(rand()%1000);
        t[i]=temp;
    }
   return t;
}

void affiche(float *a,int n){
    printf("tab =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%f,",a[i]);
    }
    printf("%f",a[n-1]);
    printf("]\n");
}

int main()
{
    for (int len = 0; len < 560; len++)
    {
    printf("-------------\n");
    float p[len];
    CP(p,len);
    printf("-------------\n");
    int cpt=0;
    float res;
    res = EvalSM(p,3,len,&cpt);
    printf("degre =%d  |",len);
    printf("%d  |", cpt);
    cpt=0;
    res = EvalN(p,3,len,&cpt);
    printf("%d  |", cpt);
    cpt = 0;
    res = EvalH(p,3,len,&cpt);
    printf("%d |\n",res, cpt);}
}