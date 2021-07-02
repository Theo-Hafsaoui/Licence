#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <errno.h>

/*int main(int argc, char const *argv[])
{
    execlp("echo","echo","HI HITLER",NULL);
    printf("Goebels");
    return 0;
}*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*#define N 2
int main(void) {
     int i,  pid, pidinit;
     pidinit =  getpid();
     printf("pere de  pid initial %d\n",pidinit);
     for (i  =  0;  i  <  N;  i++) {
        pid=fork();
        printf("boucle num %d  pid:%d\n", i,  getpid());
     }
     if(!pid){
         printf("prout %d\n",getpid());
         exit(0);
     }
     else{
         execl("lbinlshl",  "sh",  "-c",  "echo  i",  (char *)  NULL);
         if (fork())
         {
             i+=fork()*2;
         }
        while(wait(NULL)  !=  -1);
        return 0; 
     }}

*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define  N  2 //deux train
#define  VOY  2 //deux voyage
#define  D  2 //nombre de jours d'analyse
#define voyageurs 42
#define retards 42

int main(){
    int msgid;
    int i,pid,jour,j;
    key_t key = 23;
    printf("key = %d\n", key);
    if ((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
        perror("Erro on msgget");
        exit(-1);
    }
    struct msgbuf {
        long type;
        long retard;
        long voyage;
    } msgp;
    msgp.voyage=0;
    msgp.retard=0;
    for  (i= 0;  i< N;  i++)  { 
        if  (!  pid)  {
            srand(time(NULL)  *  getpid());
            for  (jour= 0;  jour< D;  jour++){
                int  nb_v,  rtd;
                sleep(rand()%3);
                printf("Train %d:  debut  du jour %d\n",  i,  jour);
                for  (j  =  0;  j  <  VOY;  j++)  { 
                    nb_v =  rand()%10 ;
                    printf("Train %d,  jour %d:  depart  voyage  %d avec  %d voyageurs\n",  i  ,jour,  j,  nb_v);
                    msgp.voyage+=nb_v;
                    sleep(rand()%3);
                    rtd =rand()% 7  -  3;
                    msgp.retard+=rtd;
                    printf("Train %d,  jour %d:  arrivee  voyage  %d avec  retard de  %d\n",  i,  jour,  j,  rtd);
                }
                if ((msgsnd(msgid, &msgp, sizeof(lon), 0)) < 0) {
                    perror("msgsnd failed"), printf("errno = %d\n", errno), exit(-1);
                }
            }
            exit(0);
        }
    }
    //father
    //afichae des stat
    printf("retard =%d",msgp.retard);
    srand(time(NULL)  * getpid());
    int  total_voy =  0,  total_rtd =  0;
    for  (jour= 0;  jour< D;  jour++)  {
        sleep(rand()%3);
        printf("Gare:  statistiques  jour %d\n",  jour);
        for  (i= 0;  i< N;  i++)  {
            printf ("Gare:  train %d:  %d voyageurs,  %d retards\n",  i,  voyageurs ,  retards );
        }
    }
    printf("Gare:  total  sur %d jours:  %d voyageurs,  %d retards\n",  D,  total_voy,  total_rtd);
    return D;
}
