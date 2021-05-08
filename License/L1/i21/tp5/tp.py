#TP5
def fusionner(T1,T2):
    i=0
    j=0
    cpt=0
    T=[]
    while i<len(T1) and j<len(T2):
        if T1[i]<=T2[j]:
            T+=[T1[i]]
            i+=1
        else:
            T+=[T2[j]]
            j+=1
        cpt+=1
    if i==len(T1):
        while j<len(T2):
            T+=[T2[j]]
            j+=1
    if j==len(T2):
        while i<len(T1):
            T+=[T1[i]]
            i+=1
    return(T,cpt)

def fusion_partielle(T,a,b):
    ttemp=fusionner(T[:a],T[a:b])[0]
    T=ttemp+T[b:]
    return T

T = [2,4,5,3,6,8,5,4,2,7]
print(fusion_partielle(T,3,6))