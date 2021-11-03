//https://nguyen.univ-tln.fr/poo-tp3-c.html
#include <iostream>
#include "complex.h"
#include "Vcomplex.h"
#include "poly.h"
using namespace std;

//complex G_x;
//void bidon(){
    //complex f_x;
    //for (int i = 0; i < 5; i++)
    //{
        //continue;
    //}
//}
//void bidon2(const complex& x){
    //for (int i = 0; i < 5; i++)
    //{
        //continue;
    //}
//}

int main(){
    //EX1:
    //cout<<"Debut:"<<endl;
    //complex m_x;
    //cout<<"*********************************************"<<endl;
    //bidon();
    //complex& r_mx=m_x;
    //bidon2(r_mx);
    //EX2
    // float t[3]={1,2,3};
    // poly x(t,3);
    // x.print();
    // return 0;
    // EX3
    //complex arr[5];
    //Vcomplex arg(arr,5);
    //arg.print();
    //ifstream file("data.txt");
    //Vcomplex arg(file);
    //arg.print();
    //EX4
    complex x1(2,2);
    complex x2(2,2);
    //complex x3=x1+x2;
    //complex x3=x2-x1;
    complex x3=x2/x1;
    x3.print();
}
