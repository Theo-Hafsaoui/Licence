#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

graph create_graph(int x){
//Creat a square matrix of lenght x
  graph n_graph;
  n_graph.n=x;
  n_graph.T=calloc(x, sizeof(int*));
  for (int i=0; i<x; i++) {
    n_graph.T[i]=calloc(x, sizeof(int));
  }
  return n_graph;
}

void free_graph(graph g){
//Free a graph creat throught create_graph
  for (int i=0; i<g.n; i++) {
    free(g.T[i]);
  }
  free(g.T);
} 
