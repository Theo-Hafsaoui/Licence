#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

pid_t pid_fils;
int main()
{
	pid_fils = fork();
	if (pid_fils != 0)
	{
		// pere
		printf("Je suis le pere, mon fils a pour PID %d \n", pid_fils);

	}
	else
	{
		// fils
		printf("Je suis le fils, mon pere a pour PID %d\n", getppid() );
	}
}
	
	
