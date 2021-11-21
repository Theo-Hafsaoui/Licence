import tkinter as tk
import ex2
root = tk.Tk()
cnv=tk.Canvas(root, bg="ivory")
l_color=ex2.color()
#retourne une liste des couleurs sous forme
#('NOM',(255,255,255))
cpt=0
#boucle sur sur la racine carre de ma matrice carre
for i in range(int((len(l_color)**0.5))):
    for j in range(int((len(l_color)**0.5))):
        rgb_color=l_color[cpt][1]
        tk.Frame(height = 5,width = 5,bg = ex2.from_rgb(rgb_color)).grid(row=j)
        cpt+=1
cnv.configure(scrollregion = cnv.bbox("all"))
tk.Button(text="Ok", command=exit).pack()
tk.Button(text="Annuler", command=exit).pack()
root.mainloop()
exit(0)
