#include <stdlib.h>
#include <stdbool.h> 

#include "graph.h"
#include "binary.h"

graph create_graph(int n) {
    graph res; int i;
    res.nbs = n;
    res.mat = calloc(n, sizeof(int *));
    for(i = 0; i < n; i++)
        res.mat[i] = calloc(n,sizeof(int));
    return res;
}

graph copy_graph(graph g) {
  graph res = create_graph(g.nbs);
  for(int i = 0; i < g.nbs; i++) {
    for(int j = (i+1); j < g.nbs; j++) {
      res.mat[i][j] = res.mat[j][i] = g.mat[i][j];
    }
  }
  return res;
}

void free_graph(graph g) {
    for (int i = 0; i < g.nbs; i++)
        free(g.mat[i]);
    free(g.mat);
}

graph random_graph(int n, float p) {
    graph res = create_graph(n);
    double threshold = p*RAND_MAX;
    for(int i = 0; i < n; i++) {
        for (int j = (i+1); j < n; j++) {
            if (random() < threshold)
                res.mat[i][j] = res.mat[j][i] = 1;

        }
    }
    return res;
}

uint degree(graph g, uint s) {
    uint res = 0;
    for(int i = 0; i < g.nbs; i++) {
        if (g.mat[s][i] == true)
            res++;
    }
    return res;
}
void print_mat(graph g) {
    for(int i = 0; i < g.nbs; i++) {
        printf("[");
        for(int j = 0; j < (g.nbs-1); j++) 
            printf("%d,",g.mat[i][j]);
        printf("%d]\n", g.mat[i][g.nbs-1]);
    }
}

void print_edge(edge_t edge) {
    printf("%d---%f----%d\n", edge.i, edge.wt, edge.j);
}

void print_arr_edge(edge_t * edges, size_t nmemb) {
    for (int i = 0; i < nmemb; i++) {
        print_edge(edges[i]);
    }
}


//graph hypercube(int) {
//  graph res - create_graph()
//}
