#
# FIchier à compléter: parcours.py
#
# Chaque fonction retourne la liste des paires d'indices correspondant
# au parcours nommé.
#

def parcours_ligne(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours tableau de taille n x n en ligne.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,2,3,4,5,6,7,8,9 et la
    fonction retournera la liste d'indices [(0,0),(1,0),(2,0),(0,1) ...]

    """
    l=[]
    i=0
    while i < n:
        i2=0
        while i2 < n:
            l+=[(i2,i)]
            i2+=1
        i+=1
    print(i < n)
    print(l)
    return l

def parcours_colonne(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours de tableau de taille n x n en colonne.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,4,7,2,5,8,3,6,9 et la
    fonction retournera la liste d'indices [(0,0),(0,1),(0,2),(1,0) ...]

    """
    l=[]
    i=0
    while i < n:
        i2=0
        while i2 < n:
            l+=[(i,i2)]
            i2+=1
        i+=1
    print(i < n)
    print(l)
    return l

def parcours_diagonal(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours de tableau de taille n x n en diagonale.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 3,2,6,1,5,9,4,8,7 et la
    fonction retournera la liste d'indices [(2,0),(1,0),(2,1),(0,0) ...]

    """
    l=[(n-1,0)]
    i=n
    while i >0:
        i2=0
        temp=i
        while temp<n:
            l+=[(temp,i2)]
            temp+=1
            i2+=1
        i-=1
    i=0
    a=n
    while i <n:
        for j in range(a):
            l+=[(j,j+i)]
        i+=1
        a-=1
    return l

def parcours_antidiagonal(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours de tableau de taille n x n en anti-diagonale.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 9,6,8,3,5,7,2,4,1 et la
    fonction retournera la liste d'indices [(2,2),(2,1),(1,2),(2,0) ...]

    """
    l=[(0,n-1)]
    i=n
    while i >0:
        i2=0
        temp=i
        while temp<n:
            l+=[(i2,temp)]
            temp+=1
            i2+=1
        i-=1
    i=0
    a=n
    while i <n:
        for j in range(a):
            l+=[(j+i,j)]
        i+=1
        a-=1
    return l

def parcours_serpentin(n):
    """Retourne la liste des indices (colonne,ligne) (!!attention ici
    ligne et colonne sont inversées!!)  des cases correspondant à un
    parcours de tableau de taille n x n en serpentin.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,2,3,6,9,8,7,4,5 et la
    fonction retournera la liste d'indices [(0,0),(1,0),(2,0),(2,1) ...]

    """
    a=-1
    i2=-1
    l=[]
    i=0
    while i < n:
        if i%2==0:
            i2=n
        else:
            i2=0
        while i2 < n and i2>0:
            l+=[(i2,i)]
            i2+=a
        i+=1
        a=a*-1
    print(i < n)
    print(l)

def parcours_sinusoidal(n):
    """Retourne la liste des indices (ligne,
    colonne) des cases correspondant a un parcours sinusoidal d'un
    tableau de taille n x n.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,4,7,8,5,2,3,6,9 et la
    fonction retournera la liste d'indices :
    [(0,0),(1,0),(2,0),(2,1),(2,2) ...]

    """
    l=[]
    i=0
    sens=1
    while i<n:
        if sens ==1:
            for j in range(n):
                l+=[(i,j)]
        else:
            j=n-1
            while j>-1:
                l+=[(i,j)]
                j-=1
        i+=1
        sens=sens*-1
    return l

def parcours_zigzag(n):
    """Retourne la liste des indices (ligne,
    colonne) des cases correspondant a un parcours sinusoidal d'un
    tableau de taille n x n.

    Ex: pour T = [ [1,2,3],
                   [4,5,6],
                   [7,8,9] ]
    le parcours correspond aux cases 1,2,3,6,5,4,7,8,9 et la
    fonction retournera la liste d'indices :
    [(0,0),(0,1),(0,2),(1,2),(1,1) ...]

    """
    l=[]
    i=0
    sens=1
    while i<n:
        if sens ==1:
            for j in range(n):
                l+=[(j,i)]
        else:
            j=n-1
            while j>-1:
                l+=[(j,i)]
                j-=1
        i+=1
        sens=sens*-1
    return l

print(parcours_zigzag(2))
