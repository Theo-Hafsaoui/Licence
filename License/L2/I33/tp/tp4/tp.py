import random
def genmatrix(n,p,t):
    l=[]
    for i in range(n):
        l.append([])
        for j in range(p):
            l[len(l)-1].append(random.randrange(t))
    return l

def gendiag(n,t):
    l=[]
    temp=[0]*n
    i=0
    while len(l)!=n:
        temp1=temp[:]
        temp1[i]=random.randrange(t)
        l.append(temp1)
        i+=1
    return l

def gentrianginf(n,t):
    l=[]
    temp=[0]*n
    i=1
    while len(l)!=n:
        temp1=temp[:]
        for j in range(i):
            temp1[j]=random.randrange(t)
        l.append(temp1)
        i+=1
    return l

def gensym(n,t):
    '''envoie une matrice symétrique'''
    l=gentrianginf(n,t)
    for i in range(n):
        for j in range(i+1,n):
            l[i][j]=l[j][i]
    return l

def genasym(n,t):
    '''envoie une matrice antisymétrique'''
    l=gentrianginf(n,t)
    for i in range(n):
        for j in range(i+1,n):
            l[i][j]=-(l[j][i])
    return l

def transpose(M):
    l=[]
    for i in range(len(M[0])):
        l.append([])
        for j in range(len(M)):
            l[len(l)-1].append(M[j][i])
    return l

def gencirculante(l):
    m=[l[:]]
    for i in range(len(l)-1):
        temp=[(m[len(m)-1][len(l)-1])]+(m[len(m)-1][:-1])
        m.append(temp)
    return m

def gen_circulante2(k,t):
    l=[(bin(k)[2:t+3]).zfill(t)]
    bi=[k]
    for i in range(t-1):
        temp=l[len(l)-1][-1]+l[len(l)-1][:-1]
        l.append(temp)
        bi.append(int(l[len(l)-1], 2))
    return bi

def liste_perm(n):
    l=list(range(n))
    for i in range(1,n):
        tmp=random.randrange(0, n-i)
        l[tmp],l[n-i]=l[n-i],l[tmp]
    return l

def genmatrixperm(n):
    tmp=([0]*n-1)+[1]
    l=[]
    for i in range(n):
        tmp=lis





    



#~~~~~~~~~~~~~~~~~~~~~~~~~~~~
print(liste_perm(6))

	



