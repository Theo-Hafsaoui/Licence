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
    s=s.split()
    l = []
    i = 0
    dic={"OU":"OP","ET":"OP","NON":"OP","(":"PO",")":"PF",}
    for ch in s:
        if(ch==" " or ch=="\n"):
            continue
        elif(ch[i]=='V' or ch[i]=='F'):
            l.append(("BOOL",ch))
        elif(ch in dic):
            l.append((dic[ch],ch))
        else:
            print("Lexical error at:",ch)
            return(-1)
    return l
"""
print()
if __name__ == '__main__':
    tests = [('123+-',[('NB',1),('NB',2),('NB',3),('OP','+'),('OP','-')]),
             ('(1+2)',[('PO','('),('NB',1),('OP','+'),('NB',2),('PF',')')])]
    for cas, resultat in tests:
        if scanner(cas) != resultat:
            print("Erreur cas: {}\n    sortie: {}\n  resultat: {}".format(cas, scanner(cas),resultat))
        else:
            print("ok")

"""
