"""
Ex1:
    T={0,1,2,3,4,5,6,7,8,9,+,−}
    N={Expr}
    S=Expr
    Expr→Expr+Term|Expr-Term|Term
    Term→digit
"""
def Epr():
    if Term()==1:
        return 1
    if Term()==1 and cc=='+' and expr():
        return 1
    else:
        return 0