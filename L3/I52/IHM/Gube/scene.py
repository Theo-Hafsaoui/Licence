import tkinter as tk

"""Return a list of the coordonate of the grid
"""

def Creat_grid_list(size_scene,diag,wx,wy):
    decx=wx
    decy=wy/2
    diag_2=d*2
    l_case=[]
    x=diag*10
    for i in range(size_scene):
        for j in range(size_scene):
            x=decx+(j-i)*diag_2
            y=decy+(i+j)*diag
            l_i=[x,y, x+diag_2, y+diag,
                 x,y+diag_2, x-diag_2,y+diag,
                 x,y]
            l_case.append((l_i))
    return l_case

def Summon_grid(Master,canvas,diag,size_scene):
    wy = Master.winfo_reqwidth()
    wx = Master.winfo_reqheight()
    l=Creat_grid_list(size_scene,diag,wx,wy)
    for i in range(size_scene**2):
        cnv.create_polygon(l[i],outline="#d79921",fill="#fbf1c7")
    cnv.pack(fill=tk.BOTH)

def Summon_Right_Face(l_grid,dia,size_scene):


Master=tk.Tk()
Master.attributes('-type', 'dialog')
#Creation Scene
cnv=tk.Canvas(Master,background="#282828")
d=10
size_scene=8
Summon_grid(Master,cnv,d,size_scene)

Master.mainloop()


