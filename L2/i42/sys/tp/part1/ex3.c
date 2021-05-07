#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int i=0;
    int Son_id,Father_id;
    Son_id=fork();
    if (Son_id==0)
    {
        i++;
        Father_id=getppid();
        printf("je suis le fils, i=%d\n",i);
    }
    else
    {
        i++;i++;
        printf("je suis le pere, i=%d\n",i);
    }
    

}