#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

void main (int argc, char** argv) {
    printf("xdddddd\n");
    key_t key;
    key = ftok("file_exo4", 'A');
    printf("key for ftok1.c is %d\n", key); 
    while(1);
}
