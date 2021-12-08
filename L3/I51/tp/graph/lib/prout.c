#include <stdlib.h>
#include "graphe.h"
#include "nuage.h"
#include "disjoint.h"

typedef struct {
    int r, s;
    double w;
} arc;



static int cmp(const void *p1, const void *p2)
{
    double t = ((arc *) p1)->w - ((arc *) p2)->w;
    if (t > 0)
	return 1;
    if (t < 0)
	return -1;
    return 0;
}

graphe kruskal(void)
{
    int i, j;
    int n = nbpoint;
    graphe res = initGraphe(n);
    int m = (n * (n - 1)) / 2;
    arc *t;
    disjoint *d, rx, ry;

    t = calloc(m, sizeof(arc));
    m = 0;
    for (i = 0; i < n; i++)
	for (j = i + 1; j < n; j++) {
	    t[m].r = i;
	    t[m].s = j;
	    t[m++].w = poids(i, j);
	}

    qsort(t, m, sizeof(arc), &cmp);

    d = initdisjoint(n);

    for (i = 0; i < m; i++) {
	rx = representant(d[t[i].r]);
	ry = representant(d[t[i].s]);
	if (rx != ry) {
	    reunion(rx, ry);
	    res.mat[t[i].r][t[i].s] = 1;
	    res.mat[t[i].s][t[i].r] = 1;
	}
    }

    free(d);
    free(t);

    return res;
}

