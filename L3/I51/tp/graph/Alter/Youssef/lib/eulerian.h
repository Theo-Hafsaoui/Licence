#ifndef EULERIEN_H
#define EULERIEN_H
#include "list.h"
int pre_eulerian(int *s, graph g);
int next_neigh(graph g, uint s);
list_t quick_stroll(graph* g, uint s);
list_t eulerian_path(graph g_copy, uint s) ;
list_t eulerian(graph g);
void draw_eulerian(graph g, char * filename) ;
#endif
