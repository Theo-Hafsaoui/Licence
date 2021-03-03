#tp position

def somme_pair(l):
    s=0
    for i in l:
        if i%2==0:
            s+=i
    return s

def somme_ind_pair(l):
    s=0
    i=0
    while i<len(l):
        s+=l[i]
        i+=2
    return s

def min5(l):
    i=0
    j=-1
    s=0
    while i<len(l) and j>-len(l):
        if l[i]<l[j]:
            s=l[i]
            j-=1
        else:
            s=l[j]
            i+=1
    return s


def minimum(l):
    min=0
    i=1
    while i<len(l):
        if l[i]<l[min]:
            min=i
        i+=1
    return l[min]
        

def minimum2(l):
    min=0
    i=1
    s=0
    while i<len(l):
        if l[i]<l[min]:
            min,s=i,min
        if l[i]!=l[min] and l[i]<l[s] or s==min:
            s=i
        i+=1
    return l[s]


def minimum_posi(l):
    t=[]
    min=0
    i=0
    while i<len(l):
        if l[i]<l[min]:
            min=i
            t=[i]
        elif l[i]==l[min]:
            t.append(i)
        i+=1
    return t

def som_div_propres(n):
    s=1
    bite=int(n**1/2)
    for i in range(2,bite):
        if n%i==0:
            k=n//i
            s+=(i+k)
    return s

def amicaux(n):
    t=[]
    for i in range(2,2**n+1):
        sd=som_div_propres(i)
        if som_div_propres(sd)==i and (i,sd) not in t and i!=sd and (sd,i) not in t:
            t.append((i,sd))
    return t

def partition(l):
    i=0
    j=0
    k=len(l)-1
    while j<k+1:
        if l[j]<3:
            l[j],l[i]=l[i],l[j]
            i+=1
            j+=1
        elif l[j]>6:
            l[j],l[k]=l[k],l[j]
            k-=1
        else:
            j+=1
    return l

def majoritaire(l):
    t={}
    for i in l:
        if i not in t:
            t[i]=1
        else:
            t[i]=t[i]+1
            if t[i]>len(l)//2:
                return i
    return False

def recherche(l,S,p):
    t=[]
    for i in range(len(l)-p):
        s=0
        for j in range(p+1):
            s+=l[i+j]
        if s>=S:
            t.append(i)
    return t

def recherche2(l,S,p):
    #ne fonctionne pas
    s=0
    t=[]
    for i in range(len(l)):
        if s>=S:
            t.append(i-(p+1))
        if i<p+1:
            s+=l[i]
        else:
            s+=l[i]
            s-=l[i-(p+1)]
            if i+1 ==len(l):
                if s>=S:
                    t.append(i+1-(p+1))
    return t

print(recherche2([70, 94, 70, 18, 26, 81, 92, 21, 57, 68, 24, 28, 88, 93, 82, 80, 79, 13, 98, 45, 23, 3, 76, 28, 18, 88, 55, 86, 51, 3, 93, 74, 14, 95, 67, 8, 50],384,6))
print(recherche([70, 94, 70, 18, 26, 81, 92, 21, 57, 68, 24, 28, 88, 93, 82, 80, 79, 13, 98, 45, 23, 3, 76, 28, 18, 88, 55, 86, 51, 3, 93, 74, 14, 95, 67, 8, 50],384,6))
#print(recherche2([0,1,2,1,3,2,1,0],5,3))
