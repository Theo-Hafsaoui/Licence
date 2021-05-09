/*
* exemple d'utilisation de semget()
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define CLE 123
int main()
{
  int semid ; /* identificateur des semaphores */
   int cle;
  /*
   * allocation de quatre semaphores
   */
  if (( semid = semget(cle=ftok("cree4sem.c",(key_t)CLE), 4, 0600|IPC_CREAT|IPC_EXCL)) == -1) {
    perror("Echec de semget") ;
    exit(1) ;
  }
  printf(" le semid de l'ensemble de semaphore est : %d\n",semid) ;
  printf(" cet ensemble est identifie par la cle unique : %d\n",cle) ;
  exit(0);
}
