def elementmedian(M):
    l=[]
    for i in range(len(M)):
        for j in range(len(M)):
            l.append(M[i][j])
    l.sort()
    a=int((((len(M))**2)-1)/2)
    return(l[a])

def multiplie(x,y,P):
    if (a == 0) or (b == 0):
        return 0
    m_ = len(bin(P)) - 3
    i = log_table[a]
    j = log_table[b]
    return alpha_table[(i+j) % ((1 << m_)-1)]

def matmat(A,B):
    l=[]
    for i in range (len(A)):
        tmp = []
        for k in range(len(B[0])):
            s=0
            for j in range(len(A[0])):
                s+=(A[i][j])*(B[j][k])
            tmp.append(s)
        l.append(tmp)
    return l

def resolution(A,b):
    x=0
    y=0
    z=(A[len(M)-1][len(M)]-1)*b[len(M)-1]

print(matmat([[14, 8, 9], [0, 4, 12], [12, 10, 12]],[[11, 12, 8], [7, 8, 15], [4, 9, 5]]))


