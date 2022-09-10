TP8-compil-algo-ram
Lombardo Hafsaoui

Le but de ce tp et de realiser un compilateur d'un langage pseudo algorithmique vers un
pseudo langage machine,(http://zanotti.univ-tln.fr/ALGO/I31/MachineRAM.html)

Cahier des charges:
  -traduire des algo ecris en langage algorithmique en programme executable de la machine RAM(zf zanotti)
Le langage alogritmique:
  un algo est decrit comme suit:
    ALGO: nom de l'algo <-alpha numerique sans espace
    ENTREE: liest_des_entree <- identificateur (int)
    DEBUT
      |                  {declaration des variables avec "var" ex: var i(pas de declaration multiple)
      |                  |affectation avec <- ex: i<-2
      |                  |op arith +,-,(unair et binair),*,/,%
      |                  |op bool: OU,ET,NON
      |                  |comparaison:<,>,<=,>=,=,!=
      |                  |structure condionelle:
      |                  | [SI exp ALORS
      |                  | |  instruction
      |                  | |SINON
      |                  | |  instruction
      |                  | L FSI
      corps de l'algo<===|fin d'instruction par saut de ligne"\n"
      |                  |
      |                  | [SI exp ALORS
      |                  | |  instruction
      |                  | L FSI
      |                  |structure de boucle:
      |                  |
      |                  | [TQ exp FAIRE
      |                  | |  instruction
      |                  | L FTQ
      |                  |
      |                  |Commentaire:
      |                  |   -1 seule ligne separee masque par un croisillion
      |                  |
      |                  |Lexique:
      |                  |  KeyWord: ALGO,VAR,SI,SINON,TQ---> Reserver
      |                  |  ID=AlphaNumerique+_+ ne commence pas par un nombre
      |                  |  Nombre: Decimaux (Propre ne commence pas par zero sauf zero) avec l'interval[−256,255]. avec hex
      |                  |
      |                  {
    FIN

Structure du compilateur:
          |
lexer.lex analyse lexical<-------------------+
          |                                  |
          |flot de token                     |
          |                                  |
parser.y  (analyserur sytaxique)<---- table de symbole ts.h ts.c
          |                                  |
          |arbre abstrait                    |
          |                                  |
asa.c asa.c generateur de code<--------------+
          |
          code RAM

TEST
  
