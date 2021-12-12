#include "graph.h"
#include "eulerian.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int pre_eulerian(int *s, graph g) {
    // return 0 not eulerian
    // return 1 eulerian
    // return 2 semi-eulerian
    uint nb_odds = 0;
    uint res;
    uint last_odds;
    for(int i = 0; i < g.nbs; i++) {
        if (degree(g,i) % 2 != 0) {
            // deg(i) odd
            nb_odds++;
            last_odds = i;
        }
    }
    if (nb_odds == 2) {
        //semi-eulerian
        res = 2;
        (*s) = last_odds;
    } else if (nb_odds == 0) {
        res = 1;
        (*s) = 0;
    } else {
        res = 0;
    }
    return res;
}

int next_neigh(graph g, uint s) {
    // return -1 if there arent neighbours
    // return x such as x is a neighbour of s
    int x = -1 ;
    for(uint i = 0; i < g.nbs && x == -1; i++) {
        if(g.mat[s][i] == 1)
            x = i;
    }
    return x;
}

list_t quick_stroll(graph* g, uint s) {
    list_t list = {NULL, NULL};
    int neigh;
    uint curr_s = s;
    while((neigh = next_neigh((*g), curr_s)) != -1) {
        push_back(&list, curr_s);
        g->mat[curr_s][neigh] = g->mat[neigh][curr_s] = 0;
        curr_s = neigh;
    }
    push_back(&list, curr_s);
    return list;
}

list_t eulerian_path(graph g_copy, uint s) {
    //g should be eulerian or semi-eulerian and s the start point
    list_t l = quick_stroll(&g_copy, s);
    list_t res = {NULL, NULL};
    list_elm_t * aux = l.head;
    list_t tmp;
    while (aux) {
        if(degree(g_copy, aux->val) > 0){
            tmp = eulerian_path(g_copy, aux->val);
            extend(&res, &tmp);
        } else {
            push_back(&res ,aux->val);
        }
        aux = aux->next;
    }
    free_list(l);
    return res;
}

list_t eulerian(graph g) {
    int start;
    list_t res;
    if (pre_eulerian(&start, g)) {
        graph g_copy = copy_graph(g);
        res = eulerian_path(g_copy, start);
        free_graph(g_copy);
    } else {
        printf("Not eulerian graph!");
    }
    return res;
}

void draw_eulerian(graph g, char * filename) {
    list_t eulerian_path = eulerian(g);
    list_elm_t * aux, *prec;

    FILE *dst;
    char fn[1024];
    sprintf(fn, "../data/eulerian_%s.dot",filename);
    dst = fopen(fn,"w");
    if (!dst) {
        perror("open error");
        exit(1);
    }
    char cmd[1024];
    fprintf(dst, "digraph { \n");

    aux = eulerian_path.head;
    do {
        prec = aux;
        aux = aux->next;
        fprintf(dst,"%d->%d;\n", prec->val, aux->val);
    } while(aux->next != NULL);

    fprintf(dst,"}\n");
    fclose(dst);
    sprintf(cmd, "dot -Tpng -o ../data/eulerian_%s.png ../data/eulerian_%s.dot",filename, filename);
    system(cmd);
    printf("Drawed succesfully\n");

    free_list(eulerian_path);

}
