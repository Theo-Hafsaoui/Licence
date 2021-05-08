
cgitb.enable()#voir tes faute sur ta page html 
# cette ligne recupere les information de ton formulaire de la page precedente 
form=cgi.FieldStorage()
#cette ligne te permet de prendre une des variable de ton formulaire 
#transition html en pyhton 
nom_groupe=form.getvalue('code') 
#------------------connection----------
hostname = 'localhost'  
username = 'postgres'
password = ''
database = 'postgres'
TableTest1 = "projet.client"

myConnection = psycopg2.connect( host=hostname, user=username,
password=password, dbname=database )
if myConnection :
    cursor =myConnection .cursor()
# ----------------pour un selcet -----------------------

# Requete SQL
reqmaxid_client = ('SELECT * from {}'.format(TableTest1))
# Exécution de la requête
cursor.execute(reqmaxid_sqlclient)
# Sortie à l'écran
#data=((nom,prenom,age),(nom,prenom,age).....)
    data = cursor.fetchall()    
#pour afficher on fais comme sa
print(f" le nombre de client depuis sont ouverture est :{data[0][0]}")
#tu peux aussi utiliser pour faire des session si tu vois pas commment faire je peux taider 

#----------------pour un insert -------------------------------------------------    
# Requete SQL
sqlclient = """INSERT INTO projet.client (nom,prenom,age)
VALUES (%s,%s,%s)"""
# Exécution de la requête
    cursor.execute(sqlclient )
# Sortie à l'écran
nom="jean"
prenom='toto'
age=18
value = (nom,prenom,age)
# Exécution de la requête
cursor .execute(sqlclient, value)
# validé la modification
myConnection .commit()
count = cursor .rowcount
#------------------------------

