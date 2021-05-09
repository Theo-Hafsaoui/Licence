def decompose(n):
    l=[]
    p=1
    i=1
    while n != 0:
        l.append(n&1)
        n=n >> 1 
        i+=1
    l.reverse()
    return l

def decompose1(n):
    l=[]
    s=0
    j=1
    if n%2 ==0:
        l.append([2,j])
        while n%2 == 0:
            n=n//2
            l[0]=[2,j]
            j+=1
    i=3
    while n != 1:
        j=1
        if n%i == 0:
            l.append([2,j])
            while n%i == 0:
                n=n//i
                l[len(l)-1]=[i,j]
                j+=1
        i+=2
    return l

def inverse(x,P):
    if (a == 0) or (b == 0):
        return 0
    l = len(bin(P))-3
    n = log_table[x]
    return alpha_table[((1 << l) - 1) - n]

def multbyalpha(b,f):
    t = b<<1
    n = len(bin(f))-3
    if ((t & (1<<n)) != 0) or (((t & (1<<n)) >> n) ==1) :
        t = t ^ f
    return t

def table_alpha(P):
    a=bin(P)[2:]
    L = len(a)
    d = (1<<L)-1
    l=[1,2]
    i,m=2,2
    while i < d:
        m=multbyalpha(m,P)
        if m not in l:
            l.append(m)
        i+=1
    return l


def table_alpha2(P):
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
print(table_alpha(13)==table_alpha2(13))
