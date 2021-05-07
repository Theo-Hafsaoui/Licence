
"""
texte = "untexteadechiffrer" 
texte_dechiffre = ""
k = 1
c= 5
abcd = []
ascci = 97
for i in range(26):
    abcd.append(chr(97+i))
print(abcd)

for i in range(0, len(texte)):
        texte_dechiffre += abcd[((abcd.index(texte[i])*c) + k) %26] 
print(texte_dechiffre)
"""





texte_chiffre = "untexteadechiffrer" 
texte = ""
a = 17
b = 4
abcd = []

for i in range(26):
    abcd.append(chr(97+i))
print(abcd)

for i in range(len(texte)):
        texte += abcd[((abcd.index(texte_chiffre[i]) - b)//a) %26] 
        print(texte)

print("xxxx", texte)
