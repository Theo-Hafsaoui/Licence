#ifndef ETUDIANT2_H
#define ETUDIANT2_H
#include "etudiant.h"
#include <string>
typedef std::string str;
class etudiant2: private etudiant1{
  private:
    str* Lm;
  public:
    etudiant2(string nom,string prenom,int age,int nbnote, int nb_suiv );
    etudiant2(const etudiant2&);
    ~etudiant2();
    void print();
    int avg();
    etudiant2 operator=(const etudiant2&);
};

#endif
