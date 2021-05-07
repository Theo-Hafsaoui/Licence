#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef int Semaphore[2];

void initSem(Semaphore S, int n) {
    int temp;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        temp=rand();
        write(S[1], &temp, sizeof(int));
    }
}

void v(Semaphore S){
    int m=42;
    write(S[1], &temp, sizeof(int));
}

void p(Semaphore S){
    int m=42;
    read(S[0], &temp, sizeof(int));}