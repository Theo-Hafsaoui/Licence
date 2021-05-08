#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    char * com1 = argv[1];
    char * com2 = argv[2];
    int tube[2];
    pipe(tube);
    if (fork() == 0)
    {
        // fils
        dup2(tube[1], 1);
        close(tube[1]);
        close(tube[0]);
        execlp(com1, com1, NULL);
    }
    else
    {
        close(tube[1]);
        dup2(tube[0], 0);
        execlp(com2, com2, NULL);
    } 
} 
