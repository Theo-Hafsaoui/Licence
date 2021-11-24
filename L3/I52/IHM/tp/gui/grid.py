import tkinter as tk

root= tk.Tk()
l1=tk.Label(root, text="Je hais tkinter")
l2=tk.Label(root, text="Je VRAIMENT hais tkinter")
l3=tk.Label(root, text="                                   ")
l1.grid(row=0,column=0)
l3.grid(row=0,column=2)
l2.grid(row=1,column=5)
root.mainloop()
