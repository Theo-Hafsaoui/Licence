#include <stdio.h>
#define PRINT(int) printf("%d\n, int")

void main()
{
	int x;
	x = -3 + 4 * 5 - 6;
	printf("%d\n", x);
	x = 3 + 4 % 5 - 6;
	printf("%d\n", x);
	x = -3 * 4 % -6 / 5;
	prinf("%d\n", x);
	x = (7 + 6) % 5 / 2;
	printf("%d\n", x);
}
