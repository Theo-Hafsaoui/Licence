#include <iostream>
#include "echangiste.h"
#include "complexe.h"
using namespace std;

int main(){
	//int a=42;	
	//int b=32;	
	//permuter(a,b);
	//cout<<a<<"  "<<b<<endl;
	//complexe x;x.a=1;x.b=2;
	//complexe y;y.a=11;y.b=22;
	//AfficherComplexe(x);
	//permuter(x,y);
	//AfficherComplexe(x);
	complexe x;x.a=1;x.b=2;
	complexe y;y.a=11;y.b=22;
  complexe z=Somme(x,y);
	AfficherComplexe(z);
	return 0;
}
