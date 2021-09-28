#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned char uchar;
typedef unsigned int uint;

uchar* crible( uint n )
{  uint  i, j;
  uchar *t = calloc(n, sizeof(uchar));
  for (i = 2; i < n; i++)
    if (0 == t[i]) 
      for (j = 2*i; j < n; j += i)
	t[j] = 1;
  return t;
}

int main(int argc, char *argv[])
{  
  uint n = 100, i, cpt = 0;
  uchar *t;
  int opt, print = 0 , time=0;
  clock_t debut, fin;
  char *optstr="p:hl:t";
  while ((opt = getopt(argc, argv, optstr)) != -1) {
    switch (opt) {
    case 'p': print = atoi(optarg);
      break;
    case 'l': n = 1 << atoi(optarg);
      break;
    case 't': time=1;
      break;
    case 'h' :
    default: 
      fprintf(stderr, "Usage: %s [%s]\n", argv[0], optstr);
      exit(EXIT_FAILURE);
    }
  }
  
  debut = clock();
  t = crible( n );
  fin = clock();

  if ( print ) {
    print = n / print;
    cpt = 0;  
    for (i = 2; i < n; i++) {
      cpt += 1 - t[i];
      if ( 0 ==  i % print  )
	printf("pi(%d)=%d\n", i, cpt);
    }
    i--;
    if ( 0 <  i % print  )
      printf("pi(%d)=%d\n", i, cpt);
  }
  if ( time ) {
    printf("%d %ld\n",n,fin-debut);
  }
  return 0;
}
