#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

int c = 5;
void inc(int sig)
{
    c += 1;
}

void dec(int sig)
{
    c -= 1;
}


void main(int argc, char** argv)
{
    int tubes[3][2];
    int n = atoi(argv[1]);

    for(int i = 0; i < 3; i++)
    {
        pipe(tubes[i]);
    }

    if (fork() == 0)
    {
        // P1
        close(tubes[1][0]);
        close(tubes[1][1]);
        close(tubes[0][0]);
        close(tubes[2][0]);

        srand(time(NULL));
        int random_num;
        for(int i = 0; i < n; i++)
        {
            random_num = rand() % 100;
            printf("tube 0 num = %d\n", random_num);
            write(tubes[0][1], &random_num, sizeof(random_num));
            random_num = rand() % 100;
            printf("tube 2 num = %d \n", random_num);
            write(tubes[2][1], &random_num, sizeof(random_num));
        }

    }
    else
    {
        if(fork() == 0)
        {
            // P2
            close(tubes[0][1]);
            close(tubes[1][0]);
            close(tubes[2][1]);
            close(tubes[2][0]);

            signal(SIGUSR1, inc); 
            signal(SIGUSR2, dec);
            
            int buffer;
            for(int i = 0; i < n; i++)
            {
                read(tubes[0][0], &buffer, sizeof(buffer));
                printf("buffer = %d\n", buffer);
                buffer += c;
                printf("buffer = %d\n", buffer);
                write(tubes[1][1], &buffer, sizeof(buffer));
            }
        }
        else
        {
            //P3
            close(tubes[0][0]);
            close(tubes[0][1]);
            close(tubes[1][1]);
            close(tubes[2][1]);

            int t1_val, t2_val;
            for(int i = 0; i < n; i++)
            {
                read(tubes[1][0], &t1_val, sizeof(t1_val)); 
                read(tubes[2][0], &t2_val, sizeof(t2_val)); 
                printf("tube 1 val = %d, tube 2 val = %d, diff = %d\n", t1_val, t2_val,t2_val - t1_val);
            }
        }
    }
}
            

            

