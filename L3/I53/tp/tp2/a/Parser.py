import sys
tokens_list = ""
pos = 0
rpn = []

def parser(tokens):
    """
    exécute le premier expr(), et agit en fonction du résultat.
    En cas d'erreur il retourne celle ci dans la sortit d'erreur
    standart.
    """
    global tokens_list
    global pos
    tokens_list = tokens
    if expr():
        return rpn
    else:
        if pos >= len(tokens_list):
            sys.stderr.write("non: " + str(pos-1) + " " + str(tokens_list[pos-1]) + '\n')
        else:
            sys.stderr.write("non: " + str(pos) + " " + str(tokens_list[pos]) + '\n')
        exit(-1)

def expr():
    return terme() and reste_e()

def terme():
    return facteur() and reste_t()

def facteur():
    """
    Facteur -> NB | (Expr)
    """
    global tokens_list
    global pos
    if pos >= len(tokens_list):
        return False
    if tokens_list[pos][0] == 'NOMBRE':
        rpn.append(tokens_list[pos])
        pos += 1
        return True
    elif tokens_list[pos][0] == 'PAR_OUV':
        pos += 1
        if expr():
            if pos < len(tokens_list) and tokens_list[pos][0] == 'PAR_FER':
                pos += 1
                return True
    return False

def reste_e():
    """
    Reste_E -> * Terme Reste_E
             | / Terme Reste_E
             | epsilon

    Le if d'exception ne rentre en jeux que
    si la chaîne est fini(epsilon) ou qu'il
    rencontre ). Sinon il vérifie si il s'agit
    d'un operateur + ou - et agit comme le veut
    notre grammaire.
    """
    global tokens_list
    global pos
    if pos>=len(tokens_list) or(tokens_list[pos][1]==')'and tokens_list[pos-1][1]!=')'):
        return True
    elif tokens_list[pos][0] == 'OP' and (tokens_list[pos][1] == '+' or tokens_list[pos][1] == '-'):
        r = tokens_list[pos]
        pos += 1
        if terme():
            rpn.append(r)
            return reste_e()
    return False

def reste_t():
    """
    Reste_T -> * Facteur Reste_T
             | / Facteur Reste_T
             | epsilon

    Le comportement de reste_e ressemble a celui
    de reste_t a ceci pres qu'il doit laisser la
    main a celui ci si il rencontre un + ou -
    on profite dans la condition d'exceptions pour
    prendre en compte le cas de la parenthese fermante.
    """
    global tokens_list
    global pos
    if pos >= len(tokens_list) or tokens_list[pos][0] == 'PAR_FER' \
            or (tokens_list[pos][0] == 'OP' and \
            (tokens_list[pos][1] == '+' or tokens_list[pos][1] == '-')):
        return True
    elif tokens_list[pos][0] == 'OP' and (tokens_list[pos][1] == '*' or tokens_list[pos][1] == '/'):
        r = tokens_list[pos]
        pos += 1
        if facteur():
            rpn.append(r)
            return reste_t()
    return False
