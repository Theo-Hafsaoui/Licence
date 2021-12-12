#ifndef GRAPHE_H
#define GRAPHE_H

typedef int sommet ;

typedef struct _liste_{
	int num ;
	struct _liste_ * svt ;
}enrliste , * liste ;


typedef struct {
	int nbs ;
	int ** mat ;
	liste * adj ;
	double ** w ;
	}graphe ;

graphe creer_graphe(int n);
void liberer_graphe(graphe g);

graphe GrapheAlea(int n , float proba);
void conversionListe(graphe*g);
void afficher(graphe g);//aficher les listes d adjacences
graphe grapheComplet(int n);

void AjouterArete(graphe g , sommet s,sommet r);
void AjouterAreteAdj(graphe*g , sommet s , sommet r);
int * TabDegre(graphe g);
int degre(graphe g , sommet s);
int nbArete(graphe g);


#endif
