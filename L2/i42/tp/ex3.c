#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void traitersignal(int sig) {
   printf("tg %d", sig);
}

int main(){
    if (fork() != 0) {
        int chilid = getpid();
        signal(SIGUSR1, traitersignal(chilid));
    }
    else
    {
        sleep();
        kill(SIGUSR1,chilid)
    }
    
}