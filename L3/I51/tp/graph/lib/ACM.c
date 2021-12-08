#include "ACM.h"
#include "graph.h"
#include "list.h"
#include "set.h"
#include <stdlib.h>
/*
 *KRUSKAL( G, w )
 *pour chaque sommet s
 *singleton ( s )
 *r ← 0
 *pour chaque arete xy par ordre croissant
 *   si representant (x) != representant (y)
 *      alors Union( x , y )
 *   fsi
 *r←r+w( xy )
 *retourner r
 */

static int cmp(const void *p1, const void *p2)
{
  double res = ((edge *)p1)->w -((edge *)p2)->w;
  return res;
}

edge* graph2edge(graph g, int nb_edge){
 //return a tab of the edge with their weight
 edge* res= calloc(nb_edge, sizeof(edge));
 for (int i=0; i<g.n; i++) {
   for (int j=i; j<g.n; j++) {
      res[i].i=i;
      res[i].j=j;
      res[i].w=g.W[i][j];
   }
 }
 return res;
}

graph kruskhal(graph g){
   //Return an ACM in the form of a graph 
  graph res = create_graph(g.n);
  int nb_edge=(g.n*(g.n-1))/2;
  edge* l_edge=graph2edge(g,nb_edge);
  qsort(l_edge,nb_edge,sizeof(edge), &cmp);
  set* s_vertex=calloc(g.n, sizeof(set));
  for (int i=0; i<g.n; i++) {
    s_vertex[i]=singleton(i);
  }
  edge* alt_res=calloc(nb_edge, sizeof(edge));
  int cpt=0;
  int x,y;set a,b;
  for (int i=0; i<nb_edge; i++) {
    x = l_edge[i].i;
    y = l_edge[i].j;
    if ((a = rep(s_vertex[x])) != (b = rep(s_vertex[y]))) {
      alt_res[cpt]=l_edge[i];
      cpt++;
      Union(a, b);
     }
  }
  free(s_vertex);
  free(l_edge);
  return res;
}

