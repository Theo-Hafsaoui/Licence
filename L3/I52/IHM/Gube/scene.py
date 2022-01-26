import tkinter as tk

"""Return a list of the coordonate of the grid

"""

def creat_grid_list(size_scene,diag,wx,wy):
    #increment size scne for cube creation
    size_scene+=1
    decx=wx
    decy=wy/2
    diag_2=diag*2
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

def summon_grid(Master,canvas,diag,size_scene):
    """
        Summon a grid from a list, in a canvas

        the first column and row stay
        invisible and are here only to help 
        the summon of the cube, the center depend
        of the window
    """
    wy = Master.winfo_reqwidth()/2
    wx = Master.winfo_reqheight()
    l=creat_grid_list(size_scene,diag,wx,wy)
    print(l)
    for i in range(1,size_scene):
        for j in range(1,size_scene):
            cnv.create_polygon(l[i+(j*(size_scene+1))],outline="#d79921",fill="#fbf1c7")
    cnv.pack(fill=tk.BOTH)
"""return a list compose of every grid for
    z from 0 to size of grid

    each grid shift from one grid
    """
def grid_all_level():
    l=[]
    wy = Master.winfo_reqwidth()/2
    wx = Master.winfo_reqheight()
    z_0=creat_grid_list(size_scene,diag,wx,wy)
    return l

def creat_a_gube_list(l_grid,x,y,size_scene):
    """
    Return the pixel coordonate of a gube by using
        the coordonate in the grid in a form a list
        ex: l=[[l_up],[l_right],[l_left]]

        It use the coordonate of the invisible part of
        the grid
    """
    base=l_grid[(x+((y*(size_scene+1))))]
    up=l_grid[((x-1)+((y-1)*(size_scene+1)))]
    left=up[2:4]+base[2:6]+up[4:6]
    right=up[6:8]+base[6:8]+base[4:6]+up[4:6]
    l_gube=[up,left,right]
    return l_gube

Master=tk.Tk()
Master.attributes('-type', 'dialog')
#Creation Scene
l=[[200, 50.0, 220, 60.0, 200, 70.0, 180, 60.0, 200, 50.0], [220, 60.0, 240, 70.0, 220, 80.0, 200, 70.0, 220, 60.0], [240, 70.0, 260, 80.0, 240, 90.0, 220, 80.0, 240, 70.0], [260, 80.0, 280, 90.0, 260, 100.0, 240, 90.0, 260, 80.0], [280, 90.0, 300, 100.0, 280, 110.0, 260, 100.0, 280, 90.0], [300, 100.0, 320, 110.0, 300, 120.0, 280, 110.0, 300, 100.0], [320, 110.0, 340, 120.0, 320, 130.0, 300, 120.0, 320, 110.0], [340, 120.0, 360, 130.0, 340, 140.0, 320, 130.0, 340, 120.0], [360, 130.0, 380, 140.0, 360, 150.0, 340, 140.0, 360, 130.0], [180, 60.0, 200, 70.0, 180, 80.0, 160, 70.0, 180, 60.0], [200, 70.0, 220, 80.0, 200, 90.0, 180, 80.0, 200, 70.0], [220, 80.0, 240, 90.0, 220, 100.0, 200, 90.0, 220, 80.0], [240, 90.0, 260, 100.0, 240, 110.0, 220, 100.0, 240, 90.0], [260, 100.0, 280, 110.0, 260, 120.0, 240, 110.0, 260, 100.0], [280, 110.0, 300, 120.0, 280, 130.0, 260, 120.0, 280, 110.0], [300, 120.0, 320, 130.0, 300, 140.0, 280, 130.0, 300, 120.0], [320, 130.0, 340, 140.0, 320, 150.0, 300, 140.0, 320, 130.0], [340, 140.0, 360, 150.0, 340, 160.0, 320, 150.0, 340, 140.0], [160, 70.0, 180, 80.0, 160, 90.0, 140, 80.0, 160, 70.0], [180, 80.0, 200, 90.0, 180, 100.0, 160, 90.0, 180, 80.0], [200, 90.0, 220, 100.0, 200, 110.0, 180, 100.0, 200, 90.0], [220, 100.0, 240, 110.0, 220, 120.0, 200, 110.0, 220, 100.0], [240, 110.0, 260, 120.0, 240, 130.0, 220, 120.0, 240, 110.0], [260, 120.0, 280, 130.0, 260, 140.0, 240, 130.0, 260, 120.0], [280, 130.0, 300, 140.0, 280, 150.0, 260, 140.0, 280, 130.0], [300, 140.0, 320, 150.0, 300, 160.0, 280, 150.0, 300, 140.0], [320, 150.0, 340, 160.0, 320, 170.0, 300, 160.0, 320, 150.0], [140, 80.0, 160, 90.0, 140, 100.0, 120, 90.0, 140, 80.0], [160, 90.0, 180, 100.0, 160, 110.0, 140, 100.0, 160, 90.0], [180, 100.0, 200, 110.0, 180, 120.0, 160, 110.0, 180, 100.0], [200, 110.0, 220, 120.0, 200, 130.0, 180, 120.0, 200, 110.0], [220, 120.0, 240, 130.0, 220, 140.0, 200, 130.0, 220, 120.0], [240, 130.0, 260, 140.0, 240, 150.0, 220, 140.0, 240, 130.0], [260, 140.0, 280, 150.0, 260, 160.0, 240, 150.0, 260, 140.0], [280, 150.0, 300, 160.0, 280, 170.0, 260, 160.0, 280, 150.0], [300, 160.0, 320, 170.0, 300, 180.0, 280, 170.0, 300, 160.0], [120, 90.0, 140, 100.0, 120, 110.0, 100, 100.0, 120, 90.0], [140, 100.0, 160, 110.0, 140, 120.0, 120, 110.0, 140, 100.0], [160, 110.0, 180, 120.0, 160, 130.0, 140, 120.0, 160, 110.0], [180, 120.0, 200, 130.0, 180, 140.0, 160, 130.0, 180, 120.0], [200, 130.0, 220, 140.0, 200, 150.0, 180, 140.0, 200, 130.0], [220, 140.0, 240, 150.0, 220, 160.0, 200, 150.0, 220, 140.0], [240, 150.0, 260, 160.0, 240, 170.0, 220, 160.0, 240, 150.0], [260, 160.0, 280, 170.0, 260, 180.0, 240, 170.0, 260, 160.0], [280, 170.0, 300, 180.0, 280, 190.0, 260, 180.0, 280, 170.0], [100, 100.0, 120, 110.0, 100, 120.0, 80, 110.0, 100, 100.0], [120, 110.0, 140, 120.0, 120, 130.0, 100, 120.0, 120, 110.0], [140, 120.0, 160, 130.0, 140, 140.0, 120, 130.0, 140, 120.0], [160, 130.0, 180, 140.0, 160, 150.0, 140, 140.0, 160, 130.0], [180, 140.0, 200, 150.0, 180, 160.0, 160, 150.0, 180, 140.0], [200, 150.0, 220, 160.0, 200, 170.0, 180, 160.0, 200, 150.0], [220, 160.0, 240, 170.0, 220, 180.0, 200, 170.0, 220, 160.0], [240, 170.0, 260, 180.0, 240, 190.0, 220, 180.0, 240, 170.0], [260, 180.0, 280, 190.0, 260, 200.0, 240, 190.0, 260, 180.0], [80, 110.0, 100, 120.0, 80, 130.0, 60, 120.0, 80, 110.0], [100, 120.0, 120, 130.0, 100, 140.0, 80, 130.0, 100, 120.0], [120, 130.0, 140, 140.0, 120, 150.0, 100, 140.0, 120, 130.0], [140, 140.0, 160, 150.0, 140, 160.0, 120, 150.0, 140, 140.0], [160, 150.0, 180, 160.0, 160, 170.0, 140, 160.0, 160, 150.0], [180, 160.0, 200, 170.0, 180, 180.0, 160, 170.0, 180, 160.0], [200, 170.0, 220, 180.0, 200, 190.0, 180, 180.0, 200, 170.0], [220, 180.0, 240, 190.0, 220, 200.0, 200, 190.0, 220, 180.0], [240, 190.0, 260, 200.0, 240, 210.0, 220, 200.0, 240, 190.0], [60, 120.0, 80, 130.0, 60, 140.0, 40, 130.0, 60, 120.0], [80, 130.0, 100, 140.0, 80, 150.0, 60, 140.0, 80, 130.0], [100, 140.0, 120, 150.0, 100, 160.0, 80, 150.0, 100, 140.0], [120, 150.0, 140, 160.0, 120, 170.0, 100, 160.0, 120, 150.0], [140, 160.0, 160, 170.0, 140, 180.0, 120, 170.0, 140, 160.0], [160, 170.0, 180, 180.0, 160, 190.0, 140, 180.0, 160, 170.0], [180, 180.0, 200, 190.0, 180, 200.0, 160, 190.0, 180, 180.0], [200, 190.0, 220, 200.0, 200, 210.0, 180, 200.0, 200, 190.0], [220, 200.0, 240, 210.0, 220, 220.0, 200, 210.0, 220, 200.0], [40, 130.0, 60, 140.0, 40, 150.0, 20, 140.0, 40, 130.0], [60, 140.0, 80, 150.0, 60, 160.0, 40, 150.0, 60, 140.0], [80, 150.0, 100, 160.0, 80, 170.0, 60, 160.0, 80, 150.0], [100, 160.0, 120, 170.0, 100, 180.0, 80, 170.0, 100, 160.0], [120, 170.0, 140, 180.0, 120, 190.0, 100, 180.0, 120, 170.0], [140, 180.0, 160, 190.0, 140, 200.0, 120, 190.0, 140, 180.0], [160, 190.0, 180, 200.0, 160, 210.0, 140, 200.0, 160, 190.0], [180, 200.0, 200, 210.0, 180, 220.0, 160, 210.0, 180, 200.0], [200, 210.0, 220, 220.0, 200, 230.0, 180, 220.0, 200, 210.0]]
cnv=tk.Canvas(Master,background="#282828")
#add 1 for base because of shift
Y=4
X=6
D=10
SIZE_SCENE=8
UP=0
summon_grid(Master,cnv,D,SIZE_SCENE)
base=l[(X+((Y*(SIZE_SCENE+1))))]
cnv.create_polygon(creat_a_gube_list(l,X,Y,SIZE_SCENE)[0],outline="#d79921",fill="#8f3f71")
cnv.create_polygon(base,outline="#d79921",fill="#f4f4f4")

Master.mainloop()
