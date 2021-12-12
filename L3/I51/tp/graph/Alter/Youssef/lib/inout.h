#ifndef INOUT_H
#define INOUT_H

#include "graph.h"

void write_graph(char* dst, graph g);
graph read_graph(char* src);
void draw_graph(graph g, char * filename);
void draw_graph_wt(graph g, char * filename);




#endif
