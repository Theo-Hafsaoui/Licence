#include <stdio.h>
#define PRINT(int) printf("%d\n, int")

void exo_12()
{
	int x, y, z;
	x = 2;
	y = 1;
	z = 0;
	x = x && y || z;
	PRINT(x);
	PRINT(x * x || !y && z);
	x = y = z;
	z = x++ - 1;
	PRINT(x);
	PRINT(z);
	z += -x++ + ++y;
	PRINT(x);
	PRINT(z);
	z = x / ++x;
	PRINT(z);
}
