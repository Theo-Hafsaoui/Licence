#include <stdio.h>
#include <stdlib.h>

#include "euler.h"
#include "graphe.h"
#include "connexe.h"

int preEulerien(int *d , graphe g)
{
   int imp = 0 ; 
   for(int i = 0 ; i < g.nbs ; i++)
   {
   	if(degre(g,i)%2 != 0)
   	{
   		imp ++ ; 
   		*d = i ; 
   	}
   }
   //semi eulerien 
   if (imp == 2 )
   {
   	printf("le graphe est semi eulerien\n");
   	return 2 ;
   }
   //eulerien
   //aucun sommet n est impair
   //et un parcours eulerien peut
   //etre fait et le depart est par 0
   
   if (imp == 0 )
   {
   	*d = 0 ;
   	printf("le graphe est eulerien\n");
   	return 1 ;
   }
   
   // graphe non eulerien 
   else 
   {
   	printf("le graphe n est ni eulerien ni semi eulerien \n ");
   	return 0 ; 
   }
  	
}

pile balade(int s , graphe g)
{
	int t = 0 ;
	pile res = NULL ;
	while(degre(g,s)>0)
	{
		Empiler(s,&res);
		for(t=0 ; g.mat[s][t] == 0 ;t++);
			g.mat[s][t] = g.mat[t][s] = 0 ;
		s = t ;
	}
	Empiler(s, &res);
	return res ;
}
	

void Parcours(graphe g , sommet s)
{
	
	pile p = NULL ;
	p = balade(s,g);
	while(p)
	{
		int courant = Depiler(&p);
		printf("%d.",courant);
		if(degre(g,courant) > 0)
			Parcours(g,courant);
	}
	printf("\n");
}

void Eulerien(graphe g)
{
	graphe res = creer_graphe(g.nbs) ;
	res = g ;
	int d = 0 ;
	if (EstConnexe(res) && preEulerien(&d,res))
	{
		printf(" ce parcours est possible :\n");
		Parcours(res,d);
	}
	else 
		printf("le graphe n est pas eulerien \n");
}













		
	    
	    


























			 
	
