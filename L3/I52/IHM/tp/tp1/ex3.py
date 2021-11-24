import tkinter as tk
import ex2
root = tk.Tk()
big_frame = tk.Frame(root,bg="Black")
cnv=tk.Canvas(big_frame, bg="ivory")
l_color=ex2.color()
#retourne une liste des couleurs sous forme
#('NOM',(255,255,255))
cpt=0
#size
sz=20
d = int((len(l_color)**0.5))
#boucle sur sur la racine carre de ma matrice carre
for i in range(d):
    for j in range(d):
        rgb_color=l_color[cpt][1]
        cnv.create_rectangle(sz*i, sz*j, sz*i+sz, sz*j+sz, fill=ex2.from_rgb(rgb_color))
        cpt+=1
title=tk.Label(root, text="largeur")
cnv.pack(side="left")
big_frame.pack()
cnv.pack(side="left")
#lie la scrollbar et le canvas
scrollbar=tk.Scrollbar(big_frame, command=cnv.yview)
cnv.config(yscrollcommand=scrollbar.set)
tk.Button(text="Ok", command=exit).pack()
tk.Button(text="Annuler", command=exit).pack()
root.mainloop()
exit(0)
