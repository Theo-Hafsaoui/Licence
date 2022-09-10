from logging import raiseExceptions
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
import astropy as ap
from astropy import units as u
from astropy.coordinates import SkyCoord
from astropy.coordinates import Distance
import csv
import copy
import math as math

"""
* Introduction :

Dans ce TP, nous allons expérimenter avec les données de l'article
"How much a galaxy knows about its large-scale environment?: An information theoretic perspective" analysé en TD.
Comme nous l'avons vu en TD, cet article a révélé une corrélation intéressante entre type morphologique et emplacement des galaxies à l'aide de l'information mutuelle. Nous allons explorer cette relation un peu plus, notamment en considérant des variables additionelles afin de calculer des informations d'interaction.

Les variables additionelles que nous utiliserons sont :
        - la densité (c.a.d combien de galaxies se trouvent autour de la galaxie considérée, dans un rayon donné)
        - le redshift
        - la masse des étoiles de la galaxie
        - l'age moyen des étoiles de la galaxie
        - la métallicité

Puisque l'article
"How much a galaxy knows about its large-scale environment?: An information theoretic perspective" 
a trouvé que la corrélation est la plus forte entre type et emplacement en considérant des petits emplacements locaux de ~10 Mpc, nous allons aussi considérer des emplacements de 10 Mpc de côté. Pour calculez les densités, nous considérerons également des voisinages de 10 Mpc de rayon.

* Fonctionnement du TP :

Il vous est fourni ci-dessous un squelette de code qui vous permettra de vous concentrer sur les points les plus intéressants du TP. Certaines fonctions sont fournies, notamment les fonctions de chargement des données et sélection des galaxies. D'autres fonctions attendent d'être complétées par vos soins.

Attention : plusieurs fonctions sont incomplètes et sont donc commentées. Vous compléterez ces fonctions au fur et à mesure de l'avancement du TP (et donc il faudra les dé-commenter).

Les données ont été récupérées depuis le serveur de la mission d'observation SDSS (http://skyserver.sdss.org/dr12/en/tools/search/sql.aspx). Elles sont fournies dans un fichier CSV. Des fonctions sont fournies pour charger et manipuler ces données, vous n'avez donc pas besoin de toucher à ce fichier, mais vous pouvez bien sûr y jeter un oeil si vous êtes curieux.

* Compte-rendu de TP :

Le TP se fait en binôme.

Il vous sera demandé d'uploader sur Moodle un compte-rendu de TP par binôme, au format PDF. Il est fortement recommandé de le préparer au fur et à mesure du TP et d'utiliser tout temps supplémentaire pour vous relire et peaufiner un minimum la présentation.

Le compte-rendu doit contenir vos résultats et les réponses aux questions posées dans l'énoncé du TP. Il doit servir à démontrer votre réflexion et votre compréhension. Un bon compte-rendu répond aux questions de manière concise mais complète : ne cachez pas votre travail et le résultat de vos réflexions, mais n'essayez pas non plus d'étaler vos connaissances pour éblouir.

Attention : Tout compte-rendu mal formaté et difficile à lire sera recalé.
Attention : Veillez à ce que vos deux noms apparaissent clairement en tête du compte-rendu.
"""

"""
Les fonctions suivantes sont fournies et ne nécessite pas de modification. Vous pouvez en regarder le fonctionnement si vous êtes curieux.
Il est recommandé d'examiner la classe Galaxy car elle va être très utile.
"""

class Galaxy:
    def __init__(self, point, type, logMass, age, metallicity):
        self.point = point              #coordonnées [ascension, déclinaison, redshift]
        self.type = type                #0: elliptical, 1: spiral
        self.logMass = logMass          #mass (log) des étoiles de la galaxie
        self.age = age                  #age moyen des étoiles de la galaxie
        self.metallicity = metallicity  #métallicité moyenne des étoiles de la galaxie

def load_data(filepath='Skyserver_SQL4_23_2019 5_45_40 PM.csv'):
    with open(filepath) as f:
        line = f.readline().replace('\n','')
        fields = line.split(',')

        line = f.readline().replace('\n','')

        galaxies = []

        while line:
            ra, dec, z, cx, cy, cz, spiral, elliptical, uncertain, mag1, absmag, logMass, age, metallicity = line.split(',')
            ra = float(ra)
            dec = float(dec)
            z = float(z)
            cx = float(cx)
            cy = float(cy)
            cz = float(cz)
            spiral = int(spiral)
            elliptical = int(elliptical)
            uncertain = int(uncertain)
            if z<0:
                line = f.readline().replace('\n','')
                continue

            point = (ra, dec, z)

            type = -1
            if elliptical:
                type = 0
            elif spiral:
                type = 1

            galaxies += [Galaxy(point, type, logMass, age, metallicity)]

            line = f.readline().replace('\n','')

    return galaxies

def pts_to_scatter_pts(list_pts):
    xs = []
    ys = []
    zs = []
    for x, y, z in list_pts:
        xs += [x]
        ys += [y]
        zs += [z]
    return np.array(xs), np.array(ys), np.array(zs)

def make_catalog(list_rdz):
    ra, dec, z = pts_to_scatter_pts(list_rdz)
    #print ("z range: ", min(z), max(z))
    distances = Distance(z=z)
    #print ("distance range: ", min(distances), max(distances))
    catalog = SkyCoord(
        ra=ra * u.degree, dec=dec * u.degree, distance=distances)
    return catalog

def select_cube(galaxies, radius=0):
    """
    Sélection des galaxies se trouvant dans le cube d'espace étudié.
    Un buffer autour de ce cube peut être défini afin de calculer des densités correctes aux bords du cube.
    """
    points = [g.point for g in galaxies]
    c_coords = make_catalog(points)
    galaxies_cube = []
    galaxies_buffer = []
    for g, c in zip(galaxies, c_coords):
        if radius != 0:
            if c.cartesian.x >= (-400 - radius) * u.Mpc and c.cartesian.x <= (-100 + radius) * u.Mpc\
                    and c.cartesian.y >= (-100 - radius) * u.Mpc and c.cartesian.y <= (100 + radius) * u.Mpc\
                    and c.cartesian.z >= (5-radius) * u.Mpc and c.cartesian.z <= (205 + radius) * u.Mpc:
                if c.cartesian.x >= -400 * u.Mpc and c.cartesian.x <= -100 * u.Mpc\
                        and c.cartesian.y >= -100 * u.Mpc and c.cartesian.y <= 100 * u.Mpc\
                        and c.cartesian.z >= 5 * u.Mpc and c.cartesian.z <= 205 * u.Mpc:
                    galaxies_cube += [g]
                else:
                    galaxies_buffer += [g]
        else:
            if c.cartesian.x >= -400 * u.Mpc and c.cartesian.x <= -100 * u.Mpc\
                    and c.cartesian.y >= -100 * u.Mpc and c.cartesian.y <= 100 * u.Mpc\
                    and c.cartesian.z >= 5 * u.Mpc and c.cartesian.z <= 205 * u.Mpc:
                galaxies_cube += [g]
    return galaxies_cube, galaxies_buffer

def compute_densities(galaxies, catalog, radius):
    """
    Calcule la densité pour chaque galaxie : nombre de galaxies voisines dans un voisinage de rayon 'radius'

    galaxies: catalogue of galaxies
    catalog: catalogue of galaxies in the cube + in the buffer space of size radius
    radius: neighbourhood (in Mpc), type float
    """
    idxc, idxcatalog, d2d, d3d = catalog.search_around_3d(galaxies, radius * u.Mpc)
    densites = []
    for i in range(0, len(galaxies)):
        ind_i = np.where(idxc == i)
        densites += [ind_i[0].size - 1]
    return densites

def save_galaxies(galaxies, emplacements, densites):
    with open('cube.csv', mode='w') as cube_file:
        cube_writer = csv.writer(cube_file, delimiter=',', lineterminator='\n')

        for g, e, d in zip(galaxies, emplacements, densites):
            cube_writer.writerow([g.point[0], g.point[1], g.point[2], g.type, g.logMass, g.age, g.metallicity, e, d])

        print("cube sauvegardé")

def load_galaxies(csv_file):
    galaxies = []
    emplacements = []
    densites = []

    with open(csv_file) as f:
        line = f.readline().replace('\n','')

        while line:
            ra, dec, z, type, logMass, age, metallicity, emplacement, densite = line.split(',')
            ra = float(ra)
            dec = float(dec)
            z = float(z)
            type = int(type)
            logMass = float(logMass)
            age = float(age)
            metallicity = float(metallicity)
            emplacement = int(emplacement)
            densite = float(densite)

            point = (ra, dec, z)
            galaxies += [Galaxy(point, type, logMass, age, metallicity)]
            emplacements += [emplacement]
            densites += [densite]

            line = f.readline().replace('\n','')

    return galaxies, emplacements, densites

def plot_galaxies(galaxies, coords, colors=np.array([])):

    N = 1000 # N détermine combien de galaxies seront affichées. Sa valeur peut être réduite si l'ordinateur peine.

    inds = list(range(0,len(galaxies)))
    np.random.shuffle(inds)
    inds = inds[:N]

    galaxies_disp = [galaxies[i] for i in inds]
    coords_disp = [coords[i] for i in inds]

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    if colors.size:
        c_x = u.quantity.Quantity([c.cartesian.x for c in coords_disp])
        c_y = u.quantity.Quantity([c.cartesian.y for c in coords_disp])
        c_z = u.quantity.Quantity([c.cartesian.z for c in coords_disp])

        colors_disp = [colors[i] for i in inds]

        ax.scatter(c_x, c_y, c_z, c=colors_disp, marker='.', cmap='hsv', alpha=0.75)

    else:
        """Par défaut, la couleur représente le type morphologique"""
        c_x = u.quantity.Quantity([c.cartesian.x for g, c in zip(galaxies_disp, coords_disp) if g.type == 0])
        c_y = u.quantity.Quantity([c.cartesian.y for g, c in zip(galaxies_disp, coords_disp) if g.type == 0])
        c_z = u.quantity.Quantity([c.cartesian.z for g, c in zip(galaxies_disp, coords_disp) if g.type == 0])
        ax.scatter(c_x, c_y, c_z, c='b', marker='.')
        print(len(c_x), " galaxies elliptiques")
        c_x = u.quantity.Quantity([c.cartesian.x for g, c in zip(galaxies_disp, coords_disp) if g.type == 1])
        c_y = u.quantity.Quantity([c.cartesian.y for g, c in zip(galaxies_disp, coords_disp) if g.type == 1])
        c_z = u.quantity.Quantity([c.cartesian.z for g, c in zip(galaxies_disp, coords_disp) if g.type == 1])
        ax.scatter(c_x, c_y, c_z, c='r', marker='.')
        print(len(c_x), " galaxies spirales")

    plt.show()

def calcule_emplacement_discretise(liste_coords):
    """
    Cette fonction calcule l'emplacement discrétisé à partir des coordonnées cartésiennes des galaxies.

    Elle prend en entrée une liste de coordonnées, pour chaque galaxie. Ces coordonnées sont sous la forme d'un object SkyCoords de la librairie AstroPy. On peut accéder facilement aux coordonnées cartésiennes ainsi : liste_coords[galaxie].cartesian.x, liste_coords[galaxie].cartesian.y, et liste_coords[galaxie].cartesian.z

    La fonction renvoie une liste d'emplacements pour toutes les galaxies. Les emplacements sont identifiés par un indice i.
    """

    taille_case = 10.

    liste_emplacements = []

    for c in liste_coords:
        # 1) discrétisation de chaque coordonnée
        x = int(np.floor((c.cartesian.x.value + 400) / taille_case))
        y = int(np.floor((c.cartesian.y.value + 100) / taille_case))
        z = int(np.floor((c.cartesian.z.value - 5) / taille_case))

        # 2) conversion en 1D
        ind = x + int(np.ceil((300/taille_case))) * (y + int(np.ceil((200/taille_case))) * z)

        liste_emplacements += [ind]

    print(len(set(liste_emplacements)))

    return liste_emplacements


def prepare_galaxies():
    """
    Cette fonction charge les galaxies de la portion de l'espace qui nous intéresse, et pré-calcule leurs coordonnées cartésiennes, leur emplacement discrétisé, et leur densités.
    Elle renvoie : une liste d'objets Galaxy (voir class plus haut), une liste de coordonnées (objet SkyCoords de la librairie AstroPy), une liste d'emplacements, et une liste de densités. Les coordonnées coords[i], emplacement emplacements[i], et densité densites[i] correspondent à la galaxie cube[i].
    """
    #galaxies = load_data()
    #print(len(galaxies), " galaxies au total")
    #neighbourhood = 10
    #cube, buffer = select_cube(galaxies, neighbourhood)
    cube, emplacements, densites = load_galaxies("cube.csv")
    print(len(cube), " galaxies selectionnees")
    #print(len(buffer), " galaxies dans le buffer")
    points = [g.point for g in cube]
    coords = make_catalog(points)
    #emplacements = calcule_emplacement_discretise(coords)
    #points_buffer = [g.point for g in buffer]
    #coords_catalog = make_catalog(points+points_buffer)
    #densites = compute_densities(coords, coords_catalog, neighbourhood)
    #save_galaxies(cube, emplacements, densites)
    return cube, coords, emplacements, densites

"""
EXERCICE 1 : Propriétés des galaxies et définition des variables
========================================================================

La fonction `prepare_galaxies` ci-dessus charge les galaxies avec leurs
propriétés (voir la classe Galaxy) et leurs coordonnées cartésiennes.
Elle pré-calcule aussi leur emplacement discrétisé et leur densité.
Vous n'avez donc pas besoin de vous inquiéter de ces calculs.

1) La fonction main() ci-dessous demontre quelques manières d'appeler
la fonction d'affichage afin de visualiser les galaxies dans l'espace
ainsi que certaines de leurs propriétés en couleur.

Visualisez à l'aide de cette fonction d'affichage chacune des variables
qui seront utilisées lors de ce TP, à savoir :
    - le type morphologique
    - la densité
    - le redshift
    - la masse des étoiles de la galaxie
    - l'age moyen des étoiles de la galaxie
    - la métallicité

Incluez les plots à votre compte-rendu et commentez brièvement vos
observations et leur utilité pour la suite de l'analyse.
Observez/vérifiez en particulier les points suivants :
- Y a t'il des corrélations entre certaines propriétés ?
- Regardez en particulier la corrélation entre chaque propriété et l'emplacement :  les galaxies voisines ont elles les mêmes propriétés ?

2) Comme la plupart de ces variables sont continues, nous allons avoir
besoin de les discrétiser pour obtenir les variables discrètes à utiliser pour
calculer les informations mutuelles.

    a) Quel type de discrétisation (échantillonnage ou quantification)
    faut-il effectuer ? Pourquoi ?

#############################################
    Quantification car il s'agit de maniere fondamental d'un signal discret mais 
    qui vint bien sur du relle donc avec beaucoup de precision qui complexifie 
    inutilement notre travaille
#############################################

    b) Calculez et affichez les histogrammes pour chaque variable initiale
    (uniquement les variables continues !).
    Incluez les histogrammes à votre compte-rendu. Décrivez / commentez
    les brièvement, en vous concentrant sur ce qui influencera votre
    choix de méthode de discrétisation.

    c) Il existe plusieurs manières de discrétiser les données, comme
    vu en cours. Pour chaque propriété, sélectionnez au moins 2 méthodes possibles,
    en expliquant et en justifiant votre choix, et appliquez les.
    Il est recommandé de vous aider de la fonction `numpy.digitize`.
    Calculez et affichez les nouveaux histogrammes et
    nouvelles visualisations 3D.
    Comparez les histogrammes avant et après discrétisation :
    les distributions ont elles changé significativement,
    ou bien ont elles été préservées ?

    d) Procédez à un choix de méthode de discrétisation finale, pour
    chacune des propriétés (continues) des galaxies. Expliquez vos choix.
"""

def main():
    galaxies, coords, emplacements, densites = prepare_galaxies()
    print("galaxies chargées")
    #"""affichage de l'emplacement discrétisé"""
    #emp = np.array(emplacements)
    #emp = (emp - min(emp)) / (max(emp) - min(emp))
    """affichage de l'emplacement discrétisé"""
    colors = np.array(emplacements)
    colors = (colors - min(colors)) / (max(colors) - min(colors))
    #for i in galaxies:
    #    print(i.age)
    """affichage de age"""
    #colors = np.array([k.age for k in galaxies])
    #colors = (colors - min(colors)) / (max(colors) - min(colors))
    """affichage de metallicity"""
#    colors = np.array([k.metallicity for k in galaxies])
#    colors = (colors - min(colors)) / (max(colors) - min(colors))
    """affichage de masse"""
    #mass = np.array([k.logMass for k in galaxies])
    #mass = (colors - min(colors)) / (max(colors) - min(colors))
    """affichage du redshift"""
    #l_redshift=[g.point[2] for g in galaxies]
    #double_proba=[]
    #for i,j,k in zip(l_redshift,colors,mass):
    #    double_proba.append((i,j,k))
    #print(calcule_entropy(calcule_distribution_proba(double_proba)))
    #affichage_histogramme(l_redshift)
    #l_redshift=disc_moy(l_redshift,5)
    #print("len=",max(l_redshift))
    #affichage_histogramme(l_redshift,[1,2,3,4,5,6,7,8,9,10])
    #colors = np.array()
    #colors = (colors - min(colors)) / (max(colors) - min(colors))
    #colors = abs(1-colors)
    """affichage des densités"""
    #colors = np.array(densites)
    #colors = (colors - min(colors)) / (max(colors) - min(colors))
    """affichage du type morphologique"""
    #l_type=[k.type for k in galaxies]
    #affichage_histogramme(l_type)
    #colors = np.array(l_type)
    #plot_galaxies(galaxies, coords, colors)
    #l_type=[k.type for k in galaxies]
    #l_redshift=[g.point[2] for g in galaxies]
    #colors = np.array(emplacements)
    #colors = (colors - min(colors)) / (max(colors) - min(colors))
    #print(calcule_information_interaction(l_type,l_redshift,colors))
#######################################################################################################################################
#EX 2
    #disc_red=[g.point[2] for g in galaxies]
    #morph=[k.type+1 for k in galaxies]
    #print("NMI avec red et morph=",calcule_NMI(disc_red,morph))
#######################################################################################################################################
#EX 3
    met = np.array([k.metallicity for k in galaxies])
    met = (met - min(met)) / (max(met) - min(met))
    mass = np.array([k.logMass for k in galaxies])
    mass = (mass - min(mass)) / (max(mass) - min(mass))
    disc_red=[g.point[2] for g in galaxies]
    morph=[k.type+1 for k in galaxies]
    emp = np.array(emplacements)
    emp = (emp - min(emp)) / (max(emp) - min(emp))
    ds = np.array(densites)
    ds = (ds - min(ds)) / (max(ds) - min(ds))
    print("red II=",calcule_information_interaction(emp,disc_red,morph))
    print("mass II=",calcule_information_interaction(emp,mass,morph))
    print("dens II=",calcule_information_interaction(emp,ds,morph))
    print("met II=",calcule_information_interaction(emp,met,morph))


def disc_quantils(liste_valeurs_propriete,nb_class):
    """
    Cette fonction prend en entrée une liste des valeurs d'une propriété pour toutes les galaxies
    Elle discrétise avec les methode des quantils est renvoie une liste compris entre
    0 et nb_class
    """
    liste_valeurs_propriete_cp=copy.deepcopy(liste_valeurs_propriete)
    liste_valeurs_propriete_cp.sort()
    l=[]
    q=len(liste_valeurs_propriete_cp)//nb_class
    for i in range(len(liste_valeurs_propriete)//nb_class*nb_class):#legere perte d'informations mais negligable
        l.append(i//q)
    return l

def disc_moy(liste_valeurs_propriete,nb_class):
    """
    Cette fonction prend en entrée une liste des valeurs d'une propriété pour toutes les galaxies
    Elle discrétise avec les methode des moyenne et l’écart-type est renvoie un liste
    """
    avg=np.mean(liste_valeurs_propriete)
    std=np.std(liste_valeurs_propriete)
    liste_valeurs_propriete_cp=copy.deepcopy(liste_valeurs_propriete)
    bins=[]
    i=-nb_class/2
    while i<nb_class/2:
        bi=avg+i*std
        bins.append(bi)
        i+=1
    l=np.digitize(liste_valeurs_propriete_cp,np.array(bins))
    return l

def discretisation(liste_valeurs_propriete):
    """
    Cette fonction prend en entrée une liste des valeurs d'une propriété pour toutes les galaxies. Elle discrétise les valeurs et renvoie une liste contenant les valeurs discrétisées.
    """
    ## fonction à remplir
    # remplacer la ligne ci-dessous par la discrétisation
    liste_valeurs_propriete_discretisee = liste_valeurs_propriete
    return liste_valeurs_propriete_discretisee

def affichage_histogramme(liste_valeurs_propriete, bins=50):
    hist, edges = np.histogram(liste_valeurs_propriete, bins)
    width = 0.99 * (edges[1] - edges[0])
    plt.bar(edges[:-1], hist, align='edge', width=width)
    plt.show()

"""
EXERCICE 2 : Calcul des informations mutuelles
========================================================================

En utilisant la méthode vue en cours et en TD, calculez l'information
mutuelle normalisée entre le type morphologique et chaque variable
définie à l'exercice 1. Vous aurez pour cela besoin de compléter les
fonctions `calcule_distribution_proba`, `calcule_entropy` et
`calcule_NMI` ci-dessous.

Dans votre rapport, présentez dans un tableau les valeurs des entropies
marginales et jointes, ainsi que les informations mutuelles normalisées.

Calculez aussi l'information mutuelle normalisée entre le type
morphologique et l'emplacement. Cela nous permettra de vérifier le haut
degré de corrélation vu dans l'article.

Commentez les résultats. Quelles variables sont corrélées avec le type
morphologique ? A quel point ? Peut-on en conclure sur l'existence de
relations de cause à effet entre ces variables ?

"""

def calcule_distribution_proba(liste_tirages):
    """
    Cette fonction calcule la probabilité d'occurence p_i de chaque
valeur i que peut prendre la variable. Elle prend en entrée une liste
(np.array) de valeurs générées lors de plusieurs tirages successifs sur la variable.
Ces valeurs sont représentées par des tuples. Ainsi, si la variable aléatoire est une
combinaison de deux variables (Y,Z), les valeurs seront des tuples de 2 éléments (y,z).
Elle renvoie un tableau (np.array) contenant les probabilités p_i pour chaque valeur i.
    """
    print(len(liste_tirages[0]))
    Univers, occurence = np.unique(liste_tirages,axis=0,return_counts=True)
    pi=occurence/(len(liste_tirages))
    return pi

def calcule_entropy(l_i):
    """
    Cette fonction calcule l'entropie d'une
    variable aléatoire dont la distribution de probabilité est données
    dans la liste (np.array) l_i
    Elle renvoie la valeur de l'entropie (float).
    """
    res=0
    for i in l_i:
        if i>0:
            res+=i*np.log2(i)
    return -res

def join_entropy(nb,l_i,l_j,l_k=None):
    """
    Calcule l'entropie jointe
    """
    l_i=[]
    if nb==3:
        for i,j,k in zip(l_i,l_j,l_k):
            l_i.append((i,j,k))
    elif nb==2:
        for i,j in zip(l_i,l_j):
            l_i.append((i,j))
    else:
        print("not the right nb of parameter")
    return calcule_entropy(l_i)


def calcule_NMI(liste_tirages_varX, liste_tirages_varY):
    """
    Cette fonction doit calculer l'information mutuelle normalisée entre deux variables X et Y.
    Elle prend en entrée, pour chaque variable, une liste de valeurs générées lors de plusieurs tirages successifs sur la variable.
    Remarques : Les deux listes doivent avoir la même taille. liste_tirages_varX[i] et liste_tirages_varY[i] sont les valeurs prises simultanément par les variables X et Y lors du tirage sur la galaxie i.
    La fonction renvoie la valeur de l'information mutuelle normalisée (NMI) (float).
    Conseil : Il existe plusieurs formules (dont plusieurs vues en cours) pour calculer l'IM. La formule IM(X;Y) = H(X) + H(Y) - H(X,Y) est probablement la plus simple à implémenter en Python.
    """
    HC=calcule_entropy(liste_tirages_varX)
    HY=calcule_entropy(liste_tirages_varY)
    HCY=join_entropy(2,liste_tirages_varX,liste_tirages_varY)
    IM=HC+HY-HCY
    NMI=2*IM/(HC+HY)
    return NMI

"""
EXERCICE 3 : Calcul des informations d'intéraction
========================================================================

En utilisant la méthode vue en cours, calculez l'information
d'intéraction entre le type morphologique, l'emplacement, et chaque
variable utilisée dans l'exercice 2. Vous aurez pour cela besoin de
compléter la fonction `calcule_information_interaction` ci-dessous.

Présentez et commentez les résultats. Peut-on conclure sur l'existence
de relations de cause à effet entre ces variables ?

"""

def calcule_information_interaction(liste_tirages_varX, liste_tirages_varY, liste_tirages_varZ):
    """
    Cette fonction doit calculer l'information d'intéraction entre trois variables X, Y, et Z.
    Elle prend en entrée, pour chaque variable, une liste de valeurs générées lors de plusieurs tirages successifs sur la variable.
    Remarques : Les trois listes doivent avoir la même taille. liste_tirages_varX[i], liste_tirages_varY[i], et liste_tirages_varZ[i] sont les valeurs prises simultanément par les variables X, Y, et Z lors du tirage joint i.
    La fonction renvoie la valeur de l'information d'intéraction (float).
    Remarque : Il existe plusieurs formules (dont plusieurs vues en cours) pour calculer l'IM. La formule basée sur l'entropie des sous-ensembles de variables est probablement la plus simple à implémenter ici.
    """
    liste_tirages_varX=np.asarray(liste_tirages_varX)
    liste_tirages_varY=np.asarray(liste_tirages_varY)
    liste_tirages_varZ=np.asarray(liste_tirages_varZ)
    HX=calcule_entropy(liste_tirages_varX)
    HY=calcule_entropy(liste_tirages_varY)
    HZ=calcule_entropy(liste_tirages_varZ)
    HXY=join_entropy(2,liste_tirages_varX,liste_tirages_varY)
    HYZ=join_entropy(2,liste_tirages_varY,liste_tirages_varZ)
    HXZ=join_entropy(2,liste_tirages_varX,liste_tirages_varZ)
    HXYZ=join_entropy(3,liste_tirages_varX,liste_tirages_varY,liste_tirages_varZ)
    II=-(HX+HY+HZ)+HXY+HYZ+HXZ-HXYZ
    return II

"""
EXERCICE 4 : Exploration facultative
========================================================================

Vous pouvez explorer le problème plus en profondeur en calculant les
informations d'intéraction entre le type morphologique et d'autres
choix de deux variables (donc autres que l'emplacement).

Commentez les résultats et présentez vos conclusions.

"""

main()
