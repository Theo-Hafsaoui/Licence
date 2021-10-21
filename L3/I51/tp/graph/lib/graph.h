#ifndef GRAPH_H
#define GRAPH_H


typedef struct{
  int n;
  int **T;
}graph;

graph create_graph(int);
void free_graph(graph);
graph random_graph(int, float);


#endif
