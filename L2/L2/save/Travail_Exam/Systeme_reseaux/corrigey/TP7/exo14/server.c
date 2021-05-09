#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>
#include <unistd.h>

void main (int argc, char **argv) {
    int msgid;
    key_t key = ftok("server.c", 123);
    printf("key = %d\n", key);
    if ((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
        perror("Erro on msgget");
        exit(-1);
    }
    printf("[server] msgid = %d, pid = %d\n", msgid, getpid());

    struct msgbuf {
        long mtype;
        pid_t mtext;
    } msgp;
    while (1) {
        printf("[server] Waiting for a msg of type 1\n");
        if (msgrcv(msgid, &msgp, sizeof(pid_t), 1, 0) < 0) {
            perror("msgrcv failed"), printf("errno = %d\n", errno), exit(-1);
        }
        printf("[server] Reception a msg with pid %d\n", msgp.mtext);
        msgp.mtype = msgp.mtext;
        msgp.mtext = getpid();
        if (msgsnd(msgid, &msgp, sizeof(pid_t), 0) < 0) {
            perror("msgsnd failed"), printf("errno = %d\n", errno), exit(-1);
        }
        printf("[server] Sent his pid");

    }
}
