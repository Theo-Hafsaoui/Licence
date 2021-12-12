#include "disjoint.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    assert(argc == 2);
    int N = atoi(argv[1]);

    disjoint t[N];
    for (int i = 0; i < N; i++)
        t[i] = singleton(i);

    srand(time(NULL));
    int graph_connected = 0;
    disjoint tmp1, tmp2;
    int m = 0;
    int i, j;
    while (graph_connected < N-1) {
        i = rand() % N;
        j = rand() % N;
        if ((tmp1 = rep(t[i])) != (tmp2 = rep(t[j]))) {
            reunion(tmp1, tmp2);
            graph_connected++;
        }
        m++;
    }
    printf("Graph order : %d\n", N);
    printf("Graph edges : %d\n", m);
    return 0;
}
