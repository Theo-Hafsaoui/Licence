def codegen(ul):
    """
    Écrit une chaîne de charactere qui sera lu par le compilo
    Retourne une erreur si la pile n'est pas fini
    """
    i = 1
    code = ""
    code += "#!/usr/bin/env python\n"
    for unit in ul :
        if unit[0] == 'BOOL' :
            code += "t"+str(i)+" = "+str(unit[1])+"\n"
            i += 1
        elif unit[0] == 'BINOP' :
            i -= 1
            if unit[1] == 'OU' :
                code += "t"+str(i-1)+" = t"+str(i-1)+" or "+"t"+str(i)+"\n"
            elif unit[1] == 'ET' :
                code += "t"+str(i-1)+" = t"+str(i-1)+" and "+"t"+str(i)+"\n"
        elif unit[0] == 'UNOP' :
            if unit[1] == 'NON' :
                code += "t"+str(i-1)+" = not t"+str(i-1)+"\n"
    if(i-1!=1):
        print("Stack Error")
        return -1
    code += "print(t"+str(i-1)+")\n"
    return code
