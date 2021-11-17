#include "afn.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

//static int i=0;
char ch_rpn[64];

char* rpn(char** token){
  int len;
  for (len=0; token[len]!=0; len++) { }
  char** ch_token= calloc(64, sizeof(char*));
  for (int i=0; i<64; i++) {
    ch_token[i]=calloc(2, sizeof(char*));
  }
  for (int i=0; i<len; i++) {
    ch_token[i][0]=token[len-i-1][0];
    ch_token[i][1]=token[len-i-1][1];
  }
  ch_token[len]=0;
  for (int i=0; i<64; i++) {
    free(token[i]);
  }
  free(token);
  return ch_token[0];
}

int expr(char** ch_token){
      
}
