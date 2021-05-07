#include <unistd.h>
#include <time.h>
#include <wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>


#define CLE 1
#define CLE_MEM 2

int semid ;
int shmid ;
int *caisse;


struct sembuf operation[2] ;
char *path = "mineOr.c" ;

union {
  int val ;
  struct semid_ds *buf ;
  ushort array[3] ; } arg ;


void mineur(int numMineur) {
   srand((unsigned)time(NULL)*getpid());

  int qtOr = 0;
  int attenteAvantTravail = 1+(int) (5.0*rand()/(RAND_MAX+1.0));
  int dureeDeTravail = 1+(int) (5.0*rand()/(RAND_MAX+1.0));

  /* attente avant de se mettre au travail */
  printf("Le mineur %d attend %d heures avant de travailler.\n",numMineur,attenteAvantTravail);
  sleep(attenteAvantTravail);

  /* Prise de la pelle */
  operation[0].sem_num = 0 ;
  operation[0].sem_op = -1 ;
  operation[0].sem_flg = SEM_UNDO ;
  /* Prise de la pioche */
  operation[1].sem_num = 1 ;
  operation[1].sem_op = -1 ;
  operation[1].sem_flg = SEM_UNDO ;
  if (semop(semid,operation,2) == -1)
    perror("Erreur d'op<E9>ration sur le s<E9>maphore\n");
  printf("Le mineur %d prend une pelle et une pioche\n",numMineur);

  /* mise au travail */
  printf("Le mineur %d commence <E0> travailler pour %d heures.\n",numMineur,dureeDeTravail);
  sleep(dureeDeTravail);
  printf("Le mineur %d a extrait %d g d'or\n",numMineur,qtOr=1+(int) (1000.0*rand()/(RAND_MAX+1.0)));

 /* Remise de la pelle */
  operation[0].sem_num = 0 ;
  operation[0].sem_op = 1 ;
  operation[0].sem_flg = SEM_UNDO ;
  /* Remise de la pioche */
  operation[1].sem_num = 1 ;
  operation[1].sem_op = 1 ;
  operation[1].sem_flg = SEM_UNDO ;
  if (semop(semid,operation,2) == -1)
    perror("Erreur d'op<E9>ration sur le s<E9>maphore\n");
  printf("Le mineur %d rend une pelle et une pioche\n",numMineur);

  /* Prise de la caisse */
  operation[0].sem_num = 2 ;
  operation[0].sem_op = -1 ;
  operation[0].sem_flg = SEM_UNDO ;
  if (semop(semid,operation,2) == -1)
    perror("Erreur d'op<E9>ration sur le s<E9>maphore\n");
  *caisse = *caisse + qtOr;
  printf("Le mineur %d met %d g d'or dans la caisse\n",numMineur,qtOr);
  /* rendu de la caisse */
  operation[0].sem_num = 2 ;
  operation[0].sem_op = 1 ;
  operation[0].sem_flg = SEM_UNDO ;
  if (semop(semid,operation,2) == -1)
    perror("Erreur d'op<E9>ration sur le s<E9>maphore\n");
}

int main(int argc, char *argv[])
{
   if (argc<3) {
     printf("mineOr nbDeMineurs nbDePelles nbDePioches\n");
     exit(0);
   }

   int pid = getpid();
   int numMineur = 1;

   int nbDeMineurs = atoi(argv[1]);
   int nbDePelles = atoi(argv[2]);
   int nbDePioches = atoi(argv[3]);

    /*
     * creation d'un ensemble de deux semaphores pour repr<E9>senter
     * les pelles, les pioches et la quantite d'or.
     */
    if (( semid = semget(ftok(path,(key_t)CLE),4,0600|IPC_CREAT))==-1){
      perror("impossible de creer l'ensemble de semaphores") ;
      exit(1) ;
    }
    arg.val=nbDePelles ;
    if ((semctl(semid,0,SETVAL,arg))==-1){
      perror("Erreur d'initialisation") ;
      exit(1);
    }
    arg.val=nbDePioches ;
    if ((semctl(semid,1,SETVAL,arg))==-1){
      perror("Erreur d'initialisation") ;
      exit(1);
    }
    arg.val=1 ;
    if ((semctl(semid,2,SETVAL,arg))==-1){
       perror("Erreur d'initialisation") ;
      exit(1);
    }

    /* creation de la zone de memoire partagee qui represente
       la caisse */

 /*
   * recuperation du shmid
   */
  if (( shmid = shmget(ftok(path,(key_t)CLE_MEM), 4,IPC_CREAT|IPC_EXCL|SHM_R|SHM_W)) == -1) {
    perror("Echec de shmget") ;
    exit(1) ;
  }

/*
   * attachement du processus a la zone de memoire
   * recuperation du pointeur sur la zone memoire commune
   */
  if ((caisse = (int *)shmat (shmid, 0, 0)) == (int*)-1){
    perror("attachement impossible") ;
    exit (1) ;
  }

  *caisse = 0;

    while (numMineur<=nbDeMineurs) {
      pid = fork();
      if (pid == 0)
        {
          mineur(numMineur);
          exit(0);
        }
      else printf("cr<E9>ation du mineur %d (%d)\n",numMineur,pid);
      numMineur++;
    }

    while ((pid=waitpid(-1,NULL,0)) != -1)
      printf("Le mineur de pid %d a fini.\n",pid);



    printf("Fin du travail des mineurs, la caisse contient: %d g d'or.\n",*caisse);

 /*
   * detachement du segment
   */
  if (shmdt(caisse)== -1){
    perror("detachement impossible") ;
    exit(1) ;
  }

  /* Destruction du semaphore et de la memoire partagee */
  shmctl(shmid,IPC_RMID,NULL);
  semctl(semid,0,IPC_RMID,NULL);
  exit(0);
}
