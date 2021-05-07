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
    printf("argv[0]=%s\n",argv[0]);
    printf("fktoa avec A en parametre =%d\n",ftok(argv[0],'a'));
    printf("fktoa avec B en parametre =%d\n",ftok(argv[0],'b'));
    return 0;
}
