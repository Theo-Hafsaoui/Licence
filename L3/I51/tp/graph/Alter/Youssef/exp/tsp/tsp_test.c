#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "graph.h"
#include "disjoint.h"
#include "kruskal.h"
#include "inout.h"
#include "tsp.h"

float distance(int x_0, int y_0, int x_1, int y_1)
    return  sqrt(pow(x_0-x_1, 2) + pow(y_0-y_1, 2));

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
    graph res = kruskal(g_complet);
    int * approx = possible_tsp_sol(res, 0);
    int cost;
    int min_cost;
    int * min_approx;
    for (int i = 0; i < res.nbs; i++) {
        approx = possible_tsp_sol(res, i);
        cost = 0;
        for(int j = 1; j < res.nbs; j++) {
          cost += res.wt[approx[j-1]][approx[j]];
        }
        if (i==0) {
          min_cost = cost;
          min_approx = approx;
        }
        //printf("cost = %d, min_cost = %d\n", cost, min_cost);
        if (cost < min_cost) {
          min_approx = approx;
          min_cost = cost;
        }
    }

    for (int i = 1; i < res.nbs; i++) {
      int a_x = points[min_approx[i-1]][0];
      int a_y = points[min_approx[i-1]][1];
      int b_x = points[min_approx[i]][0];
      int b_y = points[min_approx[i]][1];
        for (int j = 1; j < res.nbs; j++) {
          int d_x = points[min_approx[j-1]][0];
          int d_y = points[min_approx[j-1]][1];
          int c_x = points[min_approx[j]][0];
          int c_y = points[min_approx[j]][1];
        }
    for(int i = 0; i < res.nbs; i++) {
      printf("%d ", points[min_approx[i]][0]);
      printf("%d\n", points[min_approx[i]][1]);
    }
    printf("%d ", points[min_approx[0]][0]);
    printf("%d\n", points[min_approx[0]][1]);
//    draw_graph_wt(res, "tsp_test");
    /* print_arr_edge(kruskal(g_complet), (N-1)); */
    // frees
    for (i = 0; i < N; i++) {
      free(g_complet.wt[i]);
    }
    free(g_complet.wt);
    free_graph(g_complet);
    for (i = 0; i < N; i++) {
      free(points[i]);
    }
    free(points);

    return 0;
}
