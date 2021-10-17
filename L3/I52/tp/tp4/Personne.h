#include <string>
using std::string;
#ifndef PERSSONE_H
#define PERSSONE_H


class personne{
    private:
        string nm;
        string pnm;
        int ag;
    public:
        personne();
        personne(string,string,int);
        personne(const personne&);
        void print();
        void vieillir();
};
#endif
