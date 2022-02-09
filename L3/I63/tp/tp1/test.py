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
    temp=[int(j) for i in l_p for j in i]
    return temp

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
    #TODO add difff with origini
    H=Vp_y-y
    M_res=[]
    M_res.append(Vp_x/W_x)#A
    M_res.append(-Vp_y/W_y)#E
    M_res.append((x*Vp_x)/W_x-x)#C
    M_res.append(-(H*Vp_y+Vp_y*y)/W_y-y)#F
    print(M_res)
    return M_res

def wc2nc(l_x,vp,wd):
    """
    return the projection from the
    Euclidian space to the screen one
    """
    w=1#2d space
    AECF=AE_CF(l_x[0],l_x[1],wd[0],wd[1],vp[0],vp[1])
    Vc=[]
    Vc.append(AECF[0]*l_x[0]+AECF[2]*l_x[1]+w*AECF[2])#x
    Vc.append(l_x[1]+AECF[1]*l_x[1]+AECF[3]+w*AECF[3])#x
    return Vc

#############################################
#############################################
#############################################

if __name__ == "__main__":
    Master = tk.Tk()
    x1,y1=200,200
    x2,y2=400,400
    l_w=[800,800]
    l_v=[400,400]
    Master.attributes('-type', 'dialog')
    Master.geometry("800x800")
    cnv=tk.Canvas(Master,height=800,width=800,background="#282828")
    rec=create_rectangle(cnv,x1,y1,x2,y2)
    list_p=file2point("point.point")
    for i in range(0,len(list_p),2):
        Vc=wc2nc([list_p[i],list_p[i+1]],[800,800],[400,400])
        print(Vc)
        create_point(cnv,Vc[0],Vc[1])
    create_point(cnv,400,400)
    #cnv.move(rec,200,200)
    #create_point(cnv,100,100)
    Master.mainloop()
