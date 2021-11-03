#include "Personne.h"
#include "prof.h"
#include <string>
#include <iostream>

prof::prof(){
  stat="Inutile";
  h=0;
}

prof::prof(string nom,string prenom,int age,string statut,short heure){
  stat=statut;
  h=heure;
}
void prof::work(int x){
  h+=x;
}

void prof::print(){
  (*this).personne::print();
  std::cout<<"stat:"<<stat<<" |heure: "<<h<<std::endl;
}


