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
#include <sys/wait.h>
#include <time.h>

void P(int id){
  struct sembuf sb[2];
  sb[0].sem_num = 0;
  sb[0].sem_op = -1;
  sb[0].sem_flg = 0;
  sb[1].sem_num = 1;
  sb[1].sem_op = -1;
  sb[1].sem_flg = 0;

  semop(id, sb, 2);
}

void V(int id)
{
  struct sembuf sb[2];
  sb[0].sem_num = 0;
  sb[0].sem_op = 1;
  sb[0].sem_flg = 0;
  sb[1].sem_num = 1;
  sb[1].sem_op = 1;
  sb[1].sem_flg = 0;

  semop(id, sb, 2);
}


union semun {
               int              val;    // Value for SETVAL
               struct semid_ds *buf;    // Buffer for IPC_STAT, IPC_SET
               unsigned short  *array;  //Array for GETALL, SETALL
               struct seminfo  *__buf;  // Buffer for IPC_INFO
                                           //(Linux-specific)
} arg;



void main(int argc, char ** argv)
{
  time_t t;
  int att;
  int trav;
  int extr;
  int n_mineur = atoi(argv[1]);
  int n_pioche = atoi(argv[2]);
  int n_pelle = atoi(argv[3]);
  printf("pioche %d \npelle %d \n",n_pioche,n_pelle);

  int sem_equip = semget(ftok("ressource",'P'),2,0777|IPC_CREAT);
//  printf("val de sem %d\n",semctl(sem_equip,0,GETVAL));
//  printf("val de sem %d\n",semctl(sem_equip,1,GETVAL));
  arg.val = n_pioche;

  semctl(sem_equip,0,SETVAL,arg);
  arg.val = n_pelle;
  semctl(sem_equip,1,SETVAL,arg);
//  printf("val de sem %d\n",semctl(sem_equip,0,GETVAL));
  //printf("val de sem %d\n",semctl(sem_equip,1,GETVAL));
  //printf("Logistique :\nmineur : %d \npioche : %d\npelle : %d\n",n_mineur,n_pioche,n_pelle);

  for (int i = 0; i < n_mineur; i++)
  {
    if(fork() == 0)
    {
      srand((unsigned)time(&t) ^getpid());
      printf("Création du Mineur %d ( %d )\n",i,getpid());
      att = (rand()%5)+1;
      printf("Le Mineur %d va attendre %d heures\n",i,att);
      sleep(att);
      P(sem_equip);
      trav = (rand()%5)+1;
      printf("Le Mineur %d va travailler %d heures\n",i,trav);
      sleep(trav);
      V(sem_equip);
      printf("Le Mineur %d a extrait %d g d'or\n",i,(rand()%1000)+1);
      exit(0);

    }
  }
    while(waitpid(-1, NULL, 0)!= -1)
    {}
      semctl(sem_equip,0,IPC_RMID);
    exit(0);

}
