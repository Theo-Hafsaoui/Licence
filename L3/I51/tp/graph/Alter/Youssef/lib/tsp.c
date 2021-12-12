#include "tsp.h"

int * track;
int * res;
int queue;
void browse_acm(graph g, int s) {
    track[s] = true;
    for (int t = 0; t < g.nbs; t++) {
        if(g.mat[s][t] && track[t] == false) {
            res[queue++] = t;
            browse_acm(g, t);
        }
    }
}
int* possible_tsp_sol(graph g, int s) {
  res = calloc(g.nbs, sizeof(int));
  track = calloc(g.nbs, sizeof(int));
  queue = 0;
  browse_acm(g, s);
  return res;
}

int*
