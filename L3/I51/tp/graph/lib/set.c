#include <stdlib.h>
#include <stdio.h>
#include "set.h"

set rep(set x){
//TODO update set
//Return lead of set
if (x==0) {
  printf("set equal 0");
  return x;
  }
  if (x->lead==x) {
    return x;
  }
  return rep(x->nxt);
}

void Union(set x, set y){
  //I will unite instead of divide. I will bring men together.
  //...
  //Unite two set the rep will be the one of x...UNITE THEM !!!!!
  while (x->nxt!=NULL) {
    x=x->nxt;
  }
  set lead=x->lead;
  x->nxt=y;
  while (x->nxt!=NULL) {
    x=x->nxt;
    x->lead=lead;
  }
}

set singleton(int i){
  //Create a set of one element
  set res=malloc(sizeof(elm_set));
  res->n=i;(res->lead)=res;res->nxt=NULL;
  return res;
}
