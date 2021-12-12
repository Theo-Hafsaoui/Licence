#ifndef DISJOINT_H
#define DISJOINT_H
/*
typedef struct _disjoint_ {
	int num ;
	struct _disjoint_ *svt;
	struct _disjoint_ *rep;
	}enrdisjoint , *disjoint ;
	
disjoint singleton (int i);
void reunion (disjoint r , disjoint s);
disjoint representant(disjoint r);
#endif 
*/

typedef struct _ed_ 
{
  int num ;
  struct _ed_ * rep ;
}enrdisjoint,*disjoint ;

disjoint singleton (int v);
void reunion (disjoint r , disjoint s );
disjoint representant(disjoint s);
disjoint racoursi(disjoint s);

 #endif 
  
