#ifndef COMPLEXE_H
#define COMPLEXE_H
typedef struct complexes{
	unsigned int ident;
	int a;
	int b;
} complexe;
typedef complexe* ptComplexe;
	
void AfficherComplexe(const complexe&);
complexe Somme(const complexe&, const complexe&);
complexe Produit(const complexe&, const complexe&);
float Module(const complexe&);
complexe conjuge(const complexe&);
void Init(complexe&);
complexe Bidon(complexe&);
void CreerComplexe_1(complexe**);
void CreerComplexe_2(ptComplexe&);
complexe* CreerComplexe_3();
complexe* CreerVecteurComplexes(unsigned int);
#endif
