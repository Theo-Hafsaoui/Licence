#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main () {
    key_t key = ftok("tmp_file", 123);
    int id = shmget(key, 8, 0777|IPC_CREAT);
    printf("%d\n", id);
}
