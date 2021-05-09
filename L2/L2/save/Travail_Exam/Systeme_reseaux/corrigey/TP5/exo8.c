#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#define N 3


// int  main()
// {
// 	execl( "/bin/ls", "/bin/ls", "-a", "/home", NULL);	 
// 	printf("Succes");
	 
// 	// char *binaryPath = "/bin/ls";
// 	// char *arg1 = "-lh";
// 	// char *arg2 = "/home";

// 	// execl(binaryPath, binaryPath, arg1, arg2, NULL);

// 	return 0;
// }

int main (int argc, char **argv)
{
	for (int i = 0; i < (argc-1); i++)
	{
		if (fork() != 0)
		{
			// father 
			printf("papa tranquilou \n");
			wait(0);

		}
		else
		{
			printf("command num %d \n", i);
			if (execlp(argv[i+1], argv[i+1], NULL) < 0) 
                exit(0);
            

		}
	}
    exit(0);
}


