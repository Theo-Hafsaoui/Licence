#question 1 fonction Python Reciproque(C) qui renvoie la cor­res­pon­dan­ce réciproque de celle passée en paramètre. 
def Lecture(nomfichier):
    dic={}
    sd=set()
    sa=set()
    fichier = open(nomfichier,"r")
    l = fichier.readlines()
    print(l)
    for i in l:
        if len(i)==4:
            print('ok')
            sd.add(i[0])
            sa.add(i[2])
            if i[0] in dic.keys():
                dic[i[0]]=dic[i[0]]|{i[2]}
            else:
                dic[i[0]]={i[2]}
        else:
            if i[0]=='>':
                sa.add(i[1])
            else:
                sd.add(i[0])
    return(sd,dic,sa)

#question2 fonction Python Reciproque(C) qui renvoie la cor­res­pon­dan­ce réciproque de celle passée en paramètre. 
def Reciproque(c):
    g=c[1]
    dic={}
    for clee in g:
        for val in g[clee]:
            dic[val]={clee}
    for clee in g:
        for val in g[clee]:
            dic[val]= dic[val] | {clee}
    return(c[2],dic,c[0])

#question3 fonction Python ImageDirecte(C,A) qui renvoie l'image directe d'une partie A de l'ensemble de départ de la cor­res­pon­dan­ce C passée en paramètre.
def ImageDirecte(C,A):
    return(C[1][A])

#question4 fonction Python ImageReciproque(C,B) qui renvoie l'image réciproque d'une partie B de l'ensemble d'arrivée de la cor­res­pon­dan­ce C passée en paramètre. 
def ImageReciproque(C,A):
    return(Reciproque(C)[1][A])


#question6 fonction Python EstFonction(C) qui décide (renvoie vrai ou faux) si la cor­res­pon­dan­ce C passée en paramètre est une fonction.
def EstFonction(c):
    for clee in c[1]:
        i=0
        for val in c[1][clee]:
            i+=1
            if i>1:
                return(False)
    return True
#question7 fonction Python EstApplication(C) qui décide si la cor­res­pon­dan­ce C passée en paramètre est une application. 
def EstApplication(c):
    if EstFonction(c):
        if len(c[0])==len(c[1]):
            return True
    else:
        return False

#question8 fonction Python Composer(g,f) qui renvoie la composition g∘f des deux cor­res­pon­dan­ces f et g passées en paramètres.
def Composer(g,f):
    

a=({'c', 'e', 'b', 'a'}, {'e': {'4'}, 'c': {'3'}, 'b': {'1'}, 'a': {'1'}}, {'3', '4', '1', '6', '5', '2'})
print(EstApplication(a))
