#include <cstdio>
#include <string>
#include <iostream>
#include "musique.h"
#include "musiqueCompressee.h"
using namespace std;

MusiqueCompressee::MusiqueCompressee(){
	perte=false;
	algo="";
	taux=0;
}

MusiqueCompressee::MusiqueCompressee(string tl,string aut, float dur,bool pr,string alg, float tx):Musique(tl, aut, dur){
	perte=pr;
	algo=alg;
	taux=tx;
}

MusiqueCompressee::MusiqueCompressee(const MusiqueCompressee& x):Musique(x){
	perte=x.perte;
	algo=x.algo;
	taux=x.taux;
}

float MusiqueCompressee::taille_mem ()const{
	return (((*this).get_duree())*(taux));	
}

ostream& operator<<(ostream& f, MusiqueCompressee& x){
	f<<x.get_titre()<<x.get_auteur()<<x.taille_mem()<<endl;
	return f;
}
