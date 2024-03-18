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
            print(self.table.item(selected_item)["values"])
            #self.generateInfo(self.table.item(selected_item)["values"], root)
        
    def onButtonSaveFormClick(self):
        print("Save button clicked")
    def onButtonResetFormClick(self):
        print("Reset button clicked")
    def createFormWindow(self, root):
        self.formWindow = Toplevel(root)
        self.formWindow.geometry("300x300")
        self.formFrame = ttk.Frame(self.formWindow, borderwidth = 5)
        
        self.nameLabel = ttk.Label(self.formFrame, text="Název školy: ")
        self.nameLabel.grid(row = 0, column = 0)
        self.nameEntry = ttk.Entry(self.formFrame)
        self.nameEntry.grid(row = 0, column = 1)
        
        self.streetLabel = ttk.Label(self.formFrame, text="Ulice: ")
        self.streetLabel.grid(row = 1, column = 0)
        self.streetEntry = ttk.Entry(self.formFrame)
        self.streetEntry.grid(row = 1, column = 1)
        
        self.cityLabel = ttk.Label(self.formFrame, text="Město: ")
        self.cityLabel.grid(row = 2, column = 0)
        self.cityEntry = ttk.Entry(self.formFrame)
        self.cityEntry.grid(row = 2, column = 1)
        
        self.pscLabel = ttk.Label(self.formFrame, text="PSČ: ")
        self.pscLabel.grid(row = 3, column = 0)
        self.pscEntry = ttk.Entry(self.formFrame)
        self.pscEntry.grid(row = 3, column = 1)
        
        self.btnFrame = ttk.Frame(self.formWindow, borderwidth=5)
        self.resetFormBtn = ttk.Button(self.btnFrame, text = "Vymazat formulář", command=self.onButtonResetFormClick)
        self.resetFormBtn.grid(row = 4, column = 0)
        self.saveFormBtn = ttk.Button(self.btnFrame, text = "Uložit záznam", command=self.onButtonSaveFormClick)
        self.saveFormBtn.grid(row = 4, column = 1)
        
        self.formFrame.pack(side="top")
        self.btnFrame.pack(side="bottom")
        self.formWindow.grab_set()
    def generateInfo(self, info, root):
        if(len(info) == 4):
            counter = 0
            for element in info:
                label = ttk.Label(self.infoFrame, text="Název: ")
                entry = ttk.Entry(self.infoFrame, text=element)
                label.grid(row = counter, column = 0)
                entry.grid(row = counter, column= 1)
    def switchFrames(index):
        if(index == 0):
            self.infoFrameHS
        else:
            self.infoFrameAF
    def get_selected_notebook(self, event):
      # Get the index of the currently selected tab (zero-based)
      self.selected_index = self.notebook.index("current")
      
      # Access the tab title using the index (optional)
      selected_tab_title = self.notebook.tab(selected_index, "text")
    def __init__(self, root):
        root.geometry("850x500")
        root.title('Administrace')
        #root.resizable(False, False)     
        def_font = tkinter.font.nametofont("TkDefaultFont")
        def_font.config(size=12)
        
        #Notebook part
        self.notebook = ttk.Notebook(root)
        self.notebook.pack()

        self.highschools = ttk.Frame(self.notebook, width=400, height=200)
        self.applications = ttk.Frame(self.notebook, width=400, height=200)

        self.notebook.add(self.highschools, text='High schools')
        self.notebook.add(self.applications, text='Application Forms')
        self.notebook.bind("<ButtonRelease-1>", self.get_selected_notebook)
        #Search bar part
        self.searchEntry = ttk.Entry(self.highschools, text="Název školy: ")
        
        #Table part - Highschool
        self.tableFrame = ttk.Frame(self.highschools,borderwidth= 5)
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
        self.bottomPartFrame = ttk.Frame(root)
        self.infoFrameHS = ttk.Frame(self.bottomPartFrame)
        for i in range(0,4):
            label = ttk.Label(self.infoFrameHS, text="Název: ")
            entry = ttk.Entry(self.infoFrameHS, text="")
            label.grid(row = i, column = 0)
            entry.grid(row = i, column= 1)
        self.infoFrameAF = ttk.Frame(self.bottomPartFrame)
        
        self.controlFrame = ttk.Frame(self.bottomPartFrame, borderwidth = 5)
        self.insertButton = ttk.Button(self.controlFrame, text="Nový záznam", command=lambda: self.createFormWindow(root))
        self.insertButton.grid(row = 0, column = 0)
        self.controlFrame.pack(side="left", anchor="nw")
        self.infoFrameHS.pack(side="right", anchor="ne")
        self.bottomPartFrame.pack()
        #self.formWindow.grab_set()
root = Tk()
myApp = MyApp(root)
root.mainloop()
