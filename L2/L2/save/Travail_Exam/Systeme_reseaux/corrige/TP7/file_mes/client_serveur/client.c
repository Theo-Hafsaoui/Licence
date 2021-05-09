/* client */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>

#define CLE 123

typedef struct msg_struc {
  long mtype;
  long data;
} msg;

int main(void) {

  int pid; /* notre pid */
  msg message; /* une variable de type message */
  int msg_id;

  /* on recupere la file de message */
  msg_id = msgget(CLE, 0777);

  /* on recupere notre pid */
  pid = getpid();

  printf("Client de pid %d envoie un message\n", pid);

  /* preparation d'un message */
  message.mtype = 1;
  message.data = pid;

  /* envoie du message au serveur */
  msgsnd(msg_id, &message, sizeof(long), 0);

  printf("Client de pid %d, message envoyee\n", pid);

  /* on attend le message de retour */
  sleep(5);
  msgrcv(msg_id, &message, sizeof(long), (long) pid,0);

  printf("Client de pid %d, message de type %ld recu de %ld\n",pid, message.mtype, message.data);

  return 0;
}
