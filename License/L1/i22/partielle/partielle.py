from random import *
def init_ram_list(taille):
    return [0]*taille

def fill_ram_random(ram, N):
    l=[]
    while len(l) != N:
        a=randrange(0,len(ram))
        if a not in l:
            l.append(a)
    for i in range(len(ram)):
        if i in l:
            ram[i]=randrange(1,255)
    return ram

def fill_ram_place(ram, N):
    if N>=len(ram):
        return ram
    for i in range(N):
        t=True
        while t:
            a=randrange(1,len(ram))
            if ram[a]==0:
                t=False
        print(i)
        ram[a]=a
    return ram


def get_value_list(ram, adresse):
    return ram[adresse]

def init_ram_dict(taille):
    return {'taille':taille}

def fill_ram_random_dict(ram, N):
    for i in range(N):
        ram[randrange(1,255)]=randrange(1,255)
    return ram

def fill_ram_place_dict(ram, N):
    for i in range(N):
        a=randrange(1,N)
        ram[a] = a
    return ram

def get_value_dict(ram, adresse):
    if adresse>ram['taille']:
        print('prout')
        return None
    try:
        print(ram[adresse])
    except KeyError:
        print(0)

def is_in(mem,mot):
    l=[]
    for i in range(len(mem)):
        if mem[i]==mot:
            l.append(True)
            indexhit = i
            i+=1
            while i<len(mem):
                l.append(False)
                i+=1
            return('hit',l,indexhit)
        else:
            l.append(False)
    return('miss',l,None)

def get_value(mem, idx):
    if mem[idx]['ok'] == True:
        return mem[idx]
    else:
        cp=mem[idx]
        cp['data'] = None
        return cp

def in_cache(mem_asso, mem_class, adresse):
    if get_value(mem_class,adresse)['ok']==False:
        return('miss', None)
    elif 'hit' in is_in(mem_asso, adresse):
        return('hit',mem_class[adresse]['data'])
    else:
        return('miss', None)

def in_cache_direct_mapped(mem_class, adresse):
    if mem_class[adresse%len(mem_class)]['ok']==True:
        return ('hit', mem_class[adresse%len(mem_class)]['data'])
    else:
        return('miss', None)
---------------------------------------------------
import random

def in_cache_direct_mapped_fixed(mem_class, adresse):
    ind=(bin(adresse)[-2:])
    if 'b' in ind:
        ind = ind[1:]
    ind = int(ind,2)
    tag = (bin(adresse)[2:].zfill(4))[:-2]
    if (mem_class[ind]['tag'])==int(tag,2):
        return ('hit',mem_class[ind]['data'])
    else:
        return ('miss', None)



def replace_random(mem_asso, mem):
    for i in range(len(mem)):
        if mem[i]['ok']==False:
            return i
    a=random.randrange(0,len(mem))
    return a




def add_fifo(fifo, valeur):
    if None in fifo:
        for i in range(len(fifo)):
            if fifo[i] == None:
                fifo[i] = valeur
                return fifo
    return fifo
'''    for i in range(len(fifo)):
        if i+1<len(fifo):
            fifo[i]=fifo[i+1]
        else:
            fifo[i]=valeur
    return fifo'''




def get_fifo(fifo):
    valeur=fifo[0]
    for i in range(len(fifo)-1):
        fifo[i]=fifo[i+1]
    fifo[len(fifo)-1]=None
    return fifo,valeur




def replace_fifo(mem, fifo):
    for i in range(len(mem)):
        if mem[i]['ok']==False:
            if None in fifo:
                add_fifo(fifo,i)
                return(i, fifo)
    temp,val=get_fifo(fifo)
    add_fifo(temp,val)
    return (fifo,val)




def update_lru(pile, valeur):
    cpt=0
    if valeur in pile:
        lmem=[]
        for i in range(len(pile)):
            if pile[i]==None:
                cpt=i
                break
            elif pile[i] != valeur:
                lmem.append(pile[i])
        lmem.append(valeur)
        lmem+=pile[cpt:]
        pile=lmem
    return pile


pile = [0, 3, 2, None]
print(update_lru(pile, 2))
