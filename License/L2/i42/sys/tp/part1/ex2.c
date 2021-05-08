#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int Son_id,Father_id;
    Son_id=fork();
    if (Son_id==0)
    {
        Father_id=getppid();
        printf("je suis le fils, le pid de mon pere est %d\n",Father_id);
    }
    else
    {
        printf("je suis le pere, le pid de mon fils est %d\n",Son_id);
    }
}