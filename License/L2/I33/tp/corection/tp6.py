import math
import copy
import time
from random import *



def decompose(n):
    L = []
    cpt = 0
    while (n % 2) == 0:
        cpt = cpt + 1
        n = n // 2
    if (cpt != 0):
        L += [[2,cpt]]
    i = 3
    while n != 1:
        cpt = 0
        while (n % i) == 0:
            cpt = cpt + 1
            n = n // i
        if (cpt != 0):
            L += [[i,cpt]]
        i = i + 2
    return L


def decompose(n):
    L=[]
    while n!=0:
        L = [n & 1] + L
        n = n >> 1
    return L


def evalue(Q,y,P):
	val=Q[0]
	for i in range(1,len(Q)):
		val = multiplie(val,y,P) ^ Q[i] 
	return val


def inverse(x,P):
    m_ = len(bin(P)) - 3
    i = log_table[x]
    return alpha_table[((1 << m_)-1)-i]


def table_alpha(P):
    m_ = len(bin(P)) - 3
    cardinal = (1 << m_)
    L = [0]*(cardinal-1)
    z = 1
    for j in range(0, cardinal-1):
        L[j] = z
        z = multbyalpha(z,P)
    return L


def matmat(A,B):
    l=[]
    for i in range (len(A)):
        tmp = []
        for k in range(len(B[0])):
            s=0
            for j in range(len(A[0])):
                s+=(A[i][j])*(B[j][k])
            tmp.append(s)
        l.append(tmp)
    return l


def gentrianginf_inv(n,t):
    M = []
    for i in range(n):
        aux = []
        for j in range(i):
            aux = aux + [random.randrange(t)]
        aux = aux + [random.randrange(1,t)]
        aux = aux + [0]*(n-i-1)
        M = M + [aux]
    return M


def gentrianginf_mod26(n):
    not_trouve = True
    while not_trouve:
        M = [0]*n
        det = 1
        for i in range(n):
            M[i] = [0]*n
            for j in range(i):
                M[i][j] = random.randrange(26)
            M[i][i] = 2*random.randrange(13)+1
            det = det * M[i][i]
        not_trouve = (((det % 13) == 0) or ((det % 2)==0))
    return M


def genmatrix_inv(n):
   #pour l'intervalle du randrange, on peut mettre
   #ce que l'on veut, il n'y avait pas de contraintes
   # dans l'énoncé
    t = random.randrange(-99,99)
    M = gentrianginf_inv(n,t)
    N = gentrianginf_inv(n,t)
    N = transpose(N)
    prod = []
    for i in range(len(M)):
        aux = []
        for j in range(len(N[0])):
            somme = 0
            for k in range(len(M[0])):
                somme = somme + M[i][k] * N[k][j]
            aux = aux + [somme]
        prod = prod + [aux] 
    return prod


def genmatrixinv_mod26(n):
    M = gentrianginf_mod26(n)
    N = gentrianginf_mod26(n)
    N = transpose(N)
    prod = []
    for i in range(len(M)):
        aux = []
        for j in range(len(N[0])):
            somme = 0
            for k in range(len(M[0])):
                somme = (somme + M[i][k] * N[k][j])%26
            aux = aux + [somme]
        prod = prod + [aux] 
    return prod


def matvec(M,V):
    aux = []
    for i in range(len(M)):
        somme = 0
        for j in range(len(V)):
            somme = somme + M[i][j]*V[j]
        aux = aux + [somme]
    return aux


def circmultvec(M,V):
    W = []
    n = len(V)
    for i in range(n):
    # la ligne i commence avec l'element M[(n-i) % n]
        somme = 0
        for j in range(n):
            somme = somme + M[(j-i) % n]*V[j]
        W = W + [somme]
    return W
   
   
def circmultmat(A,B):
	P = []
	n = len(A)
	for i in range(n):
		idxligneA = (-i % n)
		aux = []
		for j in range(n):
			somme = 0
			for k in range(n):
				idxligneB = (-k % n)
				somme = somme + A[(idxligneA+k) % n]*B[(idxligneB+j) % n]
			aux = aux + [somme]
		P = P + [aux]
	return P


def prod_perm2(M,V):
	n = len(M)
	W = [] 
	for i in range(n):
		cpt = 0
		while M[i] != 0:
			M[i] >>= 1
			cpt += 1
		W = W + [V[n-cpt]]
	return W


def permute_from_list(L,V):
	W = []
	for i in range(len(L)):
		W = W + [V[L[i]]]
	return W


def is_triangsup(M):
	if len(M) != len(M[0]):
		return False
	for i in range(len(M)):
		for j in range(i):
			if M[i][j] != 0:
				return False
	return True


def is_diag_dom(M):
	est_dominante = True
	i = 0
	while (i < len(M)) and (est_dominante):
		somme = 0
		for j in range(i):
			somme = somme + abs(M[i][j])
		for j in range(i+1,len(M)):
			somme = somme + abs(M[i][j])
		est_dominante = (abs(M[i][i]) >= somme)
		i = i + 1
	return est_dominante


def is_diag_strict_dom(M):
	est_dominante = True
	i = 0
	while (i < len(M)) and (est_dominante):
		somme = 0
		for j in range(i):
			somme = somme + abs(M[i][j])
		for j in range(i+1,len(M)):
			somme = somme + abs(M[i][j])
		est_dominante = (abs(M[i][i]) > somme)
		i = i + 1
	return est_dominante


def norme_infinie(L):
	maxi = 0
	for i in range(len(L)):
		somme = 0
		for j in range(len(L[0])):
			somme = somme + abs(L[i][j])
		if somme > maxi:
		    maxi = somme
	return maxi


def norme_une(L):
	max = 0
	for j in range(len(L[0])):
		somme = 0
		for i in range(len(L)):
			somme = somme + abs(L[i][j])
		if somme > max:
		    max = somme
	return max


def puissance(x,y,n):
    z = 1
    while y != 0:
        if (y & 1):
            z = (z * x) % n
        x = (x * x) % n
        y = y >> 1
    return z


# ~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  fonctions annexes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def multbyalpha(b,f):
    y = b << 1
    taille = len(bin(f))-3
    if ((y & (1 << taille)) != 0):
        y = y ^ f
    return y


def multiplie(b,c,f):
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




















