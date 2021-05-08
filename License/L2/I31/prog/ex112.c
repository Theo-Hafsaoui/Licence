#include <stdio.h>
#include <stdlib.h>
void ex(int *a, int *b){
    int *temp;
    *temp=*a;
    *a=*b;
    *b=*temp;

}
int main(){
    int x,x2;
    x=1;
    x2=2;
    printf("x1 = %d, x2 =%d\n",x,x2);
    ex(&x,&x2);
    printf("x1 = %d, x2 =%d\n",x,x2);
}