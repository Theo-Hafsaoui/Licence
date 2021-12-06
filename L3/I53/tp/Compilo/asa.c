#include "asa.h"

asa * creer_feuilleNb(int val)
{
  asa *p;

  if ((p = malloc(sizeof(asa))) == NULL)
    yyerror("echec allocation mémoire");

  p->type = typeNb;
  p->nb.val = val;
  return p;
}

asa * creer_noeudOp( int ope, asa * p1, asa * p2)
{
  asa * p;

  if ((p = malloc(sizeof(asa))) == NULL)
    yyerror("echec allocation mémoire");

  p->type = typeOp;
  p->op.ope = ope;
  p->op.noeud[0]=p1;
  p->op.noeud[1]=p2;
  p->ninst = p1->ninst+p2->ninst+2;
  
  return p;
}


void free_asa(asa *p)
{
 
  if (!p) return;
  switch (p->type) {
  case typeOp:
    free_asa(p->op.noeud[0]);
    free_asa(p->op.noeud[1]);
    break;
  default: break;
  }
  free(p);
}


void codegen(asa *p)
{
  if (!p) return;
  switch(p->type) {
  case typeNb:
    break;
  case typeOp:
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
