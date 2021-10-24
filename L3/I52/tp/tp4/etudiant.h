#ifndef ETUDIANT_H
#define ETUDIANT_H
#include "Personne.h"
#include <string>

class etudiant1: private personne{
  private:
  int nb;
  int* note;
  public:
    etudiant1();
    etudiant1(string,string,int,int);
    etudiant1(const etudiant1&);
    ~etudiant1();
    void add(int*,int);
    int avg();
    void print();
    etudiant1 operator=(const etudiant1&);
};


#endif
