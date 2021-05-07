/*
 * programme execute par le second processus
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define CLE 123
int semid ;
struct sembuf operation[1] ;
char *path = "ressource.c" ;
int main()
{
  /*
   * recuperation du semid
   */
  if (( semid = semget(ftok(path,(key_t)CLE),0,0))==-1){
    perror("impossible de retrouver l'ensemble de semaphores") ;
    exit(1) ;
  }
  printf("process2: traite les sem : semid %d\n",semid) ;
  /*
   * boucle d'attente de la disponibilite du semaphore.
   * On demande de ne pas rester bloquer en attente
   * en positionnement le drapeau IPC_NOWAIT
   */
  operation[0].sem_num = 2 ;
  operation[0].sem_op = -1 ;
  /* operation[0].sem_flg = SEM_UNDO ; */
  operation[0].sem_flg = IPC_NOWAIT + SEM_UNDO ;

  while ( semop(semid,operation,1) == -1) {
   printf(" demande du process2 : semaphore non disponible\n") ;
    sleep(1) ;
  }
  printf(" semaphore alloue au process2\n") ;
  /*
   * liberation du segment de semaphore
   */
  if (semctl(semid,0,IPC_RMID,0) == -1){
    perror("probleme lors de la destruction des semaphores") ;
    exit(1) ;
  }
  exit(0);
}
