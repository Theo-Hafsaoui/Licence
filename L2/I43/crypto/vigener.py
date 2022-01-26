from cesar import *
def Vchiffrement(m,k):
    cm=''
    for i in range(len(m)):
        chi=ord(m[i])
        ki=ord(k[(i%len(k))])
        ki=(ki-97)%26
        if(ord(m[i])!=32):
            cm+=chr((((chi+ki)-97)%26)+97)
    return cm

def dechiffrement(m,k):
    cm=''
    for i in range(len(m)):
        chi=ord(m[i])
        ki=ord(k[(i%len(k))])
        ki=(ki-97)%26
        if(ord(m[i])!=32):
            cm+=chr((((chi-ki)-97)%26)+97)
    return cm

def pgcd(l):
    for i in range(1,len(l)):
        while(l[i-1]!=l[i]):
            if(l[i-1]>(l[i])):
                l[i-1]=(l[i-1]-l[i])
            else:
                l[i]=l[i]-l[i-1]
    return (l[len(l)-1])

def decoupe(ch,k):
    l=[]
    for i in range(1,(len(ch)//k)+1):
        l.append(ch[(i-1)*k:i*k])
    return l

def Motif3(m):
    dic={}
    dici={}
    lvalue=[]
    for j in range(3):
        mc=m[j:]
        for i in range((len(mc)//3)+1):
            if(ord(mc[i])!=32):
                ki=mc[i*3:(i+1)*3]
                if not(ki in dic):
                    dic[ki]=1
                    dici[ki]=[j+i*3]
                    lvalue.append(ki)
                else:
                    if not(i*3-1 in dici[ki]):
                        dic[ki]+=1
                        dici[ki]+=[j+i*3]
    a=(max(dic, key=dic.get))#max de motife
    l=[]
    for i in lvalue:
        if dic[i]==dic[a]:
            l.append((i,dici[i]))
    print(l)
    return(l)

def distance(l):
    temp=0
    dis=[]
    l.sort()
    for i in range(len(l)):
        for j in range(i,len(l)):
            if l[i]==0:
                temp=l[j]+1
            else:
                temp=l[j]-l[i]
            if not temp in dis:
                dis.append(temp)
    if 0 in dis:
        dis.remove(0)
    if 1 in dis:
        dis.remove(1)
    dis.sort()
    return dis


def is_prime(n):#voler sur internet la flemme de fair un test de primaliter
  if n == 2 or n == 3: return True
  if n < 2 or n%2 == 0: return False
  if n < 9: return True
  if n%3 == 0: return False
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n % f == 0: return False
    if n % (f+2) == 0: return False
    f += 6
  return True    

def Primediv(n):
    l=[]
    for i in range(1,n+1):
        if n%i==0 and is_prime(i):
            l.append(i)
    return l

def sauteMOuton(ch,k):#on utulise l'analyse frequentielle de cesare pour finir le reste
    l=[]
    for i in range((len(ch)//k)-1):
        temp=''
        for j in range((len(ch))//5+1):
            if((j*k+i)<len(ch)):
                temp+=ch[(j)*k+i]
        l.append(temp)
    return l

def MoutonSauteur(cm,l,k):
    sv=cm
    cm=list(cm)
    for i in range((len(cm)//k)-1):
        for j in range(len(l[i])):
            cm[j*k+i]=l[i][j]
    cm=''.join(cm)
    return(cm)

def Keysize(cm):
    Lp=Motif3(cm)
    l_size=[]
    for i in range(len(Lp)):
        dis=distance(Lp[i][1])
        pg=pgcd(dis)
        pg=Primediv(pg)
        for j in range(len(pg)):
                l_size.append(pg[j])
    l_size.sort()
    key=max(set(l_size), key = l_size.count)
    return key

def MoutonTransform(l,e):
    for i in range(len(l)):
        l[i]=CFReq(l[i],e)

def MoutonMalin(cm,k,e):#test une conversion
    l_cesare=sauteMOuton(cm,k)
    MoutonTransform(l_cesare,'e')#analysefreq de cesare sur liste
    cm=MoutonSauteur(cm,l_cesare,k)
    return cm


def Keyffiche(k,cm,m):
    key=''
    for i in range((k)):
        i1=ord(cm[i])-97
        i2=ord(m[i])-97
        diff=(i1-i2)%26
        key+=chr(diff+97)
    return key

def VFReq(cm,e):
    Key_size=Keysize(cm)
    print(Key_size)
    c=(MoutonMalin(cm,Key_size,e))
    print(c)
    print('~~~~~~~~~')
    print(Keyffiche(Key_size,cm,c))



        
#------------------
cm='le kgb renait le capitlisme perit'
m='ilprendsasacocherempliedepapiersdiversdelivresdemagazinesdecrayonslepoidsdemesconnaissancescommeilaimedireenfaitlaplupartdeslivresnontjamaiseteouvertslespapierssontpourlaplupartdesnotesprisessurlevifdepuislachatdecettesacocheetsontplusprochesdeladecompositionmaisparfoisilmetlenezdedansetsamusedavoirunjoureudesideesaussigenialesunevoiturevenaitdarriverdelautrecotedelabarriereunepersonnesortitunmilitaireiletaitcommedanslesfilmsdeguerrepensadavidlesdecorationsremplissaientlavantdesavesteilsapprochadelavoitureousetrouvaitdavidlechauffeurouvritlafenetrecelaressemblaitauxgrosordinateursquedavidavaitpuvoirdansdesfilmsdesciencefictionbeaucoupdepetiteslumieresindiquaientquiletaitenfonctionalabaseunesortedaquariumavaiteteinstalletoutautourcertainementlesystemederefroidissementcardesbullesmontaientsanscessepreuvequeleauetaitenebullitionsoudaindavidrestabouchebeeunevoixcaverneusesortiedesecransouvenaitdesafficherlemotpreludelascenseurdemarratoutseulapresquelaportesesoitfermeeildescendaitilnarretaitpasdedescendrepuisilsarretaenfinlaportesouvritetdavideutlastupeurdesaviedevantluisedeployaituncomplexeinformatiqueunevingtainedepersonnessedeplacaientdunpostealautreregardantaupassagelesecransgeantsmurauxsituesaufonddelasalleilyavaitbienunecinquantainedordinateurscinqecransgeantsetsitueentrelesecransgeantsetlesordinateursunemachinerieimpressionnantelascenseurdemarratoutseulapresquelaportesesoitfermeeildescendaitilnarretaitpasdedescendrepuisilsarretaenfinlaportesouvritetdavideutlastupeurdesaviedevantluisedeployaituncomplexeinformatiqueunevingtainedepersonnessedeplacaientdunpostealautreregardantaupassagelesecransgeantsmurauxsituesaufonddelasalleilyavaitbienunecinquantainedordinateurscinqecransgeantsetsitueentrelesecransgeantsetlesordinateursunemachinerieimpressionnante'
print(Vchiffrement(cm,"Staline"))
