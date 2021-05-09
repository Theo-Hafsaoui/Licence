#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/shm.h>
#include <time.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
} arg;

void main (int argc, char** argv) {
    int miners = atoi(argv[1]), shovel = atoi(argv[2]), pickaxe = atoi(argv[3]);
    int wait_rand;
    // 0 - shovel | 1 - pickaxe
    key_t key;
    key = ftok("tmp_file", 'a');
    int semid = semget(key, 2, 0777|IPC_CREAT|IPC_EXCL); 
    int shmid = shmget(key, 4, 0777|IPC_CREAT|IPC_EXCL);
    arg.val = shovel;
    semctl(semid, 0, SETVAL, arg); 
    arg.val = pickaxe;
    semctl(semid, 1, SETVAL, arg); 
    int *shm = (int *)shmat(shmid, NULL, 0);
    for (int i = 0; i < miners; i++) {
        if (fork() == 0) {
            // miner

            srand(time(NULL) ^ getpid()<<16);
            printf("Creation of miner %d (%d)\n", i+1, getpid());
            
            wait_rand = 1 + rand() % 5; 
            printf("The miner %d waits %d hours before work\n", i+1, wait_rand);
            sleep(wait_rand);

            struct sembuf sops[2] = {{0,-1,0}, {1,-1,0}};
            semop(semid, sops, 2);
            printf("The miner %d takes a shovel and a pickaxe.\n", i+1);

            wait_rand = 1 + rand() % 5; 
            printf("The miner %d starts working for %d hours.\n", i+1, wait_rand);
            sleep(wait_rand);

            int gold;
            gold = 1 + rand() % 1000;
            printf("The miner %d has extracted %d of gold\n", i+1, gold);

            printf("The miner %d put %d g into case.\n", i+1, gold);
            *shm += gold;
            printf("The case contains %d\n", *shm);
            shmdt(shm);

            printf("The miner %d return a shovel and a pickaxe\n", i+1);
            struct sembuf sops_[2] = {{0,1,0}, {1,1,0}};
            semop(semid, sops_, 2);

            printf("The miner of pid %d finished\n", getpid());
            exit(0);
        }
    }
    while (waitpid(-1, NULL, 0)  > 0);
    printf("End of miner's work, the case contains: %d g of gold", *shm);
    semctl(semid, 0, IPC_RMID, arg);
    shmctl(shmid, IPC_RMID, NULL);
}

