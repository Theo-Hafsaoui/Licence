def expo(a,b,m):
    r=1
    if a%m==0:
        return 0
    while b != 0:
        if b%2==1:
            print("ok")
            r=(r*a)%m
        b=b//2
        a=(a*a)%m
    return r

print(expo(26,55,493))
