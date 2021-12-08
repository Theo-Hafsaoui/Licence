#include "graph.h"
#include "eulerian.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * In graph theory, an Eulerian trail (or Eulerian path) is a trail
 * in a finite graph that visits every edge exactly once 
 * cf: https://en.wikipedia.org/wiki/Eulerian_path
 */

int eulerian(int* v,graph g){
  /*
  *Search the number of odd vertex
  *indeed we know that if their is 2 odd
  *vertex the graph is semi-eulerian and 0 is Eulerian(a cycle)
  *otherwise it's not Eulerian
  *
  *return 2 if it's Eulerian
  *1 if sem-eulerian
  *0 otherwise
  */
  int nb_odd=0;
  for (int i=0; i<g.n; i++) {
    if(!(degree(g, i)%2))
      nb_odd++;
  }
  switch (nb_odd) {
    case 0:
      return 2;
    case 2:
      return 1;
    default:
      return 0;
  }
}
