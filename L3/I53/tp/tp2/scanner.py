##############################################
#
# scanner.py
# ----------
#
# Analyseur lexical d'expression arithmétique
#
# Nicolas Méloni
# I53 - Compilation et théorie des langages
# 02-10-2019
###############################################

'''
On utilise le lexique suivant:

NB --> [0-9]+
OP --> + | - | * | /
PO  --> (
PF  --> )
'''
def scan(s):
    l = []
    """Convertit la chaine de caracteres <s> en une liste d'unités
    léxicales de la forme (<type>, <valeur>). Retourne None en cas
    d'erreur et affiche le caractere fautif
    """
    i = 0
    dic={"+":"OP","-":"OP","*":"OP","/":"OP","(":"PO",")":"PF",}
    for ch in s:
        if(ch.isnumeric()):
            if len(l)>0 and l[-1][0]=="NB":
                l[-1][1]=str(l[-1][1])
                l[-1][1].append(ch)
                l[-1][1]=int(l[-1][1])
            else:
                l.append(("NB",int(ch)))
        elif(ch in dic):
            l.append((dic[ch],ch))
        elif(ch==" " or ch=="\n"):
            continue
        else:
            print("Lexical error at:",ch[i])
            return(-1)
        i+=1
    return l
print(scan("52+4"))
"""
if __name__ == '__main__':
    tests = [('123+-',[('NB',1),('NB',2),('NB',3),('OP','+'),('OP','-')]),
             ('(1+2)',[('PO','('),('NB',1),('OP','+'),('NB',2),('PF',')')])]
    for cas, resultat in tests:
        if scanner(cas) != resultat:
            print("Erreur cas: {}\n    sortie: {}\n  resultat: {}".format(cas, scanner(cas),resultat))
        else:
            print("ok")

"""