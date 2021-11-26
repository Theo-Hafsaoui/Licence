#ifndef STACK_H
#define STACK_H

typedef struct elm{
  int n;
  struct elm* nxt;
}elm, *stack;

void push(stack* head, int n);
int pop(stack* head);
void print (stack head);

#endif
