#ifndef CONNEXE_H
#define CONNEXE_H

#include "graphe.h"
#include "pile.h"

#define GRIS 1
#define BLANC 0
#define NOIR 2

void parcours(int s , graphe G);
int ComposanteConnexe(graphe G);
int EstConnexe(graphe G);
void parcoursPile(sommet s , graphe g);

#endif
