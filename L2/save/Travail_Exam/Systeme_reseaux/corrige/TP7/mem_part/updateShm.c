#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define CLE 123
struct shmid_ds buf ;
int main()
{
  char *path = "testshm.c" ; /* ATTENTION la clé doit être la même que lors de la création du segment */
  int shmid ;
  int size = 1000 ;
  /* recuperation de l'identificateur du segment de memoire de cle 123 */
  if (( shmid = shmget(ftok(path,(key_t)CLE),size,0)) == -1 ) {
    perror ("Erreur shmget()") ;
    exit(1) ;
  }
  /* lecture du pid du processus qui a effectue la derniere operation*/
  if ( shmctl(shmid,IPC_STAT,&buf) == -1){
    perror("Erreur shmctl()") ;
    exit(1) ;
  }
  printf("ETAT DU SEGMENT DE MEMOIRE PARTAGEE %d\n",shmid) ;
  printf("identificateur de l'utilisateur proprietaire: %d\n",buf.shm_perm.uid) ;
  printf("identificateur du groupe proprietaire: %d\n",buf.shm_perm.gid) ;
  printf("identificateur de l'utilisateur createur: %d\n",buf.shm_perm.cuid) ;
  printf("identificateur du groupe createur: %d\n",buf.shm_perm.cgid) ;
  printf("mode d'acces: %d\n",buf.shm_perm.mode) ;
  printf("taille de la zone memoire: %d\n",buf.shm_segsz) ;
  printf("pid du createur: %d\n",buf.shm_cpid) ;
  printf("pid (derniere operation): %d\n",(int) buf.shm_lpid) ;
  /* destruction du segment */
  if ((shmctl(shmid, IPC_RMID, NULL)) == -1){
    perror("Erreur shmctl()") ;
    exit(1) ;
  }
  exit(0);
}
