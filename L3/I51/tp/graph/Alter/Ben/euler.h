#ifndef EULER_H
#define EULER_H

#include "pile.h"
#include "graphe.h"

int preEulerien(int *d , graphe g);
pile balade(int s , graphe g);
void Parcours(graphe g , sommet s);
void Eulerien(graphe g);

#endif 
