#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
int id2;
void traitersignal() {
   printf("pid fils= %d ",id2);
}

int main(){
    int id= fork();
    id2=id;
    if (id==0)
    {
        sleep(5);
        kill(getppid(),10);

    }
    else
    {
        signal(SIGUSR1,traitersignal);
        pause();
    }
}