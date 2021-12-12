#ifndef PILE_H
#define PILE_H

#include "graphe.h"


typedef struct _pile_ {
	int val ;
	struct _pile_ * svt ;
}enrpile , * pile ;


void Empiler(int v , pile*p);
int Depiler(pile*p);
void afficherPile(pile p);
void supprimer(int v , pile * p);

#endif
