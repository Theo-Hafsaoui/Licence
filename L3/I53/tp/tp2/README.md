# TP Meloni

TPs de théorie des langages de L3 (Meloni)

```
Expr -> Terme Reste_E
Reste_E -> + Terme Reste_E
         | - Terme Reste_E
         | epsilon
Terme -> Facteur Reste_T
Reste_T -> * Facteur Reste_T
         | / Facteur Reste_T
         | epsilon
Facteur -> NB | (Expr)
```

```
Expr -> Terme Reste_E
Reste_E -> OU Terme Reste_E
         | epsilon
Terme -> Facteur Reste_T
Reste_T -> ET Facteur Reste_T
		 | epsilon
Facteur -> NOT Facteur
		 | VRAI | FAUX
		 | (Expr)
```

Le script `./test.sh` est très simple. On lui donne une expression (pas un fichier) en argument,
et il renvoie la liste des unités lexicales non postfix, compile l'expression, renvoie `a.out`,
et exécute d'abord l'expression de base avec `bc`, puis exécute `a.out`.
Cela permet de comparer l'exactitude de `a.out`.
