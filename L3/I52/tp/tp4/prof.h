#ifndef PROF_H
#define PROF_H
#include "Personne.h"
class prof : private personne{
  private:
    string stat;
    short h;
  public:
    prof();
    prof(string,string,int,string,short);
    prof(const prof&);
    void print();
    void work(int);
};



#endif
