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
import sys


'''
le lexique est le suivant:

NOMBRE --> [0-9]+
OP --> + | - | * | /
PAR_OUV  --> (
PAR_FER  --> )
'''
def scanner(s):
    """Convertit la chaîne de caracteres <s> en une liste d'unités
    lexicales de la forme (<type>, <valeur>). Retourne None en cas
    d'erreur et affiche le caractere fautif

    Le cas des nombres est un peut plus complexe car les token sont
    sous forme de tuple, aussi une réécriture complexe de token est 
    neccesaire, il s'agit d'une solution coûteuse mais qui permet
    de garder un 'for' qui rend le code plus comprehensible.

    ex: scanner((5+5))
    [('PAR_OUV','('),('NOMBRE',5),('OP','+'),('NOMBRE',5),('PAR_FER',')')]),
    """
    token = []
    i = 0
    dic={"+":"OP","-":"OP","*":"OP","/":"OP","(":"PAR_OUV",")":"PAR_FER",}
    for ch in s:
        if(ch.isnumeric()):
            if len(token)>0 and token[-1][0]=="NOMBRE":
                temp=str(token[-1][1])
                temp=temp+(ch)
                token=token[:-1]
                token.append(("NOMBRE",int(temp)))
            else:
                token.append(("NOMBRE",int(ch)))
        elif(ch in dic):
            token.append((dic[ch],ch))
        elif(ch==" " or ch=="\n"):
            continue
        else:
            sys.stderr.write("erreur: " + s[i] + " position " + str(i) + "\n")
            sys.stderr.flush()
            return None
        i+=1
    return token

