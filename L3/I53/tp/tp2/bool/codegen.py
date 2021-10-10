def gen(s):
    s=s.split()
    f=open('a.out', 'w')
    f.write("#!/usr/bin/python3\n")
    ind=1
    for ch in s:
        if ch[0]in['V','F']:
            if ch[0]=='V':
              f.write("t"+str(ind)+" = True\n")
            else:
              f.write("t"+str(ind)+" = False\n")
            ind+=1
        if ch[0]in['E','O']:
            ind-=1
            if ch[0]=='E':
              f.write("t"+str(ind-1)+"= t"+str(ind-1)+" and"+" t"+str(ind)+"\n")
            else:
              f.write("t"+str(ind-1)+"= t"+str(ind-1)+" or"+" t"+str(ind)+"\n")
    f.write("print(t1)")
    f.close()
gen("VRAI FAUX ET")
