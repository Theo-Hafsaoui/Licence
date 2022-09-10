#include "graph.h"
#include "connected.h"
#include <stdlib.h>
uint* trace;

uint balade(uint s, graph g){
//Goes throught the vertix of a compenent
//and mark them, furthermore it return the
//number of vertix in a component.
  uint vertix=1;
  trace[s]=1;
  for (int i=0; i<g.n; i++) {
    if(g.T[s][i] && !(trace[i]))
      vertix+=balade(i, g);
  }
  return vertix;
}

uint nb_components(graph g){
//Return the number of a component in a graph
//the type of graph is matrix
  trace=calloc(g.n, sizeof(uint));
  uint nb_comp=0;
  for (int i=0; i<g.n; i++) {
    if(!(trace[i])){
      balade(i,g);
      nb_comp++;
    }
  }
  free(trace);
  return nb_comp;
}

uint giant_component(graph g){
  //Return the number of vertix of the 
  //biggest component of the graph
  uint max_comp=0;uint Ibalade;
  trace=calloc(g.n, sizeof(uint));
  for (int i=0; i<g.n; i++) {
    if(!(trace[i])){
      Ibalade=balade(i,g);
      if (Ibalade>max_comp) {
        max_comp=Ibalade;
      }
  }}
  free(trace);
  return max_comp;
}
