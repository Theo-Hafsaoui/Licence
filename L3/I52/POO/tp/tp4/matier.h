#ifndef MATIER_H
#define MATIER_H
#include <string>
typedef std::string str;

class matier{
  private:
    str nm;
    int coef;
  public:
    matier();
    matier(str,int);
    void print();
    str get_nom();
    int get_coef();
};




#endif
