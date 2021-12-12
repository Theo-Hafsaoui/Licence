#include <stdio.h>
#include <stdlib.h>

#include "connexe.h"
#include "graphe.h"
#include "pile.h"

int*trace ;

//on ne peut pas allouer dynamiquement un tableau en variable globale
//ici la partie en commentaire est la partie qui renvoie le nombre de composante
/*
void parcours(int s , graphe G )
{
    trace[s] = 1 ;
    for (int j = 0 ; j < G.nbs ; j++)
    {
	   if(trace[j] == 0 && G.mat[s][j] == 1 )
           	parcours(j,G);
    }
}

int ComposanteConnexe(graphe G)
{
    trace = calloc(G.nbs , sizeof(int));
    int nb = 0 ;
    int n = G.nbs ;
    for (int i = 0 ; i < n ; i++)
    {
	     if(trace[i] == 0)
	       {
	         parcours(i,G);
	         nb++;
	       }
    }
    return nb ;
}

int EstConnexe(graphe G)
{
      trace = calloc(G.nbs , sizeof(int));
      parcours(0,G);
      for(int i = 0 ; i < G.nbs ; i++)
      {
        if (trace[i] == 0)
        {
          printf("le graphe n'est pas connexe \n");
          return 0 ;
        }
      }
      printf("le graphe est connexe\n");
      return 1 ;
}
*/
//non recursive mais iterative en utilisant la structure pile
//pile parcours en profondeur comme la facon recursive
//parcours avec file ---> largeur 

void parcoursPile(sommet s , graphe g)
{
  trace = calloc(g.nbs,sizeof(int));
  int t , v ;
  int nb = 0 ;
  liste aux ;
  pile p = NULL;
  for(int k = 0 ; k < g.nbs ; k++)
  {
    Empiler(k,&p);
    printf("le sommet %d\n",k);
    if(trace[k] == BLANC)
    {
      nb++;
      trace[k] = GRIS;
      while(p)
      {
        v = Depiler(&p);//enlever le sommet qui est lie aux autres et le recuperer 
        aux = g.adj[v];//ajouter un adjacent du point a traiter
        while(aux)
        {
          t = aux->num ;//le numero du sommet adjacent
          //printf("le sommet %d est lie au %d  \n",v,t);
          if(trace[t] == BLANC)//si le sommet n'a jamais ete visite
          {
            Empiler(t,&p);
            trace[t]=GRIS;
          }
    
          aux = aux -> svt ;
        }
        trace[v] = NOIR ;
        afficherPile(p);
      }
    }
  }
  printf("le nombre de composante connexe est %d\n",nb);
}






