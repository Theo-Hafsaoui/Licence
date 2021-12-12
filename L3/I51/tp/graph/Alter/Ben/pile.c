#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "graphe.h"

void Empiler(int v , pile*p)
{
  pile nv = malloc(sizeof(enrpile)) ;
  nv->val = v ;
  nv->svt = *p ;
  *p = nv ;//pour dire que nv est la nouvelle tele
}
int Depiler(pile*p)
{
  int tete = (*p)->val ;
  pile aux = *p ;
  *p = aux->svt ;
  free(aux);
  return tete ;

}
void supprimer(int v , pile * p)
{
  pile pil = NULL ;
  pile aux = *p ;
  while(aux != NULL)
  {
  	if(aux->val != v)
  		Empiler(aux->val,&pil);
  	aux = aux->svt ;
  }
  *p = pil ;
  
}
  
  		 
void afficherPile(pile p)
{
    pile aux = p ;
    while(aux)
    {
      printf("%d | ",aux->val);
      aux = aux->svt;
    }
    printf("\n");
}
