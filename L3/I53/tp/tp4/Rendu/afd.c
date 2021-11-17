#include <stdio.h>
#include <stdlib.h>
#include "afd.h"

void afd_init(afd * A, uint nbetat, char *alphabet, uint nbfinal,
			  uint init, uint * finals)
{
	int i, nbsymb = 0;
	uchar symb;

	A->nbetat = nbetat;
	A->nbfinal = nbfinal;
	A->init = init;

	for (i = 0; i < SYMB_NB_MAX; i++)
		A->tsymb[i] = SYMB_NONE;

	A->alphabet = malloc(strlen(alphabet) + 1);
	strcpy(A->alphabet, alphabet);
	A->nbsymb = strlen(alphabet);

	while (*alphabet != '\0') {

		if ((*alphabet < SYMB_ASCII_DEB) || (*alphabet > SYMB_ASCII_FIN)) {
			fprintf(stderr,
					"[afd_init] caractere ascii numero %d invalide\n",
					*alphabet);
			exit(-1);
		}

		symb = (uchar) (*alphabet - SYMB_ASCII_DEB);
		if (A->tsymb[symb] != SYMB_NONE) {
			fprintf(stderr,
					"[afd_init] caractere <%c> deja defini (ignorer)\n",
					symb);
		} else {
			A->tsymb[symb] = nbsymb;
			nbsymb++;
		}
		alphabet++;
	}

	A->finals = calloc(nbfinal, sizeof(uint));
	for (i = 0; i < nbfinal; i++) {
		A->finals[i] = finals[i];
	}

	int j;
	A->delta = calloc(nbetat, sizeof(uint *));
	for (i = 0; i < nbetat; i++) {
		A->delta[i] = calloc(A->nbsymb, sizeof(uint));
		for (j = 0; j < A->nbsymb; j++)
			A->delta[i][j] = ETAT_NONE;
	}
}

void afd_free(afd * A)
{
	int i;
	free(A->finals);
	free(A->alphabet);
	for (i = 0; i < A->nbetat; i++)
		free(A->delta[i]);
	free(A->delta);
}

void afd_add_trans(afd * A, uint q1, uint s, uint q2)
{
	uchar symb = A->tsymb[s - SYMB_ASCII_DEB];

	if (symb == SYMB_NONE) {
		fprintf(stderr, "[add_trans] %u -- %c --> %u\n", q1, s, q2);
		exit(-1);
	}

	if ((q1 < 0) || (q1 >= A->nbetat)) {
		fprintf(stderr, "[add_trans] etat <%d> non reconnu\n", q1);
		exit(-1);
	}
	if ((q2 < 0) || (q2 >= A->nbetat)) {
		fprintf(stderr, "[add_trans] etat <%d> non reconnu\n", q2);
		exit(-1);
	}

	A->delta[q1][symb] = q2;
}

void afd_copy(afd * dest, afd * src)
{
	dest->nbetat = src->nbetat;
	dest->nbsymb = src->nbsymb;
	dest->nbfinal = src->nbfinal;
	dest->init = src->init;

	dest->alphabet = calloc(src->nbsymb, sizeof(char));
	strcpy(dest->alphabet, src->alphabet);

	memcpy(dest->tsymb, src->tsymb, SYMB_NB_MAX);

	int size = (src->nbetat - 1) / ULLONG_BIT + 1;
	dest->finals = calloc(sizeof(ullong), size);
	memcpy(dest->finals, src->finals, sizeof(ullong) * size);

	int i;
	dest->delta = calloc(src->nbetat, sizeof(uint *));
	for (i = 0; i < src->nbetat; i++) {
		dest->delta[i] = calloc(src->nbsymb, sizeof(uint));
		memcpy(dest->delta[i], src->delta[i], sizeof(uint) * src->nbsymb);
	}
}

void afd_print(afd A)
{
	int i;

	printf("etat initial: %d\n", A.init);
	printf("etats finals:");

	for (i = 0; i < A.nbfinal; i++) {
		printf(" %u", A.finals[i]);
	}

	/* for (i = 0; i < ((A.nbetat - 1) / ULLONG_BIT) + 1; i++) {
	   for (j = 0; j < ULLONG_BIT; j++) {
	   if ((1ULL << j) & A.finals[i])
	   printf(" %lu", i * ULLONG_BIT + j);
	   }
	   } */
	printf("\n");

	uint q;
	int printed;

	for (q = 0; q < A.nbetat; q++) {
		printed = 0;
		for (i = 0; i < A.nbsymb; i++) {
			if (A.delta[q][i] != ETAT_NONE) {
				if (printed == 1)
					printf("    ");
				else
					printf("%4u", q);
				printf(" -- %c --> %u\n", A.alphabet[i], A.delta[q][i]);
				printed = 1;
			}
		}
		//if (printed==0) printf("\n");
	}
}

void afd_finit(afd * A, char *nomfichier)
{
	FILE *f;
	uint nbetat;
	char alphabet[64];
	uint nbfinal;
	uint init;
	f = fopen(nomfichier, "r");
	fscanf(f, "%u %s %u\n", &nbetat, alphabet, &nbfinal);
	fscanf(f, "%u\n", &init);
	uint finals[nbfinal];
	for (int i = 0; i < nbfinal; ++i) {
		fscanf(f, "%u", &finals[i]);
	}
	afd_init(A, nbetat, alphabet, nbfinal, init, finals);
	uint etat1;
	char symb;
	uint etat2;
	while (fscanf(f, "%u %c %u", &etat1, &symb, &etat2) != EOF)
		afd_add_trans(A, etat1, symb, etat2);
}

int afd_simul(char *s, afd A)
{
	uint etat = A.init;
	int i = 0;
	while (s[i] != '\0') {
		etat = A.delta[etat][A.tsymb[s[i] - SYMB_ASCII_DEB]];
		i++;
	}
	for (int i = 0; i < A.nbfinal; ++i)
		if (etat == A.finals[i])
			return 1;
	return 0;
}

void afd_add_state(afd * A)
{
	A->nbetat += 1;
	int j;
	A->delta = reallocarray(A->delta, A->nbetat, sizeof(uint *));
	A->delta[A->nbetat - 1] = calloc(A->nbsymb, sizeof(uint));
	for (j = 0; j < A->nbsymb; j++) {
		A->delta[A->nbetat - 1][j] = ETAT_NONE;
	}
}

void afd_add_final(afd * A, uint f)
{
	A->nbfinal += 1;
	A->finals = reallocarray(A->finals, A->nbfinal, sizeof(uint *));
	A->finals[A->nbfinal - 1] = f;
}
