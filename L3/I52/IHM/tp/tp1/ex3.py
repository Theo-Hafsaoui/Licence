import tkinter as tk
import ex2
root = tk.Tk()
cnv=tk.Canvas(root, bg="ivory")
l_color=ex2.color()
for c in l_color:
    tk.Frame(height = 5,width = 5,bg = ex2.from_rgb(c[1])).pack()
cnv.configure(scrollregion = cnv.bbox("all"))
tk.Button(text="Ok", command=exit).pack()
tk.Button(text="Annuler", command=exit).pack()
root.mainloop()
exit(0)
