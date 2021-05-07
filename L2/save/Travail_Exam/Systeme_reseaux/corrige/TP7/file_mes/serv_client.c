/* serveur */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <time.h>

#define N 5

typedef struct msg_struc {
  long mtype;
  long data;
  int pid;
} msg;

int main(void) {

  int msg_id;
  msg message; /* une variable de type message */
  int i;
  int nb_fils_finis = 0;
  int somme[N];
  int pid[N]; /* notre pid */

  /* on initialise le tableau des sommes cumulees */
  for (i = 0; i < N; i++)
    somme[i] = 0;

  /* on recupere la file de message */
  msg_id = msgget(IPC_PRIVATE, 0777 | IPC_CREAT);

  for (i = 0; i < N; i++)  {
    if ((pid[i] = fork()) == 0) {
      int j, t;
      long v;

      /* processus fils (client) */

      srand(time(NULL)*getpid());
      for (j = 0; j < 10; j++) {
	/* tirage d'une valeur aleatoire */
	v = rand() % 10;
	message.mtype = i+1;
	message.data = (long) v;
	message.pid = getpid();
	msgsnd(msg_id, &message, sizeof(long)+sizeof(int), 0);
	printf("Client %d envoie de message de valeur %ld\n", getpid(), v);
	t = rand() % 2 + 1;
	sleep(t);
      }
      printf("Fin du client %d\n", getpid());
      message.mtype = N+1;
      msgsnd(msg_id, &message, sizeof(long)+sizeof(int), 0);
      exit(0);
    }
  }
  /* processus pere (serveur) */

  printf("Serveur de pid %d en attente de messages\n", getpid());

  while(nb_fils_finis != N) {
    /* envoie du message au serveur */
    msgrcv(msg_id, &message, sizeof(long)+sizeof(int), 0,0);

    printf("Serveur de pid %d, message de type %ld recu de %d avec la valeur %ld\n", getpid(), message.mtype, message.pid, message.data);
    if (message.mtype < N+1) {
      /* reception d'un message avec une valeur */
      somme[message.mtype-1] += message.data;
    }
    else {
      /* reception d'un message de terminaison d'un client */
      waitpid(message.pid, NULL,0);
      nb_fils_finis ++;
    }
  }

  printf("Sommes cumulees pour les clients\n");
  for (i = 0; i < N; i++)
    printf("  pid = %d  somme = %d\n", pid[i], somme[i]);
  printf("Serveur: destruction de la file de message\n");
  msgctl(msg_id, IPC_RMID,0);
  exit(0);
}
