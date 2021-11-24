def from_rgb(rgb):
    """Convertit en hexa voler sur un site web by the way
    """
    return "#%02x%02x%02x" % rgb

def MoutonMoise(ch):
    #Soccupe des mot composer reunni
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
            #cas des mot simple
            k=MoutonMoise(temp[3])
            dick[k]=(int(temp[0]),int(temp[1]),int(temp[2]))
        else:
            #cas des mot composer
            x1=temp[3].capitalize()
            x2=temp[4].capitalize()
            k=x1+"_"+x2
            dick[k]=(int(temp[0]),int(temp[1]),int(temp[2]))
    f.close()
    l=dick.items()
    l=list(l)
    return l

