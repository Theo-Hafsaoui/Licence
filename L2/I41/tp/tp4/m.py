
def sm(x,n):
    r=1
    while n!=0:
        r=r*r
        n=n>>1
        if n&1:
            r=r*x
    return r

print(sm(2,50))