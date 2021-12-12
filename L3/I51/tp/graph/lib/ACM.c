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

edge* graph2edge(graph g, int nb_edge,int* cpt){
 //return a tab of the edge with their weight
 edge* res= calloc(nb_edge, sizeof(edge));
 for (int i=0; i<g.n; i++) {
   for (int j=i+1; j<g.n; j++) {
      res[*cpt].i=i;
      res[*cpt].j=j;
      res[*cpt].w=g.W[i][j];
      cpt++;
   }
 }
 return res;
}

graph kruskhal(graph g){
   //Return an ACM in the form of a graph 
  graph res = create_graph(g.n);int cpt=0;
  int nb_edge=(g.n*(g.n-1))/2;
  edge* l_edge=graph2edge(g,nb_edge,&cpt);
  l_edge = realloc(l_edge, cpt*sizeof(edge));
  qsort(l_edge,cpt,sizeof(edge), &cmp);
  set* s_vertex=calloc(g.n, sizeof(set));
  for (int i=0; i<g.n; i++) {
    s_vertex[i]=singleton(i);
  }
  edge* alt_res=calloc(nb_edge, sizeof(edge));
  cpt=0;
  int x,y;set a,b;
  int Gn=g.n;
  while (Gn>1) {
    x = l_edge[cpt].i;
    y = l_edge[cpt].j;
    a=rep(s_vertex[x]);
    b=rep(s_vertex[y]);
    if (a!=b) {
      Union(a, b);
      alt_res[Gn-cpt]=l_edge[cpt];
      Gn--;
    }
    cpt++;
  }
  free(s_vertex);
  free(l_edge);
  return res;
}

