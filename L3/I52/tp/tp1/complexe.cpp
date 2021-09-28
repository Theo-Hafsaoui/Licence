#include <iostream>
#include "complexe.h"
using namespace std;

void AfficherComplexe(const complexe& x){
	cout<< x.a<<" : "<< x.b<<endl;}

void permuter(complexe& x, complexe& y){
	complexe temp;
	temp=x;
	x=y;
	y=temp;
}

complexe Somme(const complexe& x, const complexe& y){
  complexe res;
  res.a=x.a+y.a;
  res.b=x.b+y.b;
  return res;}

complexe Produit(const complexe& x, const complexe& y){
  complexe res;
  res.a=x.a*y.a-x.b*y.b;
  res.b=x.a*y.a+x.b*y.b;
  return res;}
  
	
