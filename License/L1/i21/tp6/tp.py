#tp6
from random import *
def rand_table(n,a,b):
    t=[]
    for i in range(n):
        t.append(randrange(a,b+1))
    return t

def Recherche_binaire(T,x):
    i=0
    j=len(T)-1
    cpt=0
    while (i+j)//2 != 0:
        cpt+=1
        if T[(i+j)//2]>=x:
            j=(i+j)//2-1
        else:
            i=(i+j)//2-1
        if len (T[i:j]) ==1:
            if T[j]==x:
                return j,cpt
            else:
                return -1,cpt
    return (i+j)//2,cpt



print(Recherche_binaire([0,1,5,8,14,15,19,22],0))
