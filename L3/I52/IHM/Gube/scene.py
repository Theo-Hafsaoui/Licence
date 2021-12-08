import tkinter as tk

'''Return the list of the value of the ligne
composing the board, like so:
[0,10,200,10]'''
def Creat_list_scene(size_scene):
    l_res=[]
    for d in range(size_scene):
    return l_res

Master=tk.Tk()
#Creation Scene
cnv=tk.Canvas(Master,background="black")
cnv.create_line(0,10,200,10,fill="white")
cnv.pack(fill=tk.BOTH)

Master.mainloop()


