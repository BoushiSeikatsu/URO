# -*- coding: utf-8 -*-
"""
Created on Sun Mar 10 21:44:08 2024

@author: msi pc
"""
from tkinter import *
import tkinter.font
from tkinter import ttk

class MyApp:
    def item_selected(self, event):
        for selected_item in self.table.selection():
            print(self.table.item(selected_item)['values'])
    def onButtonSaveFormClick(self):
        print("Save button clicked")
    def onButtonResetFormClick(self):
        print("Reset button clicked")
    def createFormWindow(self, root):
        self.formWindow = Toplevel(root)
        self.formWindow.geometry("300x300")
        self.formFrame = Frame(self.formWindow, bd = 5)
        
        self.nameLabel = Label(self.formFrame, text="Název školy: ", padx=5)
        self.nameLabel.grid(row = 0, column = 0)
        self.nameEntry = Entry(self.formFrame)
        self.nameEntry.grid(row = 0, column = 1)
        
        self.streetLabel = Label(self.formFrame, text="Ulice: ", padx=5)
        self.streetLabel.grid(row = 1, column = 0)
        self.streetEntry = Entry(self.formFrame)
        self.streetEntry.grid(row = 1, column = 1)
        
        self.cityLabel = Label(self.formFrame, text="Město: ", padx=5)
        self.cityLabel.grid(row = 2, column = 0)
        self.cityEntry = Entry(self.formFrame)
        self.cityEntry.grid(row = 2, column = 1)
        
        self.pscLabel = Label(self.formFrame, text="PSČ: ", padx=5)
        self.pscLabel.grid(row = 3, column = 0)
        self.pscEntry = Entry(self.formFrame)
        self.pscEntry.grid(row = 3, column = 1)
        
        self.resetFormBtn = Button(self.formFrame, text = "Vymazat formulář", command=self.onButtonResetFormClick)
        self.resetFormBtn.grid(row = 4, column = 0)
        self.saveFormBtn = Button(self.formFrame, text = "Uložit záznam", command=self.onButtonSaveFormClick)
        self.saveFormBtn.grid(row = 4, column = 1)
        
        self.formFrame.pack(side="top")
    def __init__(self, root):
        root.geometry("850x500")
        root.title('Administrace')
        #root.resizable(False, False)     
        def_font = tkinter.font.nametofont("TkDefaultFont")
        def_font.config(size=12)
        
        #Notebook part
        self.notebook = ttk.Notebook(root)
        self.notebook.pack()

        self.highschools = ttk.Frame(self.notebook, width=850, height=500)
        self.applications = ttk.Frame(self.notebook, width=850, height=500)

        self.notebook.add(self.highschools, text='High schools')
        self.notebook.add(self.applications, text='Application Forms')
        
        #Table part - Highschool
        self.tableFrame = Frame(self.highschools,bd = 5)
        self.table = ttk.Treeview(self.tableFrame, columns=('name', 'street', 'city', 'psc'), 
                            show='headings')

        self.table.heading('name', text='School name')
        self.table.heading('street', text='Street')
        self.table.heading('city', text='City')
        self.table.heading('psc', text='PSC')

        self.table.insert('', END, values=("VŠB", "17. listopadu 2172/15", "Ostrava", "708 00"))
        self.table.insert('', END, values=("Ostravská Univerzita", "Dvořákova 138/7", "Ostrava","701 03"))
        self.table.bind('<<TreeviewSelect>>', self.item_selected)
        self.table.grid(row=0, column=0, sticky='nsew')

        scrollbar = ttk.Scrollbar(self.tableFrame, orient=VERTICAL, command=self.table.yview)
        self.table.configure(yscroll=scrollbar.set)
        scrollbar.grid(row=0, column=1, sticky='ns')
        self.tableFrame.pack(side="top")
        
        #Menu part
        self.menubar = Menu(root)
        self.filemenu = Menu(self.menubar, tearoff=0)
        self.filemenu.add_command(label="Konec", command=root.quit)
        self.menubar.add_cascade(label="Soubor", menu=self.filemenu)

        root.config(menu=self.menubar)
        
        #Form part
        self.controlFrame = Frame(self.highschools, bd = 5)
        self.insertButton = Button(self.controlFrame, text="Nový záznam", command=lambda: self.createFormWindow(root))
        self.insertButton.grid(row = 0, column = 0)
        self.controlFrame.pack(side="left", anchor="n")
        
root = Tk()
myApp = MyApp(root)
root.mainloop()
