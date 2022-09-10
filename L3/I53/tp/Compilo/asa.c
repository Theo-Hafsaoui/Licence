#include "asa.h"
#include "ts.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
/* Génération du code machine
 *  ⣴⣶⣤⡤⠦⣤⣀⣤⠆     ⣈⣭⣭⣿⣶⣿⣦⣼⣆         
 *   ⠉⠻⢿⣿⠿⣿⣿⣶⣦⠤⠄⡠⢾⣿⣿⡿⠋⠉⠉⠻⣿⣿⡛⣦       
 *         ⠈⢿⣿⣟⠦ ⣾⣿⣿⣷⠄⠄⠄⠄⠻⠿⢿⣿⣧⣄     
 *          ⣸⣿⣿⢧ ⢻⠻⣿⣿⣷⣄⣀⠄⠢⣀⡀⠈⠙⠿⠄    
 *         ⢠⣿⣿⣿⠈  ⠡⠌⣻⣿⣿⣿⣿⣿⣿⣿⣛⣳⣤⣀⣀   
 *  ⢠⣧⣶⣥⡤⢄ ⣸⣿⣿⠘⠄ ⢀⣴⣿⣿⡿⠛⣿⣿⣧⠈⢿⠿⠟⠛⠻⠿⠄  
 * ⣰⣿⣿⠛⠻⣿⣿⡦⢹⣿⣷   ⢊⣿⣿⡏  ⢸⣿⣿⡇ ⢀⣠⣄⣾⠄   
 *⣠⣿⠿⠛⠄⢀⣿⣿⣷⠘⢿⣿⣦⡀ ⢸⢿⣿⣿⣄ ⣸⣿⣿⡇⣪⣿⡿⠿⣿⣷⡄  
 *⠙⠃   ⣼⣿⡟  ⠈⠻⣿⣿⣦⣌⡇⠻⣿⣿⣷⣿⣿⣿ ⣿⣿⡇⠄⠛⠻⢷⣄ 
 *     ⢻⣿⣿⣄   ⠈⠻⣿⣿⣿⣷⣿⣿⣿⣿⣿⡟ ⠫⢿⣿⡆     
 *      ⠻⣿⣿⣿⣿⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⡟⢀⣀⣤⣾⡿⠃     
 */

static int segment_pile = 65; // segment machin commence à 65
static int numero_ligne = 0;

static FILE* executable;

/* Ouverture du fichier de la forme
 * NOM.ram
 */
void fichier_sortie(char *nom)
{
	char nom_programme[256];
	sprintf(nom_programme, "%s.ram", nom);
	executable = fopen(nom_programme, "w");
}

// Libère la table des symboles
void nettoyage(asa *p)
{
	ts_free_table();
	free_asa(p);
	fclose(executable);
}

/* Imprime une instruction dans l'exécutable, en
 * prenant soin d'incrémenter le numéro de ligne
 */
void iprintf(const char *inst, ...)
{
	va_list args;
	va_start(args, inst);
	vfprintf(executable, inst, args);
	fprintf(executable, "\n");
	numero_ligne++;
	va_end(args);
}

//##############################################
//CRÉATION DES NOEUDS ET FEUILLES DE L'ARBRE
//##############################################

asa *creer_noeudCode(asa *e, asa *i)
{
	asa * p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeCode;
	p->code.entrees = e;
	p->code.instructions = i;
	p->ninst = e->ninst + i->ninst;
	p->nl = 0;
	return p;
}

asa *creer_noeudInstruction(asa *pi, asa *p_s)
{
	asa * p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeInstruction;
	p->instruction.noeud = pi;
	p->instruction.inst_s = p_s;
	p->ninst = pi->ninst + p_s->ninst;
	return p;
}


asa *creer_noeudEntree(asa *v)
{
	asa * p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeEntree;
	p->entree.variable = v;
	p->ninst = v->ninst + 2;
	return p;
}

asa *creer_feuilleDeclaration(char *nom)
{
	asa *p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeDeclaration;
	p->declaration.nom = malloc(sizeof(nom)+1);
	strcpy(p->declaration.nom, nom);
	ts_ajouter_id(nom, 1);
	p->ninst= 0;
	return p;
}

asa *creer_feuilleId(char *nom)
{
	asa *p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeId;
	p->id.nom = malloc(sizeof(nom)+1);
	strcpy(p->id.nom, nom);
	p->ninst = 1;
	return p;
}

asa * creer_feuilleNb(int val)
{
	asa *p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeNb;
	p->nb.val = val;
	p->ninst = 1;
	return p;
}

asa *creer_noeudAffectation(char *nom, asa *p0)
{
	asa * p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeAffectation;
	p->affectation.nom = malloc(sizeof(nom)+1);
	strcpy(p->affectation.nom, nom);
	p->affectation.noeud = p0;
	p->ninst = p0->ninst+1;
	return p;
}

asa * creer_noeudOp( char ope, asa * p1, asa * p2)
{
	asa * p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeOp;
	p->op.ope = ope;
	p->op.noeud[0]=p1;
	p->op.noeud[1]=p2;
	p->ninst = p1->ninst+p2->ninst+1;
	switch(ope) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		p->ninst += 1;
		break;
	case '=':
	case '>':
	case '<':
	case 'I':
	case 'S':
	case 'N':
		p->ninst += 5;
		break;
	case '|':
		p->ninst += 7;
		break;
	case '&':
		p->ninst += 6;
		break;
	default:
		break;
	}

	return p;
}

asa * creer_noeudTQ( asa * p1, asa * p2)
{
	asa * p;
	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");
	p->type = typeTQ;
	p->TQ.noeud[0]=p1;
	p->TQ.noeud[1]=p2;
	p->ninst = p1->ninst+p2->ninst+2;
	return p;
}

asa * creer_noeudSI( asa * p1, asa * p2)
{
	asa * p;
	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");
	p->type = typeSI;
	p->SI.noeud[0]=p1;
	p->SI.noeud[1]=p2;
	p->ninst = p1->ninst+p2->ninst+1;
	return p;
}

asa * creer_noeudSIN( asa * p1, asa * p2,asa *p3)
{
	asa * p;
	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");
	p->type = typeSIN;
	p->SIN.noeud[0]=p1;
	p->SIN.noeud[1]=p2;
	p->SIN.noeud[2]=p3;
	p->ninst = p1->ninst+p2->ninst+1+p3->ninst+1;
	return p;
}

asa *creer_noeudUnop(char ope, asa *p1)
{
	asa * p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeUnop;
	p->unop.ope = ope;
	p->unop.noeud=p1;
	p->ninst = p1->ninst;

	switch(p->unop.ope){
	case '!':
		p->ninst += 4;
		break;
	default:
		break;
	}

	return p;
}

asa * creer_noeudAffichage(asa * p0)
{
	asa* p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeAffichage;
	p->affichage.noeud = p0;
	p->ninst = p0->ninst+1;

	return p;
}

asa *creer_feuilleFin()
{
	asa *p;

	if ((p = malloc(sizeof(asa))) == NULL)
		yyerror("echec allocation mémoire");

	p->type = typeFin;
	p->ninst = 1;

	return p;
}

void free_asa(asa *p)
{
	if (!p) return;
	switch (p->type) {
	case typeInstruction:
		free_asa(p->instruction.noeud);
		free_asa(p->instruction.inst_s);
		break;
	case typeDeclaration:
		free(p->declaration.nom);
		break;
	case typeId:
		free(p->id.nom);
		break;
	case typeAffectation:
		free(p->affectation.nom);
		free_asa(p->affectation.noeud);
		break;
	case typeOp:
		free_asa(p->op.noeud[0]);
		free_asa(p->op.noeud[1]);
		break;
	case typeAffichage:
		free_asa(p->affichage.noeud);
		break;
	default:
		break;
	}
	free(p);
}


/* Génération du code à partir
 * de l'arbre asa
 */
void codegen(asa *p)
{
	int d_iter;
	if (!p)
		return;
	switch (p->type) {
		case typeCode:
			if (p->code.entrees != NULL)
				codegen(p->code.entrees);
			codegen(p->code.instructions);
			iprintf("STOP");
			break;
		case typeEntree:
			codegen(p->entree.variable);
			iprintf("READ");
			iprintf("STORE %d",
			        ts_retrouver_id(p->entree.variable->declaration.nom)->adr);
			break;
		case typeInstruction:
			codegen(p->instruction.noeud);
			codegen(p->instruction.inst_s);
			break;
		case typeDeclaration:
			break;
		case typeId:
			if (ts_retrouver_id(p->id.nom) == NULL) {
				fprintf(stderr, "variable inexistante: %s\n", p->id.nom);
				exit(-1);
			}
			iprintf("LOAD %d", ts_retrouver_id(p->id.nom)->adr);
			break;
		case typeNb:
			iprintf("LOAD #%d", p->nb.val);
			break;
		case typeAffectation:
			codegen(p->affectation.noeud);
			iprintf("STORE %d", ts_retrouver_id(p->affectation.nom)->adr);
			break;
		case typeOp:
			codegen(p->op.noeud[0]);
			iprintf("STORE %d", segment_pile);
			segment_pile++;
			codegen(p->op.noeud[1]);
			segment_pile--;
			switch (p->op.ope) {
				case '+':
					iprintf("ADD %d", segment_pile);
					break;
				case '-':
					iprintf("SUB %d", segment_pile);
					break;
				case '*':
					iprintf("MUL %d", segment_pile);
					break;
				case '/':
					iprintf("DIV %d", segment_pile);
					break;
				case '%':
					iprintf("MOD %d", segment_pile);
					break;
				case '=':                             // A == B
					iprintf("SUB %d", segment_pile);  // ACC = A - B
					iprintf("JUMZ %d", numero_ligne + 3);   // ACC > 0 => A > B
					iprintf("LOAD #0");                     // Condition fausse
					iprintf("JUMP %d", numero_ligne + 2);   // Passer au-dessus de la condition juste
					iprintf("LOAD #1");  // Condition juste
					break;
				case '~':  // marche aussi
					iprintf("SUB %d", segment_pile);
					break;
				case '<':
					iprintf("SUB %d", segment_pile);
					iprintf("JUML %d", numero_ligne + 2);
					iprintf("LOAD #0");
					break;
				case '>':
					iprintf("SUB %d", segment_pile);
					iprintf("JUMG %d", numero_ligne + 2);
					iprintf("LOAD #0");
					break;
				case '{':
					iprintf("SUB %d", segment_pile);
					iprintf("JUMG %d", numero_ligne + 3);
					iprintf("LOAD #1");
					iprintf("JUMP %d", numero_ligne + 2);
					iprintf("LOAD #0");
					break;
				case '}':
					iprintf("SUB %d", segment_pile);
					iprintf("JUML %d", numero_ligne + 3);
					iprintf("LOAD #1");
					iprintf("JUMP %d", numero_ligne + 2);
					iprintf("LOAD #0");
					break;
				case '|':
					iprintf("JUMZ %d", numero_ligne + 2);
					iprintf("JUMP %d", numero_ligne + 2);
					iprintf("LOAD %d", segment_pile);
					break;
				case '&':
					iprintf("JUMZ %d", numero_ligne + 2);
					iprintf("LOAD %d", segment_pile);
					break;
				default:
					break;
			}
			break;
		case typeTQ:
			d_iter=numero_ligne;
			codegen(p->TQ.noeud[0]);
			iprintf("JUMZ %d", numero_ligne+p->TQ.noeud[1]->ninst+2);
			codegen(p->TQ.noeud[1]);
			fprintf(executable, "JUMP %d\n", d_iter);
			break;
		case typeSI:
			codegen(p->SI.noeud[0]);
			iprintf("JUMZ %d", numero_ligne+p->SI.noeud[1]->ninst+1);
			codegen(p->TQ.noeud[1]);
			break;
		case typeSIN:
			codegen(p->SIN.noeud[0]);
			iprintf("JUMZ %d", numero_ligne+p->SIN.noeud[1]->ninst+2);
			codegen(p->SIN.noeud[1]);
			iprintf("JUMP %d", numero_ligne+p->SIN.noeud[2]->ninst+1);
			codegen(p->SIN.noeud[2]);
			break;
		case typeUnop:
			codegen(p->unop.noeud);
			switch (p->unop.ope) {
				case '!':
					iprintf("JUMZ %d", numero_ligne + 3);
					iprintf("LOAD #0");
					iprintf("JUMP %d", numero_ligne + 2);
					iprintf("LOAD #1");
					break;
				default:
					break;
			}
			break;
		case typeAffichage:
			codegen(p->affichage.noeud);
			iprintf("WRITE");
			break;
		default:
			break;
	}
}

void yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  exit(0);
}
