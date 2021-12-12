#ifndef LIST_H
#define LIST_H
typedef struct list_elm{
    int val;
    struct list_elm * next;
} list_elm_t;
typedef struct _list_ {
    list_elm_t * head;
    list_elm_t * queue;
}list_t;

void print_list(list_t head);
void push_back(list_t* head, int n);
void free_list(list_t);
void extend(list_t* l1, list_t* l2);

#endif
