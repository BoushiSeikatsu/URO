# -*- coding: utf-8 -*-

from tkinter import *
from math import sqrt
import tkinter.font

class myApp:

    def prevod(self, event=None):
        v = float(self.ent_in.get())
        print(self.dir.get())
        self.ent_out.delete(0, END)
        self.ent_out.insert(0, str(round(v, 2)))

    def __init__(self, root):

        root.title('Převodník teplot')
        #root.resizable(False, False)
        root.bind('<Return>', self.prevod)        

        def_font = tkinter.font.nametofont("TkDefaultFont")
        def_font.config(size=16)

        self.left_frame = Frame(root, bd = 5)
        self.right_frame = Frame(root, bd = 5)
        
        self.dir = IntVar()
        self.dir.set(0) 
        self.dir_frame = LabelFrame(self.left_frame, text="dir_frame")
        self.dir_frame.pack()
        self.c_f = Radiobutton(self.dir_frame, text="C -> F", value=0, variable=self.dir, command=setattr)
        
        self.ent_frame = Frame(self.left_frame, bd = 5)
        self.lbl_in = Label(self.ent_frame, text="Vstup")
        self.ent_in = Entry(self.ent_frame, width=10, font = def_font)
        self.ent_in.insert(0, '0')

        self.ca = Canvas(self.right_frame, width=300, height=400)
        self.photo = PhotoImage(file="th.png")
        self.ca.create_image(150, 200, image=self.photo)

        self.left_frame.pack(side="left", fill=Y)
        self.right_frame.pack(side="right")
        self.ent_frame.pack()
        self.lbl_in.pack()  
        self.ent_in.pack()

        self.ent_in.focus_force()


root = Tk()
app = myApp(root)
root.mainloop()

