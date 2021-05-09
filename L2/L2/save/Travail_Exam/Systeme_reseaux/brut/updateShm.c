#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


void main(int argc, char ** argv)
{
  struct shmid_ds buf;
  shmctl(atoi(argv[1]),IPC_STAT,&buf);
  unsigned short pid = buf.shm_cpid;
  unsigned short lid = buf.shm_lpid;
  struct ipc_perm str_dr = buf.shm_perm;
  uid_t uid = str_dr.uid;
  gid_t gid = str_dr.gid;
  printf("pid creat %hu pid courant %hu \n uid %hu   gid %d\n",pid,lid,uid,gid);

}
