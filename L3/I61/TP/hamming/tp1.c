#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<math.h>
typedef unsigned uint;


void affiche_binaire(int val){
  int msk,bin=0;
  for (int i=7; i>=0; i--) {
    msk=1<<i;
    bin=val&msk;
    printf("%d",bin>=1);
  }
  printf("\n");
}

int bruite(int octet, float p , int k){
  int seuill=k;int msk;int i=0;
  affiche_binaire(octet);
  int var_rand=rand();int super_seuill=p*RAND_MAX;
  int bool_rand=var_rand>super_seuill;
  while (seuill&&bool_rand) {
    i=(i+1)%8;
    if (rand()%2) {
      msk=1<<i;
      octet=octet^msk;
      seuill--;
   } 
  }
  affiche_binaire(octet);
  return octet;
}
int** mots(uint k){
  double po=pow(2, k);
  int **m_res=calloc(po, sizeof(uint));
  for (double i=0; i<po; i++) {
    
  }
  return m_res;
}

void copie(const char* input_file, const char* output_file){
  FILE* origin=fopen("garbage.txt" , "r");
  FILE* out=fopen("garbage_bruit.txt" , "w");
  char c = fgetc(origin);
  while (c != EOF){
    fputc(bruite(c, 0.2, 1), out);
    c = fgetc(origin);
  }
  fclose(origin);
  fclose(out);
}

int w_hamming(int oct1,int oct2){
  return (__builtin_popcount(oct1^oct2));
}

int* vecteur(int val){
  int* v_res=calloc(8, sizeof(int));
  int msk,bin=0;
  for (int i=7; i>=0; i--) {
    msk=1<<i;
    bin=val&msk;
    v_res[i]=(bin>=1);
  }
  return v_res;
}

int valeur(int* vect){
  int res=0;
  for (int i=0; i<8; i++) {
    if (vect[i]) {
    res+=1<<i;
    }
  }
  printf("res=%d",res);
  return res;
}

/*
 *Fonction int* encode(int** g, int* v, unsigned int k,
 *unsigneds int n) qui encode le vecteur binaire v de taille k à l’aide de la matrice génératrice g
 *représentant le code C(n, k)
 */
int* encode(int** g, int* v, uint k, uint n ){
  int* v_res=calloc(8, sizeof(int));int k_i;
  for (int i=0; i<n; i++) {
    k_i=0;
    for (int j=0; j<k; j++) {
      k_i+=g[i][j]*v[j];
    }
    v[i]=k_i;
  }
  return v_res;
}

void mots(unsigned int k){
  int** v_res=calloc(3, sizeof(int*));
  int a1[]={1,2,3};
  int a2[]={4,5,6};
  int a3[]={7,8,9};
  v_res[0]=a1;
  v_res[1]=a2;
  v_res[2]=a3;
  int v[]={1,-2,2};
  for (int i=0; i<pow(2, k); i++) {
    
  }
}

void affiche_m(int **a, int d){
    for (int i=0; i < d; i++){
      printf("tab =[");
      for (int j=0; j <= d; j++){
        printf("%d,",a[i][j]);
      }
      printf("%d]\n",a[i][2]);
    }
}

void affiche_v(uint *a,int n){
    printf("tab =[");
    for (int i=0; i <= n-2; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

int main (int argc, char *argv[])
{
  //affiche_binaire(5);
  //copie("./garbage.text", "./garbage_bruit.txt");
  //test mult_matr
  //int g[][3]={{1,2,3},{4,5,6},{7,8,9}};
  int** v_res=calloc(3, sizeof(int*));
  int a1[]={1,2,3};
  int a2[]={4,5,6};
  int a3[]={7,8,9};
  v_res[0]=a1;
  v_res[1]=a2;
  v_res[2]=a3;
  int v[]={1,-2,2};
  int *v_res2=encode(v_res, v, 3, 3);
  //affiche_g();
  srand(time(NULL));
  //int *t=vecteur(5);
  //bruite(8, 0.5, 2);
  return 0;
}
