#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void GenVec(int *t,int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        t[i]=rand()%10;
    }
}

void affiche(int *a,int n){
    printf("vec =[");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[n-1]);
}

int main(int argc, char const *argv[])
{
    int pip[2];pipe(pip);
    int len = atoi(argv[1]);
    int vec1[len];GenVec(vec1,len);
    sleep(2);
    int vec2[len];GenVec(vec2,len);
    affiche(vec1,len);
    affiche(vec2,len);
    int a,b;int sca;int s;int temp;
    for (int i = 0; i < len; i++)
    {
        if (fork()==0)
        {
            sca=vec1[i]*vec2[i];
            write(pip[1],&sca,sizeof(int));
            printf("processus %d a calcule %d * %d = %d\n",i,vec1[i],vec2[i],sca);
            exit(EXIT_SUCCESS);
        }
        int main(int argc, char const *argv[])
{
    int pip[2];pipe(pip);
    int len = atoi(argv[1]);
    int vec1[len];GenVec(vec1,len);
    sleep(2);
    int vec2[len];GenVec(vec2,len);
    affiche(vec1,len);
    affiche(vec2,len);
    int a,b;int sca;int s;int temp;
    for (int i = 0; i < len; i++)
    {
        if (fork()==0)
        {
            sca=vec1[i]*vec2[i];
            write(pip[1],&sca,sizeof(int));
            printf("processus %d a calcule %d * %d = %d\n",i,vec1[i],vec2[i],sca);
            exit(EXIT_SUCCESS);
        }
        else
        {
            read(pip[0],&temp,sizeof(int));
            s+=temp;
        }
    }
    printf("\nresultat : %d",s);
    return 0;
}

        else
        {
            read(pip[0],&temp,sizeof(int));
            s+=temp;
        }
    }
    printf("\nresultat : %d",s);
  

    return 0;
}
