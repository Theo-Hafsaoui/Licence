/*
 * exemple d'utilisation de shmget()
 */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define CLE 123
int main()
{
  int shmid ; /* identificateur de la memoire commune */
  int size = 1000 ;
  char *path="testshm.c" ;
  if (( shmid = shmget(ftok(path,(key_t)CLE), size, IPC_CREAT|IPC_EXCL|SHM_R|SHM_W)) == -1) {
    perror("Echec de shmget") ;
    exit(1) ;
  }
  printf("identificateur du segment: %d \n",shmid) ;
  printf("ce segment est associe a la cle unique: %d\n",
         ftok(path,(key_t)CLE)) ;
  exit(0);
}
