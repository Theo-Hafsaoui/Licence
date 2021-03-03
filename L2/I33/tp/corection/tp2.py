import math
import copy
import time
from random import *


def pgcd(a,b):
	while b!=0:
        a,b=b,a%b
    return a


def euclide_e(a,n):
	u1=1
    v1=0
    u=0
    v=1
    while b != 0:
        r = a % b
        q = a // b
        a = b
        b = r
        aux1 = u1-q*u
        aux2 = v1-q*v
        u1=u
        v1=v
        u=aux1
        v=aux2
    return [u1,v1,a]


def inverse(a,p):
	u=1
    v=0
    u1=0
    v1=1
    p_=p
    while p != 0:
        r = a % p
        q = a // p
        a = p
        p = r
        aux1 = u-q*u1
        aux2 = v-q*v1
        u=u1
        v=v1
        u1=aux1
        v1=aux2
    return u % p_


def euler_phi(n):
	phi_ = 1
    i = 2
    while  i < n :
        naux = n
        iaux = i
        while iaux != 0:
            naux,iaux = iaux, naux % iaux
        if naux == 1:
            phi_ = phi_ + 1
        i = i + 1
    return phi_


def decompose(n,b):
	L=[]
    while n!=0:
        L = [n%b] + L
        n = n // b
    return L


def valeur(L,b):
	n = 0
    for e in L[0:len(L)-1]:
        n = n + e
        n = n * b
    n = n + L[len(L)-1]
    return n


def decompose(n):
    L = []
    if (n % 2) == 0:
        L = L + [2]
    while (n % 2) == 0:
        n = n // 2
    i = 3
    while n != 1:
        if (n % i) == 0:
            L = L + [i]
            while (n % i) == 0:
                n = n // i
        i = i + 2
    return L


def ord(a,n):
	nsav = n
    while a!=0:
        n,a=a,n%a
    return nsav/n


def generateurs(n):  # question 9
	L=[]
    for e in range(1,a):
        if pgcd(e,a)==1:
            L = L + [e]
    return L


def generateurs(p):  # question 10
	L = decompose(n-1)
    Liste_gen = []
    for g in range(2,n-1):
        j = 0 
        oncontinue = True
        while j < len(L) and oncontinue:
            oncontinue = (pow(g,(n-1)//L[j],n) != 1)
            j = j + 1
        if oncontinue:
            Liste_gen = Liste_gen + [g]
    return Liste_gen


def generateur(p):  # question 11
	g = randrange(2,p-1)
	while (pow(g,(p-1)//2,p) != 1):
		g = randrange(2,p-1)
	return g


def ord(a,p):
	if (a==1):
        return 1
    i = 2
    ok = False
    omin = p
    while (i*i <= (p-1)) and (not(ok)):
        if ((p-1) % i == 0):
            o = i
            ok = (pow(a,o,p) == 1)
            if not(ok):
                oaux = (p-1)//i
                if (pow(a,oaux,p) == 1) and (oaux < omin):
                    omin = oaux
        i=i+1
    if not(ok) and omin !=p :
        return omin
    elif not(ok):
        return p-1
    else:
        return o


#clemence
def decompose(n):
    L=[]
    cpt=0
    if n%2 ==0:
        while n%2 == 0:
            n=n//2
            cpt+=1
    if cpt !=0:
        L+=[[2,cpt]]
    i=3
    while n != 1:
        cpt=0
        if n%i == 0:
            while n%i == 0:
                n=n//i
                cpt+=1
        if cpt != 0:
            L+=[[i,cpt]]
        i+=2
    return L
#clement
def table_alpha(P):
    r = len(bin(P))-3
    p = (1<<r)-1

    L=[1,2]+(p-2)*[0]
    i=2
    a=2
    while i < p:
        a=multbyalpha(a,P)
        L[i]=a
        i+=1
    return L

























