/*
Si on ne met pas de \n le flux de données
n'est pas flush on peut forcer un flush avec fflush()*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int N = 3;
/*
int main(void) {

  int i;

  printf("Je suis seul\n");
  for (i = 10; i > 0; i--) {
    printf("%d", i);
    fflush(stdout);
    sleep(1);
  }
  printf("\n Nous sommes deux maintenant\n");
  fork();
  while(1);
}
*/
/*
int main(){
  pid_t id_f;
  id_f = fork();
  if (id_f != 0){
    printf("Je suis père %d ",getpid());
    }
  else{
    printf("Je suis fils %d",id_f);}
}
*/
/*
int main(){
  int n ;

  if (fork()){
    n++;
    printf("p = %d \n",n);}
  else
  {
    n++;
    printf("f = %d \n",n);

  }
}
*/
/* EXO 4
pid_t id_f;

void traitersignal(int sig) {
   printf("Signal du fils %d bien recu\n",id_f);
}

int main(void) {
  if (id_f = fork()){
    printf("père : %d\n",getpid());

    signal(SIGUSR1, traitersignal);
    pause();

 }
  else{
    //printf("le pid du fils est -")

    sleep(5);

    kill(getppid(),SIGUSR1);

  }
}
*/
/* Exo 5
void sf(int sig){
  printf("signal reçu\n");

  sleep(10);

}

int main(){
  if (fork()){



    while(1){
      char a = 'a';}
  }

  else{
    signal(SIGUSR1,sf);

    printf("%d\n",getpid());
    sleep(20);
    //kill(getpid(),SIGUSR1);

    kill(getppid(),SIGKILL);




  }
}
*/
//EXO4 solution youssef
/*
int cpt;

void sig(int sig){
  cpt = 0;

}
int main(){
  if (fork()){



    while(1){
      char a = 'a';}
  }

  else{
    signal(SIGUSR1,sig);


    printf("%d\n",getpid());
    while(cpt<= 10){
      printf("%d\n",i);
      sleep(1);
      i++;
    }
    //kill(getpid(),SIGUSR1);
    if (cpt== 10)
      kill(getppid(),SIGKILL);
}
}
*/

/*
void sig(int sig){
  printf("commande n°%d\n",i);
  execlp(lc[i],lc[i],NULL);

}
*/
/*
int main(){
  char* lc[N];
  lc[0] = "who";
  lc[1] = "ls";
  lc[2] = "pwd";
  for(int i = 0; i < N;i++){
    if(fork() == 0){
      //KILL(getppid(),SIGUSR1);

      kill(getpid(),17);
      sleep(1);
    }
    else{
      //signal(SIGUSR1,sig);


      execlp(lc[i],lc[i],NULL);
      wait();



    }


  }
}
*/
//EXO 8
