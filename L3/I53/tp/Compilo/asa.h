#ifndef ASA_H
#define ASA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ts.h"

typedef enum {
	typeCode,

	typeInstruction,
	typeEntree,
	typeTQ,
	typeSI,
	typeSIN,

	typeDeclaration,
	typeId,
	typeNb,

	typeAffectation,
	typeOp,
	typeUnop,

	typeAffichage,

	typeFin
} typeNoeud;

typedef struct {
	struct asa *entrees;
	struct asa *instructions;
} noeudCode;

typedef struct {
	struct asa *noeud;
	struct asa *inst_s;
} noeudInstruction;

typedef struct {
	struct asa *variable;
} noeudEntree;

typedef struct {
	char *nom;
} feuilleDeclaration;

typedef struct {
	char *nom;
} feuilleId;

typedef struct {
	int val;
} feuilleNb;

typedef struct {
	char* nom;
	struct asa *noeud;
} noeudAffectation;

typedef struct {
	char ope;
	struct asa *noeud[2];
} noeudOp;

typedef struct {
	struct asa *noeud[2];
} noeudTQ;

typedef struct {
	struct asa *noeud[3];
} noeudSIN;

typedef struct {
	char ope;
	struct asa *noeud;
} noeudUnop;
typedef struct {
	struct asa *noeud[2];
} noeudSI;

typedef struct {
	struct asa *noeud;
} noeudAffichage;

typedef struct {} feuilleFin;

typedef struct asa {
	typeNoeud type;
	int ninst;
	int nl; // numéro de ligne

	union {
		noeudCode code;
		noeudTQ TQ;
		noeudSI SI;
		noeudSIN SIN;
		noeudInstruction instruction;
		noeudEntree entree;
		feuilleDeclaration declaration;
		feuilleId id;
		feuilleNb nb;
		noeudAffectation affectation;
		noeudOp op;
		noeudUnop unop;
		noeudAffichage affichage;
		feuilleFin fin;
	};
} asa;

void fichier_sortie(char* nom);

// fonction d'erreur utilisée également par Bison
void yyerror(const char *s);

/*
  Les fonctions creer_<type> construise un noeud de l'arbre
  abstrait du type correspondant et renvoie un pointeur celui-ci
 */

asa *creer_noeudCode(asa *e, asa *i);
asa *creer_noeudInstruction(asa *pi, asa *p_s);
asa *creer_noeudEntree(asa *v);
asa *creer_feuilleDeclaration(char *nom);
asa *creer_feuilleId(char *nom);
asa *creer_feuilleNb(int value);
asa *creer_noeudAffectation(char* nom, asa *p0);
asa *creer_noeudOp(char ope, asa *p1, asa *p2);
asa *creer_noeudTQ(asa *p1, asa *p2);
asa *creer_noeudSI(asa *p1, asa *p2);
asa *creer_noeudSIN(asa *p1, asa *p2,asa *p3);
asa *creer_noeudUnop(char ope, asa *p1);
asa *creer_noeudAffichage(asa *p0);
asa *creer_feuilleFin();

void free_asa(asa *p);
void nettoyage(asa * p);

// produit du code pour la machine RAM à partir de l'arbre abstrait
// ET de la table de symbole
void codegen(asa *p);

extern ts *tsymb;

#endif
