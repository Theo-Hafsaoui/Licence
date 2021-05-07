/* ftok2.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(int argc, char * argv[])
{
  printf("ftok2\n");
  printf("  Ma cle A: %3d \n",ftok("ftok2.c",'A'));
  printf("  Ma cle B: %3d \n",ftok("ftok2.c",'B'));
  return 1;
}
