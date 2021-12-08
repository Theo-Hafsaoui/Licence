#ifndef ACM_H
#define ACM_H
#include "set.h"
#include "graph.h"
#include "list.h"

typedef struct {
  int i,j;
  double w;
}edge;

edge* graph2edge(graph g,int nb_edge);
graph kruskhal(graph g);
list approximation(graph g,int s);

#endif
