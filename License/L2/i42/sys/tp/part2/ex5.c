#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(int argc, char const *argv[])
{
    int id=semget(ftok(getenv("HOME"),'a'),4,IPC_CREAT|IPC_EXCL);
    printf("idsem=%d",id);
    return 0;
}
