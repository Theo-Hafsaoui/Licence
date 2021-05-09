#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>


typedef int Semaphore[2];


void initSem(Semaphore S,int N)
{
  pipe(S);
  char m;
  m ='a';
  for (int i = 0; i < N; i++)
  {
    write(S[1],&m,sizeof(m));

  }

}
void P(Semaphore S)
{
  char m;
  //m ='a';
  read(S[0],&m,sizeof(m));
}

void V(Semaphore S)
{
  char m;
  m ='a';
  write(S[1],&m,sizeof(m));

}



  void main(int argc, char * argv[])
{
  time_t t;
  srand((unsigned)time(&t));
  int nd = atoi(argv[1]);
  int na = atoi (argv[2]);
  int att;
  Semaphore S;
  initSem(S,1);

  for(int i = 0; i < na ; i++)
  {
    if(fork() == 0)
    {
      att = 1 + rand() % 11;

      sleep(att);
      printf("\nVol %d souhaite atterrir\n",getpid());
      P(S);
      printf("\nVol %d en phase d'atterrissage\n",getpid());
      sleep(3);
      V(S);
      printf("\nPiste libérée par le Vol %d\n",getpid());
      exit(0);
    }
  }
  for(int j = 0; j < nd ; j++)
  {
    if(fork() == 0)
    {
      att = 1 + rand() % 11;
      sleep(att);
      printf("\nVol %d souhaite décoller\n",getpid());
      P(S);
      printf("\nVol %d en phase de décollage\n",getpid());
      sleep(5);
      V(S);
      printf("\nPiste libérée par le Vol %d\n",getpid());
      exit(0);
    }
  }
}
