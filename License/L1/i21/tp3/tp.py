from random import *
from math import *

def valeur_sin(t):
    l = []
    for i in range(len (t)):
        temp = (sin(t[i]))
        l.append(temp)
    return l

def nombre_alea(n) :
    L=[]
    for i in range(n) :
        L.append(randrange(10))
    return(L)


def intervalle(a,b,inc):
    l=[]
    while a<=b:
        l.append(a)
        a+=inc
    return l
def multiplication(n1,n2):
    n11=0
    n22=0
    i1=1
    for i in n1:
        n11+=i * i1
        i1=i1*10
    i1=1
    for i in n2:
        n22+=i * i1
        i1=i1 * 10
    n=n11 * n22
    l=[]
    while n >= 1:
        l.append(int(n%10))
        n=(n-(n%10))//10
    while len (l)<(len(n1)+len(n2)):
        l.append(0)
    return(l)
def Decoposel(n):
    for i in range:
        n11+=i * i1
        i1=i1*10
print(multiplication([3,0],[9,3]))

