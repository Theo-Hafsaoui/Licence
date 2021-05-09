#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define True 1
#define False 0
#define N 7

typedef unsigned int uint;
typedef struct {
    uint n;
    int *arr;
} list;

unsigned long long comp = 0;


void print_list(list L) {
    printf("[");
    for (int i = 0; i < (L.n)-1; i++) {
        printf("%d,", L.arr[i]);
    }
    printf("%d]\n", L.arr[L.n-1]);
}

void swap (int *arr, uint i, uint j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void gen_perm(list L) {
    uint tmp;
    for (uint i = 0; i < L.n; i++) {
        tmp = rand()%(L.n - i) + i;
        swap(L.arr, i, tmp);    
    }
}

void free_list (list L) {
    free(L.arr);
}


unsigned long long fact (uint n) {
    unsigned long long res = 1;
    while (n) {
        res *= n;
        n--;
    }
    return res;
}

uint partition (list L, uint p, uint r) {
    int i = p, j = r, pivot = L.arr[p];
    while (L.arr[j] > pivot) {
        comp++;
        j--;
    }
    while (i < j) {
        swap(L.arr, i, j);
        do {
            i++;
            comp++;
        } while (L.arr[i] < pivot);
        do {
            j--;
            comp++;
        } while (L.arr[j] > pivot);
    }
    return j;
}

int is_sorted (list L) {
    int i = 1;
    while (i < L.n && L.arr[i-1] < L.arr[i]) 
        i++;
    comp += i;
    return (i == L.n);
}

void quick_sort(list L, uint p, uint r) {
    if (p == 0 && r == L.n -1) 
        gen_perm(L);
    if (p < r) {
        int q = partition(L, p, r);
        quick_sort(L, p, q);
        quick_sort(L, q+1, r);
    }
}

void quick_sort_v2(list L, uint p, uint r) {
    //if (p == 0 && r == L.n -1) 
    //    gen_perm(L);
    if (p < r) {
        int q = partition(L, p, r);
        if (!is_sorted(L)){
            quick_sort(L, p, q);
            quick_sort(L, q+1, r);
        }
    }
}

void main () {
    srand(time(NULL));
    //list L = gen_perm(5);
    //int arr[5] = {2,1,3,4,0};
    //list L = {5, arr};
    //print_list(L);
    //int j = partition_v2(L, 0, 4);
    //printf("is sorted? %d\n", is_sorted(L));
    //quick_sort(L, 0, 4);
    //printf("is sorted? %d\n", is_sorted(L));
    //printf("j = %d\n", j);
    //print_list(L);
    
    uint arr[N];  
    for (int i = 0; i<N; i++) {
        arr[i] = i+1;
    }
    list L = {N, arr};
    unsigned long long fact_n = fact(N);
    FILE *file = fopen("quicksort.txt", "w");
    for (unsigned long long i = 0; i < fact_n; i++) {
        gen_perm(L);
        quick_sort(L, 0, N-1);
        fprintf(file, "%lld\n", comp);
    }
    fclose(file);
    /*
    comp = 0;
    print_list(L);
    //for (int i = 0; i < fact_n; i++) {
    //    gen_perm(L);
    quick_sort_v2(L, 0, N-1);
    //}
    printf("quick v2 did an average of %lld comparisons\n",comp);
    */
}

