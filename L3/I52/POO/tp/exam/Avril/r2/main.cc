#include "musique.h"
#include "musiqueCompressee.h"
#include "albumMP3.h"

int main ()
{
//Test de la classe Musique
Musique m1("Tomber la chemise", "Zebda",4.5 );
Musique m2("Monter le pantalon", "Fatals picards", 2.5);
m1.affiche();
m2.affiche();

//Test de la classe MusiqueCompressee
MusiqueCompressee mc1("La sécurité de l'emploi","Fatals picards",3.3,true,"mp3",19.2);
MusiqueCompressee mc2("Goldorak est mort","Fatals picards",3.3,true,"mp3",19.2);
MusiqueCompressee mc3("Goldorak","Enrique",1.15,true,"mp3",19.2);
MusiqueCompressee mc4("Boléro", "Ravel", 6.9,true, "mp3", 19.2);
MusiqueCompressee mc5("L'informatique", "Chanson Plus Bifluorée",2.5,true,"mp3",19.2 );



MusiqueCompressee tab[3]={mc1,mc2,mc3};

//surcharge
for(int i=0; i<3;i++)
	cout<<"Titre "<<i+1<<endl<<tab[i]<<endl;

//Test de la classe AlbumMP3
AlbumMP3 mon_album(tab, 3), ton_album, son_album;
cout<<"taille totale de l'album : "<<mon_album.taille_album()<<endl;


//Surcharges
son_album=mon_album;
ton_album=son_album+mc4;
ton_album=mc5+ton_album;

cout<<"Les titres de l'album : "<<endl;
for(int i=0; i<ton_album.get_nbtitre();i++)
	cout<<"\t"<<ton_album[i]<<endl;

//cout<<"taille totale de l'album : "<<ton_album.taille_album()<<endl;
//
//
return 0;
}
