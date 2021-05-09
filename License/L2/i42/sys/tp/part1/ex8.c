#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int flag;
   for (int i = 0; i < argc; i++)
   {
      if (fork()==0)
      {
          flag=execlp(argv[i], argv[i], NULL);
          if (flag==-1)
          {
              printf("erreur\n");
              exit(NULL);
          }
          
      }
      else
      {
          wait(NULL);
      }
   }
    return 0;
}
