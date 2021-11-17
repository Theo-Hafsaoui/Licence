'''normalise ch 
ex: DarkRed->Dark_RED'''

def from_rgb(rgb):
    """translates an rgb tuple of int to a tkinter friendly color code
    """
    return "#%02x%02x%02x" % rgb

def MoutonMoise(ch):
    for i in range(1,len(ch)):
        if(ch[i].isupper()):
            return ch[:i]+'_'+ch[i:]
    return ch[0].upper()
def color():
    f = open("rgb.txt", "r")
    l_ch=f.readlines()
    dick={}
#separer les chaines en deux parties de celles
#en une partie
    for ch in l_ch:
        temp=ch.split()
        if(len(temp)==4):
            k=MoutonMoise(temp[3])
            dick[k]=(int(temp[0]),int(temp[1]),int(temp[2]))
        else:
            x1=temp[3].capitalize()
            x2=temp[4].capitalize()
            k=x1+"_"+x2
            dick[k]=(int(temp[0]),int(temp[1]),int(temp[2]))
    f.close()
    l=dick.items()
    print(l)
    return l

