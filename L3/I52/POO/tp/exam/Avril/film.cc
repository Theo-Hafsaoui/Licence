#include "film.h"
#include <string>
#include <iostream>
using namespace std;

Film::Film(){
	titre="";
	realisateur="";
	annee=0;
	duree=0;
}

Film::Film(string title, string real, int year, float dur){
	titre=title;
	realisateur=real;
	annee=year;
	duree=dur;
}

Film::Film(const Film& XXX){
	titre=XXX.titre;
	realisateur=XXX.realisateur;
	annee=XXX.annee;
	duree=XXX.duree;
}

string Film::get_titre()const{
	return titre;
}

string Film::get_realisateur()const{
	return realisateur;
}

int Film::get_annee()const{
	return annee;
}

float Film::get_duree()const{
	return duree;
}

bool Film::longmetrage(){
	return (duree>60);
}

void Film::affiche(){
	if(this->longmetrage())
		cout<<titre<<realisateur<<annee<<duree<<"Longmetrage"<<endl;
	else
		cout<<titre<<realisateur<<annee<<duree<<"Courtmetrage"<<endl;
}
