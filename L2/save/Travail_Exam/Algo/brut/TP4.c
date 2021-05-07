#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

double Power(float x, uint n)
    {double p = 1;
    for(int i = 0;i < n;i++ )
      p *= x;
    return p;
}
double SM(float x,uint n)
  {
  double r = x;
  double p = 1;
  for(;n >0;n = n/2)
  {

    if (n%2)
      p = p*r;
    r = r*r;
  }
  return p;
}

int main(){
  printf("%lf  \n%lf\n",Power(2,3),SM(2,3));
}
