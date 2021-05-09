#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef int Semaphore[2];

int initSemaphore(Semaphore S, int n)
{
 int i, code;
 char c='a';
 if ((code = pipe(S)) == 0);
      for (i = 1; i <=n ; i++)
        write(S[1],&c,1);
 return(code);
}

void P(Semaphore S)
{
  char c ;
  read(S[0],&c,1);
}

void V(Semaphore S)
{
  char c='a' ;
  write(S[1],&c,1);
}



int main(int argc, char const *argv[])
{
    int PDeco=atoi(argv[1]);
    int PAtter=atoi(argv[2]);
    int Time_att=3;
    int Time_dec=5;
    Semaphore s;int id;
    initSemaphore(s,1);
    srand(time(NULL));int Waiting_time;
    for (int i = 0; i < PAtter; i++)
    {
        if(fork()==0){
            id=getpid();
            Waiting_time=rand()%10;
            printf("Vol numero %d souhaite atterrir\n",id);
            P(s);
            printf("    Vol numero %d en phase d'atterrissage\n",id);
            sleep(Waiting_time);
            V(s);
            printf("Piste liberee par vol numero %d\n",id);
            exit(0);
        }
    }    
    for (int j = 0; j < PDeco; j++)
    {
        if(fork()==0){
            id=getpid();
            Waiting_time=rand()%10;
            printf("Vol numero %d souhaite decoller\n",id);
            P(s);
            printf("    Vol numero %d en phase de decolage\n",id);
            sleep(Waiting_time);
            V(s);
            printf("Piste liberee par vol numero %d\n",id);
            exit(0);
        }
    }
    exit(0);
    


}
