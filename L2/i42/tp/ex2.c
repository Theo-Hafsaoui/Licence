#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    if (fork() != 0) {
    printf("Je suis le père, mon fils a pour PID: %d \n", getpid());
    }
    else
    {
        printf("Je suis le fils, mon père a pour PID: %d \n", getpid());
    }
    
}