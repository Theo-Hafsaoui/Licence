#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int cpt=0;
static int* qpos;
int** Board(int dim){
  int** Bd= calloc(sizeof(int*), 4);
  int* ligne=calloc(sizeof(int),dim);Bd[0]=ligne;
  int* diagG=calloc (sizeof(int),2*dim);Bd[1]=diagG;
  int* diagD=calloc (sizeof(int),2*dim);Bd[2]=diagD;
  int* colone=calloc (sizeof(int), dim);Bd[3]=colone;
  return Bd;
}


int numd(int i, int j)
{
    return i - j + 8;
}                          

void Free_B(int ** Bd){
  for (int i=0; i<4; i++) {
    free(Bd[i]);
  }
  free(Bd);
}

int numg(int i, int j)
{
    return i+j;
}                         
int val(int i, int j, int dim, int** bd)
{
  if (bd[0][j]){
    return 0;
  }
  if (bd[1][numg(i, j)]){
    return 0;
  }
  if (bd[2][numd(i, j)]){
    return 0;
  }
  return 1;
}

int Queen(int q, int dim, int** Bd){
  int ligne;int i=0;
  if (ligne==dim) {
    cpt++;
    return 1;
  }
  for (ligne=0; ligne<dim; ligne++) {
      if (val(q, ligne, dim, Bd)) {
       qpos[q]=ligne;  
       Bd[0][ligne]=1;
       Bd[1][numd(i,ligne)]=1;
       Bd[2][numg(i,ligne)]=1;
       Queen(q+1, dim, Bd);
       qpos[q]=0;
       Bd[0][ligne]=1;
       Bd[1][numd(i,ligne)]=1;
       Bd[2][numg(i,ligne)]=1;
      }
  }
}

int main(int argc, char *argv[]){
  int a=1;
  qpos = calloc(a, sizeof(int));
  int** Bd=Board(a);
  Queen(0, a, Bd); 
  printf("Sol=%d",cpt);
  return 0;
}
