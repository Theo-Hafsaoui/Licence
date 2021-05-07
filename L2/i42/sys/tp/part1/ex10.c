#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int tube[2];pipe(tube);
    int s=0;temp=0;
    if (fork()==0)
    {
        dup2(tube[1], 1);
        execlp(argv[1],argv[1],NULL);
    }
    else
    {
        close(tube[1]);
        dup2(tube[0],0);
        write(pip[1],&temp,sizeof(int));
        s+=temp;
    }
 
}
