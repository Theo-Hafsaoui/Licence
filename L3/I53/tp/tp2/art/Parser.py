import scanner as sc
"""
Exp -> Terme Reste_E
Reste_E -> + Terme Reste_E | - Terme Reste_E
Terme -> Facteur Reste_T
Reste_T -> * Facteur Reste_T | / Facteur Reste_T
fact -> digit | ( expr )
"""
i=0
RPN=[]
def expr(ch):
  #print("enter expr")
  global i
  if term(ch) and rest_e(ch):
    return RPN
  else:
    print("Erreur syntax at:",ch[i])
    return False

def term(ch):
  #print("enter term")
  return (fact(ch) and rest_t(ch))

def rest_t(ch):
  #print("enter rest_t")
  global i
  if i>=len(ch) or(ch[i][1]in['+','-',')']):
    return True
  elif ch[i][1]=='*' or ch[i][1]=='/':
    op=ch[i][1]#Important pour les parenthese
    i+=1
    if fact(ch):
      #print(op, end="", flush=True)
      RPN.append(op+' ')
      if rest_t(ch):
        return True
  return False

def rest_e(ch): 
  #print("enter rest_e")
  global i
  if i>=len(ch) or(ch[i][1]==')'and ch[i-1][1]!=')'):
    return True
  if ch[i][1]=='+' or ch[i][1]=='-':
    op=ch[i][1]#Important pour les parenthese
    i+=1
    if term(ch):
      #print(op, end="", flush=True)
      RPN.append(op+' ')
      if rest_e(ch):
        return True
  return False

def fact(ch):
  #print("enter fact")
  global i
  if i>=len(ch):
    return False
  if ch[i][0]=='NB':
    RPN.append(str(ch[i][1])+' ')
    i+=1
    return True 
  elif ch[i][0]=='PO':
    i+=1
    if expr(ch):
      if i<len(ch) and ch[i][0]=='PF':
        i+=1
        return True
  return False

#############################################
#print(expr(sc.scan("(2+4)*5")))

