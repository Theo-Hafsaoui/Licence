#include "../lib/graph.h"
#include "../lib/io.h"
#include "../lib/stack.h"
#include "../lib/set.h"
#include "../lib/connected.h"
#include "../lib/color.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
//#####t#####TEST GRAPH##########
//    graph g;
//    g = rand_graph(50, 0.5);
//    printf("ok\n");
//    w_graph("../data/house_result.gr", g);
//    draw_graph(g, "test");
//    return 0;
//#####t#####TEST STACK##########
//test stack
//    stack s=NULL;
//    push(&s, 42);
//    push(&s, 43);
//    push(&s, 44);
//    push(&s, 45);
//    push(&s, 46);
//    print(s);
//    //int n=pop(&s);printf("n=%d\n",n);
//#####t#####TEST COLOR##########
  graph g;
  g=rand_graph(5, 0.5);
  //draw_graph(g, "test");
  assert(k_colorable(g, 2)==1);
//##########TEST CONNEXE##########
//    graph g;
//    g=r_graph("../data/my_house.gr");
//    printf("nb comp=%d", nb_components(g));
//    printf("the biggest comp=%d", giant_component(g));
//    fflush(stdout);
//    draw_graph(g, "test");
//##########TEST SET##########
//    set x=singleton(42);
//    set y=singleton(42);
//    Union(x, y);
}

