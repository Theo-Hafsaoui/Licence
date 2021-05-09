#include <stdio.h> 
typedef unsigned int uint;


uint pair_ou_impair (uint n)
{
	uint res;
	if (n % 2 == 0)
	{	
		res = n/2;
	}
	else
	{
		res = 3*n + 1;
	}
	return res;
}

uint syracuse (uint u0)
{
	FILE* file = fopen("sujet3.txt", "w");
	uint next = u0, n = 0, max = u0, max_n =  0;
	fprintf(file, "%d %d\n", n, u0);
	while (next > 1)
	{
		next = pair_ou_impair(next);
		n++;
		if (next > max)
		{
			max = next;
			max_n = n;
		}
		fprintf(file, "%d %d\n", n, next);
	}
	fclose(file);
	printf("max %d, n %d\n", max, max_n);
	return n;
}

int main () 
{
	printf("%d \n", syracuse(4563281));
}


		
