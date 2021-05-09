#include<stdio.h>
int main(){
    printf(fact(0));

}
int fact(n){
    if (n==0){
        return 1;
    }
    int i,s;
    s=n;
    i=n;
    while (i>0){
        i--;
        s+=s*i;
    }
    return s;
}