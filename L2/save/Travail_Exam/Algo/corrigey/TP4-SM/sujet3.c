#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char* exp[12] = {"10","50","100","500","1000","5000","10000","50000","100000","500000","1000000","5000000"};
	char sujet1[30]= "./seconds.sh ./sujet1 ";
	char sujet2[30]= "./seconds.sh ./sujet2 ";
	for(int i = 0; i < 12; i++)
	{
		char target1[60];
		char target2[60];
		strcpy(target1, sujet1);
		strcpy(target2, sujet2);
		strcat(target1, exp[i]);
		strcat(target2, exp[i]);
		printf("Temps algo naif pour l'exposant %s ", exp[i]);
		fflush(stdout);
		system(target1);
		printf("Temps algo SM pour l'exposant %s ", exp[i]);
		fflush(stdout);
		system(target2);
		printf("\n");


		// for (int j = 0; j < 2; j++)
		// {
		// 	pid_t pid_fils = fork(); 
		// 	if(pid_fils == 0 && j == 0)
		// 	{
		// 		printf("Temps de algo naif pour l'exposant %s ", exp[i]);
		// 		fflush(stdout);
		// 		execl("./seconds.sh", "./seconds.sh", "./sujet1", exp[i], NULL);
				
		// 		exit(0);
		// 	}
		// 	else if( pid_fils == 0)
		// 	{
		// 		printf("Temps de SM pour l'exposant %s ", exp[i]);
		// 		fflush(stdout);
		// 		// execl("./seconds.sh", "./seconds.sh", "./sujet2", exp[i], NULL);
		// 		exit(0);			
		// 	}
		// }
	}
}
