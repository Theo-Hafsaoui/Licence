#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ids *buf;
    unsigned short *array;
    struct seminfo *__buf;
} arg;

void main () {
    FILE* file = fopen("tmp_file","r");
    int semid;
    fscanf(file, "%d", &semid);
    fclose(file);
    printf("semid is %d\n", semid);
    printf("semid is %d\n", semget(ftok("tmp_file", 'a'), 4, 0));
    semid = semget(ftok("tmp_file", 'a'), 4, 0);
    printf("The value of semaphore 3 is %d\n", semctl(semid, 2, GETVAL));
    arg.val = 1;
    semctl(semid, 2, SETVAL, arg);
    printf("The value of semaphore 3 is %d\n", semctl(semid, 2, GETVAL, arg));
    printf("The pid of the process that executed the last semop is %d, my pid is %d.\n", semctl(semid, 2, GETPID, arg), getpid());
    semctl(semid, 0, IPC_RMID, arg);
}
