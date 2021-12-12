#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include "connexe.h"
#include "inout.h"

graphe creer_graphe(int n)
{
   graphe res ;
   res.nbs = n ;
   res.mat = calloc(n,sizeof(int*));
   //int * car c'est une matrice : tableau de tableau
   for(int i = 0 ; i < n ; i++)
	res.mat[i]=calloc(n,sizeof(int));
   //mat[i] est simplement un tableau donc pas de int * mais int tout court
   return res ;
}

void liberer_graphe(graphe g)
{
    for(int i = 0 ; i < g.nbs ;i++)
        free(g.mat[i]);
    free(g.mat);
}

graphe GrapheAlea(int n , float proba)
{
  graphe r ;
  r = creer_graphe(n);
  long int seuil = proba * RAND_MAX ;
  int j ;
  for(int i = 0 ; i < n ; i++)
  {
    for(j = i+1 ; j<n;j++)
    {
      if(random() < seuil)
        r.mat[i][j] = r.mat[j][i] = 1 ;
    }
  }
  return r ;
}


void AjouterArete(graphe g , sommet s,sommet r)
{
  g.mat[s][r] = g.mat[r][s] = 1 ;
}


int degre(graphe g , sommet s)
{
  int deg = 0 ;
  for(int i = 0 ; i < g.nbs ; i++)
    if (g.mat[s][i] == 1) deg++ ;
  return deg ;
}

//retourne le tableau contenant tous les degres de tous les sommets
int * TabDegre(graphe g)
{
  int * t_Degre = malloc(g.nbs*sizeof(int));
  for(int i = 0 ; i < g.nbs ; i++)
    t_Degre[i] = degre(g,i) ;
  return t_Degre;
}

//nombre d arete dans un graphe
int nbArete(graphe g)
{
  int aret = 0 ;
  for(int i = 0 ; i < g.nbs ; i++)
  {
    for(int j = i ; j < g.nbs ; j++)
      if (g.mat[i][j]) aret ++ ;
  }
  return aret ;
}


void conversionListe(graphe*g)
{
  g->adj = calloc(g->nbs , sizeof(liste));
  liste aux ;
  for(int i = 0 ; i < g->nbs ; i++)
  {
    for(int j = 0 ; j < g->nbs ; j++)
      if (g->mat[i][j] )
      {

        aux = malloc(sizeof(enrliste));
        aux->num = j ;
        aux->svt = g->adj[i];
        g->adj[i] = aux ;
      }
  }
}

void AjouterAreteAdj(graphe*g , sommet s , sommet r)
{
   liste aux ;
   aux = malloc(sizeof(enrliste));
   aux->num = s ;
   aux->svt = g->adj[r];
   g->adj[r] = aux ;
   liste au ;
   au = malloc(sizeof(enrliste));
   au->num = r ;
   au->svt = g->adj[s];
   g->adj[s] = au ;
}

graphe grapheComplet(int n)
{
	graphe res = creer_graphe(n);
	for(int i = 0 ; i < n-1 ; i++)
	{

		for(int j = i+1 ; j < n ; j++)
		{
			res.mat[i][j] = 1 ;
			res.mat[j][i] = 1 ;
		}
	}
	return res ;
}



void afficher(graphe g)
{
  liste aux ;
  for(int i = 0 ; i < g.nbs ; i++)
  {
    printf("le sommet %d est reliés aux sommets  ",i);
    aux = g.adj[i];
    while(aux)
    {
      printf("%d | ",aux->num);
      aux = aux->svt;
    }
    printf("\n");
  }
}

