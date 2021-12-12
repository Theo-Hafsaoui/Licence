#ifndef KRUSCAL_H
#define KRUSCAL_H

#include "graphe.h"
#include "disjoint.h"
#include "inout.h"

typedef struct {
	int i , j ;
	double wt ;
}arete ;

typedef struct {
	double x , y ;
} point ;

graphe creerNuage(int n);

arete* kruskal ( graphe g);



#endif
