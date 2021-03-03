#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int traitersignal(pid_t sig) {
   printf("pid fils= %d\n", sig);
}

int main(){
    pid_t chilid;
    if (fork() != 0) {
        chilid = getpid();
        signal(SIGUSR1, traitersignal(chilid));
    }
    else
    {
        fflush(stdout);
        sleep(5);
        kill(SIGUSR1,chilid);
    }
    
}