#ifndef _MEILLEURSFILMS
#define _MEILLEURSFILMS
#include "recompense.h"

class MeilleursFilms {
private :
	Recompense * selection;
	int nbfilm;
public:
//constructeurs
	MeilleursFilms();
	MeilleursFilms(int);//construction d'une instance dont la taille fournie en argument
	MeilleursFilms(Recompense*, int);
	MeilleursFilms(const MeilleursFilms &);
//Deestructeur
	~MeilleursFilms();

//Accesseurs
	int get_nbfilm(){return nbfilm;};
	Recompense* get_selec(){return selection;};

//surcharge de l'opérateur =
  MeilleursFilms operator=(const MeilleursFilms&);

// Surcharge de l'opérateur +
	MeilleursFilms operator+(const Recompense &);//surcharge de l'opérateur + qui retourne 
	//une instance de la classe MeilleursFilms obtenue en ajoutant un film à l'objet courant 
	//de la classe MeilleursFilms

// Surcharge de l'opérateur []
	Recompense operator[](int i);// retourne la recompense de rang i dans la selection.

//Methode
	MeilleursFilms longmetrage();// retourne une instance de MeilleursFilms qui contient les meilleurs longs metrages ayant au moins 1 césar ou une palme d'or;
	
};
#endif
