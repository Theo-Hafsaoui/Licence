#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define N 1000

typedef struct {
    int n;
    int *arr;
} list;

unsigned long long comp = 0;

void min_max (list L, int *min, int *max) {
    *min = L.arr[0], *max = L.arr[0];
    for (int i = 0; i<L.n; i++) {
        if (L.arr[i] < *min) 
            *min = L.arr[i];
        else if (L.arr[i] > *max) 
            *max = L.arr[i];
        comp += 2;
    }
}

void swap (int *arr, uint i, uint j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void print (list L) {
    printf("[");
    for (int i = 0; i < L.n-1; i++) {
        printf("%d,",L.arr[i]);
    }
    printf("%d] n = %d\n", L.arr[L.n-1], L.n);
}

list histogramme (list L, int min, int max) {
    int *arr = (int *)calloc((max-min+1),sizeof(int));
    list H = {max-min+1, arr};
    for (int i = 0; i < L.n; i++) {
        H.arr[L.arr[i]-min]++;
        comp += 2;
    }
    return H;
}

void counting_sort (list L) {
    int k = 0, min, max;
    min_max(L, &min, &max);
    list H = histogramme(L, min, max);
    for(int i = 0; i < H.n; i++) {
        for (int j = 0; j < H.arr[i]; j++) {
            L.arr[k] = (i + min);
            j++, k++;
            comp += 2;
        }
    }
}
        
void gen_perm(list L) {
    uint tmp;
    for (uint i = 0; i < L.n; i++) {
        tmp = rand()%(L.n - i) + i;
        swap(L.arr, i, tmp);    
    }
}

int is_sorted (list L) {
    int i = 1;
    while (i < L.n && L.arr[i-1] <= L.arr[i]) 
        i++;
    return (i == L.n);
}

unsigned long long fact (uint n) {
    unsigned long long res = 1;
    while (n > 1) {
        res *= n;
        n--;
    }
    return res;
}

void main (int argc, char** argv) {
    /*
    int arr[10] = {0,91,2,3,-4,5,6,7,8,9};
    list L = {10, arr};
    int min, max;
    min_max(L, &min, &max);
    printf("min = %d, max = %d\n", min, max);
    print(L);
    print(histogramme(L, min, max));
    counting_sort(L);
    print(L);
    int arr[N];
    for (int i = 0; i < N; i++) 
        arr[i] = i+1;
    list L = {N, arr};
    for (int i = 0; i < atoi(argv[1]); i++) {
        gen_perm(L);
        counting_sort(L);
        assert(is_sorted(L));
    }
    */
    unsigned long long fact_n = fact(N);
    FILE *file = fopen("counting_sort.txt", "w");
    for (unsigned long long i = 2; i < N; i++) {
        int *arr = calloc(i, sizeof(int));
        for (int j = 0; j < i; j++) 
            arr[j] = j+1;
        list L = {i, arr};
        for (int j = 0; j < 50; j++) {
            gen_perm(L);
            counting_sort(L);
            assert(is_sorted(L));
        }
        free(L.arr);
        fprintf(file, "%lld\n", comp/50);
        comp = 0;
    }
}

