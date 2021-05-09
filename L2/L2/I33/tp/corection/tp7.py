import math
import copy
import time
from random import *



def det(A):
    signe = 1
    d = 1
    p = 1
    for j in range(len(A)-1):
        k = j
        while (k < len(A)) and (A[k][j] == 0):
            k = k + 1
        if (k == len(A)):
            return 0
        if (k != j):
            A[k],A[j] = A[j], A[k]
            signe = -signe
        d = d * A[j][j]
        for k in range(j+1,len(A)):
            p = p * A[j][j]
            s = A[k][j]
            for c in range(0,len(A)):
                A[k][c]=A[k][c]*A[j][j]-A[j][c]*s
    d = d * A[len(A)-1][len(A)-1]*signe
    if (abs(d) == 0):
        d = 0
    return(d/p)%26



def gauss(A):
	if len(A) < len(A[0]):
		nb = len(A)
	else:
		nb = len(A[0])
	for j in range(nb):
		c = j
		pastrouve = True
		while (c < len(A[0])) and pastrouve:
			l = j
			while (l < len(A)) and (A[l][c] == 0):
				l = l + 1
			pastrouve = (l == len(A))
			c = c + 1
		if (pastrouve):
			return A
		if (l != j):
			A[l],A[j] = A[j], A[l]
		if ((c-1) != j):
			for k in range(len(A)):
				A[k][c-1],A[k][j] = A[k][j],A[k][c-1]
		for k in range(j+1,len(A)):
			s = A[k][j]
			#for c in range(j+1,len(A[0])):
			for c in range(0,len(A[0])):
				A[k][c]=A[k][c]*A[j][j]-A[j][c]*s
	return A




def nature(A):
    p = len(A)
    n = len(A[0])
    M , okgauss = gauss_2(A)
    libre = int((okgauss and (p <= n)))
    generatrice = int((okgauss and (p >= n)))
    return(generatrice,libre)




def resolution(A,b):
	x = [b[0]/A[0][0]]
	for i in  range(1,len(A)):
		somme = b[i]
		for j in range(i):
			somme = somme - A[i][j]*x[j]
		x = x + [somme/A[i][i]]
	return x



# ~~~~~~~~~~~~~~~~fonction annexe ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

def gauss_2(A):
	if len(A) < len(A[0]):
		nb = len(A)
	else:
		nb = len(A[0])
	for j in range(nb):
		c = j
		pastrouve = True
		while (c < len(A[0])) and pastrouve:
			l = j
			while (l < len(A)) and (A[l][c] == 0):
				l = l + 1
			pastrouve = (l == len(A))
			c = c + 1
		if (pastrouve):
			return (A,False)
		if (l != j):
			A[l],A[j] = A[j], A[l]
		if ((c-1) != j):
			for k in range(len(A)):
				A[k][c-1],A[k][j] = A[k][j],A[k][c-1]
		for k in range(j+1,len(A)):
			s = A[k][j]
			#for c in range(j+1,len(A[0])):
			for c in range(0,len(A[0])):
				A[k][c]=A[k][c]*A[j][j]-A[j][c]*s
	return (A,True)





