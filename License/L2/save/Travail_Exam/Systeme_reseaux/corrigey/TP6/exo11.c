#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

void main(int argc, char** argv)
{
    int n = argc - 2;
    int main_tube[2];

    pipe(main_tube);

    for(int i = 0; i < n; i++)
    {
        if(fork() == 0)
        {
            // fils
            int tube[2]; 
            pipe(tube);
            
            close(main_tube[0]);

            if(fork() == 0)
            {
                //fils du fils
                dup2(tube[1], 1);
                close(tube[1]);
                close(main_tube[1]);
                close(tube[0]);
                execlp("grep", "grep", "-o", argv[1], argv[i + 2], NULL);
            }
            else
            {
                // fils
                dup2(main_tube[1], 1);
                dup2(tube[0], 0);
                close(main_tube[1]);
                close(tube[1]);
                close(tube[0]);
                execlp("wc", "wc", "-l", NULL);

            }
        }
    }
    close(main_tube[1]);

    int total = 0; 
    char buffer[1];
    for(int i = 0; i < (n*2); i++)
    {
        read(main_tube[0], &buffer, sizeof(buffer));
        if(isdigit(buffer[0]))
            total += atoi(buffer);
    }
    printf("%d\n", total);
}

    
