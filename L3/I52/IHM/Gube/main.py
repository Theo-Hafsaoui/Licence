import tkinter as tk
def unknwow():
    print("prout")

Master=tk.Tk()
#Bar
#TODO change color hover, center save
bg_bar='#4c566a'
bar=tk.Frame(Master, bg=bg_bar)
Nouveaux=tk.Button(bar, text="Nouveaux",bg=bg_bar,fg=bg_bar,bd=0,
highlightthickness=0,command=unknwow)
icon_nouveaux = tk.PhotoImage(file="./Resource/icon_menuN.png")
Nouveaux.config(image=icon_nouveaux)
Nouveaux.pack(side='left',padx=2,pady=2)
Sauver=tk.Button(bar, text="Sauver",bg=bg_bar,fg=bg_bar,bd=0,highlightthickness=0,command=unknwow)
icon_sauver = tk.PhotoImage(file="./Resource/icon_menuS.png")
Sauver.config(image=icon_sauver)
Sauver.pack(side='left',padx=2,pady=2)
Ouvrir=tk.Button(bar, text="Ouvrir",bg=bg_bar,fg=bg_bar,bd=0,highlightthickness=0,command=unknwow)
icon_ouvrir = tk.PhotoImage(file="./Resource/icon_menuO.png")
Ouvrir.config(image=icon_ouvrir)
Ouvrir.pack(side='left',padx=2,pady=2)
bar.pack(side="top",fill=tk.X)
#Left panel
bg_pannel='#3b4253'
bg_tab='#2e3441'
l_pannel=tk.Frame(Master, bg=bg_pannel)
infoT=tk.PhotoImage(file="./Resource/infoT.png")
info_tab=tk.Label(l_pannel,image=infoT,bg=bg_tab)
info_tab.pack(side='top',fill=tk.X)
l_pannel.pack(side='left',expand=1,fill=tk.BOTH)
#Dummy Cube
dummy=tk.Frame(Master, bg=bg_pannel)
dummyIM=tk.PhotoImage(file="./Resource/dummy.png")
dummyIM=tk.Label(dummy,image=dummyIM)
dummyIM.pack()
dummy.pack(side='left',expand=1,fill=tk.BOTH)
#Right panel
bg_pannel='#3b4253'
r_pannel=tk.Frame(Master, bg=bg_pannel)
im_filler=tk.PhotoImage(file="./Resource/filler.png")
filler=tk.Label(r_pannel,image=im_filler,bg=bg_pannel)
filler.pack(side='top',fill=tk.X)
Plus=tk.Button(r_pannel, text="Plus",bg=bg_pannel,fg=bg_pannel,bd=0,
highlightthickness=0,command=unknwow)
icon_plus = tk.PhotoImage(file="./Resource/PlusN.png")
Plus.config(image=icon_plus)
r_pannel.pack(side='left',expand=1,fill=tk.BOTH)
Plus.pack(side='top',padx=2,pady=80)
Minus=tk.Button(r_pannel, text="Minus",bg=bg_pannel,fg=bg_pannel,bd=0,
highlightthickness=0,command=unknwow)
icon_minus = tk.PhotoImage(file="./Resource/minusN.png")
Minus.config(image=icon_minus)
r_pannel.pack(side='left',expand=1,fill=tk.BOTH)
Minus.pack(side='top',padx=2)
Rotary=tk.Button(r_pannel, text="Rotary",bg=bg_pannel,fg=bg_pannel,bd=0,
highlightthickness=0,command=unknwow)
icon_rotary = tk.PhotoImage(file="./Resource/Rotary.png")
Rotary.config(image=icon_rotary)
r_pannel.pack(side='left',expand=1,fill=tk.BOTH)
Rotary.pack(side='top',padx=2,pady=80)


Master.mainloop()
