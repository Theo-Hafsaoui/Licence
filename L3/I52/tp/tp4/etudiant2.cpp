#include "etudiant2.h"
#include <iostream>
#include <string>
typedef std::string str;


etudiant2::etudiant2(string nom,string prenom,int age,int nbnote, int nb_suiv ): etudiant1(nom, prenom, age, nbnote){
  Lm= new str[nb_suiv];
}


etudiant2::etudiant2(const etudiant2&):{

}

