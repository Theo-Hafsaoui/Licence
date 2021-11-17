#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/* 
nombre de diagonales : d = 2n-1 avec n dimensions n*n du plateau
diagonales indicées de 0 jusqu'à 2n-2

#####   GAUCHE
indice de la diagonale : i - j + n-1
### Droite
indice de la diagonale : i+j

 */
#define numG(i,j) i-j
#define numD(i,j) i+j

void disp_arr(int l [], size_t n)
{
    printf("[ ");
    for(int i = 0; i < n-1; i++)
    {
        printf("%d ",l[i]);
    }
    printf(" ]\n");
}

long millis(){
    struct timespec _t;
    clock_gettime(CLOCK_REALTIME, &_t);
    return _t.tv_sec*1000 + lround(_t.tv_nsec/1.0e6);
}

/* Déclaration des variables globales */
//case libre 0 case occupé 1
int * Colone;      // tableau de n valeurs qui indique si une colone est occupé
int * DiagDroite;  // tableau de 2*n-1 valeurs, antidiagonales du plateeau
int * DiagGauche;  // tableau de 2*n-1 valeurs, diagonales du plateau
// pos[i] colone sur laquelle on se trouve i rangée sur laquelle on se trouve
// -1 rangée inoccupée
int * pos;


int cpt = 0;

/* initialise les variables globales */
void init_board(int n, int **c, int ** dg, int ** dd, int ** p)
{
    *c = calloc(sizeof(int),n);
    *dg = calloc (sizeof(int),2*n-1);
    *dd = calloc (sizeof(int),2*n-1);
    *p = calloc (sizeof(int), n);
    for(int i = 0; i < n; i++)
        (*p)[i] = -1;
}

void free_board(int *c, int* dg, int *dd, int * p)
{
    free(c);
    free(dg);
    free(dd);
    free(p);
}
/*
fonction qui vérifie si la dame peut être placée sur la position i,j
*/
int accept (int i, int j, int n)
{
/* on vérifie successivement si les colones et les diagonales de la position i,j sont libres */
    if (Colone[j])
        return 0;
    if(DiagGauche[numG(i,j)+(n-1)])
        return 0;
    if (DiagDroite[numD(i,j)])
        return 0;
    return 1;
}

/* 
fonction qui place les dames de facons renvoie vrai si la dame a pu être placé
*/
int dames(int i, int n, int pos [])
{
    /* On vérifie si les n dames ont pu être placées */
    if(i == n)
    {
        cpt++;
        return 1;
    }
    /* On parcourt les colones */
    for(int j = 0; j < n; j++)
    {
        /* on vérifie si on peut placer la reine */
        if (accept(i,j,n))
        {
        /* placement de la reine */
            pos[i] = j;
            Colone[j] = 1;
            DiagDroite[numD(i,j)] = 1;
            DiagGauche[numG(i,j)+(n-1)] = 1;
        /* On passe a la rangée suivante i + 1 */
            dames(i+1,n,pos);     
        /*backtracking car les n dames n'ont pu être placés alors on rétablit à l'état d'origine les tableaux*/
            pos[i] = -1;
            Colone[j] = 0;
            DiagDroite[numD(i,j)] = 0;
            DiagGauche[numG(i,j)+(n-1)] = 0;
            }
    }
}
void n_dames(int n)
{
    clock_t start, end;
    double exec;
    init_board(n,&Colone,&DiagGauche,&DiagDroite,&pos);
    start = clock();
    dames(0,n,pos);
    end = clock();
    exec = ((double) (end - start)) / CLOCKS_PER_SEC;
    free_board(Colone,DiagGauche,DiagDroite,pos);
    printf("Q(%d) : %d              %f s\n",n,cpt,exec);
    cpt = 0;
}
void main ()
{
    for(int i = 1; i < 18; i ++)
        n_dames(i);

}   
