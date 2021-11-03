//MAIN 
#include "film.h"
#include "recompense.h"
#include "meilleursFilms.h"
#include <iostream>
using namespace std;
int main()
{

//test classe Film
Film F;
Film Django("Django unchained","Quentin Tarantino",2013,165); 
Film DJ(Django);
DJ.affiche();


//test classe Recompense

Recompense ELM("Entre les murs", "Laurent Cantet",2008,128,1, true);
Recompense VA("La vie d'Adèle", "Abdellatif Kechiche", 2013,179,4, true);
Recompense CH("Le cri du homard", "Nicolas Guiot", 2013, 30,1,false);
Recompense M("Les miettes", "Pierre Pinaud", 2008, 30,1, false);
Recompense FDAP("Le fabuleux destin d'Amélie Poulain", "Jean-Pierre Jeunet", 2001,122,2,false);
Recompense TWBB("There Will Be Blood","Paul Thomas Anderson",2008,158,0,false);

// test de longmetrage()
if (FDAP.longmetrage())
	cout<<FDAP.get_titre()<< " est un long métrage"<<endl;
else
  	cout<<FDAP.get_titre()<< " est un court métrage"<<endl;

if (CH.longmetrage())
	cout<<CH.get_titre()<< " est une long métrage"<<endl;
else
	cout<<CH.get_titre()<< " est un court métrage"<<endl;


//surcharge de << 
cout<<endl<<VA<<endl<<FDAP;



Recompense tab[4]={ELM,VA,CH,TWBB};

//surcharge de <<
for(int i=0; i<4;i++)
	cout<<"Film "<<i+1<<endl<<tab[i]<<endl;



//test classe MeilleursFilms

// tests des constructeurs de la classes MeilleursFilms
MeilleursFilms mesMF(tab,4), tesMF(2), sesMF;

// test de la surcharge de = et de +
tesMF= mesMF + M + FDAP;

//test de longmetrage
MeilleursFilms  tesLM;

tesLM=tesMF.longmetrage();


cout<<"Tes longs Métrages : "<<endl;
for(int i=0; i<tesLM.get_nbfilm();i++)
	cout<<"Film "<<i+1<<endl<<tesLM[i]<<endl;


return 0;
}
