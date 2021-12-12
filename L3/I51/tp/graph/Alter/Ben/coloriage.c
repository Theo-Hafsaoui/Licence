#include <stdio.h>
#include <stdlib.h>

#include "coloriage.h"
#include "graphe.h"
#include "pile.h"

typedef unsigned int ensemble ;


//**********************************version avec les PILES**************************************************//

pile * pos ;
int cpt ;

void coloriablePile(int k , graphe g)
{
	cpt = 0 ;
	pos = calloc(g.nbs,sizeof(pile));
	for(int i = 0 ; i < g.nbs ; i++)
		Empiler((1 << k) - 1 ,&pos[i]);
	coloriagePile(0,g);
	printf("le graphe est %d coloriable %d fois \n",k,cpt);

}


static void coloriagePile(int s , graphe g )
{
	if(s == g.nbs)
	{
		cpt ++ ;
		return ;
	}

	ensemble x = (pos[s])->val ,c , t;
	while(x>0)
	{
		t = (x-1)&x;
		c = x ^ t ;
		for(int r = s+1 ; r < g.nbs ;r++)
		{
			if(g.mat[s][r])///pour chaque voisin r de s 
			{
		    	int u = pos[r]->val ;//avoir toutes les couleurs sauf la couleur choisie pas s 
		    	Empiler(u & (~c) , &pos[r]);
		    }
		}
		
		             coloriagePile(s+1,g);
		             
		             
		for(int r = s+1 ; r < g.nbs ;r++)
		{
			if(g.mat[s][r])
				Depiler(&pos[r]);
		    
		}
		x = t ;
	}
}
