#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef int semaphore[2];
void init_sem(semaphore s, int n);
void p(semaphore s);
void v(semaphore s);

void main(int argc, char** argv) {
    int p2_takeoff = atoi(argv[1]);
    int p2_land = atoi(argv[2]);
    const int time_for_landing = 3;
    const int time_for_takeoff = 5;
    int random_num, status = 0; 
    pid_t curr_pid, wpid;
    semaphore sem;
    init_sem(sem, 1);

    for (int i = 0; i < p2_takeoff; i++) {
        if (fork() == 0) {
            //son plane to takeoff           
            curr_pid = getpid();
            srand(time(NULL) ^ (getpid() << 16));
            random_num = rand() % 11 + 1;
            sleep(random_num);
            printf("The flight number %d want to take off\n", curr_pid);
            p(sem);
            printf("\tThe flight number %d in phase of takeoff\n", curr_pid);
            sleep(time_for_takeoff);
            v(sem);
            printf("\t\tThe runaway is free by the flight %d\n", curr_pid);
            exit(0);
        }
    }
            
    for (int i = 0; i < p2_land; i++) {
        if (fork() == 0) {
            //son plane to land 
            curr_pid = getpid();
            srand(time(NULL) ^ (getpid() << 16));
            random_num = rand() % 11 + 1;
            sleep(random_num);
            printf("The flight number %d want to land\n", curr_pid);
            p(sem);
            printf("\tThe flight number %d in phase of landing\n", curr_pid);
            sleep(time_for_landing);
            v(sem);
            printf("\t\tThe runaway is free by the flight %d\n", curr_pid);
            exit(0);
        }
    }
    while (wpid = wait(&status) > 0);
}
