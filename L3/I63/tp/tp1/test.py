import tkinter as tk


def create_rectangle(cnv,x1,y1,x2,y2):
    rec=cnv.create_polygon(x1,y1,x1,y2,x2,y2,x2,y1,outline="#fb4934",fill="#fbf1c7")
    cnv.pack()
    return rec

def ABC(x,y,W_x,W_y,Vp_x,Vp_y,HY):
    """ca pue le y sert a rien"""
    M_res=[]
    M_res.append(Vp_x*x**4/W_x)#A
    M_res.append(-Vp_y*x**4/W_y)#B
    M_res.append(x**4)#C
    return M_res

def wc2dc(l_x,vp,wd):
    """
    assumons que les coordoner de la viewport sont le coins
    inferieur gauche
    transform plan
    soit le vecteur  v (u,v,1)
    et la matrice M
                  [A B C]
                  |D E F]
                  [G H I]
    le rusltat de v*m et la matrice:
                  [Au+Bv+C]
                  |Du Ev F]
                  [Gu Hv I]
    """
    return vc


if __name__ == "__main__":
    Master = tk.Tk()
    Master.attributes('-type', 'dialog')
    Master.geometry("800x800")
    cnv=tk.Canvas(Master,height=800,width=800,background="#282828")
    rec=create_rectangle(cnv,200,200,400,400)
    #cnv.move(rec,200,200)


    Master.mainloop()
