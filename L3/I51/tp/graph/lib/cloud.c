#include "cloud.h"
#include <stdio.h>
#include <stdlib.h>

int* cloud(int n){
  int* res=calloc(n*2, sizeof(int));
  for (int i=0; i<n; i+=2) {
    res[i]=((random())/RAND_MAX);
    res[i+1]=((random())/RAND_MAX);
  }
  return res;
}

