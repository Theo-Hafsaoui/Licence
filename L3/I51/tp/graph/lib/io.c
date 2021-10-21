#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void w_graph(char* scr,graph g){
//Write a graph in G.data
//
//Nbs is the number the number of vertice 
//and each edge is describe with:
//number vertice: number vertice
  FILE* fl;
  fl= fopen(src,"w+");
  if (fl==NULL) {
    printf("Incorrect graph");
  }
  fprintf(fl, 'Nbs:%d\n',g.n);
}
