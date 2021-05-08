/* serveur */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define CLE 123

int msg_id;

typedef struct msg_struc {
  long mtype;
  long data;
} msg;

void nettoie(int sig) {
  printf("Serveur: destruction de la file de message\n");
  msgctl(msg_id, IPC_RMID,0);
  exit(0);
}

int main(void) {

  int pid; /* notre pid */
  msg message; /* une variable de type message */
  long pid_client;

  /* prepare à nettoyer la file de message en quittant */
  signal(SIGINT, nettoie);

  /* on recupere la file de message */
  msg_id = msgget(CLE, 0777 | IPC_CREAT);

  /* on recupere notre pid */
  pid = getpid();

  printf("Serveur de pid %d en attente de messages\n", pid);

  while(1) {
    /* envoie du message au serveur */
    msgrcv(msg_id, &message, sizeof(long), 1,0);

    printf("Serveur de pid %d, message de type %ld recu de %ld\n", pid, message.mtype, message.data);

    /* on envoie le message de retour */
    /* avec comme contenu le pid du serveur */
    pid_client = message.data;
    message.mtype = pid_client;
    message.data = pid;
    msgsnd(msg_id, &message, sizeof(long),0);

    printf("Serveur de pid %d, message de type %ld envoye\n",pid, message.mtype);
  }

  return 0;
}
