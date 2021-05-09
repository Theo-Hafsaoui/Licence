#############################################
# Jeu du Puissance 4                        #
# Cours d'algorithmique                     #
# Licence Informatique - 1ere année         #
# Université de Toulon                      #
#                                           #
# Version du 01/03/2019                     #
#############################################


def init_jeu():
    """Renvoie une grille de jeu 6x7 sous forme d'une
    liste de listes remplie de 0"""


def dessine_grille(grille):
    """Retourne sous forme de chaine de caracteres l'état de la grille de jeu 
    ainsi que le numéro des colonnes:
       -O pour le joueur 1
       -X pour le joueur 2
       
    """
    ligne=""
    G=""
    for el in grille[::-1]:
        for el2 in el:
            if el2 == 2:
                ligne+='X'
            elif el2 == 1:
                ligne+='O'
            else:
                ligne+=' '
        G+='|'+ligne+'|'+'\n'
        ligne=''
    G+='---------'+'\n'
    G+=' 0123456 '
    return(G)
def coups_legaux(grille):
    """Renvoie la liste des colonnes dans lesquelles il est possible de
    jouer un jeton

    """
    l=[]
    for i in range(len(grille[-1])):
        if grille[-1][i]==0:
            l+=[i]
    return(l)
    return

def jouer_coup(joueur, coup, grille):
    """Ajoute un jeton pour le joueur <joueur> dans la colonne <coup> dans
    la grille et renvoie la ligne où celui-ci a été joué

    """
    return
    

def gagnant_colonne(lig, col, grille):
    """Renvoie True si le coup joué (lig,col) forme une colonne de 4 jetons
    False sinon
    """
    i2=0
    for i in range(6):
        if grille[i][col]==1:
            i2+=1
        if i2==4 and grille[lig][col]==1:
            return True
    return False

def gagnant_ligne(lig, col, grille):
    """Renvoie True si le coup joué (lig,col) forme une ligne de 4 jetons
    False sinon
    """
    i2=0
    i1=0
    for i in range(6):
        if grille[lig][i]==1:
            i1+=1
        if grille[lig][i]==2:
            i2+=1
        if i2==4 or i1==4 and grille[lig][col]==1:
            return True
    return False
def gagnant_diagonale(lig,col,grille):
    mv=[()]
print(gagnant_diagonale(3,2,[[1,1,2,2,2,1,2],
                           [2,1,2,1,1,2,1],
                           [1,1,1,2,1,1,2],
                           [1,2,1,1,0,2,1],
                           [0,2,2,0,0,2,2],
                           [0,1,0,0,0,0,1]]))
def gagnant_antidiagonale(lig, col, grille):
    """Renvoie True si le coup joué (lig,col) forme une antidiagonale de 4 jetons
    False sinon
    """
    return

def gagner(lig, col, grille):
    """Renvoie True si le coup joué est un coup gagnant
    False sinon
    """
    return

def main():
    """Programme principal:
    A chaque itération de la boucle de jeu il faut:
      - afficher l'état du jeu
      - calculer les coups légaux
      - stopper la partie si la liste est vide
      - demander un coup legal au joueur actif
      - ajouter son jeton dans la grille
      - arreter la partie si le coup est gagnant
      - changer le joueur actif et recommencer

    """
    pass
    
if __name__=='__main__':
    main()
def cases_reine(col,lig):
    L=[]
    Li=[(1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,-1),(-1,1),(1,-1)]
    for i,i2 in Li:
        Icol=col
        Ilig=lig
        for i in range(8):
            Icol+=i
            Ilig+=i2
            if Icol in (0,1,2,3,4,5,6,7) and Ilig in (0,1,2,3,4,5,6,7):
                Ldep+=[(Icol,Ilig)]      
    return(Ldep)

