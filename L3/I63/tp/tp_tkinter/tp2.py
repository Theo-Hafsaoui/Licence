import tkinter as tk
#Génération de tracés
###Global
x1,y1=200,200
x2,y2=400,400
W=[800,800]
Vp=[200,200]
Ov=[200,200]
#

def create_vp():
    rec=create_rectangle(cnv,x1,y1,x2,y2)
    return rec

def create_rectangle(cnv,x1,y1,x2,y2):
    """return the object for futher modification,
        take the coordoner of 2 point of the rectangle
    """
    rec=cnv.create_polygon(x1,y1,x1,y2,x2,y2,x2,y1,outline="#fb4934",fill="#fbf1c7")
    cnv.pack()
    return rec

def pixel(x,y):
    """return the object for futher modification,
        take the coordoner of 2 point of the pixel
    """
    pt=cnv.create_line(x,y,x+1,y+1,fill="#076678")
    cnv.pack()
    return pt

def test_pixel(x,y):
    """
    test the pixel from the funtion...
    pixel
    """
    for i in range(0,100):
        pixel(x+i,y)

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

def Bessenaif(cnv,p1,p2):
    """
    naiv funtion that drw a line between
    to point using his equation

    p1[0]=x1
    p1[1]=y1
    y=ax+b
    """
    a=(p2[1]-p1[1])/(p2[0]-p1[0])
    b=p1[1]-a*p1[0]
    y=0
    print(b)
    while y<p2[1]:
        y=a*p1[0]+b
        l_p=wc2nc([p1[0],y],Vp,W,Ov)
        pixel(l_p[0],l_p[1])
        #TODO cliping
        p1[0]+=1

def Boct1(dx,dy):
    """
    
    """
    dec=dx-2dy
    pass

#############################################
#############################################
#############################################

if __name__ == "__main__":
    Master = tk.Tk()
    Master.attributes('-type', 'dialog')
    Master.geometry("800x800")
    cnv=tk.Canvas(Master,height=800,width=800,background="#282828")
    create_vp()
    Bessenaif(cnv,[400,400],[800,800])
    Master.mainloop()##
