//
#include <iostream>
#include "complex.h"
#include "poly.h"
using namespace std;

int main(){
	float t[3]={1,2,3};
	poly x(t,3);
	x.print();
	return 0;
}
