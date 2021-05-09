#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int tube[2];pipe(tube);int temp;
    char ctemp[2] = "\0";
    int s=0;
    for (int i = 2; i < argc; i++)
    {
        if (fork()==0)
        {
            dup2(tube[1],1);
            close(tube[1]);
            close(tube[0]);
            execlp("grep","grep","-c",argv[1],argv[i],NULL);
        }
    }
    close(tube[1]);
    wait(NULL);
    for (int i = 2; i < argc; i++){
        {
            read(tube[0],&temp,sizeof(char));
            ctemp[0]=temp;
            temp=atoi(ctemp);
            printf("temp=%d\n",temp);
            s+=temp;
        }
    }
    printf("s=%d",s);
    return 0;
}