#ifndef COLOR_H
#define COLOR_H
#include "graph.h"

typedef unsigned int uint;
int valid(int vertex,graph g, int* t_color,int i);
int color(graph g, int k,int* t_color,int vertex);
int k_colorable(graph g,uint k);


#endif
