import scanner
import codegen
import Parser
import sys
import os

if __name__ == '__main__':
	if len(sys.argv) == 1:
		print("No argument")
		sys.exit()
	exp = sys.argv[1]
	Parse_ch = scanner.scan(exp)
	print(Parse_ch)
	RPN= ''.join(Parser.expr(Parse_ch))
	codegen.gen(RPN)
	os.system("python3 ./a.out")
