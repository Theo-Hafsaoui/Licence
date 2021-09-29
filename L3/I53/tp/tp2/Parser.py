import scanner as sc
"""
Ex1:
    T={0,1,2,3,4,5,6,7,8,9,+,−}
    N={Expr}
    S=Expr
    Expr→Expr+Term|Expr-Term|Term
    Term→digit
    Todo mettre le truck correct
"""
i=0

def expr(ch):
  global i
  if term(ch) and rest(ch):
    return True
  else:
    print("Erreur syntax at:",ch[i])
    return False

def rest(ch):
  global i
  if i==len(ch):
  	return True
  if ch[i][0]=='OP':
	  i+=1
	  if term(ch):
		  print(ch[i-2][1], end="", flush=True)
		  if rest(ch):
			  return True
  return False

def term(ch):
  global i
  if i==len(ch):
  	False
  if ch[i][0]=='NB':
	  print(ch[i][1], end="", flush=True)
	  i+=1
	  return True
  else:
    return False

a=sc.scan('5+2+3')
print(expr(a))
