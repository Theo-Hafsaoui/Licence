#ifndef _MC
#define _MC
#include "musique.h"
#include <iostream>
using namespace std;

class MusiqueCompressee : public Musique{
private :
	bool perte;//booleen qui est vrai si l'encodage se fait avec perte d'information
	string algo;//nom de l'algorithme d'encodage
	float taux;//en kilo octets par seconde
	
public:
	//constructeurs
	MusiqueCompressee();//par défaut pas de compression
	MusiqueCompressee(string, string, float, bool, string, float);
	MusiqueCompressee(const MusiqueCompressee &);
	//polymorphisme 
	float taille_mem ()const;// calcule la taille du fichier
	//surcharge de l'opérateur <<
	friend ostream& operator<<(ostream&, MusiqueCompressee&);	
};
#endif
