#bite
from numpy import *
def ascii2i(ch):
    l=[]
    for i in range(len(ch)):
        l.append(ord(ch[i])-97)
    return l

def couplage(l):
    lc=[]
    for i in range(len(l)//2):
        lc.append([l[i*2],l[i*2+1]])
    return lc

def matmat(A,B):
    l=[]
    for i in range (len(A)):
        tmp = []
        for k in range(len(B[0])):
            s=0
            for j in range(len(A[0])):
                s+=(A[i][j])*(B[j][k])
            tmp.append(s%26)
        l.append(tmp)
    return l

def inverse(M):
    M=.matrix.getH()

def chiffrement(Ma,ch):
    l=ascii2i(ch)
    l=couplage(l)
    l=matmat(l,Ma)
    ch=''
    for i in range(len(l)):
        for j in range(len(l[0])):
            ch+=chr(l[i][j]+97)
    return ch
    

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ch='texteachiffrer'
ma=[[2,7],[5,4]]
print(inverse(ma))
print(chiffrement(ma,ch))
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~