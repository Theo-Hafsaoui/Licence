#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef int semaphore[2];

void init_sem(semaphore s, int n) {
    char chip = '#';
    pipe(s);
    for(int i = 0; i < n; i++) {
        write(s[1], &chip, sizeof(char));
    }
}

void p(semaphore s) {
    char chip;
    read(s[0], &chip, sizeof(char));
}

void v(semaphore s) {
    char chip = '#';
    write(s[1], &chip, sizeof(char));
}

