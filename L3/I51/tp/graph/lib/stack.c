#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void push(stack *top, int n){
  //Push a stack, must be initialize at NULL
  elm* n_top=malloc(sizeof(elm));
  n_top->n=n;
  n_top->nxt=(*top);
  (*top)=n_top;
}

int pop(stack*top){
  //pop a stack 
  if(top==NULL){
    perror("Head is null");
  }
  int res=(*top)->n;
  elm* top2 =*top;
  *top=(*top)->nxt;
  free(top2);
  return res;
}

void print(stack top){
  //print a stack
  elm* tete= top;
  printf("| = |\n");
  while (tete) {
      printf("| - |\n");
      printf("|%d |\n",tete->n);
      tete=tete->nxt;
  }
  printf("|=|\n");
}
