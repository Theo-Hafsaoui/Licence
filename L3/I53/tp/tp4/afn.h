#ifndef AFN_H
#define AFN_H

#include <stdlib.h>
#include <stdio.h>
#include "afd.h"


#define INT_ETAT(q) (1ULL<< (q))// met un bit 1 au q eme espace
#define IN(q,X) ((INT_ETAT(q) & X ) > 0)//regarde si le bit a 1 et aussi a 1 dans X

typedef unsigned int uint;
typedef unsigned long long int ullong;

typedef struct{
  uint nbetat, nbsymb;
  char * alphabet;
  uchar tsymb[SYMB_NB_MAX];
  ullong init, finals;
  ullong **delta;
} afn;

void afn_init(afn *A, uint nbetat, char * alphabet, ullong init, ullong finals);
void afn_add_trans(afn *A, uint q1, uint s, uint q2);
void afn_free(afn *A);

void afn_print(afn A);
void afn_finit(afn *A, char *f);

ullong afn_epsilon_fermeture(afn A, ullong R);
void afn_determinisation(afn A, afd *D);
void afn_char(afn *C, char c, uint nbsymb);
void shift_copy(afn *A, afn B,int ind);
void afn_union(afn *C, afn A, afn B);
void afn_concat(afn *C, afn A, afn B);

#endif
