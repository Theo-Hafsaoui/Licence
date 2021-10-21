#include "afn.h"


void afn_init(afn *A, uint nbetat, char * alphabet, ullong init, ullong finals)
{
  A->nbetat = nbetat;
  
  A->alphabet = malloc(strlen(alphabet)+1);
  strcpy(A->alphabet, alphabet);
  A->nbsymb = strlen(alphabet);
  
  A->init = init;
  A->finals = finals;

  int i;
  uchar symb;

  for (i=0; i<SYMB_NB_MAX; i++)
    A->tsymb[i] = SYMB_NONE;

  for (i=0; i<A->nbsymb; i++){
    if ( (alphabet[i] < SYMB_ASCII_DEB) ||
	 (alphabet[i] > SYMB_ASCII_FIN) ){
      fprintf(stderr,"[afd_init] caractere ascii numero %d invalide\n", alphabet[i]);
      exit(-1);
    }
    symb = (uchar) (alphabet[i] - SYMB_ASCII_DEB);
    if ( A->tsymb[symb] != SYMB_NONE ){
      fprintf(stderr,"[afd_init] caractere <%c> deja defini (ignorer)\n",alphabet[i]);
    }
    else {
      A->tsymb[symb] = i;
    }
  }
  A->delta = calloc(nbetat, sizeof(ullong *));
  for (i=0; i<nbetat; i++){
    A->delta[i] = calloc(A->nbsymb, sizeof(ullong));
  }
}

  /*
  Ajoute la relation (<q1>, <s>, <q2>) a l'AFN <A> 
*/
void afn_add_trans(afn *A, uint q1, uint s, uint q2)
{
  uchar symb = A->tsymb[s-SYMB_ASCII_DEB];
      
  if (symb == SYMB_NONE){
    fprintf(stderr, "[add_trans] %u -- %c --> %u symbole inconnu\n", q1,s,q2);
    exit(-1);
  }

  if ( (q1<0) || (q1>=A->nbetat) ){
   fprintf(stderr, "[add_trans] etat <%d> non reconnu\n", q1);
    exit(-1);
  }
  if ( (q2<0) || (q2>=A->nbetat) ){
   fprintf(stderr, "[add_trans] etat <%d> non reconnu\n", q2);
    exit(-1);
  }
  
  A->delta[q1][symb] |= INT_ETAT(q2);
}


/*
  Libere la memoire de l'AFN <A>
*/
void afn_free(afn *A)
{
  free(A->alphabet);

  int i;
  for (i=0; i < A->nbetat; i++)
    free(A->delta[i]);
  free(A->delta);  
}


/*
  Affiche l'AFN <A>
*/
void afn_print(afn A){
  uint q,q1,s;
  printf("init:");
  for (q=0; q<A.nbetat; q++)
    {
      if IN(q,A.init)
	     printf(" %d",q);
    }
  printf("\n");
  printf("finals:");
  for (q=0; q<A.nbetat; q++)
    {
      if IN(q,A.finals)
	     printf(" %d",q);
    }
  printf("\n");
  for (q=0; q<A.nbetat; q++){
    for (s=0; s<A.nbsymb; s++){
      if (A.delta[q][s]!=0){
	printf("%d -- %c --> {", q, A.alphabet[s]);
	for (q1=0; q1<A.nbetat; q1++)
	  {
	    if (IN(q1, A.delta[q][s]))
	      printf("%d,",q1);
	  }
	printf("\b}\n");
      }
    }
  }
}



/*
  Initialise l'AFN <A> a partir des donnees du fichier <nomfichier> au
  format:

  nb_etats nb_symboles
  etat_initial
  nb_etats_finals
  etat_final_1 etat_final_2 ... etat_final_n
  etat_i_11 symb_j_1 etat_i_12
  etat_i_21 symb_j_2 etat_i_22
  .
  .
  .
  etat_i_n1 symb_j_n etat_i_n2

*/
void afn_finit(char *nomfichier, afn *A);

/*
  Retourne l'epsilon fermeture de l'ensemble d'états <R> par
  l'automate <A>
*/
ullong afn_epsilon_fermeture(afn A, ullong R);

/*
  Calcule un automate deterministe equivalent à <A> et affecte le
  resultat a <D>. Les etats de l'afd sont renumerotés à partir de 1
*/
void afn_determinisation(afn A, afd *D);

/*
  Calcule l'automate qui reconnait le caractere <c> dans un alphabet a
  <nbsymb> symboles
*/  
void afn_char(afn *C, char c, uint nbsymb);

/*
  Calcule un automate qui reconnait l'union de <A> et <B>
*/
void afn_union(afn *C, afn A, afn B);

/*
  Calcule un automate qui reconnait la concatenation de <A> et <B>
*/
void afn_concat(afn *C, afn A, afn B);

/*
  Calcule un automate qui reconnait la fermeture de Kleene de <A>
*/
void afn_kleene(afn *C, afn A);
