import tkinter as tk

def create_rectangle(cnv,x1,y1,x2,y2):
    rec=cnv.create_polygon(x1,y1,x1,y2,x2,y2,x2,y1,outline="#fb4934",fill="#fbf1c7")
    cnv.pack()
    return rec

def wc2dc(l_x,vp,wd):
    """
    transform plan
    """
    u=l_x[1]
    v=l_x[2]
    vc=[]
    vc.append()


if __name__ == "__main__":
    Master = tk.Tk()
    Master.attributes('-type', 'dialog')
    Master.geometry("800x800")
    cnv=tk.Canvas(Master,height=800,width=800,background="#282828")
    rec=create_rectangle(cnv,200,200,400,400)
    #cnv.move(rec,200,200)


    Master.mainloop()
