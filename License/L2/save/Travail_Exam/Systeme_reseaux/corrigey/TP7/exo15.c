#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define N 5
#define True 1
#define False 0

void print_list(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n-1; i++) {
        printf("%d,", arr[i]);
    }
    printf("%d]\n",arr[n-1]);
}

void main (int argc, char **argv) {
    int msgid;
    key_t key = ftok("exo15.c", 123);
    printf("key = %d\n", key);
    if ((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
        perror("Erro on msgget");
        exit(-1);
    }

    struct msgbuf {
        long mtype;
        pid_t arr[2];
    } msgp;

    for (int i = 0; i < N; i++) {
        if (fork() == 0) {
            //child
            srand(time(NULL) ^ getpid());
            int random_num;
            msgp.arr[1] = getpid();
            msgp.mtype = i+1;
            for (int j = 0; j < 3; j++) {
                random_num = (rand() % 10) + 1;
                msgp.arr[0] = random_num;
                if (msgsnd(msgid, &msgp, sizeof(msgp.arr), 0) < 0) {
                    perror("msgsnd failed"), printf("errno = %d\n", errno), exit(-1);
                }
                printf("[child %d] Sent num = %d\n", i+1, random_num);
                sleep(rand() % 3 + 1);
            }
            msgp.mtype = N+1;
            if (msgsnd(msgid, &msgp, sizeof(msgp.arr), 0) < 0) {
                perror("msgsnd failed"), printf("errno = %d\n", errno), exit(-1);
            }
            printf("[child %d] Finished\n", i+1);
            exit(0);
        }
    }
    // father

    int sum_child[N];
    for (int i = 0; i < N; i++) {
        sum_child[i] = 0;
    }
    print_list(sum_child, N);
    int end = N;
    while (end) {
        if (msgrcv(msgid, &msgp, sizeof(msgp.arr), 0, 0) < 0) {
            perror("msgrcv failed"), printf("errno = %d\n", errno), exit(-1);
        }
        if (msgp.mtype == (N+1)) {
            end--;
        } else {
            printf("[father] Received %d from child %ld with pid %d\n", 
                                    msgp.arr[0], msgp.mtype, msgp.arr[1]);
            sum_child[msgp.mtype-1] += msgp.arr[0];
        }
    }
    print_list(sum_child, N);
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += sum_child[i];
    }
    printf("The total sum of values is %d\n", total);
    msgctl(msgid, IPC_RMID, NULL);
}
