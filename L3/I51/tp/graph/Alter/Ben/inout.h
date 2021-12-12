#ifndef INOUT_H
#define INOUT_H

#include "graphe.h"
#include "pile.h"

graphe lire_graphe(char*src);
void ecrire_graphe(char*dest , graphe g);
void dotify(char*dest,graphe g);
void ecrire2(char * dest , graphe g);

#endif
