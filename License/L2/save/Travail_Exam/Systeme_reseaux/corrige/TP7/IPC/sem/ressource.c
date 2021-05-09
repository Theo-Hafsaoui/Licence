/*
 * programme execute par le premier processus
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define CLE 123
int semid ;
struct sembuf operation[1] ;
char *path = "ressource.c" ;
union {
  int val ;
  struct semid_ds *buf ;
  ushort array[4] ; } arg ;
int main()
{
    /*
     * creation d'un ensemble de 4 semaphores
     */
    if (( semid = semget(ftok(path,(key_t)CLE),4,0600|IPC_CREAT))==-1){
      perror("impossible de creer l'ensemble de semaphores") ;
      exit(1) ;
    }
  printf("process1: je viens de creer un ensemble de semphore : %d\n",semid) ;
  /*
   * mise a 1 du troisieme semaphore
   */
  arg.val=1 ;
  if ((semctl(semid,2,SETVAL,arg))==-1){
    perror("semctl") ;
    exit(1);
  }
  /*
   * demande de ressource au troisieme semaphore
   */
  printf("process1: je vais demander une ressource\n") ;
  operation[0].sem_num = 2 ; /* operation sur le troisieme semaphore */
  operation[0].sem_op = -1 ; /* operation de decrementation */
  operation[0].sem_flg = SEM_UNDO; /* pour defaire les operations */
  if ( semop(semid,operation,1) == -1){
    perror("semop:operation de decrementation non effectuee") ;
    exit(1) ;
  }
  /*
   * attente pour bloquer le second processus
   */
  printf("process1: j'attends 10 sec\n") ;
  sleep(10) ; /* attente ... */
  printf("process1: j'ai fini d'attendre: je libere la ressource\n") ;
  /*
   * liberation de ressource
   */
   operation[0].sem_op = 1 ; /* incrementation */
  if ( semop(semid,operation,1) == -1){
    perror("semop:operation d'incrementation non effectuee") ;
    exit(1) ;
  }
    printf("mort de process1\n") ;
  exit(0) ;
}
