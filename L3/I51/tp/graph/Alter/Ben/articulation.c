
#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
#include "articulation.h"
#include "connexe.h"

int estPointArticulation(graphe g)
{
    int nb = 0 ;
    for(int i = 0 ; i < g.nbs ;i++)
    {
    	int nombreConnexe = ComposanteConnexe(g);
    	for(int j = i + 1 ; j < g.nbs ;j++)
    	{
    		
    	    if((g.mat[i][j])&&(degre(g,i)>1))
    	    {
    	    	g.mat[i][j] = g.mat[j][i] = 0 ;   
    	        int nouveauNombre = ComposanteConnexe(g);
    	        if(nouveauNombre > nombreConnexe)
    	    	     nb++;	
    	        g.mat[i][j] = g.mat[j][i] = 1 ;
            }
        }
    }
    return nb ;
}

 //dans un arbre tous les sommets de degre strictement superieur
