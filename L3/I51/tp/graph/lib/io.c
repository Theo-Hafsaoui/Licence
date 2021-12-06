#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void w_graph(char* src,graph g){
//Write a graph in G.data
//
//Nbs is the number the number of vertice 
//and each edge is describe with:
//number vertice: number vertice
  FILE* fl;
  fl= fopen(src,"w+");
  if (fl==NULL) {
    printf("Incorrect Path graph");
  }
  fprintf(fl, "Nbs:%d\n", g.n);
  for (int i=0; i<g.n; i++) {
    fprintf(fl, "%d :", i);
    for (int j=0; j<g.n; j++) {
      if(g.T[i][j]){
        fprintf(fl, "%d", j);
      }
    }
    fprintf(fl,"\n");
  }
}

graph r_graph(char* src){
//read a graph in a file
//
//Src if path of the file
//NB: fget stop at \n
  graph res;char line[1024];int dim;
  int r,s;
  FILE* fl;
  fl= fopen(src,"r+");
  if (fl==NULL) {
    printf("Incorrect graph");
  }
  while (!feof(fl)) {
    fgets(line, 1024, fl);
    switch(line[0]) {
      case '#': break;
      case 'n':
                if(sscanf(line, "nbs = %d", &dim)){
                  res = create_graph(dim);
                  break;
                }
      default:
                if(sscanf(line, "%d %d", &r, &s)) {
                  res.T[r][s] = 1;
                  res.T[s][r] = 1;
                }
    }
  }
  return res; 
}

void draw_graph(graph g, char * filename) {
//cf:https://github.com/dxkkxn/univ-tln/blob/50064089918dc96a9537c00b7904275c093bb8d9/L3/S5/I51-Algorithmique-des-graphes/lib/inout.c
    FILE *dst;
    char fn[1024];
    sprintf(fn, "../data/%s.dot",filename);
    dst = fopen(fn,"w");
    if (!dst) {
        perror("not existing filename");
        exit(1);
    }
    char cmd[1024];
    fprintf(dst, "graph { \n");
    for(int i = 0; i < g.n; i++) {
        for(int j = i; j < g.n; j++) {
            if (g.T[i][j])
                fprintf(dst,"%d--%d;\n",i,j);
        }
    }
    fprintf(dst,"}\n");
    fclose(dst);
    sprintf(cmd, "dot -Tpng -o %s.png ../data/%s.dot && feh %s.png",filename, filename,filename);
    system(cmd);
}
