#ifndef COLORIAGE_H
#define COLORIAGE_H

#include "graphe.h"
#include "pile.h"

///////////////////////////////////////////////////////////////////////

int acceptePile(int i , pile p );
static void coloriagePile(int s , graphe g );
void coloriablePile(int k , graphe g);

//si un sommet est impair je peux pas le colorier avec 2 couleurs


#endif
