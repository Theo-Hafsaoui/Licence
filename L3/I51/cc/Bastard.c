#include <stdio.h>
#include <stdlib.h>

static int *pos;
static int *colonne;
static int *diag_gauche;
static int *diag_droite;
static int echiquiers = 0;

int numg(int i, int j)
{
    return i + j;
}                                // ⟍ 

int numd(int i, int j, int n)
{
    return i - j + n;
}                                // ⟋

int accept(int i, int j, int n)
{
    if (colonne[j])
        return 0;
    if (diag_gauche[numg(i, j)])
        return 0;
    if (diag_droite[numd(i, j, n)])
        return 0;
    return 1;
}

void reine(int i, int n)
{
    int j;
    if (i == n) {
        echiquiers++;
        return;
    }
    for (j = 0; j < n; j++)
        if (accept(i, j, n)) {
            pos[i] = j;
            colonne[j] = 1;
            diag_gauche[numg(i, j)] = 1;
            diag_droite[numd(i, j, n)] = 1;
            reine(i + 1, n);
            pos[i] = 0;
            colonne[j] = 0;
            diag_gauche[numg(i, j)] = 0;
            diag_droite[numd(i, j, n)] = 0;
        }
}

int main(int argc, char **argv)
{
    int n = 15;
    printf();
    pos = calloc(n, sizeof(int));
    colonne = calloc(n, sizeof(int));
    diag_gauche = calloc(n * 2 - 1, sizeof(int));
    diag_droite = calloc(n * 2 - 1, sizeof(int));
    reine(0, n);
    free(pos);
    free(colonne);
    free(diag_gauche);
    free(diag_droite);
    printf("%d\n", n);
    return 0;
}
