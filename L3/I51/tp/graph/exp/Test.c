#include "../lib/graph.h"
#include "../lib/io.h"
#include "../lib/stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
//#####t#####TEST TP1##########
//    graph g;
//    g = r_graph("../data/my_house.gr");
//    printf("ok\n");
//    w_graph("../data/house_result.gr", g);
//    return 0;
//#####t#####TEST TP2##########
//test stack
    stack s=NULL;
    push(&s, 42);
    push(&s, 43);
    push(&s, 44);
    push(&s, 45);
    push(&s, 46);
    print(s);
    //int n=pop(&s);printf("n=%d\n",n);
}
