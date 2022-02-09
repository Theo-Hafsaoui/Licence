import tkinter as tk

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


def wc2nc(l_x,vp,wd,Ov):
    """
    return the projection from the
    Euclidian space to the screen one

    K[0]=x
    K[1]=y
    """
    Vc_x= l_x[0]*(vp[0]/wd[0]) + (Ov[0]*wd[0])/wd[0]
    Vc_y= (l_x[1]*(vp[0]/wd[1]) + (Ov[0]*wd[1])/wd[1])
    return [Vc_x,Vc_y]

def draw_from_file():
#TODO
    pass

#############################################
#############################################
#############################################

if __name__ == "__main__":
    Master = tk.Tk()
    x1,y1=200,200
    x2,y2=400,400
    W=[800,800]
    Vp=[200,200]
    Ov=[200,200]
    Master.attributes('-type', 'dialog')
    Master.geometry("800x800")
    cnv=tk.Canvas(Master,height=800,width=800,background="#282828")
    rec=create_rectangle(cnv,x1,y1,x2,y2)
    list_p=file2point("point.point")
    for i in range(0,len(list_p),2):
        Vc=wc2nc([list_p[i],list_p[i+1]],Vp,W,Ov)
        print("Vc=",Vc)
        create_point(cnv,Vc[0],Vc[1])
    #cnv.move(rec,200,200)
    #create_point(cnv,300,300)
    #create_point(cnv,150,150)
    Master.mainloop()
