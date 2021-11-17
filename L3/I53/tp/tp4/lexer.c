#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *Convertit la chaine de caracteres <ch> en une liste d'unités
 *léxicales de la forme (<type>, <valeur>). Retourne une chaine vide en cas
 *d'erreur et affiche le caractere fautif

 *On utilise le lexique suivant:
 * a -> charactere <c>
 * * -> fermeture de kleene <k>
 * . -> concaténation <p>
 * + -> union <u>
 * - -> Exreg <m>
 *
 * ex: a+a => [['c','a'],['u','+'],['c','a'],/NULL]
*/
char** scanner(char* ch){
  int i;
  char** token= calloc(64, sizeof(char*));
  for (int i=0; i<64; i++) {
    token[i]=calloc(2, sizeof(char*));
  }
  for (i=0; ch[i]!=0; i++) {
    if (ch[i]>64) {
      token[i][0]='c'; token[i][1]=ch[i]; }
    else if (ch[i]==40) {
      token[i][0]='o'; token[i][1]='('; }
    else if (ch[i]==41) {
      token[i][0]='f'; token[i][1]=')'; }
    else if (ch[i]==42) {
      token[i][0]='k'; token[i][1]='*'; }
    else if (ch[i]==43) {
      token[i][0]='u'; token[i][1]='+'; }
    else if (ch[i]==45) {
      token[i][0]='m'; token[i][1]='-'; }
    else if (ch[i]==46) {
      token[i][0]='p'; token[i][1]='.'; }
    else {
      printf("Lexical error at: %c", ch[i]);
      char** token= calloc(64, sizeof(char*));
      for (int i=0; i<64; i++) {
        token[i]=calloc(2, sizeof(char*));
      }
      return token;
    }
  }
  token[i++]=NULL;
  return token;
}
