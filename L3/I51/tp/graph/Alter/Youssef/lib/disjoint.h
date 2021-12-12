#ifndef DISJOINT_H
#define DISJOINT_H

#include <stdlib.h>

typedef struct _disjoint_ {
    int num;
    struct _disjoint_ * next;
    struct _disjoint_ * rep;
    int card;
} el_disjoint, * disjoint;

disjoint singleton(int);
disjoint rep(disjoint);
void reunion(disjoint r, disjoint s);
#endif
