#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

typedef int Semaphore[2];

int initSemaphore(Semaphore S, int n)
{
 int i, code;
 char c='a';
 if ((code = pipe(S)) == 0);
      for (i = 1; i <=n ; i++)
        write(S[1],&c,1);
 return(code);
}

void P(Semaphore S)
{
  char c ;
  read(S[0],&c,1);
}

void V(Semaphore S)
{
  char c='a' ;
  write(S[1],&c,1);
}
