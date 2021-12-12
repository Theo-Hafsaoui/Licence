#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
typedef unsigned int uint;
typedef struct {
    int nbs;
    int **mat;
    double **wt;
} graph;

typedef struct {
  int i, j;
  double wt;
} edge_t;


graph create_graph(int n);
void free_graph(graph g);
graph random_graph(int n, float p);
uint degree(graph g, uint s);
graph copy_graph(graph g);
void print_mat(graph g);
void print_edge(edge_t edge);
void print_arr_edge(edge_t * edges, size_t nmemb);
#endif
