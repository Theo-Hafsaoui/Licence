#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>


void main(int argc, char * argv[]){
  char * com1 = argv[1];
  char * com2 = argv[2];

  pid_t pid;
  int t[2];
  pipe(t);


  if (pid = fork() == 0){
    dup2(t[1],1);
    close(t[1]);
    close(t[0]);
    execlp(com1,com1,NULL);
    exit(1);

  }
  else{
    wait(&pid);
    dup2(t[0],0);
    close(t[1]);
    close(t[0]);

    execlp(com2,com2,NULL);

  }
  exit(1);

}
