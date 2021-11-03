#include "etudiant2.h"
#include "etudiant.h"
#include <iostream>
#include <string>
//JE HAIS LES  TP DE C++
typedef std::string str;


etudiant2::etudiant2(string nom,string prenom,int age,int nbnote, str* list_m): etudiant1(nom, prenom, age, nbnote){
  Lm= new str[nbnote];
}

etudiant2::etudiant2(const etudiant2& x):etudiant1(x){
  Lm=x.Lm;
}

etudiant2::~etudiant2(){
  delete [] Lm;
}

void etudiant2::print(){
  std::cout<<nom<prenom<<
}
