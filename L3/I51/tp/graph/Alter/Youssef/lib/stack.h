#ifndef STACK_H
#define STACK_H
typedef struct stack_elm{
    int val;
    struct stack_elm * next;
} stack_elm_t, * stack_t;

void print(stack_t head);
void push(stack_t* head, int n);
int pop(stack_t* head);
int check_head_val(stack_t head);


#endif
