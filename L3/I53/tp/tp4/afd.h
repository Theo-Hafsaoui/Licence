/*
  I53 Compilation et théorie des langages
  Nicolas Méloni
  01 - 11 - 2019
*/

#ifndef AFD_H
#define AFD_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define ALPABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789&"
#define SYMB_NB_MAX 96
#define SYMB_ASCII_DEB 32
#define SYMB_ASCII_FIN 127
#define SYMB_NONE 255

#define ETAT_NONE ((uint) -1)
#define ETAT_MAX ((uint) -2)
#define ULLONG_BIT (sizeof(ullong)*CHAR_BIT)

typedef unsigned int uint;
typedef unsigned long long int ullong;
typedef unsigned char uchar;
typedef struct {
  uint nbetat, nbsymb, nbfinal; 
  uint init;
  char * alphabet;
  uchar tsymb[SYMB_NB_MAX];
  uint *finals;
  uint **delta;//Liste des etat
} afd;

void afd_init(afd *A, uint nbetat, char *alphabet, uint nbfinal, uint init, uint *finals);
void afd_add_trans(afd *A, uint q1, uint s, uint q2);
void afd_free(afd *A);
void afd_copy(afd *dest, afd *src);
void afd_print(afd A);
void afd_finit( afd *A, char *nomfichier);
int afd_simul(char *s, afd A);


#endif
