#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>

void main () {
    int shmid = 32768;
    char *sh_mem = shmat(shmid, NULL, 0);
    if (sh_mem == (char *) -1) {
        perror("shmat xd");
    }

    int num, i = 10;
    while (i) {
        while (*sh_mem == '*');
        num = *sh_mem;
        printf("[shm_lit] Read the num %d in the shared memory\n", num);
        *sh_mem = '*';
        printf("[shm_lit] Writes the '*'\n");
        i--;
    }
    shmdt(sh_mem);
}
