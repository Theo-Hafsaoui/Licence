#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
   for (int i = 0; i < argc; i++)
   {
      if (fork()==0)
      {
          execlp(argv[i], argv[i], NULL);
      }
      else
      {
          wait(NULL);
      }
   }
    return 0;
}
