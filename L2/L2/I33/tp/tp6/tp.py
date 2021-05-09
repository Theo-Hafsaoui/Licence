def matmat(A,B):
    l=[]
    for i in range (len(A)):
        l.append([])
        s=0
        for k in range(len(B[i])):
            s=0
            for j in range(len(A[i])):
                s+=(A[i][j])*(B[j][k])
            l[len(l)-1].append(s)
    return l

print(matmat([[8, 1, 5, 5, 0, 0], [1, 1, 3, 7, 3, 7], [0, 6, 1, 5, 1, 6]],[[8, 5, 8, 8], [4, 5, 3, 7], [3, 6, 2, 5], [7, 4, 5, 4], [6, 1, 8, 3], [6, 3, 2, 5]]))

