#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
pid_t child_id;
int c =0;
void traitersignal(int sig) {
    c=1;
}
int main(){
	int id=fork();
	c=1;
	if (id==0)
	{
		printf("pid =%d\n",getpid());
		while (c)
		{
			c=0;
			for (int i = 0; i < 10; i++)
			{
				sleep(1);
				printf("%d",i);
				fflush(stdout);
				signal(SIGUSR1,traitersignal);
			}
			printf("\nsignal recu\n");
		}
		kill(getppid(),9);

	}
	else
	{
		while (1)
		{
		}
	}
	
	
}
