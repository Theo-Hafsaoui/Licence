#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

  pid_t pid;
  unsigned int resultat,i,taille;
  int tube[2];
  int fd;
  char r;

  pipe(tube);
  for (i = 1; i < argc; i++)
    {
      pid = fork();
      if (pid == 0)
        {
         dup2(tube[1],1);
         close(tube[0]);
         close(tube[1]);
         fd = open(argv[i],O_RDONLY);
         dup2(fd,0);
         close(fd);
         execlp("wc","wc","-c",NULL);
         /* ici on n'a pas passe argv[i] en parametre de wc */
         /* car autrement le nom du fichier aurait ete envoye */
         /* dans le tube */
         exit(0);
       }
    }
   resultat = 0;
   for ( i = 1; i < argc; i++)
     {
      read(tube[0],&r,sizeof(char));
      taille = 0;
      while (r != '\n')
        {
          taille = taille * 10 + atoi(&r);
          read(tube[0],&r,sizeof(char));
        }
      resultat = resultat + taille;
     }
    close(tube[0]);
    close(tube[1]);
   printf("Taille totale : %d\n",resultat);
   exit(0);
}
