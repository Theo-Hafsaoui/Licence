#include <stdio.h>

typedef enum {False = 0, True} tbool;

tbool commence_par(char* mot, char* deb)
{
	int i = 0;
	tbool flag = True;
	while(deb[i] != '\0' && flag)
	{
		if (deb[i] != mot[i])
			flag = False;
		i++;
	}
	return flag;
}
tbool bien_parenthese(char* expr)
{
	int pile = 0, i = 0;
	while (expr[i] != '\0' && pile >= 0)
	{
		if (expr[i] == '(')
		{
			pile++;
		}
		else if (expr[i] == ')') 	
		{
			pile--;
		}	
		i++;
	}
	return (pile == 0);
}
	
/*
void main(int argc, char* argv[])
{
	printf("%d\n",commence_par(argv[1], argv[2]));
}
*/

void main ()
{
	char chaine[] = ")(3+2(5−1))";
	printf("%d\n", bien_parenthese(chaine));
}
	
			
	
