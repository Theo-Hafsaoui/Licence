from random import *
from numpy import *
#Ex1
#baa=hlt
#aba=gdf
#aab=mcb
#d'ou[[7,6,12],[11,,3,2],[19,2,1]]
#en dechifrant on obtien:
#
#   TOUSLESDIXMETRESUNEPANCARTEINDIQUAITQUECEGRILLAGE
#   ETAITELECTRIFIEUNPETITCHEMINLONGEAITLESGRILLAGES
#   DECHAQUECOTEETLONPOUVAITYVOIRDETEMPSENTEMPSDEUX
#   GARDESARMESFAIRELEURRONDELAROUTESEMBLAITINTERMINABLE
#   CAILLOUTEUSEASOUHAITAUDELADESGRILLAGESCETAITLA
#   FORETUNEFORETBIENENTRETENUEPRESQUEARTIFICIELLEPENSADAVIDZZ
# l'inverse a etait calculer en ligne
#Ex2

def ascii2i(ch):
    l=[]
    for i in range(len(ch)):
        if (ord(ch[i])==44):
            l.append(27)
        if (ord(ch[i])==32):
            l.append(28)
        if (ord(ch[i])==46):
            l.append(28)
        else:
            l.append(ord(ch[i])-97)
    return l

def couplage(l):
    lc=[]
    for i in range(len(l)//2):
        lc.append([l[i*2],l[i*2+1]])
    return lc

def matmat(A,B):#vient du i33
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

def randinv(n):
    while(True):
        inv=randint(0,n)
        for i in range(n):
            if((i*inv)%n==1):
                return inv

def gentrianginf_mod29(n):
    not_trouve = True
    while not_trouve:
        M = [0]*n
        det = 1
        for i in range(n):
            M[i] = [0]*n
            for j in range(i):
                M[i][j] = randrange(29)
            M[i][i] = 2*randrange(14)+1
            det = det * M[i][i]
        not_trouve = (((det % 14) == 0) or ((det % 2)==0))
    return M

def gen_cle_hill(n):
    k=(gentrianginf_mod29(3))
    l=[]
    for i in range(n):
        l.append(randint(0,1024))
    k.append(l)
    return k

def Hill_affine_chiffre(ch,ab):
    k=ab[:3]
    l=ascii2i(ch)
    l=couplage(l)
    l=matmat(l,k)
    b=ab[3]
    s=[]
    for i in range(len(l)):
        for j in range(len(l[i])):
            l[i][j]=(l[i][j]+b[j])%26
    ch2=''
    for i in range(len(l)):
        for j in range(len(l[0])):
            ch2+=chr(l[i][j]+97)
    return ch2
    
Hill_affine_dechiffre(texte, cle):
    pass#jamais a dechiffrer avec hill normale alors affine, meh
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ab=[[14,17,4],[28,20,10],[19,20,27],[10,18,6]]
ch='soitxmamoyeneonsupposexnonulalorsxtentverszero'
print(Hill_affine_chiffre(ch,ab))
