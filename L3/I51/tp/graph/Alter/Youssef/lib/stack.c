#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print(stack_t head) {
    stack_elm_t *aux = head;
    printf("/TOP\\\n");
    while (aux) {
        printf("|%d|\n", aux->val);
        aux = aux->next;
    }
    printf("\\-/\n");
}

void push(stack_t* head, int n) {
    stack_elm_t * new_head = malloc(sizeof(stack_elm_t));
    new_head->val = n;
    new_head->next = (*head);
    (*head) = new_head;
}

int pop(stack_t* head) {
    assert(*head != NULL);
    int r_val = (*head)->val;
    stack_elm_t * old_head = (*head);
    (*head) = (*head)->next;
    free(old_head);
    return r_val;
}



