#include <iostream>
#include "complex.h"
using namespace std;

complex::complex(){
	a=0;
	b=0;
}

complex::complex(int x,int y){
	a=x;
	b=y;
}	

complex::complex(const complex& x){
	a=x.a;
	b=x.b;
}

complex::~complex(){
	cerr<<"prout"<<endl;
}

void complex::print(){
	cout<<"X="<<a<<"+i"<<b<<endl;
}

int complex::getRe(){
	return a;
}
	
int complex::getIm(){
	return b;
}

