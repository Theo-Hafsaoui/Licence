#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>



  void main(int argc, char * argv[]){
    char c [64] ;
    char * chr = argv[1];
    char * fichier;

    int total;

    pid_t pid;
    int t[2];
    pipe(t);



    for(int i = 2; i < argc; i++)
      {
        if (pid = fork() == 0)
        {
          fichier = argv[i];

          dup2(t[1],1);
          close(t[1]);
          close(t[0]);

          execlp("grep","grep",chr,fichier,"-c",NULL);
          exit(1);
        }
        //dup2(t[0],0);
        //close(t[1]);
        //close(t[0]);
        //wait(&pid);
        read(t[0],&c,sizeof(c));

        //printf("tmp = %s\n",c);
        total += atoi(c);
        //total += tmp;
      }
      printf("total = %d \n",total);
}
