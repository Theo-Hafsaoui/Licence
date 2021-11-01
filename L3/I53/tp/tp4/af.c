/*
  I53 Compilation et théorie des langages
  Nicolas Méloni
  28 - 10 -2019
 */
#include <stdio.h>
#include "afd.h"
#include "afn.h"

int main(int argc, char *argv[])
{
  printf("test=%d\n", IN(0,1));
  afd A;
  char alphabet[] = "ab";
  uint finals[2] = {1,4};
  afd_init(&A, 5, alphabet, 2, 1, finals);
  afd_add_trans(&A, 1, 'a', 2);
  afd_add_trans(&A, 1, 'b', 1);
  afd_add_trans(&A, 2, 'a', 3);
  afd_add_trans(&A, 2, 'b', 1);
  afd_add_trans(&A, 3, 'a', 4);
  afd_add_trans(&A, 3, 'b', 1);
  afd_add_trans(&A, 4, 'a', 4);
  afd_add_trans(&A, 4, 'b', 4);
  //afd_print(A);
  //afd_finit(&B, "exemple.afd");
  //afd_print(B);
  afn C;afn D;afn CD;
  afn_char(&C,'a',0);
  afn_char(&D,'b',0);
  afn_print(C);
  afn_print(D);
  //afn_union(&CD,C,D);
  afn_concat(&CD,C,D);
  afn_print(CD);
//  afn_finit(&C, "exemple.afn");
//  afn_print(C);
//  printf("%d", afd_simul(argv[1],B)); 
//  if (afd_simul("a",B)) {
//    printf("Expression is correct\n");
//  }
//  else {
//    printf("Expression is incorrect\n");
//  }
  //printf("je reson:%d\n",0==NULL);
  afn_free(&C);
  afd_free(&A);
  return  0;
}
