import numpy as np
Code=[]
########
#TP:MONSIEUR PITOUNE
########
#Codage de la source
#
#1/On peut l'envoyer avec des signaux de fumee binaire, avec pour chaque charatere
#un encodage en ascii
#
#2/T=3/8 E=2/8 S,D,I=1/8
#donc entropy= 3/8*log2((3/8))+2/8*log2(2/8)+1/8*log2(1/8)+1/8*log2(1/8)+1/8*log2(1/8)
#=2.15
#
#3/
def Str2Dic(txt):
    """
    Return a list with a dictonary of every letter
    of the string txt with for each the nb of
    occurence, and the len of txt
    """
    dic={}
    for i in txt:
        if i in dic:
            dic[i]+=1
        else:
            dic[i]=1
    return [[v for k,v in dic.items()],len(txt)]

def Entropy(l_i,nb_occurence):
    res=0
    for i in l_i:
        if i>0:
            pi=i/nb_occurence
            res+=pi*np.log2(pi)
    return -res
#4/Nos calcul sont correct
#5/ T=3 E=2 S,D,I=1 d'ou l'arbre
#    8
#   / \
#  5   3
# /\   /\
#3  2  2 1 I
#T  E /\
#   S 1 1 D

class Node:
    def __init__(self, att ,left=None, right=None):
        self.att=att#a list of occurence and letter
        self.left = left
        self.right = right


def Creat_Htree():
    l_i,nb_occurence=(TXT)
    root=Node(nb_occurence,None)
    return None

if __name__ == "__main__":
    TXT="TESTDETI"
    print(Str2Dic(TXT))
    l_i,nb_occurence=Str2Dic(TXT)
    entrop=Entropy(l_i,nb_occurence)
    print(entrop)
