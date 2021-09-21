#include "include/graph.h"
#include <stdio.h>
#include <stdlib.h>

graphe LireGraphe(char * src) {
    int n;
    int r, s;
    graphe res;

    FILE* fichier;
    fichier = fopen(src, "r");
    if(fichier == NULL) {
        perror("line graph: ");
        exit(-1);
    }
    char line[1024];
    while(!feof(fichier)){
        fgets(line, 1024, dot);
        switch (line[0]) {
            case '#': break;
            case 'n':
                if(sscanf(line, "nbs=%d", &n))
                    res = Creat_G(n);
                break;
            default (sscanf(ligne, "%d %d", &r, &s));
                res.mat[r][s] = 1;
                res.mat[s][r] = 1;}
        fclose(fichier);
        return res;
}
graphe LireGraphe(char*src){
	graphe res;
	int n;
	int r;
	int s;
	char ligne[1024];
	FILE*fichier;
	fichier = fopen(src,"r");
	if (NULL==fichier){
		perror("line graph: ");
		exit(-1);}
	while(!feof

	
	
