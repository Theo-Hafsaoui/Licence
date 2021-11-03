#include "Personne.h"
#include <string>
#include <iostream>

using std::string;

personne::personne(){
    nm="";
    pnm="";
    ag=0;
}

personne::personne(string nom,string prenom, int age){
    nm=nom;
    pnm=prenom;
    ag=age;
}

void personne::print(){
    std::cout<<"Nom: "<<nm<<" |Prenom: "<<pnm<<" |age: "<<ag<<std::endl;
}

personne::personne(const personne& x){
    nm=x.nm;
    pnm=x.pnm;
    ag=x.ag;
}

void personne::vieillir(){
    ag++;
}
