def decompose(n):
    nc = n
    L = []
    while n > 0:

        e = n%2
        L = [e]+L
        n = n//2

    return L

def eval_poly(P,b):
    i=0
    s=P[i]*b + P[i+1]
    i+=2
    while i<len(P):
        s= (s*b)+P[i]
        i+=1
    return s

print(eval_poly([1, 2, 5, 5, 1],3))