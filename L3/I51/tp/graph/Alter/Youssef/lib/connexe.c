#include <assert.h>
#include "graph.h"
#include "connexe.h"
#include "stack.h"


int * track;
uint nb_of_components_r(graph g) {
    track = calloc(g.nbs, sizeof(int));
    uint nbc = 0;
    for(uint s = 0; s < g.nbs; s++) {
        if (track[s] == false) {
            browse(s, g);
            nbc += 1;
        }
    }
    free(track);
    return nbc;
}

uint browse(uint s, graph g) {
    track[s] = true;
    uint temp = 1;
    for (int t = 0; t < g.nbs; t++) {
        if(g.mat[s][t] && track[t] == false)
            temp += browse(t, g);
    }
    return temp;
}

uint max_component(graph g) {
    track = calloc(g.nbs, sizeof(int));
    uint max_comp = 0, curr_comp= 0;
    for(uint s = 0; s < g.nbs; s++) {
        if (track[s] == false) {
            curr_comp = browse(s, g);
            if (curr_comp > max_comp) 
                max_comp = curr_comp;
            curr_comp = 0;
        }
    }
    free(track);
    return max_comp;
}

uint nb_of_components_it(graph g) {
    int i = 0, curr;
    unsigned int nbc = 0;
    stack_t stack = NULL;
    track = calloc(g.nbs, sizeof(int));
    for(i = 0; i < g.nbs; i++) {
        assert(stack == NULL);
        if(track[i] == false) {
            push(&stack, i);
            track[i] = true;
            nbc++;
        }
        while(stack != NULL) {
            curr = pop(&stack);
            for(int j = 0; j < g.nbs; j++) {
                if((g.mat[curr][j] == true) && (track[j] == false)) {
                    push(&stack, j);
                    track[j] = true;
                }
            }
        }
    }
    free(track);
    return nbc;
}




