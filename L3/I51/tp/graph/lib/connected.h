#ifndef CONNECTED_H
#define CONNECTED_H
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
/*
 *Library on connected graph ex:
 * 0---0----0
 * nb_components is 3
 */

typedef unsigned int uint;

uint nb_components(graph g);
uint balade(uint s, graph g);
uint giant_component(graph g);

#endif
