#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
/* //EXO2#############################################################################
int main(void)
{

 pid_t pid, ppid;

 ppid = getpid();
 pid = fork();
 if (pid > 0) printf("Je suis le pere, mon fils a pour PID: %d\n",pid);
   else printf("Je suis le fils, mon pere a pour PID: %d\n",ppid);
 return 0;
}
*/

/* //EXO3 ############################################################################

int main(void)
{

 pid_t pid;
 int n;

 printf("Adresse de n: %p\n", &n);
 n = 0;
 pid = fork();
 if (pid > 0)
     // incrementation par le processus pere
     n++;

 if (pid > 0)
        printf("Je suis le pere, n vaut %d\n", n);
 else
        printf("Je suis le fils, n vaut %d\n", n);
 return 0;
}
*/

/* //EXO4 ############################################################################
pid_t pid,ppid;

void traitersignal(int sig)
  {
     printf("PID de mon fils: %d\n", pid);
  }

int main(void)

{
  ppid = getpid();
  pid = fork();
  if (pid == 0)
    {
      sleep(5);
      kill(ppid, SIGUSR1);
    }
  else
    {
      signal(SIGUSR1, traitersignal);
      pause();
    }
  exit(0);
}
*/

/* //EXO5 ############################################################################

int pid, ppid, cpt;

void traitersignal(int sig)
  {
     cpt = 1;
  }

int main(int argc, char *argv[])

{
  pid = fork();
  if (pid == 0)
    {
      signal(SIGUSR1, traitersignal);
      ppid = getppid();
      while (cpt <= 10)
         {
           sleep(1);
          // printf("%d\n", cpt);
           cpt ++;
         }
      kill(ppid, 3);
    }
  else
    {
      printf("Num fils : %d\n", pid);
      while(1);
    }
  exit(0);
}

*/

/* //EXO7 ############################################################################
int main(int argc, char *argv[])
{

  pid_t pid;
  int i;

  for (i = 1; i < argc; i++)
    {
     pid = fork();
     if (pid == 0) {
         execlp(argv[i], argv[i], NULL);
        }
     else wait(0);
    }
  exit(0);
}
*/

/* //EXO8 ############################################################################
int main(int argc, char *argv[])
{

  pid_t pid;
  int i;

  for (i = 1; i < argc; i++)
    {
     pid = fork();
     if (pid == 0) {
         execlp(argv[i], argv[i], NULL);
        // si exec echoue il faut sortir du fils
        // sinon ce dernier va continuer a executer
        //la boucle for
         printf("Erreur d'execution\n");
         exit(1);
        }
     else wait(0);
    }
  exit(0);
}

*/
