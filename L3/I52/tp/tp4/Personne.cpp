#include "personne.h"
#include <string>
#include <iostream>

using std::string;

personne::personne(){
    nm="";
    pnm="";
    ag=NULL;
}

personne::personne(string nom,string prenom, int age){
    nm=nom;
    pnm=prenom;
    ag=age;
}

void personne::print(){
    std::cout<<"Nom: "<<nm<<" |Prenom: "<<pnm<<" |age: "<<ag<<std::endl;
}