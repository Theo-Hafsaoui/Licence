#include "matier.h"
#include <string>

matier::matier(){
  nm="";
  coef=0;
}

matier::matier(str nom, int coeff){
  nm=nom;
  coef=coeff;
}

str matier::get_nom(){
  return nm;
}
int matier::get_coef(){
  return coef;
}
