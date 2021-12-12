#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "ensemble.h"

int entier(int x)
{
   int res = 0 ;
   while(x>1)
   {
       x = x >> 1 ;
       res ++ ;
   }
   return res ;
}

void afficherEnsemble(ensemble X)
{
   ensemble T ;
   putchar('{');
   while(X)
   { 
      T = X & ( X - 1);
      int n = X ^ T ;
      printf("%d ",entier(n));
      X = T ;
   }
   putchar('}');
   putchar('\n');
}


/*void dame(int r , ullong G , ullong D , ullong C)
{
       ullong X = C & ~ G & ~ D ;
       while (X)
       {
       	Y = X & (X-1) ;
       	Y = X ^ Y ;
       	X = X ^ Y ;
       	printf("%d %d %d \n",(G|Y)<<1,(D|Y)>>1 ,C ^ Y );
       	dame(r+1,(G|Y)<<1 , (D|Y)>>1 ,C ^ Y );
       }
}*/

       	






























      


