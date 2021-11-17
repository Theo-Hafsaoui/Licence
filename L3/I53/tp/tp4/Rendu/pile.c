#include "pile.h"
#include <stdlib.h>

void empile(unsigned int v, pile * p)
{
	pile tmp = malloc(sizeof(redpile));
	tmp->rec = v;
	tmp->nxt = *p;
	*p = tmp;
}

unsigned int depile(pile * p)
{
	pile tmp = *p;
	int val = tmp->rec;
	*p = tmp->nxt;
	free(tmp);
	return val;
}
