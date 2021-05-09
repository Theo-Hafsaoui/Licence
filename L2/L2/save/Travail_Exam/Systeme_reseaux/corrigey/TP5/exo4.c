#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
 
/*
void traitersignal(int sig) {
   printf("Signal %d bien recu\n", sig);
}
 
int main(void) {
   signal(SIGUSR1, traitersignal);
   while(1);
}
*/

pid_t pid;
void traitersignal(int sig) {
   printf("Le pid de mon fiston est %d\n", pid);
}
 
int main()
{
	if ((pid = fork()) != 0)
	{
		// pere
		signal(SIGUSR1, traitersignal);
		pause();
	} 
	else
	{
		printf("je suis le fils et mon pid est %d\n", getpid());
		sleep(5);
		kill(getppid(), SIGUSR1); 
	}
}
	
	


