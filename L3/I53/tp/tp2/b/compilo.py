import Codegen
import Scanner
import Parser
import sys
import os

def main():
    """
    Écrit le A.out et retourne -1 en cas d'erreur
    """
    if len(sys.argv)==1:
        print("No argument")
        return -1
    fn = open(sys.argv[1], 'r')
    s = fn.read().strip()
    tokens = Scanner.scanner(s)
    if tokens != None :
        tokens_postfix = Parser.parser(tokens)
        code = Codegen.codegen(tokens_postfix)
        f = open("a.out", 'w')
        f.write(code)
        f.close()
        os.chmod('a.out', 0o755)
    else:
        return -1

if __name__ == '__main__':
    main()
    