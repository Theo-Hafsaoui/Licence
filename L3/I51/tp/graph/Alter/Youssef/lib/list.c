#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_list(list_t list) {
    list_elm_t *aux = list.head;
    putchar('[');
    while(aux->next != NULL) {
        printf("%d->", aux->val);
        aux = aux->next;
    }
    printf("%d]\n", aux->val);
}

void push_back(list_t* list, int n) {
    list_elm_t * new_queue = malloc(sizeof(list_elm_t));
    if (list->head == NULL) 
        list->head = new_queue;
    else if (list->queue != NULL) 
        list->queue->next = new_queue;
    list->queue = new_queue;
    new_queue->val = n;
    new_queue->next = NULL;
    assert(list->head != NULL && list->queue != NULL);
}
void free_list(list_t list) {
    list_elm_t * curr, * aux;
    curr = list.head;
    while(curr) {
        aux = curr;
        curr = curr->next;
        free(aux);
    }
}

void extend(list_t* l1, list_t * l2) {
    l1->queue->next = l2->head;
    l1->queue = l2->queue;
}




