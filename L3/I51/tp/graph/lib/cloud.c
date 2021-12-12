#include "cloud.h"
#include "graph.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* cloud(int n){
  //Create a cloud of point
  int* res=calloc(n*2, sizeof(int));
  for (int i=0; i<n; i+=2) {
    res[i]=((rand())%1000);
    res[i+1]=((rand())%1000);
  }
  return res;
}

void apply_the_sky(int* t,graph* g,int n){
  /*apply the weight of the absolute distance
   *between two point of the cloud on a graph g
   * t is the array of point and n is size divide
   * by 2
   */
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      g->W[i][j]=sqrt(pow(t[i]+t[j],2)+pow(t[i+1]+t[j+1], 2));
      g->W[j][i]=sqrt(pow(t[i]+t[j],2)+pow(t[i+1]+t[j+1], 2));
    }
  }
}
