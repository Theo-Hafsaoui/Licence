#Question 1 fonc­tion ListerVariables(expression) qui renvoie la liste des va­riab­les boo­léen­nes utilisées dans la chaîne expression.
def ListerVariables(ex):
    L=[]
    for i in ex:
        if i.isalpha() and not i in L:
            L.append(i)
    L=sorted(L)
    return L

#Question 2  fonction DicoVariables(liste) qui, à partir d'une liste de caractères triés dans l'ordre alpha­bé­ti­que, renvoie un dictionnaire dont les clés sont ces caractères et les valeurs sont leur ordre dans la liste.
def DicoVariables(L):
    d={}
    i=0
    while i<len(L):
        d[L[i]]=i
        i+=1
    return d 

#Question 3 fonction Int2Bin(entier,n) qui renvoie la chaîne de caractères correspondant à l'écriture binaire de l'entier passé en paramètre sur n bits. 
def Int2Bin(entier,n):
    b=bin(entier)[2:]#on peut aussi fair b=bin(entier)[2:].zfill(8)
    while len(b)<n:
        b='0'+b
    return b

# Question 4 
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
def gary(n):
    garry=''
    b=bin(n)[2:]
    bshift='0'+b[:-1]
    i=0
    while i< len(b):
        garry+=str(int(b[i])^int(bshift[i]))
        i+=1
    return garry


print(gary(6))
