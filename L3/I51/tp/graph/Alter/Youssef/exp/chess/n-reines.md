# Problème des n-reines
Le problème des n-reines consiste à placer sur un échequier de taille n x n, n reines ou dames telles que deux dames ne se controlent pas mutuellement. Voici un exemple pour n = 8:

<p align="center">
  <img src="https://rosettacode.org/mw/images/b/bd/N_queens_problem.png"/>
</p>


Pour résoudre ce problème, on utilise le "backtracking" ou retour sur trace. La notion de "backtracking" permet de tester systématiquement l'ensemble de configurations possibles des n-dames en tenant compte qu'il ne peut pas y avoir 2 dames ni dans la même diagonal ni dans la même ligne colonne ni dans la même diagonal.
## Langage pseudo algorithmique
Voici l'algorithme utilisé en langage pseudo-algorithmique. (n étant la taille de l'échequier)
```
ALGORITHME reines(entier ligne, entier n)
VARIABLES GLOBALES
    DIAGONAL_G: tableau de booléens de taille 2n - 1
    DIAGONAL_D: tableau de booléens de taille 2n - 1
    COLONNE: tableau de booléens de taille n 
    POSITION: tableau de entiers
VARIABLES
    col: entier
DEBUT
    SI (ligne = n) ALORS
        traitement(position)
    SINON
        POUR col ALLANT DE 1 JUSQU'À n
            SI COLONNE[col], DIAGONAL_G[numG(ligne, col)], DIAGONAL_D[numD(ligne, col)] sont libres ALORS
                COLONNE[col] <- occupé
                DIAGONAL_G[numG(ligne, col)] <- occupé
                DIAGONAL_D[numD(ligne, col)] <- occupé
                reines(ligne+1, n);
                COLONNE[col] <- libre
                DIAGONAL_G[numG(ligne, col)] <- libre
                DIAGONAL_D[numD(ligne, col)] <- libre 
            FSI
        FPOUR
    FSI
FIN
```
### Example :
Voici un example d'execution pour n = 3. 
<p align="center">
  <img src="https://miro.medium.com/max/1200/1*89khR1bWFu0Tc0TY44_vFw.png"/>
</p>

> SOURCE = https://towardsdatascience.com/
## Langage C
Voici l'implementation en langage C
```c
#include <stdio.h>
#include <stdlib.h>
#define num_r(i, j) ((int)i-(int)j+(size-1))
#define num_l(i, j) (i+j)

typedef unsigned int uint;
typedef enum{false = 0, true = 1} bool;

uint* arr;
uint* columns;
uint* diag_r;
uint* diag_l;
uint size;

bool valid2(uint line, uint col) {
    if(columns[col])
        return false;
    if(diag_r[num_r(line, col)] || diag_l[num_l(line,col)])
        return false;
    return true;
}

void queen(uint line) {
    if(line == size) {
      printf("One solution is : ");
      printf("[");
      for(uint i = 0; i < size-1; i++) {
          printf("%d,",arr[i]);
      }
      printf("%d]\n", arr[size-1]);
      print_chessboard(arr, size); // affiche la configuration valide
      return;
    }
    for(uint col = 0; col < size; col++) {
        if(valid2(line, col)) {
            arr[line] = col;
            columns[col] = true;
            diag_r[num_r(line, col)] = true;
            diag_l[num_l(line, col)] = true;

            queen(line+1);

            arr[line] = -1;
            columns[col] = false;
            diag_r[(int)line-(int)col + (size-1)] = false;
            diag_l[line+col] = false;

        }
    }
}

void print_all_solutions(uint size_bis) {
    size = size_bis;
    arr = calloc(size, sizeof(uint));
    columns = calloc(size, sizeof(uint));
    diag_r = calloc(2*size - 1, sizeof(uint));
    diag_l = calloc(2*size - 1, sizeof(uint));

    queen(0);

    free(diag_r);
    free(diag_l);
    free(columns);
    free(arr);
}

int main(void) {
    print_all_solutions(8);
    return 0;
```
## Complexité de l'algorithme
Appelons l la ligne courante, notons que à la l-ième appel de la fonction le nombre de cases libres est majoré par ```n-l+1``` (+1 car nos tableaux sont indexés de 1 à n et pas de 0 à n-1).

Au départ le nombre des cases libre à la ligne 1 est n, pour chaque dame mise dans ces cases on testera les ```n-2+1``` casses disponibles dans la ligne 2 et succesivement ce qui fait une complexité majorée par
``` 
O(n*(n-1)*(n-2)*(n-3)....(n-(n-1)) = O(n!)
```

## Benchmark
Avec le temps de calcul empirique on remarque que notre function est de l'ordre de n!
<p align="center">
  <img src="https://raw.githubusercontent.com/dxkkxn/univ-tln/master/L3/S5/I51-Algorithmique-des-graphes/exp/chess/xd2.png"/>
</p>

> temps de calcul(seconds)/taille de l'échequier 

## Nombre de solutions en fonction de n

n  |   Solutions totales  |
-------|--------------------- |
1      |                 1  |  
2      |                 0  |  
3      |                 0  |  
4      |                 2  |  
5      |                10  |  
6      |                 4  |  
7      |                40  |  
8      |                92  |  
9      |               352  |  
10     |               724  |  
11     |             2,680  |  
12     |            14,200  |  
13     |            73,712  |  
14     |           365,596  |  
15     |         2,279,184  |  
16     |        14,772,512  |  
17     |        95,815,104  |  
18     |       666,090,624  |  
19     |     4,968,057,848  |  
20     |    39,029,188,884  |  
21     |   314,666,222,712  |  
22     | 2,691,008,701,644  |  
23     |24,233,937,684,440  |  
24     |  227,514,171,973,736| 
25     |2,207,893,435,808,352| 
26     |22,317,699,616,364,044|
> source: https://oeis.org/A000170
