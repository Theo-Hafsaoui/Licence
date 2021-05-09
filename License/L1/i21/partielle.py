def voyelle(L):
    l=[]
    for j in range(len(L)):
        l.append(0)
    for j in range(len(L)):
        for k in range(len(L[j])):
            if L[j][k] in ['a','e','i','o','u','y']:
                l[j]+=1
    return l

def Tri(L):
    cpt=-1
    sv=L
    L=voyelle(sv)
    for i in range(len(L)):
        x=L[i]
        y=sv[i]
        j=i
        cpt+=1
        while j>0 and L[j-1]>x:
            L[j]=L[j-1]
            sv[j]=sv[j-1]
            j-=1
            cpt+=1
        L[j]=x
        sv[j]=y
    return(sv)


L = ["a", "sncf", "arret", "oeil"]
print(Tri(L))


