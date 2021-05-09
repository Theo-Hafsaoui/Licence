#include <sys/types.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <stdlib.h>

void main(int argc, char** argv) {
    printf("file name is %s\n", argv[0]);
    key_t key = ftok("tmp_file", 'a');
    int sem_id = semget(key, 4, IPC_CREAT | IPC_EXCL | S_IRUSR |
                    S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    
    FILE* file = fopen("tmp_file", "w");
    fprintf(file, "%d\n", sem_id);
    fclose(file);
}

    
