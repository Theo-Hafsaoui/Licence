import math
def pgcd(a,b):
    pgcd=[a,b]
    while pgcd[1]!=0:
        pgcd[0],pgcd[1]=pgcd[1],pgcd[0]
        pgcd[1]=pgcd[1]%pgcd[0]
    return pgcd[0]

def euclide_e(a,n):
    u=1
    v=0
    u1=0
    v1=1
    while n!=0:
        q=a//n
        r=a%n
        tv1=v1
        tu1=u1
        v1=v-q*v1
        u1=u-q*u1
        u=tu1
        v=tv1
        a,n=n,(a%n)
    return [a,tu1]

def inverse(a,n):
    sv=n
    u=1
    v=0
    u1=0
    v1=1
    while n!=0:
        q=a//n
        r=a%n
        tv1=v1
        tu1=u1
        v1=v-q*v1
        u1=u-q*u1
        u=tu1
        v=tv1
        a,n=n,(a%n)
    return (tu1%sv)

def euler_phi(n):
    r=0
    for i in range(n):
        pgcd=[i,n]
        while pgcd[1]!=0:
            pgcd[0],pgcd[1]=pgcd[1],pgcd[0]
            pgcd[1]=pgcd[1]%pgcd[0]
        if pgcd[0]==1:
            r+=1
    return r

def decompose(n,b):
    l=[]
    powe=0
    while b**powe<n:
        temp=n//b**powe
        l.append(temp%b)
        powe+=1
    l.reverse()
    return l

def valeur(l,b):
    l.reverse()
    s=0
    b1=1
    for i in range(len(l)):
        s+=l[i]*b1
        b1=b1*b
    return s

def decompose(n):
    l=[]
    s=0
    if (n/2)%1==0:
        l.append(2)
    while n%1==0:
        n=n/2
    n=n*2
    i=3
    while i<=n:
        if (n/i)%1==0 and i != 25:
            l.append(i)
            n=n/i
        i+=2
    return l

def ord(a,n):
    pgcd=[n,a]
    while pgcd[1]!=0:
        pgcd[0],pgcd[1]=pgcd[1],pgcd[0]
        pgcd[1]=pgcd[1]%pgcd[0]
    return n/pgcd[0]

def generateurs(n):
    l=[]
    for a in range(n):
        if pgcd(a,n)==1:
            l.append(a)
    return l

def generateurs(p):
    l=[]
    lk=decompose(p-1)
    for g in range(1,p):
            for i in range(len(lk)):
                if pow(g,(p-1)//lk[i],p)==1:
                    break
                elif i == len(lk)-1:
                    l.append(g)
    return l
            
def generateurs_x(n):
  gen_list = []
  prime_num = decomposePremiers(n-1)
  i = 1 
  while i < n:
    j=0
    boolean = True
    while j < len(prime_num) and boolean:
      if pow(i,(n-1)//prime_num[j],n) == 1:
        boolean = False
      j += 1
    if boolean == True:
      gen_list += [i]
    i += 1
  return gen_list

def generateur(p):
    i=randrange(p)
    while pow(g,(p-1)//lk[i],p)!=1:
        i=randrange(p)
    return i





print(generateurs2(1039))