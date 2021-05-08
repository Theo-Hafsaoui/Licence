#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned int uint;

char* l2s(unsigned int* arr, int n);
unsigned int* s2l(char* ch);
int print_array(int* arr, int n);


unsigned int* add(unsigned int* A, int na, unsigned int* B, int nb, unsigned int base) {
    int tmp, *temp, carry = 0;
    if (na < nb) {
        tmp = na;
        na = nb;
        nb = tmp;

        temp = A;
        A = B;
        B = temp;
    } 
    unsigned int* res = (unsigned int *) malloc(sizeof(unsigned int) * na+1); 
    for (int i = 0; i < nb; i++) {
        tmp = carry + A[i] + B[i];
        if (tmp >= base) {
            carry = 1;
            tmp %= base;
        } else {
            carry = 0;
        }
        res[i] = tmp; 
    }
    for (int i = nb; i < na + 1; i++) {
        tmp = A[i] + carry;
        if (tmp >= base) { 
            tmp %= base;
            carry = 1;
        } else {
            carry = 0; 
        }
        res[i] = tmp;
    }
    return res;
}
        
uint* mult(uint* A, int na, uint* B, int nb, uint base) {
    unsigned int* res = (unsigned int*) malloc(sizeof(uint)*(na+nb));
    uint carry = 0, tmp;
    for (int i = 0; i < na; i++) {
        int j = 0;
        for (; j < nb; j++) {
            tmp = res[i+j] + A[i] * B[j] + carry;
            if (tmp >= base) {
                carry = tmp / base;
                tmp %= base;
            } 
            else {
                carry = 0;
            }
            res[i+j] = tmp;
        }
        if (carry) 
        {
            res[i+j] = carry;
            carry = 0;
        }
        
        
    }
    return res;
}    
    

void main (int argc, char** argv) {
    char* a_str = argv[1];
    char* b_str = argv[2];
    uint len_a = strlen(argv[1]);
    uint len_b = strlen(argv[2]);
    uint base = atoi(argv[3]);
    int max = len_b > len_a ? len_b : len_a;
    printf("add ->%s\n", l2s(add(s2l(a_str), len_a, s2l(b_str), len_b, base), max + 1));
    printf("mult ->%s\n", l2s(mult(s2l(a_str), len_a, s2l(b_str), len_b, base), len_a + len_b));
}


