#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  int tube[2], *vec1 , *vec2 , i, produit, produit_scal, res, n;
  pid_t pid;

  n = atoi(argv[1]);
  pipe(tube);
  srand(time(NULL));
  vec1 = (int *)malloc(n*sizeof(int));
  vec2 = (int *)malloc(n*sizeof(int));

  for (i = 0 ; i < n; i++)
   {
     vec1[i] = rand() % 10;
     vec2[i] = rand() % 10;
   }

  for (i = 0 ; i < n; i++)
    printf("%5d ",vec1[i]);
  printf("\n");
  for (i = 0 ; i < n; i++)
    printf("%5d ",vec2[i]);
  printf("\n");
  for (i = 0; i < n; i++)
    {
      pid = fork();
      if (pid == 0)
         {
           close(tube[0]);
           produit = vec1[i] * vec2[i];
           printf("Processus %d a calcule %5d x %5d = %5d\n",i,vec1[i],vec2[i],produit);
           write(tube[1],&produit,sizeof(produit));
           close(tube[1]);
           exit(0);
         }
     }
 produit_scal = 0;
 for (i = 0; i < n; i++)
     {
       read(tube[0],&res,sizeof(res));
       produit_scal += res;
     }
 printf("Resultat: %d\n",produit_scal);
 exit(0);
}
