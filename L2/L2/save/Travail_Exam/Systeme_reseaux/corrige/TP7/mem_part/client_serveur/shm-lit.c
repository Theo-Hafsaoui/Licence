/* shm-lit.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define CLE 123
int main()
{
  int shmid ; /* identificateur de la memoire commune */
  int size = 1000 ;
  char *path="shm-ecrit.c";
  char *mem ;
  int flag = 0 ;
  /*
   * recuperation du shmid
   */
  if (( shmid = shmget(ftok(path,(key_t)CLE), size,0)) == -1) {
    perror("Echec de shmget") ;
    exit(1) ;
  }
  printf("identificateur du segment: %d \n",shmid) ;
  printf("ce segment est associe a la cle unique: %d\n",
         ftok(path,(key_t)CLE)) ;
  /*
   * attachement du processus a la zone de memoire
   * recuperation du pointeur sur la zone memoire commune
   */
  if ((mem = shmat (shmid, 0, flag)) == (char*)-1){
    perror("attachement impossible") ;
    exit (1) ;
  }
  /*
   * traitement du contenu du segment
   */
  printf("lecture du segment memoire partage : %s\n",mem) ;

  /*
   * detachement du segment
   */
  if (shmdt(mem)== -1){
    perror("detachement impossible") ;
    exit(1) ;
  }
  exit(0);
}
