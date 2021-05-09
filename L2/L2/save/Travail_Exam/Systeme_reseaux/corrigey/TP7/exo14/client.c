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
    if ((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
        perror("Erro on msgget");
        exit(-1);
    }
    pid_t curr_pid = getpid();
    printf("[client %d] msgid = %d\n", curr_pid, msgid);

    struct msgbuf {
        long mtype;
        pid_t mtext ;
    } msgp;
    msgp.mtype = 1;
    msgp.mtext = curr_pid;
    
    
    if (msgsnd(msgid, &msgp, sizeof(pid_t), 0) < 0) {
        perror("msgsnd failed"), printf("errno = %d\n", errno), exit(-1);
    }
    printf("[client %d] Sent a msg of type 1\n", curr_pid);

    if (msgrcv(msgid, &msgp, sizeof(pid_t), curr_pid, 0) < 0) {
        perror("msgsnd failed"), printf("errno = %d\n", errno), exit(-1);
    }
    printf("[client %d] Received the pid of server -> %d", curr_pid, msgp.mtext);
    
}
