/* ftok3.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(int argc, char * argv[])
{
  printf("ftok3\n");
  printf("  Ma cle A: %d \n",ftok(getenv("HOME"),'A'));
  printf("  Ma cle B: %d \n",ftok(getenv("HOME"),'B'));
  return 1;
}
