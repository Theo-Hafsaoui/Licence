#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

int calcul_id(char * user) {
    int i = 0, id = 0;
    while(user[i] != '\0') {
        id += (i + 1) * user[i];
        i++;
    }
    return id;
}



void main(int argc, char** argv) {
    printf("xdddddd\n");
    key_t key;
    char* user_name = getenv("USER");
    key = ftok("file_exo4", calcul_id(user_name));
    //printf("key for ftok1.c is %d\n", key); 
    //while(1);
}
