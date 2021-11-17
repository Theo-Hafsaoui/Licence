#ifndef PILE_H
#define PILE_H

typedef struct _pile_ {
    unsigned int rec;
    struct _pile_ *nxt;
} redpile, *pile;

void empile(unsigned int v, pile* p);
unsigned int depile(pile* p);

#endif // PILE_H
