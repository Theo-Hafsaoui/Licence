#include "binary.h"
#include "stdio.h"

void print_binary(ullong num) {
    printf("%lld --> ", num);
    for (ullong i = 0; i < 64; i++) {
        printf("%d", (num & (ullong) 1<<(64-i-1)) > 0);
    }
    printf("\n");
}

uint wt(ullong num) {
    uint weight = 0;
    while(num){
        num &= num - 1;
        weight++;
    }
    return weight;
}
