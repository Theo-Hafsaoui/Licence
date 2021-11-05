#include "film.h"
#include "recompense.h"
#include "meilleursFilms.h"
#include <iostream>

MeilleursFilms::MeilleursFilms(){
	selection=0;
	nbfilm=0;
}

MeilleursFilms::MeilleursFilms(int x){
	selection= new Recompense[x];
	nbfilm=x;
}

MeilleursFilms::MeilleursFilms(Recompense* t, int x){
	selection= new Recompense[x];
	nbfilm=x;
	for (int i=0; i<x; i++) {
		selection[i]=t[i];
	}
}

MeilleursFilms::MeilleursFilms(const MeilleursFilms& x){
  selection= new Recompense[x.nbfilm];
	nbfilm=x.nbfilm;
	for (int i=0; i<x.nbfilm; i++) {
		selection[i]=x.selection[i];
	}
}

MeilleursFilms::~MeilleursFilms(){
	delete [] selection;
}

MeilleursFilms MeilleursFilms::operator=(const MeilleursFilms&){
	MeilleursFilms temp;
	temp.selection=selection;
	temp.nbfilm=nbfilm;
	return temp;
}

MeilleursFilms MeilleursFilms::operator+(const Recompense& x){
	MeilleursFilms temp;
	temp.nbfilm= nbfilm+1;
	temp.selection=new Recompense[temp.nbfilm];
	for (int i=0; i<nbfilm; i++) {
		temp.selection[i]=selection[i];
	}	
	temp.selection[nbfilm]=x;
	return temp;
}


Recompense MeilleursFilms::operator[](int i){
	Recompense temp;
	temp=selection[i];
	return temp;
}
//MeilleursFilms MeilleursFilms::longmetrage(){
//
//}
