#include <stdio.h>
#define PRINT(int) printf("%d\n, int")
int main()
{
    int x,y,z;
    x=2;y=1;z=0;
    2
    
    printf("c vraiment null",*a);
}


void Createtudiant(n,p,d,s,n,no){

      Etudiant = {n;p;d;s;n;no}
}

#include <stdio.h>
#include <stdlib.h>

enum niveau_t {L1=0, L2, L3, M1, M2} ;
enum sexe_t {F=0, M=1} ;
typedef struct Etudiant {
char nom[20] ;
char prenom[20] ;
int date_naissance ;// # de la forme DDMMYEAR
enum sexe_t sexe ;
enum niveau_t niveau ;
float notes[4] ;
} Etudiant ;
typedef struct ElementEtudiant{
Etudiant *etud ;
Etudiant *etud_suiv ;
Etudiant *etud_prec ;
} ElementEtudiant ;
typedef struct ListeEtudiant{
ElementEtudiant *premier_etud ;
ElementEtudiant *dernier_etud ;
int nb_etud ;
} ListeEtudiant ;
#define ERR -1

Etudiant* createEtudiant()
{
  char *nom =(char*)malloc(sizeof(char)*20);
  char *prenom = (char*)malloc(sizeof(char)*10);
  int date_naissance;
  enum sexe_t sexe;
  enum niveau_t niveau;
  float *notes = (float*)malloc(sizeof(float)*4);

  Etudiant *etudiant = (Etudiant *)malloc(sizeof(Etudiant ));

  printf("Entrez un nom : ");
  scanf(" %s", etudiant->nom );
  printf("Entrez un prenom : ");
  scanf(" %s", etudiant->prenom );
  printf("Entrez une date_naissance : ");
  scanf(" %d", &date_naissance );
  printf("Entrez le sexe: ");
  scanf(" %d", &sexe );
  printf("Entrez le niveau d'etudes: ");
  scanf(" %d", &niveau );
  printf("Entrez 4 notes : ");
  for(int i=0; i<4; i++)
    scanf("%f",&(etudiant->notes[i]));

  //etudiant->nom = nom;
  //etudiant->prenom =prenom;
  etudiant->date_naissance = date_naissance;
  etudiant->sexe = sexe;
  etudiant->niveau = niveau;
 // etudiant->notes = notes;
return etudiant;
};

int main()
{
    Etudiant *Billy=createEtudiant();
    printf("%c",Billy->sexe);
}

/*
char * nom = (char*)malloc(sizeof(char)*20);
    char * prenom = (char*)malloc(sizeof(char)*20);
    float moy[4]={1,2,3,4,5};
    //prenom="Billy";
    //nom="Roger";
    Etudiant Billy;//={nom,prenom,101199,M,L2,moy};
    printf("%s",Billy.nom);
    Billy->nom="Roger";
    Billy->prenom="Billy";
    Billy->date_naissance=01011999;
    Billy->sexe=M;
    Billy->niveau=L2;
    */