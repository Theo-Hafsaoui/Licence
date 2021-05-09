#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int c = 2;

void c_plus(int sig){
  printf("\nConstante c incrémentée\n");
  c++;
}

void c_minus(int sig){
  printf("\nConstante c décrémentée\n");
  c--;
}

void main(int argc, char * argv[]){
  int n = atoi(argv[1]);
  int res_2;
  int res_3;
  int res_1;

  time_t t;
  int t_1[2];
  int t_2[2];
  int t_3[2];
  srand((unsigned)time(&t));
  pipe(t_1);
  pipe(t_2);
  pipe(t_3);
  pid_t p1 = getpid();
  pid_t p2 ;
  pid_t p3;


  if (p2 = fork() == 0){
    p2 = getpid();

    //printf("%d\n",getpid());
  }

  if ((getpid() == p1 )&& (p3 = fork() == 0))
    p3 = getpid();

  //if(getpid() == p1)
    //printf("p1:%d   p2:%d   p3:%d\n",p1,p2,p3);
     if(getpid() == p1){
      close(t_1[0]);
      close(t_3[0]);
      close(t_2[1]);
      close(t_2[0]);
    }

    if(getpid() == p2){
      close(t_1[1]);
      close(t_3[1]);
      close(t_2[0]);
      close(t_3[0]);
    }

    if(getpid() == p3){
      close(t_1[1]);
      close(t_1[0]);
      close(t_2[1]);
      close(t_3[1]);
    }




  for(int i = 0; i < n; i++)
    { //printf("\npid : %d\n",getpid());
      if (p1 == getpid())
      { //printf("P1\n");
        res_1 = rand()%10;
        write(t_1[1],&res_1,sizeof(res_1));
        write(t_3[1],&res_1,sizeof(res_1));
      }

      if (p2 == getpid())
      {//printf("P2\n");

        signal(SIGUSR1,c_plus);
        signal(SIGUSR2,c_minus);
        read(t_1[0],&res_2,sizeof(res_2));
        res_2 += c;
        write(t_2[1],&res_2,sizeof(res_2));

      }
      if (p3 == getpid()){
        //printf("P3\n");
        read(t_2[0],&res_2,sizeof(res_2));
        read(t_3[0],&res_3,sizeof(res_3));
        printf("Etape %d\n( %d , %d ) ,   %d\n",i,res_3,res_2,res_2-res_3);
      }


    }
    //printf("%d\n",getpid());
    wait(&p2);
    wait(&p3);
    exit(0);
  }
