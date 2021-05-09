from random import randrange


def init_ram_list (taille) :
    return taille * [0]




def fill_ram_random (RAM, N) :
    for i in range (N) :
        ind = randrange (len(RAM))
        don = randrange (1,256)
        RAM[ind] = don
    return RAM

def  fill_ram_place(RAM, N) :
    for i in range (N) :
        ind = randrange (len(RAM))
        
        RAM[ind] = ind
    return RAM

def get_value_list(RAM, N) :
    return (RAM[N])

def init_ram_dict(taille) :
    return {'taille ' : taille}


def fill_ram_random_dict (RAM, N) :
    i=0
    while i < N :
        
        ind = randrange (RAM['taille ']-1)
        
        if ind not in RAM :
            don = randrange (1,256)
            RAM[ind] = don
            i+=1
    return RAM

def fill_ram_place_dict (RAM, N) :
    i=0
    while i < N :
        
        ind = randrange (RAM['taille ']-1)
        
        if ind not in RAM :
            
            RAM[ind] = ind
            i+=1
    return RAM


def get_value_dict (RAM, N) :
    return (RAM.get(N,0))



def is_in(mem_asso,mot) :
    r = 'MISS'
    n = None
    if mot in mem_asso :
        r = 'HIT'
        

    t = (r,[])
    cpt = 0
    for i in mem_asso :
        if i == mot :
            n=cpt
            
        t[1].append (i == mot)
        cpt += 1
    t += (n,)
    return (t)

def get_value (mem, idx) :
    
    if idx > len(mem) or mem[idx]['ok'] == False :
        return ({'ok': False, 'data' : None})
    
    else :
        return (mem[idx])


def in_cache (mem_asso, mem_class, adresse) :
     

    if is_in (mem_asso, adresse)[0] == 'MISS' :
        return (('MISS' , None))
    
    else :
        v = get_value (mem_class, adresse)['ok']
        
        if v :
            return (('HIT', get_value (mem_class, adresse)['data']))
        else :
            return (('MISS' , None))

def in_cache_direct_mapped (mem_class, adresse) :
    id = bin (adresse)
    if len (id) < 4 :
        idx = int(id[-1],2)
    else :
        idx = int (id[-2:],2)
    
    print(idx)
    d = get_value (mem_class, idx)
    if d['ok'] :
        return (('HIT', d['data']))
    else:
        return (('MISS', None))

--------------------------------------------------
def in_cache_direct_mapped_fixed(mem_class, adresse):

    
    







        
        
        
    
    


    




