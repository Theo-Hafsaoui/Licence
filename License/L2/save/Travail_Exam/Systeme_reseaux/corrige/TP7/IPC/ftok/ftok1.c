/* ftok1.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(int argc, char * argv[])
{
  printf("ftok1\n");
  printf("  Ma cle A: %d \n",ftok("ftok1.c",'A'));
  printf("  Ma cle B: %d \n",ftok("ftok1.c",'B'));
  return 1;
}
