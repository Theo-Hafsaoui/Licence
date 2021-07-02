#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    int key=ftok(argv[0],42);
    int msgid;
    struct msgbuf {
        long type;
        long retard;
        long voyage;
    } msgp;
    if ((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
        perror("Erro on msgget");
        exit(-1);
    }
    msgp.voyage=0;
    msgp.retard=0;
    printf("id=%d\n",msgid);
    if (fork()==0)
    {
        msgp.retard++;
        if ((msgsnd(msgid,&msgp,sizeof(long),0))<0)
        {
            printf("merde\n");
        }
        exit(0);
    }
    else{
        printf("retard=%d\n",msgp.retard);
        if ((msgrcv(msgid,&msgp,sizeof(long),0,0))<0)
        {
            printf("merde\n");
        }
        printf("retard=%d\n",msgp.retard);
    }
    return 0;
}
