#include<fstream>
#include "complex.h"
#include<iostream>
#ifndef VCOMPLEX_H
#define VCOMPLEX_H

class Vcomplex{
    private:
        complex* v;
        unsigned int n;
    public:
        Vcomplex();
        Vcomplex(complex*,unsigned int);
        Vcomplex(const Vcomplex&);
        ~Vcomplex();
        void print();
        Vcomplex(std::ifstream&);    
};



















#endif