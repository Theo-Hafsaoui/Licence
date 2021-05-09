#
# Fichier à compléter: deplacement.py
#
# Chaque fonction doit renvoyer la liste des indices (col,lig) des
# cases sur lesquelles la pièce en question peut aller.
#

def cases_fou(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un fou positionné sur la case (col, lig)

    Ex: fou en (2,3)
    - - - - - - - - - -
    |           x     |
    | x       x       |
    |   x   x         |
    |     F           |
    |   x   x         |
    | x       x       |
    |           x     |
    |             x   |
    - - - - - - - - - -

    """
    
    mv=[(1,1),(-1,-1),(-1,1),(1,-1)]
    L=[]
    for a,b in mv:
        n=8
        Icol=col
        Ilig=lig
        for i in range(n):
            Icol+=a
            Ilig+=b
            if Icol in (0,1,2,3,4,5,6,7) and Ilig in (0,1,2,3,4,5,6,7):
                L+=[(Icol,Ilig)]      
    return(L)


def cases_tour(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer une tour positionnée sur la case (col, lig)

    Ex: tour en (5,3)
    - - - - - - - - - -
    |           x     |
    |           x     |
    |           x     |
    | x x x x x T x x |
    |           x     |
    |           x     |
    |           x     |
    |           x     |
    - - - - - - - - - -
        l=[]
        for i in range(0,8):
            l.append([col,i])
            l.append([i,lig])
        print([col,lig])
        print(l)
        l.remove([col,lig])
        print(l.remove([col,lig]))
    """
    l=[]
    for i in range(0,8):
        if i!=lig:
            l.append([col,i])
        if i!=col:
            l.append([i,lig])
    return l
def cases_reine(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un fou positionnée sur la case (col, lig)

    Ex: dame en (6,1)
    - - - - - - - - - -
    |           x x x |
    | x x x x x x D x |
    |           x x x |
    |         x   x   |
    |       x     x   |
    |     x       x   |
    |   x         x   |
    | x           x   |
    - - - - - - - - - -

    """
def cases_reine(col,lig):
    Limit=[(1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,-1),(-1,1),(1,-1)]
    L=[]
    for j,j2 in Limit:
        cpt1=col
        cpt2=lig
        i=0
        while i<8:
            cpt1+=j
            cpt2+=j2
            if cpt1 in (0,1,2,3,4,5,6,7) and cpt2 in (0,1,2,3,4,5,6,7):
                L+=[(cpt1,cpt2)]    
            i+=1  
    return(L)



def cases_roi(col,lig):
   """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un roi positionné sur la case (col, lig)

    Ex: Roi en (4,5)
    - - - - - - - - - -
    |                 |
    |                 |
    |                 |
    |                 |
    |      x x x      |
    |      x R x      |
    |      x x x      |
    |                 |
    - - - - - - - - - -

   """
   print((col,lig))
   val=[[0,1],[0,-1],[1,0],[-1,0],[1,1],[1,-1],[-1,-1],[1,-1]]
   l=[]
   for i in val:
       if (col+i[0]>-1) and (col+i[0]<8) and (lig+i[1]<8) and (lig+i[1]>-1):
           print(i)
           l+=[(col+i[0],lig+i[1])]
   print(l)
   return l

def cases_cavalier(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un fou positionné sur la case (col, lig)

    Ex: cavalier en (3,3)
    - - - - - - - - - -
    |                 |
    |     x   x       |
    |   x       x     |
    |       C         |
    |   x       x     |
    |     x   x       |
    |                 |
    |                 |
    - - - - - - - - - -

    """
    val=[[2,1],[2,-1],[1,-2],[-1,-2],[1,2],[-1,2],[-2,-1],[-2,1]]
    l=[]
    for i in val:
        if (col+i[0]>-1) and (col+i[0]<8) and (lig+i[1]<8) and (lig+i[1]>-1):
            l+=[(col+i[0],lig+i[1])]
    return l
    return []

def cases_pion(col,lig):
    """Retourne la liste des indices (col,lig) des cases où peut se
    déplacer un fou positionné sur la case (col, lig)

    Ex: pions en (1,6) et (5,3)
    - - - - - - - - - -
    |                 |
    |                 |
    |           x     |
    |           P     |
    |   x             |
    |   x             |
    |   P             |
    |                 |
    - - - - - - - - - -

    """
    print(col,lig)
    l=[]
    if lig == 6 :
        l=[(col,lig-1),(col,lig-2)]
    elif (lig-1)>-1:
        l=[(col,lig-1),]
    return l
