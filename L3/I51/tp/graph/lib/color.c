#include "graph.h"
#include "color.h"
#include <stdlib.h>
#include <stdio.h>

//####################################################################
//############################BACKTARCKING############################
//####################################################################
//See course and https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

int valid(int cpt_vertex,graph g, int* t_color,int i){
  /*See if for a vertex we did not already assigne 
   * the same color
   */
  for (int j=0; j<g.n; j++) {
    if((g.T[cpt_vertex][j])&&(i==t_color[j]))
      return 0;
  }
  return 1;
}

int color(graph g,int k,int* t_color,int cpt_vertex){
/*Return 1 if a graph g is coloarble with k color
 *else it return 0
 *
 *Use backtracking, in other word try a direction 
 *by using recursion and go back if this direction
 *doesn't work
 */
  if (g.n==cpt_vertex) {
    return 1;
  }
  for (int i=1; i<=k; i++) {
    if (valid(cpt_vertex,g,t_color,i)){
        t_color[cpt_vertex]=i;
        if(color(g,k,t_color,cpt_vertex+1))
          return 1;
        t_color[cpt_vertex]=0;
    }
  }
  return 0;
}
void printTab(int color[],graph g)
{
    for (int i = 0; i < g.n; i++)
        printf(" %d ", color[i]);
    printf("\n");
}


int k_colorable(graph g,uint k){
/*Main of the coloarble program
 */
  int* t_color= calloc(g.n, sizeof(int));
  if ((color(g,k,t_color,0))==0) {
    printf("No solution for %d colors...\n",k);
    return 0;
  }
  printf("solution find for %d colors...\n",k);
  printTab(t_color, g);
  fflush(stdout);
  return 1;
}
