'''normalise ch 
ex: DarkRed->Dark_RED'''
def MoutonMoise(ch):
    for i in range(1,len(ch)):
        if(ch[i].isupper()):
            return ch[:i]+'_'+ch[i:]
    return ch[0].upper()

f = open("rgb.txt", "r")
l_ch=f.readlines()
dick={}
#separer les chaines en deux parties de celles
#en une partie
for ch in l_ch:
        temp=ch.split()
        print(len(temp))
        if(len(temp)==4):
            k=MoutonMoise(temp[3])
            dick[k]=(temp[0],temp[1],temp[2])
        else:
            x1=temp[3].capitalize()
            x2=temp[4].capitalize()
            k=x1+"_"+x2
            dick[k]=(temp[0],temp[1],temp[2])
print(dick.items())
f.close()

