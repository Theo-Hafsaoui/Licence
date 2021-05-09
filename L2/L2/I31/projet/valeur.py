def valeur():
    i=584
    while (len(bin(i))-2)%11!=0:
        i=i<<1
        print(i)
    print(i)
valeur()