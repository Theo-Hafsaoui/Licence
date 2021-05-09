#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>

int pid, cpt, n, aux, aux1, aux2, c ;
int tube1[2], tube2[2], tube3[2];

void traitersignal(int sig)
  {
     if (sig == SIGUSR1) c++;
     else if (sig == SIGUSR2) c--;
     printf(" XXXX c = %d XXXX\n",c);
  }

int main(int argc, char *argv[])

{
  n = atoi(argv[1]);
  c = atoi(argv[2]);
  pipe(tube1);
  pipe(tube2);
  pipe(tube3);
  pid = fork();
  if (pid == 0)
    {
      close(tube1[0]);
      close(tube2[0]);
      close(tube3[0]);
      srand(time(NULL));
      for (cpt = 1; cpt <= n; cpt++)
        {
          aux = rand() % 20;
          printf("*%d ",aux);
          fflush(stdout);
          write(tube1[1], &aux, sizeof(aux));
          write(tube3[1], &aux, sizeof(aux));
        }
      close(tube1[1]);
      close(tube2[1]);
      close(tube3[1]);
      exit(0);
     }
   pid = fork();
   if (pid == 0)
     {
      printf("Mon PID : %d\n",getpid());
      signal(SIGUSR1, traitersignal);
      signal(SIGUSR2, traitersignal);
      close(tube2[0]);
      close(tube3[0]);
      close(tube1[1]);
      close(tube3[1]);
      for (cpt = 1; cpt <= n; cpt++)
        {
          read(tube1[0], &aux, sizeof(aux));
          aux += c;
          write(tube2[1], &aux, sizeof(aux));
          sleep(1);
        }
      close(tube1[0]);
      close(tube2[1]);
      exit(0);
     }
   pid = fork();
   if (pid == 0)
     {
      close(tube1[0]);
      close(tube1[1]);
      close(tube2[1]);
      close(tube3[1]);
      for (cpt = 1; cpt <= n; cpt++)
        {
          read(tube2[0], &aux1, sizeof(aux1));
          read(tube3[0], &aux2, sizeof(aux2));
          printf("\nT2: %d, T3: %d, diff: %d",aux1,aux2,aux1-aux2);
          sleep(1);
        }
      close(tube2[0]);
      close(tube3[0]);
      exit(0);
     }
    wait(0);wait(0);wait(0);
    exit(0);
}
