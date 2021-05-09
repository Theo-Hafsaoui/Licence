#include <stdio.h>
#define PRINTX printf("%d\n", x)

void main()
{
	int x=2,y,z;
    x*=3+2;
    x*= y = z = 4; PRINTX;
    x=y==z;PRINTX;
    x==(y=z); PRINTX;
}
