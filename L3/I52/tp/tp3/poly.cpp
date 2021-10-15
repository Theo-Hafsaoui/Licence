#include <iostream>
#include "poly.h"
using namespace std;

poly::poly(){
	ord=0;
	t=NULL;
}

poly::poly(float* x,int y){
	ord=y;
	t=new float[y+1];
	for(int i=0;i<y+1;i++){
		t[i]=x[i];}
}	

poly::poly(const poly& x){
	ord=x.ord;
	t=new float[x.ord];
	for(int i=0;i<x.ord;i++){
		t[i]=x.t[i];}
}

poly::~poly(){
	delete t;
	cerr<<"prout"<<endl;
}

void poly::print(){
	for(int i=0;i<ord;i++){
		cout<<"t["<<i<<"]="<<t[i]<<endl;}
		}

