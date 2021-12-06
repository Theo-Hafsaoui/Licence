#import "ACM.h"
#import "set.h"
#import "graph.h"
#import <stdlib.h>

static int cmp(const void *p1, const void *p2)
{
  return 0;
}

edge* graph2edge(graph g){
 //return  a tab of the edge with their wight
 edge* res= calloc(g.n, sizeof(edge));
 for (int i=0; i<g.n; i++) {
   int a=i;
   for (int j=i; j<g.n; j++) {
      res[i].i=i;
      res[i].j=j;
      res[i].w=j-i;
   }
 }
 return res;
}

edge* kruskhal(graph g){
  set res=singleton(g.n);
  
}
