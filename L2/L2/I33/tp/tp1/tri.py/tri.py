#include <stdio.h>

def triins(t):
    i2=0
    j=1
    for k in range(len(t)):
        for i in range(1,j):
            if t[i-1]>t[i]:
                print(t)
                t[i],t[i-1]=t[i-1],t[i]
        j+=1
    return t
def triabulle(t):
    k=len(t)
    for i in range(len(t)):
        for j in range(0,k-1):
            if t[j]>t[j+1]:
                t[j],t[j+1]=t[j+1],t[j]
        k-=1
    return t

def triselection(t):
    for i in range(len(t)):
        max=i
        for j in range(i,len(t)):
            if t[max]<t[j]:
                max=j
        t[i],t[max]=t[max],t[i]
        print(t)
    return t

print(triselection([6, 5, 3, 1, 8, 7, 2, 4]))
