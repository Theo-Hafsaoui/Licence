def codegen(ul):
    """
    Écrit une chaîne de charactere qui sera lu par le compilo
    Retourne une erreur si la pile n'est pas fini
    """
    i = 1
    code = ""
    code += "#!/usr/bin/env python\n"
    for unit in ul :
        if unit[0] == 'NOMBRE' :
            code += "t"+str(i)+" = "+str(unit[1])+"\n"
            i += 1
        elif unit[0] == 'OP' :
            i -= 1
            code += "t"+str(i-1)+" = t"+str(i-1)+" "+unit[1]+" "+"t"+str(i)+"\n"
    if(i-1!=1):
        print("Stack Error")
        return -1
    code += "print(t"+str(i-1)+")\n"
    return code
