#include <string>
#include <iostream>
#include "musique.h"
#include "musiqueCompresse.h"

using namespace std;

MusiqueCompressee::MusiqueCompressee(){
	perte=false;
	algo="";
	taux=0;
}

MusiqueCompressee::MusiqueCompressee(string tl,string aut, float dur,bool pr,string alg, float tx):Musique(tl, aut, dur){
	perte=pr;
	algo=alg
	taux=tx;
}

MusiqueCompressee::MusiqueCompressee(const MusiqueCompressee& x):Musique(x){
	perte=x.perte;
	algo=x.algo
	taux=x.taux;
}

float taille_mem ()const{
	
}

