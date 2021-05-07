#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define N 50


typedef unsigned int uint;
unsigned int comp;

void print_tas(int *arr, unsigned int n) {
    int depth = floor(log(n)/log(2));
    int k = 0, mid;
    for (int j = 0; j <= depth; j++) {
        for (int i = 0; i < pow(2,depth-j) - 1; i++) {
            printf(" ");
        }

        for(int l = 0; k < n && l < pow(2,j); l++) {
            printf("%d", arr[k]);
            k++;
            for (int i = 0; i < pow(2,depth-j+1)-1; i++) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void tamiser(int *arr, unsigned int i, unsigned int n) {
    /* 
     ***NAIF ALGO***

    int iright_child = i*2+1;
    int ileft_child = i*2+2;
    print_tas(arr,14);

    if (ileft_child <= n) {
        if (arr[iright_child] < arr[ileft_child] && arr[ileft_child] > arr[i]) {
            swap(arr,ileft_child, i);
            tamiser(arr, ileft_child, n);
        } else if (arr[iright_child] > arr[i]){
            swap(arr, iright_child, i);
            tamiser(arr, iright_child, n);
        }
    }
    else if (iright_child <= n && arr[iright_child] > arr[i]) {
        swap(arr, iright_child, n);
    }
    */
    //print_tas(arr,14);
    int child = 2*i+1;
    if (child < n && arr[child+1] > arr[child]) 
        child += 1;
    if (child <= n && arr[child] > arr[i]) {
        comp += 2;
        swap(arr, child, i);
        tamiser(arr, child, n);
    }
}

unsigned int* gen_perm(uint n) {
    uint *new_arr = (uint *) malloc(sizeof(uint)*n);
    for (int i = 0; i<n; i++) {
        new_arr[i] = i;
    }
    uint tmp;

    for (uint i = 0; i < n; i++) {
        do {
            tmp = rand() % n;
        } while (tmp < i);
        swap(new_arr, i, tmp);    
    }
    return new_arr;
}

void entasser(int *arr, unsigned int n) {
    int node = n/2 - 1;
    while (node >= 0) {
        //printf("---->%d\n", node);
        //print_tas(arr,n);
        tamiser(arr, node, n-1);
        node--;
    }
}

void tri_tas(int *arr, unsigned int n) {
    entasser(arr, n);
    //print_tas(arr, n);
    for (int i = n-1; i > 0; i--) {
        swap(arr, 0, i);
        tamiser(arr, 0, i-1);
    }
}

uint fact (uint n) {
    uint res = 1;
    while (n) {
        res *= n;
        n--;
    }
    return res;
}
    
void main(int argc, char **argv) {
    //int liste[] = {0,1,2,3,4,5,6,7,8,9};
    //print_tas(liste, 10);
    //entasser(liste, 9);
    //print_tas(liste, 10);
    //tri_tas(liste, 10);
    //print_tas(liste, 10);
    unsigned int cte = N*(log(N)/log(2));
    unsigned long nlogn = cte;
    uint fact_n = fact(N);
    srand(time(NULL));
    FILE *file = fopen("tris_tas", "w");
    for (int i = 0; i < atoi(argv[1]); i++) {
        uint* tab = gen_perm(N);
        tri_tas(tab, N);
        fprintf(file, "%ld %d\n", nlogn, comp);
        nlogn += cte;
        free(tab);
    }
    fclose(file);
}

