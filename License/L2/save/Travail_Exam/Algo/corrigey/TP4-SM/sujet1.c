#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int uint;

// #define N 5000000
double power_a(float x, uint n)
{
	double res = 1;
	for(int i = 0; i < n; i++)
	{
		res *= x;
	}
	return res; 
}


int main( int argc, char * argv[])
{
/*
	uint exp[12] = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000};
	for(int i = 0; i < 12; i++)
	{
		time_t init = time(NULL);
		
		for(int j = 0; j < 10000; j++)
		{
			power_a(1.00000001, exp[i]);
		}
		time_t end = time(NULL);
		
		printf("the time for %d is %f \n ", exp[i], end - init);
	}
*/
	
	for(int i = 0; i < 10000; i++)
	{
		power_a(1.01, atoi(argv[1]));
	}

}
