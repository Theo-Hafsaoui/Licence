#include <stdio.h>

void main()
{
    int b;
    scanf("%d\n",&b);
    int a=estparfait(b);
    printf("%d",a);
}
int SommeDesImpaire(n){
    int s=0;
    int i=1;
    for (i;i<n;i=i+2){
        s+=i;
    }
    return s;}

int puissance(x,n){
    if (n<=0){
        printf("erreur");
    }
    else{
        int i=0;
        int s=1;
        for(i;i<n;i++){
            s=s*x;
        }
    return s;
    }}

int estPremier(n){
    int i=2;
    if (n==1){
        return 0;
    }
    if (n<=0){
        return 0;
    }
    for (i;i<n;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}

void premierPremier(n){
    int i=0;
    int cpt=0;
    for (i;cpt<n;i++){
        if (estPremier(i)){
            printf("%d\n",i);
            cpt++;
        }
    }
}

int estDvisible(a,b){
    int r=a%b;
    return (r==0);

int estparfait(x){
    int s=0;
    int i=0;
    for (i;i<x;i++){
        if (estDvisible(x,i)){
            s+=i;
        }}
    return (s==x);
}