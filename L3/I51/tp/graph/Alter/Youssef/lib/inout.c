#include "graph.h"
#include "inout.h"
#include <error.h>
#include <stdlib.h>
#include <stdio.h>

graph read_graph(char* filename) {
    graph res; char line[1024]; int n; int r,s;
    FILE* src;
    src = fopen(filename, "r");
    if (NULL == src) { 
        perror("read filename error");
        exit(1);
    }
    while (!feof(src)) {
        fgets(line, 1024, src);
        switch(line[0]) {
            case '#': break;
            case 'n':
                      if(sscanf(line, "nbs = %d", &n)){
                          res = create_graph(n);
                          break;
                      }
            default:
                      if(sscanf(line, "%d %d", &r, &s)) {
                          res.mat[r][s] = 1;
                          res.mat[s][r] = 1;
                      }
                        
        }
    }
    return res;
}

void write_graph(char* filename, graph g) {
    FILE* dst;
    if (NULL == filename) 
        dst = stdout;
    else {
        dst = fopen(filename,"w");
        if (NULL == dst) {
            perror("filename error in write_graph");
            exit(1);
        }
    }
    fprintf(dst, "nbs = %d\n", g.nbs);
    for (int i = 0; i < g.nbs; i++) {
        fprintf(dst, "%d :", i);
        for (int j = i; j < g.nbs; j++) {
            if (g.mat[i][j])
                fprintf(dst, "%d ", j);
        }
        fprintf(dst,"\n");
    }
}

void draw_graph(graph g, char * filename) {
    FILE *dst;
    char fn[1024];
    sprintf(fn, "../data/%s.dot",filename);
    dst = fopen(fn,"w");
    if (!dst) {
        perror("open error");
        exit(1);
    }
    char cmd[1024];
    fprintf(dst, "graph { \n");
    for(int i = 0; i < g.nbs; i++) {
        fprintf(dst,"%d;\n", i);
        for(int j = i; j < g.nbs; j++) {
            if (g.mat[i][j])
                fprintf(dst,"%d--%d;\n",i,j);
        }
    }
    fprintf(dst,"}\n");
    fclose(dst);
    sprintf(cmd, "dot -Tpng -o ../data/%s.png ../data/%s.dot",filename, filename);
    system(cmd);
    printf("Drawed succesfully\n");
}
    

void draw_graph_wt(graph g, char * filename) {
    FILE *dst;
    char fn[1024];
    sprintf(fn, "../../data/%s.dot",filename);
    dst = fopen(fn,"w");
    if (!dst) {
        perror("open error");
        exit(1);
    }
    char cmd[1024];
    fprintf(dst, "graph { \n");
    for(int i = 0; i < g.nbs; i++) {
        fprintf(dst,"%d;\n", i);
        for(int j = i; j < g.nbs; j++) {
            if (g.mat[i][j])
                fprintf(dst,"%d--%d [label=%f];\n",i,j, g.wt[i][j]);
        }
    }
    fprintf(dst,"}\n");
    fclose(dst);
    sprintf(cmd, "dot -Tpng -o ../../data/%s.png ../../data/%s.dot",filename, filename);
    system(cmd);
    printf("Drawed succesfully\n");
}
