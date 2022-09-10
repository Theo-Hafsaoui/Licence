#ifndef _Amp3
#define _Amp3
#include "musiqueCompressee.h"

class AlbumMP3 {
private :
	MusiqueCompressee* album;
	int nbtitre;
public:
	//constructeurs
	AlbumMP3();
	AlbumMP3(int);//construction d'une instance dont le nombre de morceaux est fourni en paramètre
	AlbumMP3(MusiqueCompressee*, int);
	AlbumMP3(const AlbumMP3 &);
	~AlbumMP3();
	//Accesseurs
	int get_nbtitre(){return nbtitre;};
	//surcharge de l'opérateur =
	
	//surcharge de l'opérateur + qui ajoute un morceau de musique à mon album courant
	AlbumMP3 operator+(const MusiqueCompressee &);
	//surcharge de l'opérateur + qui ajoute une instance de la classe AlbumMP3 à une instance de la classe MusiqueCompressee

	//surcharge de l'opérateur []
	MusiqueCompressee operator[](int i){return album[i];};// retourne l'épisode de rang i dans la liste des épisodes.

	float taille_album();//retourne la taille de l'album en Mo
	
};
#endif
