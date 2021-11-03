#ifndef _RECOMPENSE
#define _RECOMPENSE
#include "film.h"
#include <iostream>
using namespace std;

class Recompense : public Film{
private :
	int cesar; // nombre de César reçus
	bool palmedor;//true si palme d'or, false sinon
public:
//constructeurs
	Recompense();//par défaut aucune recompense
	Recompense(string, string, int, float, int, bool);
	Recompense(const Recompense &);

//polymorphisme 
	bool longmetrage () ;// retourne vrai si la longeur du film est d'au moins 1 heure et s'il a au moins une recompense César ou palme d'or

//surcharge de l'opérateur <<
	
	
	
};
#endif
