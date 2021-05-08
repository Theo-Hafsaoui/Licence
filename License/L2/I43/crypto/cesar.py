

def chifrement(m,k):
    cm=''
    for i in range(len(m)):
        if(ord(m[i])!=32):
            cm+=chr((((ord(m[i])+k-97))%26)+97)
    return cm

def dechifrement(m,k):
    cm=''
    for i in range(len(m)):
        if(ord(m[i])!=32):
            cm+=chr((((ord(m[i])-k-97)%26)+97))
    return cm

def majo(ch):
    dic={'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0,'k':0,'l':0,'m':0,'n':0,'o':0,'p':0,'q':0,'r':0,'s':0,'t':0,'u':0,'v':0,'w':0,'x':0,'y':0,'x':0,'z':0}
    for i in range(len(ch)):
        dic[ch[i]]+=1
    return(max(dic, key=dic.get))

def CFReq(cm,f):
    maj=majo(cm)
    if(ord(f)>ord(maj)):
        k=ord(f)-ord(maj)
        return(dechifrement(cm,k))
    else:
        k=ord(maj)-ord(f)
        return(dechifrement(cm,k))
    pass
#------------------------------
m='myibtgmrgylrmbtntynfsydskxdmbtzfk'
k=23
cm=chifrement(m,k)