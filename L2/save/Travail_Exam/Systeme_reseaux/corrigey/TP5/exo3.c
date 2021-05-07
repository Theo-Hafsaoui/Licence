#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int n = 25;
	if (fork() != 0)
	{ 
		// pere
		int papa = 5;
		printf("je suis le pere est n = %d\n", n);
		n += 2;
		printf("pere N+2 n = %d\n", n);
	}
	else
	{
		// fils
		printf("je suis le fils est n = %d\n", n );
		n += 5;
		printf("fils N+5 n = %d\n", n);
		printf("papa? %d", papa);
		
	}
}
