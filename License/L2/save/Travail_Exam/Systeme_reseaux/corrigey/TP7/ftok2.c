#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

void main (int argc, char** argv) {
    key_t key;
    key = ftok("file_exo4", 'B');
    printf("key for ftok2.c is %d\n", key); 
    while(1);
}
