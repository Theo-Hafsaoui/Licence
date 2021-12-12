#ifndef LIST_H
#define LIST_H
typedef struct list_elm{
    int val;
    struct list_elm * next;
}list_elm_t;

typedef struct _list_ {
    list_elm_t * head;
    list_elm_t * queue;
}list;

void print_list(list head);
void Push(list* head, int n);
void free_l(list);
void add(list* l1, list* l2);

#endif
