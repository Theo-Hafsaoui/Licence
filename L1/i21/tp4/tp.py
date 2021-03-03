from random import *
def randtable(n,a,b):
    '''fonction qui retourne une liste d’entiers tirees aleatoirement entre a et b.'''
    l=[]
    for i in range(n):
        l.append(randrange(a,b))4
    return l

def triebulle(L):
    '''fonction qui trie du plus petit au plus grand, et qui renvoie le nb de comparaison'''
    cpt=0
    for i in range(len(L)-1):
        k=len(L)-i-1
        tri=True
        for j in range(k):
            cpt+=1
            if L[j]>L[j+1]:
                L[j],L[j+1]=L[j+1],L[j]
                tri=False
        if tri:
            return(cpt)
    return(cpt)

def max(L):
    cpt=0
    Max=0
    j=0
    for i in range(len(L)):
        cpt+=1
        if L[i]>L[Max]:
            Max= i
    return Max,cpt

def triinsertion(L):
    '''fonction qui trie du plus petit au plus grand, et qui renvoie le nb de comparaison'''
    cpt=-1
    for i in range(len(L)):
        x=L[i]
        j=i
        cpt+=1
        while j>0 and L[j-1]>x:
            L[j]=L[j-1]
            j-=1
            cpt+=1
        L[j]=x
    return(cpt)

def triselection(L):
    cpt=0
    for i in range(len(L)):
        Max=i
        for j in range(i+1,len(L)):
            cpt+=1
            if L[j]<L[Max]:
                Max =j
        L[i],L[Max]=L[Max],L[i]
    return cpt
def retourner(T,i):
    j=len(T)-1
    while i<j:
        a=T[i]
        T[i]=T[j]
        T[j]=a
        i+=1
        j-=1
    return (T)

def retourner(L,k):
    a=L[k:]
    a.reverse()
    T=L[:k]+a
    for i in range(len(T)):
        L[i]=T[i]






#---------------------------------
L=[1,2,5,4,3,6]
print('liste aleatoire:', randtable(10,0,100))
print('trie bulle:', triebulle(L),L)
L=[1,2,3,4,5,6]
print(L,"max", max(L))
print('trie insertion:', triinsertion(L), L)RRR
L=[2,1,6,4,5,3]
print('trie selection:', triselection(L), L)
L=[2, 0, 3, 1]
print('retourner 2:', retourner(L,1),L)
print(L)