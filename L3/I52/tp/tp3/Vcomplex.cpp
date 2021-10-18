#include<fstream>
#include "complex.h"
#include<iostream>
#include "Vcomplex.h"

Vcomplex::Vcomplex(){
    v=nullptr;
    n=0;
}

Vcomplex::Vcomplex(complex* t,unsigned int x){
    v=new complex[x];
    n=x;
    for (int i = 0; i < x; i++)
    {
        v[i]=t[i];
    }
}

Vcomplex::Vcomplex(const Vcomplex& x){
    v=new complex[x.n];
    n=x.n;
    for (int i = 0; i < x.n; i++)
    {
        v[i]=x.v[i];
    }
}

Vcomplex::~Vcomplex(){
    delete v;
}

void Vcomplex::print(){
    for (int i = 0; i < n; i++)
    {
        v[i].print();
    }
}

Vcomplex::Vcomplex(std::ifstream& file){
    file >> n;
    v = new complex[n];
    float a, b;
    for (int i = 0; i < n; i++)
    {
        file >> a; file >> b;
        v[i] = complex(a, b);
  }
}