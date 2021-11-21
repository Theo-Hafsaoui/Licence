#include "../lib/graph.h"
#include "../lib/io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    graph g;
    g = r_graph("../data/my_house.gr");
    printf("ok\n");
    w_graph("../data/house_result.gr", g);
    return 0;
}
