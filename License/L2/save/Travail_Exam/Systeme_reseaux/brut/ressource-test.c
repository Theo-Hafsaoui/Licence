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
  int semid = semget(ftok("ressource",'N'),1,0777|IPC_CREAT);
  printf("[test] val de sem %d\n",semctl(semid,0,GETVAL));
  P(semid);
  printf("[test] val de sem %d\n",semctl(semid,0,GETVAL));

  sleep(3);

  V(semid);
  printf("[test] val de sem %d\n",semctl(semid,0,GETVAL));

  //semop("")
}
