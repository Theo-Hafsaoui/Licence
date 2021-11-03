#include <stdint.h>
#include "backt.h"

int64_t queen(int n){
  //TODO Version non optimize of backtracking
  return 42;
}

void Print_Sol(int64_t t){
  //TODO affiche les solutions 
}

int64_t O_queen(int n){
  //TODO Version optimize of backtracking
  return 42;
}
//Essai avec un tableau de mot de 64 bit, un peu trop 
//embetant a mon gout
//boul Is_Free(int64_t Board){
//  
//}
//
//int64_t N_Queen(int64_t Board, short dim){
//  int64_t incr; int ligne=0;
//  if (ligne>=dim) {
//    return Board;
//  }
//  Board=1;
//  int tst=1;
//  while (ligne<dim) {
//    if (Is_Free(Board)) {
//      Board^=tst;
//      Board&=(tst<<1);//On test une nouvelle solution
//    }
//    ligne++;
//    Board&=(incr<<8);
//    tst=incr;
//  }
//  return True;
//}
