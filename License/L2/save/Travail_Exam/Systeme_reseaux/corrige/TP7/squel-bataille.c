#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

/* A VOIR
   union semun {
   int val ;
   struct semid_ds *buf ;
   ushort *array ;
   } arg_ctl ;
*/

/* Une seul groupe de sémaphore dans ce programme */
/* Nous garderons l'ID en global */
key_t SEMID;

void sem_create(key_t cle, int semNum) /* creation d'un ensemble de semaphores relie a cle */
{
  int semid ;
  semid = semget(ftok("bataille.c",cle),semNum,IPC_CREAT|IPC_EXCL|0666) ;
  if (semid == -1) {
    semid = semget(ftok("bataille.c",cle),semNum,IPC_EXCL|0666) ;
    if (semid == -1) {
      perror("Erreur semget()") ;
      exit(1) ;
    }
  }
  SEMID = semid ;
}

void init_sem(int SemNum, int initval)
{
  union semun {
    int val ;
    struct semid_ds *buf ;
    ushort *array ;
  } arg_ctl ;

  arg_ctl.val = initval ;
  if (semctl(SEMID,SemNum,SETVAL,arg_ctl) == -1) {
    perror("Erreur initialisation semaphore") ;
    exit(1) ;
  }
}

void P(int sem)
{
  struct sembuf sempar ;
  sempar.sem_num = sem ;
  sempar.sem_op = -1 ;
  sempar.sem_flg = SEM_UNDO ;
  if (semop(SEMID, &sempar, 1) == -1)
    perror("Erreur operation P") ;
}

void V(int sem)
{
  struct sembuf sempar ;
  sempar.sem_num = sem ;
  sempar.sem_op = 1 ;
  sempar.sem_flg = SEM_UNDO ;
  if (semop(SEMID, &sempar, 1) == -1)
    perror("Erreur operation V") ;
}

void sem_delete()
{
  if (semctl(SEMID,0,IPC_RMID,0) == -1)
    perror("Erreur dans destruction semaphore") ;
}

int main (int argc, char* argv[]){
  typedef int booleen;
#define faux 0
#define vrai 1
#define S0   0 /* semaphore 0 du groupe */
#define S1   1
#define S2   2
#define NBBAT 5 /* Nombre de bateaux */
#define RATE 1
#define COULE 2

#define CLE 123

  char *path="bataille.c";

  char Bat [NBBAT][NBBAT]; /* Mes bateaux */
  char BatA [NBBAT][NBBAT]; /* Mes bateaux */

  int i,j,N;
  int NumM;
  typedef struct {
    int R; /* Résultat du tir précédent */
    int X; /* Nouveau tir */
    int Y;
  } Tir;

  Tir *pTir;
  int X, Y;
  int Fin = faux;
  int param = atoi (argv[1]);

  int NBCAdv = 0; /* Nb de bateaux adverses coulés */
  int NBC = 0;

  printf("Bataille navale\n");

  for (i=0; i<NBBAT; i++){
    for (j=0; j<NBBAT; j++){
      Bat[i][j] = '.';
      BatA[i][j] = '.';
    }
  }

  srand(getpid());
  N=NBBAT;
  while (N>0) {
    i = rand() % NBBAT;
    j = rand() % NBBAT;
    if (Bat[i][j] == '.'){
      Bat[i][j]='B';
      N--;
    }
  }

  printf("Initialisation des bateaux OK\n");

  /* ### Exercice 1 ### */
  NumM = shmget (ftok(path,(key_t)CLE),sizeof(Tir), IPC_CREAT | 0666);
  printf("NumM %d\n", NumM);
  pTir = (Tir*) shmat (NumM, NULL, 0);

  sem_create(ftok(path,(key_t)CLE), 3);

  if (param == 1){
    printf("Joueur 1\n");
    pTir->R=0;
    init_sem(S0, 1);
    init_sem(S1, 0);
    init_sem(S2, 2);
  } else     printf("Joueur 2\n");


  P(S2); /* seulement deux joueurs */

  while (!Fin) {
    printf("En attente de l'autorisation de tir....\n");
    param == 1 ? P(S0) : P(S1);
    printf("OK\n");

    /* Résultat de mon tir précédent */
    switch (pTir->R) {
    case 0 :
      /* premier tir : pas de résultats */
      break;
    case RATE :
      if (BatA[X][Y] != 'C') BatA[X][Y] = 'R';
      printf("Mon tir raté en %d %d\n", X, Y);
      break;
    case COULE :
      BatA[X][Y] = 'C';
      NBCAdv++;
      printf("Adversaire coul<E9> en %d %d, Nb de bateaux coulés: %d\n",X, Y,NBCAdv);
      if (NBCAdv == NBBAT) {
        Fin = 1;
        printf("Tous les bateaux adverses sont coulés\n");
      }
      break;
    }

    if (!Fin) {
      if (pTir->R == 0) {
        pTir->R = -1; /* de Resultat pour l'adversaire */
      }
      else if (Bat[pTir->X][pTir->Y] == 'B'){
        printf("== Mon bateau coulé en %d %d\n",pTir->X,pTir->Y);

        pTir->R = COULE;
        Bat[pTir->X][pTir->Y] = 'C';
        NBC++;
        if (NBC==NBBAT) {
          Fin = vrai;
          printf("Tous mes bateaux sont coulés.\n");
        }
    } else {
      if (Bat[pTir->X][pTir->Y] != 'C') {
        Bat[pTir->X][pTir->Y] = 'R';
      }
      printf("== Tir adverse raté en %d %d\n",pTir->X,pTir->Y);
      pTir->R = RATE;
    }
  }

  printf("\nMes bateaux         Adversaires\n\n");
  for(i=0; i<NBBAT; i++) {
    for(j=0; j<NBBAT;j++) printf("%c ",Bat[i][j]);
    printf("%10s", " ");
    for(j=0; j<NBBAT;j++) printf("%c ",BatA[i][j]);
    printf("\n");
  }

  printf("\nCoulés : %d         Coulés : %d\n",NBC, NBCAdv);

  if (!Fin) {
    printf("\n\n");
    printf("Tir en X Y ?");scanf("%d %d",&X, &Y);
    pTir->X = X;
    pTir->Y = Y;
  }
  param == 1 ? V(S1):V(S0);
  }
  if (param==1) sem_delete();
  exit(0);
 }
