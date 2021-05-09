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
    printf("[ressource] Creation of semaphore the val is %d\n", semctl(sem_id, 0, GETVAL));

    struct sembuf sops[1] = {{0,1,0}};
    semop(sem_id, sops, 1);
    printf("[ressource] Set value of semaphore to %d\n", semctl(sem_id, 0, GETVAL));
    sops[0].sem_op = -1;
    semop(sem_id, sops, 1);
    printf("[ressource] val of sem is %d\n[ressource] go into sleep\n", semctl(sem_id, 0, GETVAL));
    sleep(10);
    sops[0].sem_op = 1;
    semop(sem_id, sops, 1); 
    printf("[ressource] val of sem is %d\n[ressource] finished\n", semctl(sem_id, 0, GETVAL));


}
    
