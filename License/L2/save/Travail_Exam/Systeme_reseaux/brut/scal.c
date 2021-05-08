#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

void main(int argc,char* argv[]){

  int n = atoi( argv[1]);
  int v1[n];
  int v2[n];
  pid_t pid;
  time_t t;
  int res;
  int tmp = 0;
  int tube[2];
  pipe(tube);
  int total = 0;
  //write(tube[1],z,4);

  printf("  ");
  srand((unsigned)time(&t));
  for(int j = 0; j< n;j++)
    {
      v1[j] = rand()%10;
      printf("%d  ",v1[j]);}

  printf("\n  ");
  for(int j = 0; j< n;j++){

          v2[j] = rand()%10;        //generation des 2 tableaux aléatoires
          printf("%d  ",v2[j]);}
  printf("\n");
  for(int i = 0; i < n;i++)
    {
      if(pid = fork() == 0)
      {
      res = v1[i] * v2[i];
      printf("processus %d : %d * %d  = %d \n",i,v1[i],v2[i],res);
      printf("n = %d \n",n);
      write(tube[1],&res,sizeof(res));      // ecriture de la valeur tmp pour processus i
      close(tube[1]);                        // ferme l' écrivain fils
      exit(1);
      }
      //for(int k = 0; k < n;k++){
        //printf("%d \n",pid);
      wait(&pid);
      read(tube[0],&tmp,sizeof(tmp));     // on lit le tmp courant et on l'additionne au total
      printf("tmp = %d \n",tmp);
      //close(tube[0]);
      total += tmp;



    }
    close(tube[0]);
    printf("%d \n",total);

}
