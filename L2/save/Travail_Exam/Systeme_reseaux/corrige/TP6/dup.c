#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

  pid_t pid;
  int tube[2];

  pipe(tube);
  pid=fork();
  if (pid == 0)
   {
     dup2(tube[0],0);
     close(tube[1]);
     /* tube[0] n'est plus utile puisque l'entree standard */
     /* a ete redirigee dessus */
     close(tube[0]);
     printf("\n");
     execlp(argv[2],argv[2],NULL);
   }
  else
    {
      dup2(tube[1],1);
      close(tube[0]);
     /* tube[1] n'est plus utile puisque la sortie standard */
     /* a ete redirigee dessus */
     close(tube[1]);
      execlp(argv[1],argv[1],NULL);
    }
  exit(0);
}
