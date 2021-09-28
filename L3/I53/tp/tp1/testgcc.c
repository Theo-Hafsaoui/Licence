#define CARRE(X) ((X)*(X))
#define CUBE(X) (CARRE(X)*(X))
#define DIX 10
#include <stdio.h>
/*
Commentaire sur
plusieurs
lignes
*/
int main(int argc , char *argv [])
{
	int a=2,b=1,c,i;
	// Commentaire sur une seule ligne
	for (i=0; i<DIX; i++) a++;
	a = a+1;
	b = a+b;
	c = CARRE(a+b) + CUBE(a-b);
	return c;
}
