#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "graph.h"
#include "disjoint.h"
#include "kruskal.h"
#include "inout.h"

int main(int argc, char* argv[]) {
    assert(argc==2);
    int N = atoi(argv[1]);
    int i, j;
    int** points = calloc(N, sizeof(int *));
    for (i = 0; i < N; i++) {
      points[i] = calloc(2, sizeof(int));
    }
    // [[int*],[int*],[int*]]
    // [x,y] [x,y] [x,y] 
    // generer n points
    for (i = 0; i < N; i++) {
      points[i][0] = rand()%1000;
      points[i][1] = rand()%1000;
    }
    graph g_complet = random_graph(N,1);
    g_complet.wt = calloc(N, sizeof(double*));
    for (i = 0; i < N; i++) {
      g_complet.wt[i] = calloc(N, sizeof(double));
    }
    for (i=0; i < N; i++) {
      for (j=i+1; j < N; j++) {
        g_complet.wt[i][j] = sqrt(pow(points[i][0]-points[j][0],2) +
                            pow(points[i][1]-points[j][1],2));
        g_complet.wt[j][i] = sqrt(pow(points[i][0]-points[j][0],2) +
                                  pow(points[i][1]-points[j][1],2));
      }
    }
    //draw_graph_wt(g_complet, "kruskal_test");
    edge_t* t = kruskal(g_complet);
    /* print_arr_edge(kruskal(g_complet), (N-1)); */
    // frees
    for (i = 0; i < N; i++) {
      free(g_complet.wt[i]);
    }
    free(g_complet.wt);
    free(t);
    free_graph(g_complet);
    for (i = 0; i < N; i++) {
      free(points[i]);
    }
    free(points);

    return 0;
}
