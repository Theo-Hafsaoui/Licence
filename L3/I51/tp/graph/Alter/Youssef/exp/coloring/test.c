#include "graph.h"
#include "inout.h"
#include "coloring.h"
int main(int argc, char* argv[]) {
    graph g;
    g = read_graph(argv[1]);
    print_mat(g);
    printf("nb_solutions 5 coloreables %d",n_colorable(g, 5));
    free_graph(g);
    return 0;
}

