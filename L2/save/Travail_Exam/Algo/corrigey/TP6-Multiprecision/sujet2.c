#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int* s2l (char* ch) { 
    int n = strlen(ch);
    int* array = (int *) malloc(sizeof(int)*n); 
    for (int i = 0; i < n; i++) {
        array[i] = (int) ch[n-i-1] - 48;
    }
    return array; 
}

char* l2s (unsigned int* arr, int n) {
    char* ch = (char *) malloc(sizeof(char)*n);
    for (int i = 0; i < n; i++) {
        ch[i] = arr[n-1-i] + 48;
    }
    return ch;
}


void print_array(int* arr, unsigned int n) {
    printf("[");
    for (int i = 0; i < n-1; i++) {
        printf("%d,", arr[i]);
    }
    printf("%d]\n", arr[n-1]);
}


