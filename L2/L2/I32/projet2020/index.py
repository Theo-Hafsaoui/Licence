# coding: utf-8
#!/bin/sh
import cgitb
cgitb.enable()
Page = """
<!doctype html>
<html lang="fr">
<head>
<meta charset="utf-8">
<title>Le formulaire</title>
</head>
<body>
<form action="views.py" method="post">
<label>Nom</label> : <input type="text" name="nom" />
<label>Prenom</label> : <input type="text" name="prenom" />
<input type="submit" value="Envoyer" />
</form>
</body>
</html>"""
print(Page)