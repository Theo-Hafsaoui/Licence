import tkinter as tk
root = tk.Tk()
cnv=tk.Canvas(root, bg="ivory")
cnv.pack(padx=50, pady=50)
tk.Button(text="Ok", command=exit).pack()
tk.Button(text="Annuler", command=exit).pack()
root.mainloop()
exit(0)
