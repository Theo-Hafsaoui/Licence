#include <stdio.h>
#include <stdlib.h>


typedef enum tbool tbool;

typedef unsigned int uint;

enum tbool
{
  true = 1, false = 0
};
/* SUJET 1
tbool EstPalindrome(char *c){
  int n = strlen(c);
  int i = 0;
  int j = n-1;
  int m = n/2;
  while (i != m && j!= m){
    if (c[i] != c[j])
      return false;
    i++;
    j--;
  }
  return true;

}

int main(){
  char *p = "radar";
  char *p1 = "chien";
  char *p2 = "kayak";
  char *p3 = "chat";
  printf("%d %d %d %d \n",EstPalindrome(p),EstPalindrome(p1),EstPalindrome(p2),EstPalindrome(p3));
}
*/
//unsigned int <- 4 octets
/* SUJET 2
void TriSelection(int *L, uint n){
  if (n == 0)
    exit(0);
  //int min = l[0];
  int imin;
  int i = 0;
  int j;
  int temp;
  while(i < n){
    j = i;
    imin = i;
    while(j <n){
      if (L[imin] > L[j])
        imin = j;
      j++;
    }
    temp = L[i];
    L[i] = L[imin];
    L[imin] = temp;
    i++;
  }

}

int main(){
  int liste[6] = {8,2,1,5,10,7};
  TriSelection(liste,6);
  printf("[ ");
  for(int i = 0; i < 6;i++)
    printf("%d ",liste[i]);
  printf("]\n");

}
*/

uint PairOuImpair(uint n){
  if (n%2)
    return 3*n+1;
  return n/2;
}

uint syracuse(uint u0){
  int n = 0;
  while(1){
    if (u0 ==1)
      return n;
    u0 = PairOuImpair(u0);
    n++;

  }
}

int main(){
  printf("%d\n",syracuse(100));
}
