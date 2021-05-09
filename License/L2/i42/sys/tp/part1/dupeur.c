#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
 
int main(void) {
    pid_t pid, pid_fils ;
    pid = fork();
    printf ("%d", pid);
    if (pid != 0) {
        printf("papa %d variable pid ->%d \n", getpid(), pid);
        pid_fils = pid;
    }
    else
    {
        printf("fiston.%d variable pid -> %d, variable pid_fils %d \n", getpid(), pid, pid_fils);
    }
    
}