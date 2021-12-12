#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "graphe.h"
#include "disjoint.h"
#include "kruscal.h"
#include "inout.h"

graphe creerNuage(int n)
{
	graphe res = grapheComplet(n);
	double * x , * y;
	x = calloc(n , sizeof(double));
	y = calloc(n , sizeof(double));
	for(int i = 0 ; i < n ; i++)
	{
		x[i] = random();
		y[i] = random();
	}
	res.w = calloc(n , sizeof(double*));
	for(int i = 0 ; i < n ; i ++)
		res.w[i] = calloc(n , sizeof(double));
	for(int i = 0; i < n ; i++)
	{
		for(int j = i + 1 ; j < n ; j++)
			res.w[i][j] = sqrt( pow(x[i]-x[j],2) + pow(x[i]-x[j],2) );
	}
	return res ;
}
	
/*double W(arete a , nuage N)
{
	double xi , xj , yi , yj ;
	xi = N.t[a.i].x ;
	yi = N.t[a.i].y ;
	xj = N.t[a.j].x ;
	yj = N.t[a.j].y ;
	a.wt = sqrt[(xi - xj) * (xi-xj) + (yi-yj)*(yi-yj)] ;
	return sqrt[(xi - xj) * (xi-xj) + (yi-yj)*(yi-yj)] ;
}*/



static int comp (const void * p1, const void * p2)
{
    arete a1 = *((arete*)p1);
    arete a2 = *((arete*)p2);
    if (a1.wt > a2.wt) return  1;
    if (a1.wt < a2.wt) return -1;
    return 0;
}
arete* kruskal ( graphe g)
{
	int m = nbArete(g) ;
	arete * table = calloc(m , sizeof(arete));
	int ACM = g.nbs - 1 ;
	printf("                 %d \n",ACM);
	arete * Y = calloc(m , sizeof(arete));
	int i,j, k = 0 ;
	for(i = 0 ; i < g.nbs ; i++)
	{
		for(j = i+1 ; j < g.nbs ; j++)
			if (g.mat[i][j])
			{
				table[k].i = i ;
				table[k].j = j ;
				table[k].wt = g.w[i][j];
				k++;
			}
	}
	qsort (table, m, sizeof(*table), comp);
	disjoint  ensembleDisj[g.nbs] ;
    for(int t = 0 ; t < g.nbs ; t++)
   		ensembleDisj[t] = singleton(t);
   	int p = g.nbs ;
    k = 0 ;
   	while( p > 1)
   	{
   		arete xy = table[k] ;
   		i = xy.i ;
   		j = xy.j ;
   		disjoint ri = representant(ensembleDisj[i]);
   		disjoint rj = representant(ensembleDisj[j]);
   		if( ri != rj)
        	{
   			reunion(ri,rj);
   			Y[k] = xy ;	
   		}
   	k++;
    }
    return Y ;
}
