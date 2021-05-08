#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define True 1
#define False 0

typedef unsigned int uint;
typedef unsigned long long ullong;

void swap(uint *arr, uint i, uint j) {
    uint tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void print_array(uint *arr, uint n) {
    printf("[");
    for (uint i = 0; i < n-1; i++) {
        printf("%d,", arr[i]);
    }
    printf("%d]\n", arr[n-1]);
}

void create_arr(uint *arr, uint n) {
    for (uint i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void copy_arr(uint *arr, uint *new_arr, uint n) {
    for (uint i = 0; i < n; i++) {
        new_arr[i] = arr[i];
    }
}

uint* gen_perm(uint n) {
    uint *new_arr = (uint *) malloc(sizeof(uint)*n);
    create_arr(new_arr, n);
    uint tmp;

    for (uint i = 0; i < n; i++) {
        do {
            tmp = rand() % n;
        } while (tmp < i);
        swap(new_arr, i, tmp);    
    }
    return new_arr;
}

uint idx_min(int *arr, uint a, uint b) {
    uint min = arr[a], min_idx = a;
    for (uint i = a+1; i < b+1; i++) {
        if (min > arr[i]) {
            min = arr[i];
            min_idx = i;
        }
    }
    return min_idx;
}
        
ullong selection_sort(int *arr, uint n) {
    int *new_arr = (int *) malloc(sizeof(int)*n);
    copy_arr(arr, new_arr, n);
    int tmp;
    ullong comp = 0;
    for (uint i = 0; i < n; i++) {
        tmp = idx_min(new_arr, i, n-1);
        swap(new_arr, i, tmp);
        comp += (n-i);
    }
    free(new_arr);
    return comp;
}

ullong buble_sort(int *arr, uint n) {
    int *new_arr = (int *) malloc(sizeof(int)*n);
    copy_arr(arr, new_arr, n);
    uint i = 0;
    ullong comp = 0;
    int flag = True;
    while (i < n && flag) {
        flag = False;
        for (uint j = 1; j < (n-i); j++) {
            if (new_arr[j-1] > new_arr[j]) {
                swap(new_arr, j-1, j);
                flag = True;
            }
            comp += 1;
        }
        i++;
    }
    free(new_arr);
    return comp;
}

ullong insertion_sort(int *arr, uint n) {
    int *new_arr = (int *) malloc(sizeof(int)*n);
    copy_arr(arr, new_arr, n);
    ullong comp = 0;
    for (uint i = 1; i < n; i++) {
        for (uint j = i; j > 0 && new_arr[j-1] > new_arr[j]; j--) {
            swap(new_arr, j-1, j);
            comp += 1;
        }
    }
    free(new_arr);
    return comp;
}
            
ullong fact(uint n) {
    ullong res = 1;
    for (int i = 2; i < n; i++) {
        res *= i;
    }
    return res;
}


void main(int argc, char **argv) {
    uint limit = atoi(argv[1]);
    uint n = 1000;
    ullong fact_n = fact(n), comp_sel = 0, comp_bub = 0, comp_ins = 0;
    uint *arr;
    srand(time(NULL));

    FILE *file = fopen("tris_imp", "w");

    for (uint i = 0; i < limit; i++) {
        arr = gen_perm(n);

        comp_sel += selection_sort(arr, n);

        comp_bub += buble_sort(arr, n);

        comp_ins += insertion_sort(arr, n);

        free(arr);

        fprintf(file, "%llu %llu %llu\n", comp_sel, comp_bub, comp_ins); 

    }
    fclose(file);
}
    
