#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define N 25

typedef struct node {
    int val;
    struct node *next;
} node;
typedef unsigned int uint;


unsigned int len(node *head) {
    unsigned int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}


void swap (node **head, uint i, uint j) {
    node *l_i, *l_j, *l_i_prec = NULL, *l_j_prec = NULL;
    node *curr_node = *head, *prec = NULL;
    uint k = 0;
    assert(i < len(*head) && j < len(*head) && i >= 0 && j >= 0);

    if (j == i)
        return ;

    while (curr_node != NULL) {
        if (k == i) {
            l_i_prec = prec;
            l_i = curr_node;
        }
        else if (k == j) {
            l_j_prec = prec;
            l_j = curr_node;
        }
        k++;
        prec = curr_node;
        curr_node = curr_node->next;
    }

    if (l_i_prec != NULL) {
        l_i_prec->next = l_j;
    } else {
        *head = l_j;
    }

    if (l_j_prec != NULL) {
        l_j_prec->next = l_i;
    } else {
        *head = l_i;
    }

    node* tmp = l_i->next;
    l_i->next = l_j->next;
    l_j->next = tmp;

}

void free_list(node *head) {
    while (head != NULL) {
        free(head);
        head = head->next;
    }
}

void print(node *head) {
    printf("[");
    while (head->next != NULL) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("%d]\n", head->val);
}

node* index (node *head, uint j) {
    if (j < 0){
        return NULL;
    }
    node* curr = head;
    for(uint i = 0; curr && i < j; i++)
        curr = curr->next;
    return curr;
}

void insertion (node **head, node* Y, node* X) {
    // insertion of node x between prevY and Y 
    node *curr = *head, *prevY = NULL, *prevX = NULL;
    while (curr != NULL && (prevY == NULL || prevX == NULL)) {
        if (curr->next == X){ 
            prevX = curr;
        } else if (curr->next == Y) {
            prevY = curr;
        }
        curr = curr->next;
    }

    if (prevX == NULL) {
        *head = (*head)->next;
    } else {
        prevX->next = X->next;
    }
    if (prevY == NULL) {
        X->next = *head;
        *head = X;
    } else {
        prevY->next = X;
        X->next = Y;
    }
        
}

void push (node **head, uint x) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->val = x;
    new_node->next = *head;
    *head = new_node;
}


void fusion (node **head, uint p, uint q, uint r) {
    uint i = p, j = q+1;
    node *left_i = index(*head, i);
    node *right_j = index(*head, j);
    node *tmp_next, *tmp;
    while (i<=q && j<=r) {
        if (left_i->val > right_j->val) {
            tmp_next = right_j->next;
            insertion(head, left_i, right_j);
            right_j = tmp_next;
            j++;
        } else {
            left_i = left_i->next;
            i++;
        }
    }
}

void merge_sort (node **head, uint start, uint end) {
    if (start < end) {
        int q = (start+end)/2;
        merge_sort(head, start, q);
        merge_sort(head, q+1, end);
        fusion(head, start, q, end);
    }
}

node* genperm(unsigned int n) {
    node *head = (node*)malloc(sizeof(node));
    head->val = 0;
    head->next = NULL;
    node *prec_node = head;
    node *curr_node;
    for (int i = 1; i < n; i++) {
        curr_node = (node*)malloc(sizeof(node));
        curr_node->val = i;
        curr_node->next = NULL;
        prec_node->next = curr_node;
        prec_node = curr_node;
    }
    int x;
    for (int i = 0; i < n; i++) {
        do {
            x = rand() % n;
        } while (x < i);
        swap(&head, i, x);
    }
    return head;
}
void main() {
    srand(time(NULL));
    node *head_ref = genperm(N);
    //print(head);
    //print(index(head, 4));
    //insertion(&head, index(head, 4), 0);
    //print(head);

    //node *head_ref = NULL;
    //push(&head_ref, 3);
    //push(&head_ref, 0);
    //push(&head_ref, 2);
    //push(&head_ref, 4);
    //push(&head_ref, 1);
    //print(head_ref);
    //fusion(&head_ref, 0, 2, 5);

    print(head_ref);
    merge_sort(&head_ref, 0, N-1);
    print(head_ref);
    free(head_ref);
}
