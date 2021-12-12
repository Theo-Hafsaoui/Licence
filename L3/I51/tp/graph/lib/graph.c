#include "graph.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

graph create_graph(int x){
//Creat a square matrix of lenght x
  graph n_graph;
  n_graph.n=x;
  n_graph.T=calloc(x, sizeof(int*));
  for (int i=0; i<x; i++) {
    n_graph.T[i]=calloc(x, sizeof(int));
  }
  return n_graph;
}

void free_graph(graph g){
//Free a graph created throught create_graph
  for (int i=0; i<g.n; i++) {
    free(g.T[i]);
  }
  free(g.T);
} 


graph rand_graph(int x, float p) {
  graph res=create_graph(x);
  srand(time(NULL));
  int flag=0;
  double MOL = p*RAND_MAX;
      for(int i = 0; i < x; i++) {
        flag=1;
        for (int j = (i+1); j < x; j++) {
          if (rand() < MOL){
                res.T[i][j] = res.T[j][i] = 1;
                flag=0;
            }
            if (flag) {
              res.T[i][0]=1;
            }
          }
    }
    return res;
}

int degree(graph g,int vertex_i){
  int res=0;
  for (int i=0; i<g.n; i++) {
    if(g.T[vertex_i][i]){
      res++;
    }
  }
  return res;
}

int is_cycle(graph g){
  int* trace=calloc(g.n, sizeof(int));
  int* done=calloc(g.n, sizeof(int));
  int v;
  for (int i=0; i<g.n; i++){
    done[i]=-42;
  }
  stack current=NULL;
  for (int i=0; i<g.n; i++) {
      push(&current, i);
      if(trace[i]==0){
        done[v]=v;
        while (current) {
          v=pop(&current);
          trace[v]=1;
          for (int j=0; j<g.n; j++) {
            if(g.T[v][j]&&trace[j]==0){
              push(&current, j);
              done[j]=v;trace[j]=1;
            }
            else if (g.T[v][j]&&trace[j]==1&&done[v]!=j) {
              return 1;
            }
          }
      }
    }
    trace[i]=2;
  }
  return 0;
}

