#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <sys/wait.h>

int i=1;

void affiche(){
    printf("ok");
    i=0;
}

int main(int argc, char *argv[]){
    if (fork() == 0)  {
        for (int i = 0; i < 10; i++);  /* une phase de calcul */
            exit(1);
        }
        while(i){  /* une phase de calcul */
            signal(SIGCHLD,affiche);
            }}
