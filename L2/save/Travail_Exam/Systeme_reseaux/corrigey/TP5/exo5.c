#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>


int i = 0;

void traitement (int sig)
{
	i = 0;
}

	
int main ()
{
	if (fork() != 0)
	{
		while(1)
		{
			printf(".");
			fflush(stdout);
			sleep(1);
		}
	}
	else
	{
		printf("pid du fils est %d \n" , getpid());
		signal(SIGUSR1, traitement); 
		while(i < 10)
		{
			printf("%d\n", i);
			sleep(1);
			i++;
		}
		if (i == 10)
		{
			printf("kill\n");
			kill(getppid(), SIGKILL);
		}
	}
}
			
			
			
