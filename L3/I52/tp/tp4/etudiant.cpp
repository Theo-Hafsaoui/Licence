#include "Personne.h"
#include "etudiant.h"
#include <cstdlib>
#include <ostream>
#include <string>
#include <iostream>
typedef string str;


etudiant1::etudiant1(){
  nb=0;
  note=nullptr;
}

etudiant1::etudiant1(str nom,str prenom,int age,int nb_note):personne(nom, prenom, age){
  nb=nb_note;
  note= new int[nb];
}

etudiant1::etudiant1(const etudiant1& x):personne(x){
  nb=x.nb;
  note= new int[nb];
  for (int i=0; i<nb; i++) {
    note[i]=x.note[i];
  }
}

etudiant1::~etudiant1(){
  delete [] note;
}

void etudiant1::print(){
  (*this).personne::print();
  if (nb==0) {
    std::cout<<"Nome Ue:"<<nb<<" |note: Aucune"<<std::endl;
  }
  std::cout<<"Nombre Ue:"<<nb<<"|notes :";
  for (int i=0; i<nb-1; i++) {
    std::cout<<note[i]<<","; 
  }
  std::cout<<note[nb-1]<<std::endl;
}

void etudiant1::add(int* t,int n){
  nb=n;
  note=new int[n];
  for (int i=0; i<n; i++) {
    note[i]=t[i];
  }
}

int etudiant1::avg(){
  int average=0;
  for (int i=0; i<nb; i++) {
    average+=note[i];
  }
  return (average/nb);
}

etudiant1 etudiant1::operator=(const etudiant1 &x){
  etudiant1 res;
  res.personne::operator=(x);
  nb=x.nb;
  note=new int[nb];
  for (int i=0; i<nb; i++) {
    note[i]=x.note[i];
  }
  return res;
}
