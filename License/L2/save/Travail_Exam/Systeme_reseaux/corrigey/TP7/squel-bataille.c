#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

/* Une seul groupe de sémaphore dans ce programme */
/* Nous garderons l'ID en global */
key_t SEMID;


/* creation d'un ensemble de senNUm semaphores relie a cle */
/* Initialisation de SEMID */
void sem_create(key_t cle, int semNum) 
{
/* -- A compléter en vous inspirant de l'exercice  6 */
    if ((SEMID = semget(ftok("tmp_file", cle), semNum, 0777|IPC_CREAT)) < 0) {
        perror("Error creation of sem");
    }
    
}

/* Initialisation à la valeur initval du sémaphore SemNum du groupe de sémaphores SEMID */ 
void init_sem(int SemNum, int initval)
{
    /* -- A compléter en vous inspirant de l'exercice  6 */
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

/* Opération P pour le sémaphore sem du groupe de sémaphores SEMID */
void P(int sem)
{
    /* -- A compléter en vous inspirant de l'exercice  6 */
    struct sembuf sops;
    sops.sem_num = sem;
    sops.sem_op = -1;
    sops.sem_flg = 0;
    if (semop(SEMID, &sops, 1) < 0) 
        perror("Error on semop in P");
}

/* Opération P pour le sémaphore sem du groupe de sémaphores SEMID */
void V(int sem)
{
    /* -- A compléter en vous inspirant de l'exercice  6 */
    struct sembuf sops;
    sops.sem_num = sem;
    sops.sem_op = 1;
    sops.sem_flg = 0;
    if (semop(SEMID, &sops, 1) < 0)
        perror("Error on semop in V");
}


/* Destruction du groupe de sémaphores SEMID */
void sem_delete()
{
/* -- A compléter en vous inspirant de l'exercice  6 */
    if (semctl(SEMID, 0, IPC_RMID) < 0) 
        perror("semctl error in sem_delete");
}

/* Programme principal */
int main (int argc, char* argv[]){
typedef int booleen;	

/* Définition de constantes */
#define faux 0
#define vrai 1 
#define S0   0 /* Le sémaphore S0 bloque le joueur 1 qd le joueur 2 joue */
#define S1   1 /* Le sémaphore S1 bloque le joueur 2 qd le joueur 1 joue */
#define S2   2 /* Le semaphore 2 du groupe, empêche qu'il y est plus de deux joueurs*/
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
  int NumM /* Id du segment de mémoire partagée */;
  
  /* Structure du segment de mémoire partagée */
  typedef struct {
    int R; /* Résultat du tir précédent */
    int X; /* X du Nouveau tir */
    int Y; /* Y du Nouveau tir */
  } Tir;

  Tir *pTir;
  int X, Y;
  int Fin = faux; /* Initialisation du test de fin de la boucle principale */
  int param = atoi(argv[1]); /* Récupération du numéro du joueur ayant lancé le programme */

  int NBCAdv = 0; /* Nb de bateaux adverses coulés */
  int NBC = 0; /* Nb de mes bateaux coulés */
  
  printf("Bataille navale\n");
  
  
  /* Iniatilisation de chaque case des deux tableaux de bateaux avec le caractère '.' */
  /*-- Ecrire le code d'initialisation */
  for (int i = 0; i < NBBAT; i++) {
      for (int j = 0; j < NBBAT; j++) {
          Bat[i][j] = '.';
          BatA[i][j] = '.';
      }
  }
   
    
  /* Initialisation du générateur aléatoire */  
  srand(getpid());
  N=NBBAT;
  
  /* Placement aléatoire de N bateaux dans ma grille */
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

  /* Création de la zone de mémoire partagée par les deux joueurs */
         /*-- Ecrire le code de création du segment de mémoire partagée */ 
  NumM = shmget(ftok("tmp_file", CLE), sizeof(Tir), IPC_CREAT | 0666);
  if (NumM < 0 )  
      perror("shm get failed");
  printf("NumM %d\n", NumM);
         /*-- Attacher le segment de mémoire partagée (Structuré) */
  pTir = shmat(NumM, 0, 0);
  if (pTir == NULL) 
      perror("shmat failed");
  /* Création du groupe de 3 sémaphores */
  /*-- Utiliser semcreate pour créer le groupe */
  sem_create(CLE, 3);

  /* Le joueur 1 initialise les sémaphores aux valeurs */
  /* Les sémaphores S0 et S1 sont initialisé pour que le joueur 1 joue en premier */
  /* Le sémaphore S2 est initialisé au nombre de joueurs */   
  if (param == 1){
    printf("Joueur 1\n");
    pTir->R=0; /* Cette initialisation indique qu'il s'agit du premier coup */
  /*-- Ecrire le code d'initialisation */
    init_sem(0, S0);
    init_sem(1, S1);
    init_sem(2, S2);

  } else
    printf("Joueur 2\n");

  /* Blocage du processus si deux joueurs sont déjà connectés */
  P(S2); 
  while (semctl(SEMID, 2, GETVAL) > 0) {
          printf("Attente de 2 joueur\nsem2val%d\n",semctl(SEMID, 2, GETVAL)) ;
          sleep(1);
      }


  /* Boucle principale du programme se termine quand l'un des deux joueurs n'a plus de bateaux */
  while (!Fin) {
    printf("En attente de l'autorisation de tir....\n");
    
    /* Chaque joueur attend son tour pour : */
    /* Vérifier le résultat de son tir précédent */
    /* indiquer son nouveau tir */ 
    
    /*-- Ecrire le code d'attente de son tour */
    if (param == 1) {
        P(S0);
    } else {
        P(S1);
    }
    
    
    printf("A moi de jouer \n");

    /* Résultat de mon tir précédent */
    switch (pTir->R) {
        case 0 :
          /* premier tir : pas de résultats */
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
    
    /* Si la partie n'est pas finie, on répond à l'adversaire */
    if (!Fin) {
      if (pTir->R == 0) {
        pTir->R = -1; /* si c'est le premier tour, pas de resultat pour l'adversaire */
      }
      else {
      	/* On vérifie le tir de l'adversaire */
      	/* si il y a un bateau à cette place: */
      		/* on affiche touché */
      		/* on inscrit COULE dans le segment de mémoire partagée. */
      		/* on marque le bateau coule dans le tableau Bat */ 
      		/* on incrémente le nombre de bateaux coulés */
      		/* si tous les bateaux sont coulés on met Fin à vrai */ 
      		
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
      
    
      /* si le tir est manqué: */
      		/* on l'affiche et on marque le tir dans le tableau Bat avec un 'R'*/  
      		/* on écrit RATE dans le segment de mémoire partagée */
      /*-- Ecrire le code correspondant */
    
  printf("\nMes bateaux           Adversaires\n\n");
  /*-- Afficher cote à cote les deux grilles Bat et BatA: */
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

  /* Si la partie n'est pas finie on démande à l'utilisateur les coordonnée de son */
  /* prochain tir, puis on les écrit dans le segment de mémoire partagée. */ 
  if (!Fin) {
	/*-- Ecrire le code correspondant */
    printf("Prochain tir x = ");
    scanf("%d", &X);
    printf("Prochain tir y = ");
    scanf("%d", &Y);
    pTir->X = X;
    pTir->Y = Y;
  }
  
  /* Le joueur courant a fini son son tour, il autorise donc l'autre joueur à jouer */
  /*-- Ecrire le code correspondant */
  if (param == 1) {
      V(S1);
  } else if (param == 2) {
      V(S0);
  }
}
}

/*Quand la partie est finie, le joueur 1 détruit le sémaphore et le segment de mémoire partagée */
  /*-- Ecrire le code correspondant */
    if (param == 1) {
        semctl(SEMID, 0, IPC_RMID, 0);
        shmdt(&NumM);
        shmctl(NumM, IPC_RMID, 0);
    }

}
