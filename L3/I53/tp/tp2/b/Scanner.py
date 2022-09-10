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
On utilise le lexique suivant:

NOMBRE --> VRAI FAUX
BINOP --> ET | OU 
UNOP --> NON
PAR_OUV  --> (
PAR_FER  --> )
'''

def scanner(s):
    """
    Ici une plus grande liberté est possible en tout cas dans les noms
    On considérera que le"VRAI OU FAUX" est valide , et que "VRAIOUFAUX"
    ne l'est pas. Pas de dictionnaire et on realise deja une partie du
    travaille de genration de code en traduisant
    """
    list_ul = []
    ul = s.replace('(', ' ( ').replace(')', ' ) ').split()
    for u in ul :
        if u == "VRAI" or u == "FAUX":
            list_ul.append(("BOOL", u=="VRAI"))
        elif u == "OU" or u == "ET":
            list_ul.append(("BINOP", u))
        elif u == "NON":
            list_ul.append(("UNOP", u))
        elif u == '(' : 
            list_ul.append(('PO', '('))
        elif u == ')' : 
            list_ul.append(('PF', ')'))
        else:
            sys.stderr.write("erreur: " + str(u) + "\n")
            sys.stderr.flush()
    return list_ul

if __name__ == '__main__':
    tests = [("VRAI OU FAUX", [('BOOL', True), ('BINOP', 'OU'), ('BOOL', False)])
            ,("VRAI ET VRAI", [('BOOL', True), ('BINOP', 'ET'), ('BOOL', True)])
            ,("NON (VRAI)",   [('UNOP', 'NON'), ('PO', '('), ('BOOL', True), ('PF', ')')])]
    for cas, resultat in tests:
        if scanner(cas) != resultat:
            print("Erreur cas: {}\n    sortie: {}\n  resultat: {}".format(cas, scanner(cas),resultat))
        else:
            print("ok")
