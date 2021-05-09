import math
import copy
import time
from random import *


def somme_pair(L):
    i = 0
    s = 0
    while i < len(L):
        if (L[i] %2)==0:
            s = s + L[i]
        i = i + 1
    return s

def somme_ind_pair(L):
	i = 0
    s = 0
    while i < len(L):
        s = s + L[i]
        i = i + 2
    return s


def minimum(L):
	i = 0
    mini = L[0]
    while i < len(L):
        if mini > L[i]:
            mini = L[i]
        i = i + 1
    return mini


def minimum2(L):
	i = 2
    mini1 = L[0]
    mini2 = L[1]
    if mini1 > mini2:
        mini1,mini2 = mini2, mini1
    while i < len(L):
        if mini1 > L[i]:
            mini2 = mini1
            mini1 = L[i]
        elif (mini2 > L[i]) and (L[i] != mini1):
            mini2 = L[i]
        i = i + 1
    return mini2


def minimum_posi(L):
	posi = 0
    lposi = [0]
    i = 1
    while i < len(L):
        if L[posi] > L[i]:
            lposi = [i]
            posi = i
        elif L[posi] == L[i]:
            lposi = lposi + [i]
        i = i + 1
    return lposi


def som_div_propres(n):
	if n==1:
        return 0
    s = 1
    i = 2
    rac = math.sqrt(n)
    while (i < rac):
        if ((n % i) == 0):
            s = s + i + n//i
        i = i + 1
    if ((n % rac) == 0):
        s = s + rac
    return s


def amicaux(n):
	L = []
	for i in range(2,2**n):
		m = som_div_propres(i)
		if (i < m) and (som_div_propres(m) == i):
			L = L + [(i,m)]
	return(L)


def tri(L):
	for i in range(len(L)-1):
        posi = i
        for j in range(i+1,len(L)):
            if L[posi] > L[j]:
                posi = j
        L[posi],L[i] = L[i],L[posi]
    return L


def tri_bulle(L):
	for i in range(len(L)-1):
        j = len(L) - 1
        while j > i:
            if L[j] < L[j-1]:
                L[j-1],L[j] = L[j],L[j-1]
            j = j - 1
    return L


def partition(L):
	i = 0
    d1 = 0
    d2 = len(L)-1
    while i <= d2:
        if L[i] < 3:
            L[d1],L[i] = L[i],L[d1]
            d1 = d1 + 1
            i = i + 1
        elif L[i] > 6:
            L[d2],L[i] = L[i],L[d2]
            d2 = d2 - 1
        else:
            i = i + 1
    return L


def majoritaire(L):  # question 11
	i_ = 0
    n_ = len(L)
    oncontinue_ = True
    while (i_ < n_) and oncontinue_:
        cpt_ = 0
        for j in L:
            if j == L[i_]:
                cpt_ = cpt_ + 1
        oncontinue_ = (cpt_ <= n_/2)
        i_ = i_ + 1
    if oncontinue_:
        return False
    else:
        return L[i_-1]


def majoritaire(L):  # question 12
	m_ = L[0]
    l_ = 0
    i_ = 1
    while (i_ < len(L)): 
        if l_ == 0:
            m_ = L[i_]
            l_ = 1
        elif m_ == L[i_]:
            l_ = l_ + 1
        else:
            l_ = l_ - 1
        i_ = i_ + 1
    c_ = 0
    for e_ in L:
        if e_ == m_:
            c_ = c_ + 1
    if c_ <= len(L)/2 :
        return False
    else:
        return m_


def recherche(L,S,p):
	T_ = []
    k_ = 0
    while k_ < len(L) - p:
        somme_ = L[k_]
        i_ = k_ + 1
        while i_ <= p + k_:
            somme_ = somme_ + L[i_]
            i_ = i_ + 1
        if somme_ >= S:
            T_ = T_ + [k_]
        k_ = k_ + 1
    return T_


def recherche2(L,S,p):
	T_ = []
    k_ = 0
    somme_ = L[0]
    i_ = 1
    while i_ <= p :
        somme_ = somme_ + L[i_]
        i_ = i_ + 1
    if somme_ >= S:
        T_ = T_ + [0]
    k_ = 1
    while k_ < len(L) - p:
        somme_ = somme_ - L[k_-1] + L[p+k_]
        if somme_ >= S:
            T_ = T_ + [k_]
        k_ = k_ + 1
    return T_






