#include "musiqueCompressee.h"
#include "albumMP3.h"

albumMP3::albumMP3(){
	album=NULL;
	nbtitre=0;
}

albumMP3::albumMP3(int n){
	album=new MusiqueCompressee[n];
	nbtitre=n;
}

albumMP3::albumMP3(MusiqueCompressee* t, int n){
	album=new MusiqueCompressee[n];
	nbtitre=n;
	for(int i=0;i<n;i++){
		album[i]=t[i];
	}
}

albumMP3::albumMP3(const albumMP3& x){
	album=new MusiqueCompressee[x.nbtitre];
	nbtitre=x.nbtitre;
	for(int i=0;i<n;i++){
		album[i]=x.album[i]
	}
}

albumMP3::~albumMP3(){
	delete album;
}
