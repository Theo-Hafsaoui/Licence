#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>

void main(int argc, char* argv[]){

  const char * chemin = argv[1];
  printf("%d",ftok(chemin,'B'));

}
