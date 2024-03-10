# -*- coding: utf-8 -*-
"""
Created on Tue Feb 27 22:37:43 2024

@author: Michal
"""

# -*- coding: utf-8 -*-

from tkinter import *
from math import sqrt
from tkinter import ttk
import tkinter.font

class myApp:

    def prevod(self, event=None):
        v = float(self.ent_in.get())
        print(self.dir.get())
        self.ent_out.delete(0, END)
        self.ent_out.insert(0, str(round(v, 2)))
    def onRadioButtonClick(self, value):
        if(value.get() == 0):
            print("Hodnota je 0")
        else:
            print("Hodnota je 1")
    def __init__(self, root):
        root.geometry("800x400")
        root.title('Převodník teplot')
        #root.resizable(False, False)
        root.bind('<Return>', self.prevod)        

        def_font = tkinter.font.nametofont("TkDefaultFont")
        def_font.config(size=16)

        self.left_frame = Frame(root, bd = 5)
        self.dir_frame = Frame(self.left_frame, bd = 5)
        var = IntVar(value = 0)
        self.radioCF = ttk.Radiobutton(self.dir_frame,value=0,variable = var,text="C -> F", command=self.onRadioButtonClick(var))
        self.radioCF.grid(row = 0, column=0)
        self.radioFC = ttk.Radiobutton(self.dir_frame,value=1,variable = var,text="F -> C", command=self.onRadioButtonClick(var))
        self.radioFC.grid(row = 0, column=1)
        self.dir_frame.pack()
        self.ent_frame = Frame(self.left_frame, bd = 5)
        self.inputLabel = Label(self.ent_frame, text="Vstup")
        self.inputEntry = Entry(self.ent_frame, width = 10)
        self.outputLabel = Label(self.ent_frame, text="Výstup")
        self.outputEntry = Entry(self.ent_frame, width= 10)
        self.sendButton = Button(self.ent_frame, width= 5, text="Send")
        self.inputEntry.grid(row = 1, column = 0)
        self.inputLabel.grid(row = 0, column = 0)
        self.outputLabel.grid(row = 2, column= 0)
        self.outputEntry.grid(row = 3, column = 0)
        self.sendButton.grid(row = 4, column = 0, rowspan=1, padx=50)
        self.ent_frame.pack()
        self.statusBar = Label(self.left_frame, text="Michal Duba DUB0074")
        self.statusBar.pack(side="bottom")
        self.left_frame.pack(expand="true", fill="both", anchor="w", side="left")
        self.right_frame = Frame(root, bd = 5)
        
        
        
        self.ca = Canvas(self.right_frame, width=300, height=400)
        self.photo = PhotoImage(file="th_empty.png")
        self.ca.create_image(150, 200, image=self.photo)
        self.ca.grid(row = 0, column = 1)
        self.right_frame.pack(expand="true", fill= "both", anchor="e",side="right")
        r = self.ca.create_rectangle(146, 292, 152, 80, fill="blue")
        self.ca.coords(r, 146, 292, 152, 100)
        


root = Tk()
app = myApp(root)
root.mainloop()

