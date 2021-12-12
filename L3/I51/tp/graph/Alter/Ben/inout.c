#include <stdio.h>
#include <stdlib.h>

#include "inout.h"
#include "graphe.h"

graphe lire_graphe(char*src)
{
    int r , s ,n ;
    FILE*fichier = fopen(src ,"r");
    graphe res ;
    if ( NULL == fichier )
    {
	perror(" lire graphe : ");
	exit(1);
	// exit(1) car erreur ,doit etre different de 0
    }
    else
    {
        char ligne[1024];
	while(! feof(fichier))
	{

	    fgets(ligne,1024,fichier);
	    switch (ligne[0])
	    {
	        case '#' : break ;
		case 'n' :

		     if(sscanf(ligne , "n = %d",&n))
			res = creer_graphe(n);
		     break ;
		default : (sscanf(ligne ,"%d %d",&r,&s)) > 1 ;

			res.mat[r][s] = 1 ;
			res.mat[s][r] = 1 ;

	    }
	}
    }
    fclose(fichier);
    return res ;
}
void ecrire2(char * dest , graphe g)
{
    FILE*fichier ;
    if (NULL == dest )
	fichier = stdout ;
    else
	fichier = fopen(dest ,"w");
    if (NULL == fichier)
    {
         perror("ecrire graphe : ");
	 exit(1);
    }
    else
    {
	fprintf(fichier , "n=%d\n",g.nbs);
        for(int i = 0 ; i < g.nbs ; i++)
	{
		for(int j = i ; j < g.nbs ; j++)
			if(g.mat[i][j]) fprintf(fichier,"%d %d\n",i,j);
       }
    }
}
	
void ecrire_graphe(char*dest , graphe g)
{
    FILE*fichier ;
    if (NULL == dest )
	fichier = stdout ;
    else
	fichier = fopen(dest ,"w");
    if (NULL == fichier)
    {
         perror("ecrire graphe : ");
	 exit(1);
    }
    else
    {
	fprintf(fichier , "nbs = %d \n",g.nbs);
        for(int i = 0 ; i < g.nbs ; i++)
	{
		fprintf(fichier,"%d :",i);
		for(int j = i ; j < g.nbs ; j++)
			if(g.mat[i][j] > 0) fprintf(fichier,"%d ",j);
                fputc('\n',fichier);
                //fputc ecrit un caractere
       }

   }
   fclose(fichier);
}

void dotify(char*dest,graphe g)
{
  FILE*fichier ;
  fichier = fopen(dest ,"w");
  fputs("graph { \n",fichier);
  for(int i = 0 ; i < g.nbs ; i++)
          fprintf(fichier,"   %d;\n",i);
  fputc('\n',fichier);
  fputc('\n',fichier);
  int k ;
  for(int j = 0 ; j < g.nbs ; j++)
  {
    for(k=j; k < g.nbs ;k++)
        if(g.mat[j][k] > 0) fprintf(fichier,"   %d--%d;\n",j,k);
  }
  fputc('\n',fichier);
  fputc('}',fichier);
  fclose(fichier);
  char cmd[250];
  char cmd2[250];
  sprintf(cmd,"dot -Tpng %s -o %s.png",dest,dest);
  sprintf(cmd2,"xdg-open %s.png",dest);
  system(cmd);
  system(cmd2);
}



