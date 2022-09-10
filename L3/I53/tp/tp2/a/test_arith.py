import sys
import Parser
################################
_scanner = 1
_parser = 1
_codegen = 1
_compilo = 1
#################################
test_scanner = ["32 + 5 / ( 9 - 3 * 12 )", "3-5-2", "3+(3-5*9)", "((3)", "3+", ")3(","2.3"," 2%4"]
test_parser =  [[('NOMBRE', 32), ('OP', '+'), ('NOMBRE', 5), ('OP', '/'), ('PAR_OUV', '('), ('NOMBRE', 9), ('OP', '-'), ('NOMBRE', 3), ('OP', '*'), ('NOMBRE', 12), ('PAR_FER', ')')]]
test_codegen =  [[('NOMBRE', 32), ('NOMBRE', 5), ('OP', '+')]]
test_compilo  = ['tests/exemple1.arith','tests/exemple2.arith','tests/exemple3.arith', 'tests/exemple4.arith']
#################################

import os

try:
    import Scanner
except:
    print("fichier Scanner.py absent")
    _scanner = 0

try:
    import Parser
except:
    print("fichier Parser.py absent")
    _parser = 0

try:
    import Codegen
except:
    print("fichier Codegen.py absent")
    _codegen = 0

try:
    import compilo
except:
    print("fichier compilo.py absent")
    _compilo = 0


if _scanner:
    input("=========================\nTest de la fonction scanner\n=========================\n")
    for case in test_scanner:
        print("==test case: '{}'  ==\n".format(case))
        print(Scanner.scanner(case))
    
if _parser:
    input("=========================\nTest de la fonction parser\n=========================\n")
    for case in test_parser:
        print("==test case: '{}'  ==\n".format(case))
        print(Parser.parser(case))
       
if _codegen:
    input("=========================\nTest de la fonction codegen\n=========================\n")
    for case in test_codegen:
        print("==test case: '{}'  ==\n".format(case))
        print(Codegen.codegen(case))


if _compilo:
    input("=========================\nTest du compilateur\n=========================\n")
    for case in test_compilo:
        os.system('rm a.out')
        print("==test case: '{}'  ==\n".format(case))
        os.system("python compilo.py {}".format(case))
        os.system("./a.out")
