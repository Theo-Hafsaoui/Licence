def expo(a,b,m):
    r=1
    if a%m==0:
        return 0
    while b != 0:
        if b%2==1:
            r=(r*a)%m
            print(r)
        b=b//2
        a=(a*a)%m
        print(a)
    return r

print(expo(26,55,493))
