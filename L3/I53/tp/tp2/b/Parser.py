import sys
tokens_list = ""
pos = 0
postfix_tokens = []

def parser(i):
    """
    Fonction qui va exécuter le premier expr(),
    et agir en fonction du résultat.
    """
    global tokens_list
    global pos
    tokens_list = i
    if expr():
        return postfix_tokens
    else:
        if pos >= len(tokens_list):
            sys.stderr.write("non: " + str(pos-1) + " " + str(tokens_list[pos-1]) + '\n')
        else:
            sys.stderr.write("non: " + str(pos) + " " + str(tokens_list[pos]) + '\n')
        exit(-1)

def expr():
    """
    Expr -> Terme Reste_E
    """
    return terme() and reste_e()

def terme():
    """
    Terme -> Facteur Reste_T
    """
    return facteur() and reste_t()

def facteur():
    global tokens_list
    global pos
    if pos >= len(tokens_list):
        return False
    if tokens_list[pos][0] == 'UNOP':
        r = tokens_list[pos]
        pos += 1
        if facteur():
            postfix_tokens.append(r)
            return True
        else:
            return False
    if tokens_list[pos][0] == 'BOOL':
        postfix_tokens.append(tokens_list[pos])
        pos += 1
        return True
    elif tokens_list[pos][0] == 'PO':
        pos += 1
        if expr():
            if pos < len(tokens_list) and tokens_list[pos][0] == 'PF':
                pos += 1
                return True
            else:
                return False
    else:
        return False

def reste_e():
    """
    Reste_E -> OU Terme Reste_E
             | epsilon

    Le if d'exception ne rentre en jeux que
    si la chaîne est fini(epsilon) ou qu'il
    rencontre ). Sinon il vérifie si il s'agit
    d'un operateur ou et agit comme le veut
    notre grammaire.
    """
    global tokens_list
    global pos
    if pos>=len(tokens_list) or(tokens_list[pos][1]==')'and tokens_list[pos-1][1]!=')'):
        return True
    elif tokens_list[pos][0] == 'BINOP' and tokens_list[pos][1] == 'OU':
        # si l'on tombe sur un opérateur OU
        r = tokens_list[pos]
        pos += 1
        if terme():
            postfix_tokens.append(r)
            return reste_e()
        else:
            return False
    else:
        return False

def reste_t():
    """
    Reste_T -> ET Facteur Reste_T
             | epsilon
    """
    global tokens_list
    global pos
    if pos >= len(tokens_list) or tokens_list[pos][0] == 'PF' or (tokens_list[pos][0] == 'BINOP' and
            tokens_list[pos][1] == 'OU'):
        return True
    elif tokens_list[pos][0] == 'BINOP' and tokens_list[pos][1] == 'ET':
        r = tokens_list[pos]
        pos += 1
        if facteur():
            postfix_tokens.append(r)
            return reste_t()
        else:
            return False
    else:
        return False
