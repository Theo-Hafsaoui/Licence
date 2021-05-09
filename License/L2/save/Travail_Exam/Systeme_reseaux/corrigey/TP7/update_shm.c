#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <errno.h>

extern int errno;

void main () {
    int shmid = shmget(ftok("tmp_file", 123), 8, IPC_CREAT);
    struct shmid_ds buf;
    int error = shmctl(shmid, IPC_STAT, &buf);

    if (error == -1) {
        perror("perror guau guau");
    }

    printf("The uid of owner is %d\nThe gid of owner is %d\n",
            buf.shm_perm.uid, buf.shm_perm.gid);
    

    printf("The uid of creator is %d\nThe gid of creator is %d\n",
            buf.shm_perm.cuid, buf.shm_perm.cgid);

    printf("The mode of permission is %d\n", buf.shm_perm.mode);

    printf("Size of memory %ld\n", buf.shm_segsz);

    printf("The pid of creator is %d\nThe pid of last changer %d\n",
            buf.shm_cpid, buf.shm_lpid);
}
