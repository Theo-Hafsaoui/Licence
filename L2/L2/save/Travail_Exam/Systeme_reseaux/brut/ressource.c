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

void P(int id){
  struct sembuf sb;
  sb.sem_num = 0;
  sb.sem_op = -1;
  sb.sem_flg = 0;

  semop(id, &sb, 1);
}

void V(int id)
{
  struct sembuf sb;
  sb.sem_num = 0;
  sb.sem_op = 1;
  sb.sem_flg = 0;

  semop(id, &sb, 1);

}
void main()
{
  int semid = semget(ftok("ressource",'N'),1,0777|IPC_CREAT); //IPC_EXCL n'est pas là car sinon semget() renvoie une erreur si l'ensemble de sémaphores existe déjà
  printf("val de sem %d\n",semctl(semid,0,GETVAL));
  V(semid);
  printf("val de sem %d\n",semctl(semid,0,GETVAL));
  P(semid);
  printf("val de sem %d\n",semctl(semid,0,GETVAL));
  sleep(10);

  V(semid);
  printf("val de sem %d\n",semctl(semid,0,GETVAL));

  //semop("")
}
