#include "graph.h"
#include "stack.h"
typedef unsigned int uint;
//unsigned int ensemble_color;
/* returns the number of solutions with k colors*/
uint n_colorable(graph g, uint k);

void block_neighborhood(uint colour, uint vertex,  graph g);

void unblock_neighborhood(uint col, uint vertex, graph g);

void coloring(uint vertex, graph g) ;


