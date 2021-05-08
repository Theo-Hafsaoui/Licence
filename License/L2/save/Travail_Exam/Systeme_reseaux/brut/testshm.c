#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>

//int shmget(key_t key, size_t size, int shmflg);
void main()
{
  key_t key = ftok("ressource",123);
  int id = shmget(key,2,0777|IPC_CREAT);
  printf(" cle %d \n id %d \n",key,id);
  //ipcrm shm id_segment memoire


}
