#include "../lib/graph.h" 
#include "../lib/io.h"
#include "../lib/stack.h"
#include "../lib/set.h"
#include "../lib/connected.h"
#include "../lib/color.h"
#include "../lib/ACM.h"
#include "../lib/eulerian.h"
#include "../lib/cloud.h"
#include <stdio.h>
#include <math.h>
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
//    stack s=NULL;
//    push(&s, 42);
//    push(&s, 43);
//    push(&s, 44);
//    push(&s, 45);
//    push(&s, 46);
//    print(s);
//    //int n=pop(&s);printf("n=%d\n",n);
//#####t#####TEST COLOR##########
//  graph g;
//  g=rand_graph(5, 0.5);
//  k_colorable(g, 2);
//  draw_graph(g, "test");
//##########TEST CONNEXE##########
//    graph g;
//    g=r_graph("../data/my_house.gr");
//    printf("nb comp=%d", nb_components(g));
//    printf("the biggest comp=%d", giant_component(g));
//    fflush(stdout);
//    draw_graph(g, "test");
//#####t#####TEST CYCLE##########
    graph gcycle=r_graph("../data/my_house.gr");
    graph gncycle=r_graph("../data/MHC.gr");
    assert(is_cycle(gcycle)==1);
    assert(is_cycle(gncycle)==0);
    printf("all test passed");
//#####t#####TEST EULERIAN##########
//  graph g1,g2,g3;
//  g2=r_graph("../data/graph2.gr");
//  assert(eulerian(g2)==0);
//  printf("all test passed");
//##########TEST SET##########
//    set x=singleton(42);
//    set y=singleton(42);
//    Union(x, y);
//##########TEST KRUMACHIN##########
//  graph g,g2;
//  g=rand_graph(5, 1);
//  int* t=cloud(5);
//  g.W=calloc(5, sizeof(double));
//  for (int i=0; i<5; i++) {
//    g.W[i]=calloc(5, sizeof(double));
//  }
//  //g is now complete
//  for (int i=0; i<5; i++) {
//    for (int j=0; j<5; j++) {
//      g.W[i][j]=sqrt(pow(t[i]+t[j],2)+pow(t[i+1]+t[j+1], 2));
//      g.W[j][i]=sqrt(pow(t[i]+t[j],2)+pow(t[i+1]+t[j+1], 2));
//    }
//  }
//  g2=kruskhal(g);
//  w_graph("kruskhal", g2);
//  draw_graph(g, "test");
//  draw_graph(g2, "test");
}

