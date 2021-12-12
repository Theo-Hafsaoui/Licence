#ifndef TSP_H
#define TSP_H
#include <stdbool.h>

#include "graph.h"
#include "stdlib.h"
void browse_acm(graph g, int s);
int * possible_tsp_sol(graph g, int s);
#endif
