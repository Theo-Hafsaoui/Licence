import math
import copy
import time
from random import *


def decompose(n):
	if n==0:
		return [0]
	L=[]
    while n!=0:
        L = [n%2] + L
        n = n // 2
    return L


def eval_poly(P,b):
	val=P[0]
	for i in range(1,len(P)):
		val = val*b + P[i] 
	return val


def multbyalpha(b,f):
	y = b << 1
    taille = len(bin(f))-3
    if ((y & (1 << taille)) != 0):
        y = y ^ f
    return y


def multiplie(x,y,P):
	if (a == 0) or (b == 0):
        return 0
    m_ = len(bin(P)) - 3
    i = log_table[a]
    j = log_table[b]
    return alpha_table[(i+j) % ((1 << m_)-1)]


def multiplication(b,c,f):
	prod_ = 0
	aux_  = c
	while (b != 0):
		if (b & 1)!= 0:
			prod_ = prod_ ^ aux_
		aux_ = multbyalpha(aux_,f)
		b = b >> 1
	return prod_ 


def table_log(P):
	m_ = len(bin(P)) - 3
    cardinal = (1 << m_)
    L = [0]*cardinal
    L[0] = -1
    z = 1
    for j in range(0, cardinal-1):
        L[z] = j
        z = multbyalpha(z,P)
    return L


def is_irreducible(P,p):
	_irr = True
    b = 0
    while (b < p) and _irr: 
        val=P[0]
        for i in range(1,len(P)):
            val = (val*b + P[i]) % p 
        _irr = (val != 0)
        b = b + 1
    return _irr


def is_primitif(P):
	m_ = len(P) - 1
    diviseurs = decompose((1 << m_) - 1)
    oncontinue = True
    j = 0
    while j < len(diviseurs) and oncontinue:
        z = 1
        y = ((1 << m_) - 1) // diviseurs[j]
        x = 2 # représentation de l'élément alpha de F_2^m
        while y != 0:
            if (y & 1):
                z = multiplie(z,x,P)
            x = multiplie(x,x,P)
            y = y >> 1
        oncontinue = ((z != 1) and (z != 0))
        j = j + 1
    return ((j == len(diviseurs)) and (oncontinue == True))





