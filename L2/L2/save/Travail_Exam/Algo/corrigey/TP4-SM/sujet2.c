#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

double square_and_multiply(float x, uint n)
{
	double res = 1;
	while(n != 0)
	{
		if (n & 1)
			res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}

int main(int argc, char* argv[])
{
	for(int i = 0; i < 10000; i++)
	{
		square_and_multiply(1.01, atoi(argv[1]));
	}
}
		

