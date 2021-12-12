#include "kruskal.h"
#include "graph.h"

int comp_edge(const void * p1, const void * p2) {
  /* printf("p1->%f\n",((edge_t *)p1)->wt); */
  /* printf("p2->%f\n",((edge_t *)p2)->wt); */
  /* printf("p1-p2->%f\n",((edge_t *)p1)->wt -((edge_t *)p2)->wt); */
  double res = ((edge_t *)p1)->wt -((edge_t *)p2)->wt;
  //printf("diff %f ?= %d\n", res, (int)res);
  return res;
}

graph edge_arr_to_graph(edge_t* edges, int nbs) {
  graph res = create_graph(nbs);
  res.wt = calloc(nbs, sizeof(double*));
  for (int i = 0; i < nbs; i++) {
    res.wt[i] = calloc(nbs, sizeof(double));
  }
  for (int i = 0; i < nbs-1; i++) {
    res.mat[edges[i].i][edges[i].j]= 1;
    res.mat[edges[i].j][edges[i].i]= 1;
    res.wt[edges[i].i][edges[i].j]= edges[i].wt;
    res.wt[edges[i].j][edges[i].i]= edges[i].wt;
  }
  return res; 
}

graph kruskal(graph g) {
  int ordre_g = g.nbs;
  edge_t * edges =  calloc((ordre_g*(ordre_g-1))/2, sizeof(edge_t));;
  size_t nmemb_edge = 0;
  int i,j;
  for (i=0; i < ordre_g; i++) {
    for (j=i+1; j < ordre_g; j++) {
      if (g.mat[i][j]) {
        edges[nmemb_edge].i = i;
        edges[nmemb_edge].j = j;
        edges[nmemb_edge].wt = g.wt[i][j];
        nmemb_edge++;
      }
    }
  }

  /* print_arr_edge(edges,nmemb_edge); */
  edges = realloc(edges, nmemb_edge*sizeof(edge_t));
  /* print_arr_edge(edges,nmemb_edge); */
  qsort(edges, nmemb_edge, sizeof(edge_t), comp_edge);
  /* printf("sorted\n"); */
  /* print_arr_edge(edges, nmemb_edge); */
  /* printf("\n"); */
  disjoint* t = calloc(ordre_g, sizeof(disjoint));
  for (i = 0; i < ordre_g ; i++)
      t[i] = singleton(i);

  disjoint tmp1, tmp2;
  int m = 0;
  int x, y;
  edge_t * edges_res = calloc(g.nbs-1, sizeof(edge_t));
  while (ordre_g > 1) {
    x = edges[m].i;
    y = edges[m].j;
    if ((tmp1 = rep(t[x])) != (tmp2 = rep(t[y]))) {
        edges_res[g.nbs-ordre_g] = edges[m];
        reunion(tmp1, tmp2);
        ordre_g--;
    }
    m++;
  }
  free(edges);
  for (i = 0; i < g.nbs ; i++)
      free(t[i]);
  free(t);
  return edge_arr_to_graph(edges_res, g.nbs);
}
