#include "film.h"
#include "recompense.h"
#include <iostream>

Recompense::Recompense():Film(){
	cesar=0;
	palmedor=false;
}

Recompense::Recompense(string titre, string real, int an, float dur, int ces, bool palm):Film(titre, real, an, dur){
	cesar=ces;
	palmedor=palm;
}

Recompense::Recompense(const Recompense& d):Film(d){
	cesar=d.cesar;
	palmedor=d.palmedor;
}

bool Recompense::longmetrage (){
	return ((*this).Film::longmetrage()&&palmedor);
}

ostream& operator<<(ostream& f ,Recompense& x){
	if(x.Film::longmetrage())
		f<<x.get_titre()<<x.get_realisateur()<<x.get_annee()<<x.get_duree()<<"Longmetrage"<<x.cesar<<x.palmedor;
	else
		f<<x.get_titre()<<x.get_realisateur()<<x.get_annee()<<x.get_duree()<<"Longmetrage"<<x.cesar<<x.palmedor;
	return f;
}
