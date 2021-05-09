#include <stdio.h>
#include <string.h>
typedef enum{False = 0, True} bool ;

bool EstPalindrome(char *phrase)
{
	int max = strlen(phrase) - 1; 	
	int i = 0;
	while (i < max)
	{
		if (phrase[i] != phrase[max - i])
			return False;
		i++;
	}
	return True;
}
	

int main(int argc, char *argv[]) 
{
	bool boolean;
	boolean = EstPalindrome(argv[1]);
	if (boolean)
	{	
		printf("Est Palindrome \n");
	}
	else
	{
		printf ("N'est pas palindrome \n");
	}

   }



