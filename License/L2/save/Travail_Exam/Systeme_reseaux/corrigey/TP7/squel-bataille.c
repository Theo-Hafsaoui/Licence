#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

/* Une seul groupe de s�maphore dans ce programme */
/* Nous garderons l'ID en global */
key_t SEMID;


/* creation d'un ensemble de senNUm semaphores relie a cle */
/* Initialisation de SEMID */
void sem_create(key_t cle, int semNum) 
{
/* -- A compl�ter en vous inspirant de l'exercice  6 */
    if ((SEMID = semget(ftok("tmp_file", cle), semNum, 0777|IPC_CREAT)) < 0) {
        perror("Error creation of sem");
    }
    
}

/* Initialisation � la valeur initval du s�maphore SemNum du groupe de s�maphores SEMID */ 
void init_sem(int SemNum, int initval)
{
    /* -- A compl�ter en vous inspirant de l'exercice  6 */
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    }arg;
    arg.val = initval;
    if (semctl(SEMID, SemNum, SETVAL, arg) < 0) {
        perror("Error on semctl");
    }
}

/* Op�ration P pour le s�maphore sem du groupe de s�maphores SEMID */
void P(int sem)
{
    /* -- A compl�ter en vous inspirant de l'exercice  6 */
    struct sembuf sops;
    sops.sem_num = sem;
    sops.sem_op = -1;
    sops.sem_flg = 0;
    if (semop(SEMID, &sops, 1) < 0) 
        perror("Error on semop in P");
}

/* Op�ration P pour le s�maphore sem du groupe de s�maphores SEMID */
void V(int sem)
{
    /* -- A compl�ter en vous inspirant de l'exercice  6 */
    struct sembuf sops;
    sops.sem_num = sem;
    sops.sem_op = 1;
    sops.sem_flg = 0;
    if (semop(SEMID, &sops, 1) < 0)
        perror("Error on semop in V");
}


/* Destruction du groupe de s�maphores SEMID */
void sem_delete()
{
/* -- A compl�ter en vous inspirant de l'exercice  6 */
    if (semctl(SEMID, 0, IPC_RMID) < 0) 
        perror("semctl error in sem_delete");
}

/* Programme principal */
int main (int argc, char* argv[]){
typedef int booleen;	

/* D�finition de constantes */
#define faux 0
#define vrai 1 
#define S0   0 /* Le s�maphore S0 bloque le joueur 1 qd le joueur 2 joue */
#define S1   1 /* Le s�maphore S1 bloque le joueur 2 qd le joueur 1 joue */
#define S2   2 /* Le semaphore 2 du groupe, emp�che qu'il y est plus de deux joueurs*/
#define NBBAT 5 /* Nombre de bateaux */
#define RATE 1
#define COULE 2

#define CLE 123

  char *path="bataille.c";

  char Bat [NBBAT][NBBAT]; /* Mes bateaux */
  char BatA [NBBAT][NBBAT]; /* Les bateaux de l'adversaire */

  int i,j; /* Variables de parcours des tableaux de bateaux */
  int N; 
  int NumS; 
  int NumM /* Id du segment de m�moire partag�e */;
  
  /* Structure du segment de m�moire partag�e */
  typedef struct {
    int R; /* R�sultat du tir pr�c�dent */
    int X; /* X du Nouveau tir */
    int Y; /* Y du Nouveau tir */
  } Tir;

  Tir *pTir;
  int X, Y;
  int Fin = faux; /* Initialisation du test de fin de la boucle principale */
  int param = atoi(argv[1]); /* R�cup�ration du num�ro du joueur ayant lanc� le programme */

  int NBCAdv = 0; /* Nb de bateaux adverses coul�s */
  int NBC = 0; /* Nb de mes bateaux coul�s */
  
  printf("Bataille navale\n");
  
  
  /* Iniatilisation de chaque case des deux tableaux de bateaux avec le caract�re '.' */
  /*-- Ecrire le code d'initialisation */
  for (int i = 0; i < NBBAT; i++) {
      for (int j = 0; j < NBBAT; j++) {
          Bat[i][j] = '.';
          BatA[i][j] = '.';
      }
  }
   
    
  /* Initialisation du g�n�rateur al�atoire */  
  srand(getpid());
  N=NBBAT;
  
  /* Placement al�atoire de N bateaux dans ma grille */
  /*------- Ecrire le code de placement des bateaux */
  int x, y;

  for (int i = 0; i < N; i++) {
      do {
          x = rand() % NBBAT;
          y = rand() % NBBAT;
      } while (Bat[x][y] == '*'); 
      Bat[x][y] = '*';
  } 

  printf("Initialisation des bateaux OK\n");

  /* Cr�ation de la zone de m�moire partag�e par les deux joueurs */
         /*-- Ecrire le code de cr�ation du segment de m�moire partag�e */ 
  NumM = shmget(ftok("tmp_file", CLE), sizeof(Tir), IPC_CREAT | 0666);
  if (NumM < 0 )  
      perror("shm get failed");
  printf("NumM %d\n", NumM);
         /*-- Attacher le segment de m�moire partag�e (Structur�) */
  pTir = shmat(NumM, 0, 0);
  if (pTir == NULL) 
      perror("shmat failed");
  /* Cr�ation du groupe de 3 s�maphores */
  /*-- Utiliser semcreate pour cr�er le groupe */
  sem_create(CLE, 3);

  /* Le joueur 1 initialise les s�maphores aux valeurs */
  /* Les s�maphores S0 et S1 sont initialis� pour que le joueur 1 joue en premier */
  /* Le s�maphore S2 est initialis� au nombre de joueurs */   
  if (param == 1){
    printf("Joueur 1\n");
    pTir->R=0; /* Cette initialisation indique qu'il s'agit du premier coup */
  /*-- Ecrire le code d'initialisation */
    init_sem(0, S0);
    init_sem(1, S1);
    init_sem(2, S2);

  } else
    printf("Joueur 2\n");

  /* Blocage du processus si deux joueurs sont d�j� connect�s */
  P(S2); 
  while (semctl(SEMID, 2, GETVAL) > 0) {
          printf("Attente de 2 joueur\nsem2val%d\n",semctl(SEMID, 2, GETVAL)) ;
          sleep(1);
      }


  /* Boucle principale du programme se termine quand l'un des deux joueurs n'a plus de bateaux */
  while (!Fin) {
    printf("En attente de l'autorisation de tir....\n");
    
    /* Chaque joueur attend son tour pour : */
    /* V�rifier le r�sultat de son tir pr�c�dent */
    /* indiquer son nouveau tir */ 
    
    /*-- Ecrire le code d'attente de son tour */
    if (param == 1) {
        P(S0);
    } else {
        P(S1);
    }
    
    
    printf("A moi de jouer \n");

    /* R�sultat de mon tir pr�c�dent */
    switch (pTir->R) {
        case 0 :
          /* premier tir : pas de r�sultats */
          break;
        case RATE :
          if (BatA[X][Y] != 'C')
              BatA[X][Y] = 'R';
          printf("Mon tir rate en %d %d\n", X, Y);      
          break;
        case COULE :
          BatA[X][Y] = 'C';
          NBCAdv++;
          printf("Adversaire coule en %d %d, Nb de bateaux coules: %d\n",X, Y,NBCAdv);
          if (NBCAdv == NBBAT) {
              Fin = 1;
              printf("Tous les bateaux adverses sont coules\n");
          }
          break;
    }
    
    /* Si la partie n'est pas finie, on r�pond � l'adversaire */
    if (!Fin) {
      if (pTir->R == 0) {
        pTir->R = -1; /* si c'est le premier tour, pas de resultat pour l'adversaire */
      }
      else {
      	/* On v�rifie le tir de l'adversaire */
      	/* si il y a un bateau � cette place: */
      		/* on affiche touch� */
      		/* on inscrit COULE dans le segment de m�moire partag�e. */
      		/* on marque le bateau coule dans le tableau Bat */ 
      		/* on incr�mente le nombre de bateaux coul�s */
      		/* si tous les bateaux sont coul�s on met Fin � vrai */ 
      		
      /*-- Ecrire le code correspondant */
          x = pTir->X;
          y = pTir->Y;
          if (Bat[x][y] == '*') {
              printf("Touche'\n");
              pTir->R = COULE;
              Bat[x][y] = 'C';
              NBC++;
              if (NBC == NBBAT) 
                  Fin = vrai;
                  
          } else {
              printf("Rate'\n");
              pTir->R = RATE;
          }
      }
      
    
      /* si le tir est manqu�: */
      		/* on l'affiche et on marque le tir dans le tableau Bat avec un 'R'*/  
      		/* on �crit RATE dans le segment de m�moire partag�e */
      /*-- Ecrire le code correspondant */
    
  printf("\nMes bateaux           Adversaires\n\n");
  /*-- Afficher cote � cote les deux grilles Bat et BatA: */
  for (int i = 0; i < NBBAT; i++) {
      for (int j = 0; j < NBBAT; j++) {
          printf("%c ", Bat[i][j]);
      }
      printf("             ");
      for (int j = 0; j < NBBAT; j++) {
          printf("%c ", BatA[i][j]);
      }
      printf("\n");           
  }
  	
  printf("\nCoules : %d         Coules : %d\n",NBC, NBCAdv);

  /* Si la partie n'est pas finie on d�mande � l'utilisateur les coordonn�e de son */
  /* prochain tir, puis on les �crit dans le segment de m�moire partag�e. */ 
  if (!Fin) {
	/*-- Ecrire le code correspondant */
    printf("Prochain tir x = ");
    scanf("%d", &X);
    printf("Prochain tir y = ");
    scanf("%d", &Y);
    pTir->X = X;
    pTir->Y = Y;
  }
  
  /* Le joueur courant a fini son son tour, il autorise donc l'autre joueur � jouer */
  /*-- Ecrire le code correspondant */
  if (param == 1) {
      V(S1);
  } else if (param == 2) {
      V(S0);
  }
}
}

/*Quand la partie est finie, le joueur 1 d�truit le s�maphore et le segment de m�moire partag�e */
  /*-- Ecrire le code correspondant */
    if (param == 1) {
        semctl(SEMID, 0, IPC_RMID, 0);
        shmdt(&NumM);
        shmctl(NumM, IPC_RMID, 0);
    }

}
