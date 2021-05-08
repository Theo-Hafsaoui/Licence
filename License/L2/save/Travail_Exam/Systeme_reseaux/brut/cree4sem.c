#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <errno.h>
void main()
{
  int cle = ftok("ressource",(key_t)'C');
  printf("%d\n",cle);
  int semid = semget(cle,4,0777|IPC_CREAT|IPC_EXCL);
  printf("groupe de 4 sémaphores de semid %d\n",semid);
  printf("code erreur %d",errno);
};
