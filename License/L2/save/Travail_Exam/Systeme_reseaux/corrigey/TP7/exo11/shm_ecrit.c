#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>

void main () {
    int shmid = 32768;
    char *sh_mem = shmat(shmid, NULL, 0);
    if (sh_mem == (char *)-1) {
        perror("shmat xd");
    }
    srand(time(NULL));

    char num, i = 10;
    while (i) {
        num = rand() % 256;
        printf("[shm_ecrit] Write the num %d in the shared memory\n", num);
        *sh_mem = num;
        printf("[shm_ecrit] Waits the shm_lit finish reading\n");
        while (*sh_mem != '*');
        i--;
    }
    shmdt(sh_mem);
}
