#ifndef GRAPH_H
#define GRAPH_H


typedef struct{
  int n;
  int **T;
}graph;

graph create_graph(int);
void free_graph(graph);
graph rand_graph(int, float);


#endif
