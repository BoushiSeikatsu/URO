#------------------------------------------------------------------------------#
# Obycejne tlacitko                                                            #
#------------------------------------------------------------------------------#
from tkinter import *
from tkinter import ttk

class myApp:
  def __init__(self, master):
    self.bu = ttk.Button(master,text="Konec")
    self.bu.pack(side="top")
    self.bu2 = ttk.Button(master,text="Konec")
    self.bu2.pack(side="left")
    self.bu3 = ttk.Button(master,text="Konec")
    self.bu3.pack(side="right")
    self.en = Entry(master)
    self.en.pack(side="bottom", fill="both", expand="true", padx=30, pady=10)
    #self.bu4 = ttk.Button(master,text="Konec")
    #self.bu4.pack(side="bottom", fill="both", expand="true", padx=30, pady=10)

root = Tk()
app = myApp(root)
root.mainloop()

class myApp:
  def __init__(self, master):
    self.fr = Frame(master)
    self.fr2 = Frame(master)
    self.fr3 = Frame(master)
    self.lab1 = Label(self.fr, text="Jméno")
    self.lab2 = Label(self.fr2, text="Ročník")
    self.lab3 = Label(self.fr3, text="Student")
    self.ent = Entry(self.fr)
    self.ent2 = Entry(self.fr2)
    self.chk = Checkbutton(self.fr3)
    self.btn = Button(master, text="OK")
    self.fr.pack()
    self.fr2.pack()
    self.fr3.pack()
    self.lab1.pack(side="left")
    self.lab2.pack(side="left")
    self.lab3.pack(side="left")
    self.ent.pack(side="right")
    self.ent2.pack(side="right")
    self.chk.pack(side="right")
    self.btn.pack(side ="right", padx=30)

root = Tk()
app = myApp(root)
root.mainloop()
#------------------------------------------------------------------------------#



