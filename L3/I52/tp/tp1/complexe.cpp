#include <iostream>
#include "complexe.h"
#include <tgmath.h>
#include <ctime>
using namespace std;

void AfficherComplexe(const complexe& x){
	cout<< x.a<<" : "<< x.b<<endl;}

void permuter(complexe& x, complexe& y){
	complexe temp;
	temp=x;
	x=y;
	y=temp;
}

void Init(complexe& x){
  x.ident=time(NULL)%256;
  x.a=0;x.b=0;
}

complexe Somme(const complexe& x, const complexe& y){
  complexe res;
  res.a=x.a+y.a;
  res.b=x.b+y.b;
  return res;}

complexe Produit(const complexe& x, const complexe& y){
  complexe res;
  res.a=x.a*y.a-x.b*y.b;
  res.b=x.a*y.b+x.b*y.a;
  return res;}
  
float Module(const complexe& x){
  float res;
  res=sqrt((x.a*x.a)+(x.b*x.b));
  return res;
}

complexe conjuge(const complexe& x){
  complexe res=x;
  res.b=-(x.b);
  return res;
}

complexe Bidon(complexe&){
  //not usefull
}
void CreerComplexe_1(complexe** x){
  *x=new complexe;
  Init(**x);
}
	

void CreerComplexe_2(ptComplexe& x){
  x=new complexe;
  Init(*x);
}

complexe* CreerComplexe_3(){
  complexe* x=new complexe;
  Init(*x);
  return x;
}

complexe* CreerVecteurComplexes(unsigned int x){
  complexe* t=new complexe[x];
  return t;
}
