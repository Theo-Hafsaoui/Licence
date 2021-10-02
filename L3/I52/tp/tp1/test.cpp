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
	//complexe x;x.a=1;x.b=2;
	//complexe y;y.a=11;y.b=22;
	//complexe z=Somme(x,y);
	//AfficherComplexe(z);
	//complexe x;x.a=1;x.b=2;
	//complexe y;y.a=11;y.b=22;
	//complexe z=Produit(x,y);
	//AfficherComplexe(z);
	//complexe x;x.a=1;x.b=2;
	//float z= Module(x);
	//cout <<"z= "<<z<<endl;
	//complexe x;x.a=1;x.b=2;
	//complexe z=conjuge(x);
	//AfficherComplexe(z);
	//complexe z;Init(z);
	//AfficherComplexe(z);
	//cout<<"ident ="<<z.ident<<endl;

	//complexe z;Init(z);
	//cout<<"adress of z="<<&z<<endl;
	//cout<<"adress of real part of z="<<&z.a<<endl;
	//cout<<"adress of im part of z="<<&z.b<<endl;
	//cout<<"adress of ident of z="<<&z.ident<<endl;
	//complexe& z2=z;
	//cout<<"adress of z2="<<&z2<<endl;
	//cout<<"adress of real part of z2="<<&z2.a<<endl;
	//cout<<"adress of im part of z2="<<&z2.b<<endl;
	//cout<<"adress of ident of z2="<<&z2.ident<<endl;

	complexe*t=CreerVecteurComplexes(5);
	for (int i = 0; i < 5; i++)
	{
		//cout<<"t["<<i<<"]="<<t[i]<<endl;
	}
	return 0;
}
