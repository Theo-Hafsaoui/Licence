/* shm-ecrit.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define CLE 123

int main()
{
  int shmid ; /* identificateur de la memoire commune */
  int size = 1000 ; /* taille en octet de la memoire */
  char *path="shm-ecrit.c";
  char *mem ; /* pointeur sur la zone commune */
  int flag = 0 ; /* drapeau associe au segment */

  /*
   * recuperation du shmid
   */
  if (( shmid = shmget(ftok(path,(key_t)CLE), size,IPC_CREAT|0666)) == -1) {
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
   * ecriture dans la zone de memoire partagee
   */
  strcpy(mem,"Ceci est ecrit en memoire commune") ;

  /*
   * detachement du segment
   */
  if (shmdt(mem)== -1){
    perror("detachement impossible") ;
    exit(1) ;
  }
  exit(0);
}
