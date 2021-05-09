#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <sys/ipc.h>

int main(int argc, char const *argv[])
{
    printf("argv[0]=%s\n",getenv("HOME"));
    printf("fktoa avec A en parametre =%d\n",ftok(getenv("HOME"),'a'));
    printf("fktoa avec B en parametre =%d\n",ftok(getenv("HOME"),'b'));
    return 0;
}
