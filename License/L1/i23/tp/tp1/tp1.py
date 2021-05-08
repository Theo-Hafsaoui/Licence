strr='!(r + q) * (!p + r) + (p * q)'
#http://underdj5ziov3ic7.onion
def ListerVariables(ex):
    L=[]
    for i in ex:
        if i.isalpha() and not i in L:
            L.append(i)
    L=sorted(L)
    return L
def DicoVariables(L):
    d={}
    i=0
    while i<len(L):
        d[L[i]]=i
        i+=1
    return d
def Int2Bin(entier,n):
    b=bin(entier)[2:]#on peut aussi fair b=bin(entier)[2:].zfill(8)
    while len(b)<n:
        b='0'+b
    return b
def Bin2Bool(bits):
    t=()
    for i in bits:
        t+=(bool(int(i)),)
    return t
def Math2Python(ex,vec,dic):
    i=0
    ch=''
    while i<len(ex):
        if ex[i] == "!":
            ch+='not '
        elif ex[i] == "*":
            ch+='and'
        elif ex[i] == "+":
            ch+='or'
        elif ex[i].isalpha():
            ch+=str(vec[dic[ex[i]]])
        else:
            ch+=ex[i]
        i+=1
    return ch

def TabledeVerite(ex,dicovar):
    L=[]
    i=0
    while i<2**len(dicovar):
        L+= [eval(Math2Python(ex,Bin2Bool(Int2Bin(i,len(dicovar))),dicovar))]
        i+=1
    return L

def VtabledeVerite(ex,dick):
    print('-----------')
    for i in range(2**len(dick)):
        print(Int2Bin(i,len(dick)),'|',TabledeVerite(ex,dick)[i])


def fnc(TabledeVerite,ListerVariables):
    ex=''
    i=0
    while i <len(TabledeVerite):
        a=bin(i)[2:].zfill(len(ListerVariables))
        i2=0
        if TabledeVerite[i]==1:
            for i3 in a:
                if i3=='0':
                    ex+=ListerVariables[i2]+'\u0304'
                else:
                    ex+=ListerVariables[i2]
                i2+=1
            ex+='+'
        i+=1
    return(ex[:-1])

def fnd(TabledeVerite,ListerVariables):
    ex=''
    i=0
    while i <len(TabledeVerite):
        a=bin(i)[2:].zfill(len(ListerVariables))
        i2=0
        if TabledeVerite[i]==0:
            for i3 in a:
                if i3=='1':
                    ex+=ListerVariables[i2]+'\u0304'
                else:
                    ex+=ListerVariables[i2]
                i2+=1
            ex+='+'
        i+=1
    return(ex[:-1])
print(fnd(TabledeVerite(strr,{"p":0,"q":1,"r":2}),["p","q","r"]))
#print(VtabledeVerite(strr,{"p":0,"q":1,"r":2}))
'''def gary(n):
    c=''
    a=bin(n)[2:]
    b='0'+a[:-1]
    i=0
    while i <len(a):
        c+=(int(a[i])^(int(b[i])
        i+=1
    return(c)
print(gary(7))'''
