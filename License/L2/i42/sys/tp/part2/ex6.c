#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
  int val ;
  struct semid_ds *buf ;
  ushort array[4] ;
};

int main(int argc, char const *argv[])
{
    union semun arg;
    int id;
    if((id=semget(ftok(getenv("HOME"),'a'),4,0777|IPC_CREAT))==-1){
        printf("erreur creation semaphore\n");
        return(-1);
    }
    printf("semid sem=%d\n",id);
    arg.val=1;
    printf("la valeur de sem[2]= %d\n", semctl(id, 2, GETVAL));
    if (semctl(id, 2, SETVAL, arg)==-1)
    {
        printf("erreur affection\n");
    }
    printf("la valeur de sem[2]= %d\n", semctl(id, 2, GETVAL));
    if (semctl(id, 0, IPC_RMID, 0) == -1)
    {
        printf("erreur supresion\n");
        return(-1);
    }
}
