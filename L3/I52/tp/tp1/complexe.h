#ifndef COMPLEXE_H
#define COMPLEXE_H
typedef struct complexes{
	int a;
	int b;
} complexe;
	
void AfficherComplexe(const complexe&);
complexe Somme(const complexe&, const complexe&);
complexe Produit(const complexe&, const complexe&);
#endif
