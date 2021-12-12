#include "graph.h"
#include "list.h"
#include "inout.h"
#include "connexe.h"
#include <stdio.h>
#include <stdlib.h>
#include "eulerian.h"
#include "binary.h"

int main(int argc, char* argv[]) {
    /*
    graph g;
    g = read_graph(argv[1]);
    printf("ok\n");
    write_graph(NULL, g);
    dessiner_graph(g,"maison");
    return 0;
    */
    graph g = random_graph(9, 1);
    draw_graph(g, "test");
    int nb_cc = nb_of_components_r(g);
    int max_c = max_component(g);
    int start = 1001;
    int res = 1001;
    if (nb_of_components_it(g) == 1) {
        draw_eulerian(g, "test");

    }
    free_graph(g);
    ullong num = 34;
    wt(num);
/*
    printf("Nombre des composantes connexes %d\n", nb_cc);
    printf("res %d, start %d\n", res, start);
    //printf("The maximal component size is %d\n", max_c);
    //nb_cc = nb_of_components_it(g);
    //printf("Nombre des composantes connexes %d\n", nb_cc);
    */
}

