#ifndef ACM_H
#define ACM_H
#import "set.h"
#import "graph.h"

typedef struct {
  int i,j;
  double w;
}edge;

edge* graph2edge(graph g);
edge* kruskhal(graph g);

#endif
