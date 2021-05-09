#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long ullong;

ullong factorielle (unsigned char n) {
    ullong res = 1;
    for (;  1 < n; n--) {
        res *= n;
    }
    return res;
}

unsigned char count_digits (ullong num) {
    unsigned char i = 0;
    while (num != 0) {
        num /= 10;
        i += 1;
    }
    return i;
}

void main(int argc, char** argv) {
    ullong resultat;
    printf("20! = %llu\n",resultat =  factorielle(20));
    printf("20! has %d digits\n", count_digits(resultat));
    printf("20! in binary will have %f digits", floor(log(resultat)/log(2)) + 1);
}

