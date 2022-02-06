import tkinter as tk
"""
note:
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

def file2point(file_name):
    """
    read a file compose for each line
    a 2 coord and return a list
    """
    f = open(file_name, 'r')
    l_p=[]
    ls=f.readlines()
    for l in ls:
        l_p.append(l.split())
    return l_p

def create_point(cnv,x,y):
    """return the object for futher modification,
        take the coordoner of 2 point of the rectangle
    """
    pt=cnv.create_oval(x,y,x+10,y+10,outline="#fb4934",fill="#076678")
    cnv.pack()
    return pt

def create_rectangle(cnv,x1,y1,x2,y2):
    """return the object for futher modification,
        take the coordoner of 2 point of the rectangle
    """
    rec=cnv.create_polygon(x1,y1,x1,y2,x2,y2,x2,y1,outline="#fb4934",fill="#fbf1c7")
    cnv.pack()
    return rec

def AE_CF(x,y,W_x,W_y,Vp_x,Vp_y):
    """
    return the component of the
    matrix that change the space
    for the function wc2dc
    """
    H=W_y-y
    M_res=[]
    M_res.append(Vp_x/W_x)#A
    M_res.append(Vp_y/W_y)#E
    M_res.append((x*Vp_x)/W_x-x)#C
    M_res.append((y*Vp_y*-H*Vp_y)/W_y-y)#F
    return M_res

def wc2dc(l_x,vp,wd):
    """
    return the projection from the
    Euclidian space to the screen one
    """
    w=1#2d space
    MAE=AE_CF(l_x[0],l_x[1],wd[0],wd[1],vp[0],vp[1])
    Vc=[]
    Vc.append(MAE[0]*l_x[0]+MAE[1]*l_x[1]+w)#x
    Vc.append(l_x[0]+MAE[2]*l_x[1]+MAE[3]+w)#x
    return Vc

#############################################
#############################################
#############################################

if __name__ == "__main__":
    Master = tk.Tk()
    x1,y1=200,200
    x2,y2=400,400
    Master.attributes('-type', 'dialog')
    Master.geometry("800x800")
    cnv=tk.Canvas(Master,height=800,width=800,background="#282828")
    rec=create_rectangle(cnv,x1,y1,x2,y2)
    Vc=wc2dc(,)
    create_point(cnv,500,500)
    cnv.move(rec,200,200)
    l=file2point("point.point")
    print(l)
    Master.mainloop()

