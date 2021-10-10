def gen(s):
    s=s.split()
    f=open('a.out', 'w')
    f.write("#!/usr/bin/python3\n")
    ind=1
    for ch in s:
        if ch.isnumeric():
            f.write("t"+str(ind)+" = "+ch+"\n")
            ind+=1
        else:
            ind-=1
            f.write("t"+str(ind-1)+"= t"+str(ind-1)+" "+ch+" t"+str(ind)+"\n")
    f.write("print(t1)")
    f.close()
