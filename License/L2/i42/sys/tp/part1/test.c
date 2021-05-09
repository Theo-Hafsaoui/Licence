#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
 
void traitersignal(int sig) {
   printf("Signal %d bien recu\n", sig);
}
 
int main(void) {
  int pid=getpid();
  printf("pid = %d\n",pid);
  signal(SIGUSR1, traitersignal);
  while(1);
}