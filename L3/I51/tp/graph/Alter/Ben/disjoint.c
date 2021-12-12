#include <stdio.h>
#include <stdlib.h>

#include "disjoint.h"
#include "graphe.h"
/*

disjoint singleton (int i)
{
	disjoint res ;
	res = malloc(sizeof(enrdisjoint));
	res->num = i ;
	res->svt = NULL;
	res->rep = res ;
	return res ;
}

void reunion (disjoint r , disjoint s)
{
	disjoint p = r->rep ;
	disjoint pp = s->rep ;
	while(p->svt != NULL)//il faut arriver a la fin de la liste r
		p = p ->svt ;
	p->svt = s ;//le suivant du dernier maillont de la chaine
		    //est egale au sommet de la deuxieme liste 
	
	//cette boucle permet de lier tous les sommets
	//de la liste contenant s au nouveau represenant r
	while(s)
	{
		s ->rep = r ;
		s = s ->svt;
	}
}

disjoint representant(disjoint r)
{
	return r->rep ;
}*/

disjoint singleton (int v)
{
  disjoint res ;
  res = malloc(sizeof(enrdisjoint));
  res->num = v ;
  res->rep = res ;
  return res ;
}

void reunion (disjoint r , disjoint s )
{
    s->rep = r ;
}
disjoint representant(disjoint s)
{
   while(s != s->rep)
       s = s->rep ;
   return s ;
}
 
disjoint racoursi(disjoint s)
{
  disjoint res , aux,tmp ;
  res = s ; 
  while(res->rep != res )
     res = res->rep ;
  while(aux ->rep != NULL)
  {
     tmp = aux ;
     aux->rep = res ;
     aux = tmp->rep;
  }
  return res ;
}

































