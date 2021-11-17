#include "musiqueCompressee.h"
#include "albumMP3.h"
AlbumMP3::AlbumMP3(){
	album=NULL;
	nbtitre=0;
}

AlbumMP3::AlbumMP3(int n){
	album=new MusiqueCompressee[n];
	nbtitre=n;
}

AlbumMP3::AlbumMP3(MusiqueCompressee* t, int n){
	album=new MusiqueCompressee[n];
	nbtitre=n;
	for(int i=0;i<n;i++){
		album[i]=t[i];
								}
}

AlbumMP3::AlbumMP3(const AlbumMP3& x){
	album=new MusiqueCompressee[x.nbtitre];
	nbtitre=x.nbtitre;
	for(int i=0;i<x.nbtitre;i++){
		album[i]=x.album[i];
									}
}

AlbumMP3::~AlbumMP3(){
	delete album;
}

AlbumMP3 AlbumMP3::operator=(const AlbumMP3& x){
	nbtitre=x.nbtitre;
	album=new MusiqueCompressee[x.nbtitre];
	for(int i=0;i<nbtitre;i++){
		album[i]=x.album[i];
	}
	return (*this);
}

AlbumMP3 AlbumMP3::operator+(const MusiqueCompressee& x){
	AlbumMP3 res;
	res.nbtitre=nbtitre+1;
	res.album=new MusiqueCompressee[nbtitre+1];
	for(int i=0;i<nbtitre;i++){
		res.album[i]=album[i];
	}
	res.album[nbtitre]=x;
	return res;
}

AlbumMP3 operator+(const MusiqueCompressee& x,const AlbumMP3& y ){
		int n = y.get_nbtitre()+1;
		AlbumMP3 res(n);
		for (int i=0; i<n; i++) {
			res[i]=y.album[i];
		}
	res[n]=x;
	return res;
}

float AlbumMP3::taille_album(){
	float res;
	for(int i=0;i<nbtitre;i++){
		res+=(album[i]).taille_mem();
	}
	return res;
}
