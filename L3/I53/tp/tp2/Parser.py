import scanner as sc
"""
Ex1:
    T={0,1,2,3,4,5,6,7,8,9,+,−}
    N={Expr}
    S=Expr
    Expr→Expr+Term|Expr-Term|Term
    Term→digit
    Todo mettre le truck correct
#ex2 et 3
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
"""
#a=sc.scan('5*5+3+4')
#print(expr(a))
"""
Exp -> Terme Reste_E
Reste_E -> + Terme Reste_E | - Terme Reste_E
Terme -> Facteur Reste_T
Reste_T -> * Facteur Reste_T | / Facteur Reste_T
fact -> digit | ( expr )
"""
i=0
def expr(ch):
  global i
  if term(ch) and rest_e(ch):
    return True
  else:
    print("Erreur syntax at:",ch[i])
    return False

def term(ch):
  return (fact(ch) and rest_t(ch))

def rest_t(ch):
  global i
  if (i>=len(ch)-1 or(ch[i][1]in("+","-",")")))and not (i==len(ch)-1 and ch[i][0]=="OP"):
    print(ch[i][1], end="", flush=True)
    return True
  elif ch[i][1]=='*' or ch[i][1]=='/':
    print(ch[i][1], end="", flush=True)
    i+=1
    if fact(ch):
      if rest_t(ch):
        return True
  return False

def rest_e(ch): 
  global i
  if i>=len(ch)-1 or(ch[i][1]in(")")):
    return True
  if ch[i][1]=='+' or ch[i][1]=='-':
    i+=1
    print(ch[i-1][1], end="", flush=True)
    if term(ch):
      if rest_e(ch):
        return True
  return False

def fact(ch):
  global i
  if i==len(ch)-1 and (ch[i][0]in("NB","PF")):
    return True
  if ch[i][0]=='NB':
    print(ch[i][1], end="", flush=True)
    i+=1
    return True 
  elif ch[i][0]=='PO':
    i+=1
    if expr(ch):
      if ch[i][0]=='PF':
        i+=1
        return True
  return False

#############################################
a=sc.scan('5*5+4')
(expr(a))
