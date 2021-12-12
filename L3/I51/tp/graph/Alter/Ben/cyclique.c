#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include "pile.h"
#include "cyclique.h"

int*trace ;

int acyc(sommet s , graphe g)
{
  trace = calloc(g.nbs,sizeof(int));
  int t , v ;
  liste aux ;
  pile p = NULL;
  for(int k = 0 ; k < g.nbs ; k++)
  {
    Empiler(k,&p);
    if(trace[k] == BLANC)
    //si sommet non visité
    {
      trace[k] = GRIS;
      //je marque que je suis passe par lui sans dire que je l'ai traite
      while(p)
      {
        v = Depiler(&p);
        aux = g.adj[v];
        while(aux)
        {
          t = aux->num ;
          if(trace[t] == GRIS)
          {
             printf("le graphe est cyclique\n");
             return 0 ;
          }
          if(trace[t] == BLANC)
          {
            Empiler(t,&p);
            trace[t]=GRIS;
        //gris veut dire deja ete sur la _pile_
        //blanc veut dire jamais visite
        //noir veut dire parcouru et sortie de la pile
          }
          aux = aux -> svt ;
        }
        trace[v] = NOIR ;
      }
    }
  }
  printf("le graphe est acyclique\n");
  return 1 ;

}

//Bazzan
int acyclique(graphe g)
{
    int n = g.nbs;
    uint v;
    stack pile;
    pile.head = NULL;
    int * trace = calloc(n,sizeof(uint));
    int * pere = calloc(n,sizeof(int));
    for(int i = 0; i < n; i ++)
    {
        pere[i] = -1;
    }
    for(uint i = 0; i < n; i++)
    {
        if(trace[i] == 0)
        {
            push(&pile,i);
            pere[v] = v;
            while(pile.head)
            {
                v = pop(&pile);
                trace[v] = 1;
                for(uint j = 0; j < n; j++)
                {
                    if(g.mat[v][j])
                    {
                        if(trace[j] == 0)
                        {
                            push(&pile,j);
                            pere[j] = v;
                            trace[j] = 1;
                        }
                        else if(trace[j] && pere[v]!= j)
                        { 
                            free(trace);
                            free(pere);
                            return 0;
                        }
                    }
                }
            }
            trace[i] = 2;
        }
        
    }   
    free(trace);
    free(pere);
    return 1;
    
    

}
