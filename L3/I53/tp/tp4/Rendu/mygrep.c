#include "afd.h"
#include "afn.h"
#include "compregex.h"
#include <stdlib.h>
#include <getopt.h>
#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define reset "\e[0m"

int main(int argc, char *argv[])
{
	char opt;
	int verbose = 0;
	while ((opt = getopt(argc, argv, "hv")) != -1) {
		switch (opt) {
		case 'v':
			verbose = 1;
			break;
		case 'h':
			printf("usage: %s [-v] <exreg> <chaîne>\n", argv[0]);
			exit(EXIT_SUCCESS);
		default:
			printf("usage: %s [-v] <exreg> <chaîne>\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	if (argc - optind < 2) {
		printf("usage: %s [-v] <exreg> <chaîne>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	afn N;
	afd D;
	char *regex = argv[optind];
	char *s = argv[optind + 1];
	int n = strlen(regex);
	lex_unit *l = scanner(regex, n);
	N = parser(l, n);
	if (verbose) {
		afn_print(N);
	}
	afn_determinisation(N, &D);
	if (afd_simul(s, D)) {
		printf(GRN "accepté\n" reset);
	} else {
		printf(RED "rejeté\n" reset);
	}
	return 0;
}
