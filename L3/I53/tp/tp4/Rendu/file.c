#include "file.h"
#include <stdlib.h>

void enfile(unsigned long long v, file * f)
{
	file tmp = malloc(sizeof(bluefile));
	tmp->rec = v;
	tmp->nxt = *f;
	*f = tmp;
}

unsigned long long defile(file * f)
{
	file tmp = *f;
	if (!tmp->nxt) {
		int val = tmp->rec;
		*f = NULL;
		return val;
	}
	while (tmp->nxt->nxt) {
		tmp = tmp->nxt;
	}
	int val = tmp->nxt->rec;
	free(tmp->nxt);
	tmp->nxt = NULL;
	return val;
}
