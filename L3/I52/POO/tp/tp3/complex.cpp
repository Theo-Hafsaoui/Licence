#include <iostream>
#include "complex.h"
using namespace std;

//complex F_x;

complex::complex(){
	//cerr<<"Default constructor"<<endl;
	a=0;
	b=0;
}

complex::complex(int x,int y){
	//cerr<<"Parameter constructor"<<endl;
	a=x;
	b=y;
}	

complex::complex(const complex& x){
	//cerr<<"Copy constructor"<<endl;
	a=x.a;
	b=x.b;
}

complex::~complex(){
	//cerr<<"Destruction !!!!"<<endl;
}

void complex::print(){
	cout<<"X="<<this->a<<"+i"<<this->b<<endl;
}

int complex::getRe(){
	return a;
}
	
int complex::getIm(){
	return b;
}

void complex::sum(const complex& x){
	a+=x.a;
	b+=x.b;
}

bool complex::identical(const complex& x){
	return(this->a==x.a && this->b==x.b);
}
//ex4 bis
void complex::sum1(const complex& z)
{
  a = a + z.a;
  b = b + z.b;
}

complex complex::sum2(const complex& z)
{
  return complex(a+z.a, b+z.b);
}

complex complex::sum3(const complex& z)
{
  a = a + z.a;
  b = b + z.b;
  return *this;
}

complex& complex::sum4(const complex& z)
{
  a = a + z.a;
  b = b + z.b;
  return *this;
}

complex complex::operator+(const complex &x){
	complex res=*this;
	res.sum(x);
	return res;
}

complex complex::operator-(const complex &x){
	complex res=*this;
	res.a=res.a-x.a;
	res.b=res.b-x.b;
	return res;
}


complex complex::operator*(const complex &x){
	complex res=*this;
	res.a=res.a*x.a;
	res.b=res.b*x.b;
	return res;
}

complex complex::operator/(const complex &x){
	complex res=*this;
	res.a=res.a/x.a;
	res.b=res.b/x.b;
	return res;
}

complex complex::operator=(const complex &x){
	a=x.a;b=x.b;
	return *this;
}
