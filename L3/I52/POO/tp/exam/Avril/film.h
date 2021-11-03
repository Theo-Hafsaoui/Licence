#ifndef _FILM
#define _FILM

#include <string>
using namespace std;

class Film{
private : 
	string titre;//titre du film
	string realisateur;//nom du réalisateur
	int annee;//année de sortie
	float duree;// temps en minutes
	
public:
//Constructeur
	Film();
	Film(string, string, int, float);
	Film(const Film &);
//accesseurs
	string get_titre()const;
	string get_realisateur()const;
	int get_annee()const;
	float get_duree()const;
// polymorphisme
	bool longmetrage () ;//retourne true si le film est un long metrage c'est-à-dire un film qui dure au moins une heure
//methode
	void affiche();	
};
#endif
	 
