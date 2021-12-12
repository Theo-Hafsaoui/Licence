#include <stdlib.h>

#include "coloring.h"
#include "graph.h"
#include "stack.h"
typedef unsigned int uint;
//unsigned int ensemble_color;
stack_t * pos_stack;
uint nb_pos; 
/* returns the number of solutions with k colors*/
uint n_colorable(graph g, uint k) {
  nb_pos = 0;
  pos_stack = calloc(g.nbs, sizeof(stack_elm_t));
  for(int i = 0; i < g.nbs; i++)  {
    pos_stack[i] = NULL;
    push(&pos_stack[i], (1<<k)-1);
    printf("%d\n", (1<<k)-1);
  }
  coloring(0,g);
  return nb_pos;
}

void block_neighborhood(uint colour, uint vertex,  graph g) {
  uint head_val;
  for(int i = vertex; i < g.nbs; i++) {
      if(g.mat[vertex][i] == 1) {
        printf("%p, %d, col = %d\n", pos_stack[i], i, colour);
        head_val = pos_stack[i]->val;
        printf("hv =%d, col = %d\n", head_val, colour);
        push(&pos_stack[i], head_val^colour);
      }
  }
}

void unblock_neighborhood(uint colour, uint vertex, graph g) {
  for(int i = vertex; i < g.nbs; i++) {
      if(g.mat[vertex][i] == 1) {
        pop(&pos_stack[i]);
      }
  }
}

void coloring(uint vertex, graph g) {
  if (vertex == g.nbs) {
    nb_pos++;
  } else {
    uint pos_col = pos_stack[vertex]->val;
    // for every possible color
    // 021/univ-tln/L3/S5/I51-Algorithmique-des-graphes/data/maison.png' 
    uint curr_col = 0;
    uint temp;
    while(pos_col) {
      temp = pos_col&(pos_col-1);
      curr_col = pos_col ^ temp;
      block_neighborhood(curr_col, vertex, g);
      coloring(vertex+1, g);
      unblock_neighborhood(curr_col, vertex, g);

      pos_col = temp;
    }
  }
}


