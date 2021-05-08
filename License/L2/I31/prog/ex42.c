#include <stdio.h>
#include <stdlib.h>
int main(){
    double pi =3.14159265358979323846;
    double d;
    printf("rayon= ");
    scanf("%lf", &d);
    d=(2*pi)*d;
    printf("Donc le perimetre = %lf",d);
}