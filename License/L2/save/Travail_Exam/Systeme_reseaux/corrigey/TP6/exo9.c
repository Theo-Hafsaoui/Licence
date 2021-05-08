#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
 
void print_array(int n, int * tab)
{
    printf("[");
    for(int i = 0; i < n-1; i++)    
    {
        printf("%d,", tab[i]);
    }
    printf("%d]\n",tab[n-1]);
}


void main(int argc, char ** argv)
{
    // random tab creation
    int n = atoi(argv[1]);
    int tab1[n], tab2[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        tab1[i] = rand() % 10;
        tab2[i] = rand() % 10;
    }
    print_array(n, tab1);
    print_array(n, tab2);
    //
    

    // creation of n sons
    int res;
    int tube[2];
    pipe(tube);
    for(int i = 0; i < n; i++)
    {
        if(fork() == 0)
        {
            // fils 
            close(tube[0]);
            res = tab1[i] * tab2[i];
            printf("Processus %d calcul %d * %d = %d\n", i, tab1[i], tab2[i], res);
            write(tube[1], &res, sizeof(res));
            exit(0);
        }
    }
    int readbuffer = 0;
    int total = 0;
    close(tube[1]);
    for(int i = 0; i < n; i++)
    {
        read(tube[0], &readbuffer, sizeof(readbuffer));
        printf("buffer = %d\n", readbuffer);
        total += readbuffer;
    }
    printf("Result: %d\n", total);
}
    

