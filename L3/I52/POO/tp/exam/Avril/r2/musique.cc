#include <string>
#include <iostream>
#include "musique.h"
using namespace std;

Musique::Musique(){
	titre="";
	auteur="";
	duree=0;
}
	
Musique::Musique(string tit, string aut, float dur){
	titre=tit;
	auteur=aut;
	duree=dur;
}

Musique::Musique(const Musique & x){
	titre=x.titre;
	auteur=x.auteur;
	duree=x.duree;
}

string Musique::get_titre()const{return titre;}
string Musique::get_auteur()const{return auteur;}
float Musique::get_duree()const{return duree;}

float Musique::taille_mem()const{
		return (duree*KOm);
}

void Musique::affiche(){
		cout<<"title: "<<titre<<" |Author: "<<
				auteur<<" |Duratiom: "<<duree<<endl;
}
