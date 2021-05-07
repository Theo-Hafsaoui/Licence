/*
* exemple d'utilisation de semctl()
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define CLE 123
union semun {
  int val ;
  struct semid_ds *buf ;
  ushort array[4] ;
} arg ;

int main()
{
  int semid, val_sem ,val_pid;
  char *path = "cree4sem.c" ;
  /*
   * recuperation de l'identificateur
   * de l'ensemble de semaphores de cle 123
   */
  if (( semid = semget(ftok(path,(key_t)CLE),0,0)) == -1 ) {
    perror ("Semget()") ;
    exit(1) ;
  }
  printf("L'ensemble de semaphore a comme semid : %d\n",semid) ;
  printf("La cle d'acces est %d\n",ftok(path,(key_t)CLE)) ;
  /*
   * mise a 1 du
   * troisieme semaphore
   */
  arg.val = 1 ;
  if ( semctl(semid,2,SETVAL,arg) == -1){
    perror("Semctl()") ;
    exit(1) ;
  }
  /*
   * lecture du
   * troisieme semaphore
  */
  if ( (val_sem = semctl(semid,2,GETVAL,arg)) == -1){
    perror("Semctl()") ;
    exit(1) ;
  }
  else printf("la valeur du troisieme semaphore est : %d\n",val_sem) ;
  /*
   * lecture du pid du processus qui a
   * effectue la derniere operation
   */
  if (( val_pid = semctl(semid,2,GETPID,arg) )== -1){
    perror("Semctl()") ;
    exit(1) ;
  }
  else printf("la valeur du pid du processus qui a effectue la derniere operation est : %d,\nmon pid est :%d\n",val_pid,getpid()) ;
  /*
   * destruction du semaphore
   */
  if (semctl(semid,0,IPC_RMID,0)==-1){
    perror("impossible de detruire le semaphore") ;
    exit(1) ;
  }
  exit(0);
}
