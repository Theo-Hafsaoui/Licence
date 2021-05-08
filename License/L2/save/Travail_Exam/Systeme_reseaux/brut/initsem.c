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

void main(){
  semctl(0,2,SETVAL,1);
  printf("sem 3 %d\n",semctl(0,2,GETVAL));
  printf("pid : %d\n",semctl(0,2,GETPID));
  printf("pid : %d\n",getpid());
  semctl(0,0,IPC_RMID);
}
