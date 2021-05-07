#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void main () {
    key_t key = ftok("tmp_file", 'a');
    int sem_id = semget(key, 1, IPC_CREAT | S_IRUSR |
                    S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    printf("sem id is %d\n", sem_id);
    printf("[ressource test] ask for ressource\n[ressource test] val of sem is %d before dec\n", semctl(sem_id, 0, GETVAL));
    int i = 1;
    while (semctl(sem_id, 0, GETVAL) == 0) {
        printf("%d seconds without the ressource\n", i);
        sleep(1);
        i++;
    }
    struct sembuf sops[1] = {{0,-1,0}};
    semop(sem_id, sops, 1);
    printf("[ressource test] val of sem is %d after dec\n", semctl(sem_id,0,GETVAL));
    printf("[ressource test] return the ressource \n");
    sops[0].sem_op = 1;
    semop(sem_id, sops, 1); 
    printf("[ressource test] finished | val of sem is %d\n", semctl(sem_id, 0, GETVAL));
}
    
    
