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
      selected_tab_title = self.notebook.tab(self.selected_index, "text")
    def expandSearch(self):
        if(self.deleteOptions):
            self.searchStudentLabel.destroy()
            self.searchStudentEntry.destroy()
            self.searchSchoolLabel.destroy()
            self.searchSchoolEntry.destroy()
            self.deleteOptions = False
        else:  
            self.searchStudentLabel = ttk.Label(self.searchOptionsFrame, text="Jméno studenta:")
            self.searchStudentLabel.grid(row = 1, column = 0)
            self.searchStudentEntry = ttk.Entry(self.searchOptionsFrame)
            self.searchStudentEntry.grid(row = 1, column = 1)
            self.searchSchoolLabel = ttk.Label(self.searchOptionsFrame, text="Jméno školy:")
            self.searchSchoolLabel.grid(row = 2, column = 0)
            self.searchSchoolEntry = ttk.Entry(self.searchOptionsFrame)
            self.searchSchoolEntry.grid(row = 2, column = 1)
            self.deleteOptions = True
    def __init__(self, root):
        root.geometry("850x500")
        root.title('Administrace')
        #root.resizable(False, False)     
        def_font = tkinter.font.nametofont("TkDefaultFont")
        def_font.config(size=12)
        
        #Notebook part
        

        self.searchFrame = ttk.Frame(root)
        self.searchResetBtn = ttk.Button(self.searchFrame, text="Reset")
        self.searchResetBtn.pack(side="right", padx=10)
        self.searchBtn = ttk.Button(self.searchFrame, text="Vyhledej")
        self.searchBtn.pack(side="right", padx = 10)
        self.searchOptionsFrame = ttk.Frame(self.searchFrame)
        self.searchEntry = ttk.Entry(self.searchOptionsFrame, text="", width=5)
        self.searchEntry.grid(row = 0, column = 1, sticky="w")
        self.searchLabel = ttk.Label(self.searchOptionsFrame, text="Číslo přihlášky:")
        self.searchLabel.grid(row = 0, column = 0)
        self.searchOptionsFrame.pack(side = "right")
        self.expandSearchBtn = ttk.Button(self.searchFrame, text="Více", width=5, command=self.expandSearch)
        self.deleteOptions = False
        self.expandSearchBtn.pack(side = "right", padx=5)
        self.searchFrame.pack(fill="both", pady=20)
        self.applications = ttk.Frame(root, width=400, height=200)
        self.applications.pack()
        #self.notebook.add(self.applications, text='High schools')
        #self.notebook.add(self.applications, text='Application Forms')
        #self.notebook.bind("<ButtonRelease-1>", self.get_selected_notebook)
        #Search bar part
        
        
        #Table part - Highschool
        self.tableFrame = ttk.Frame(self.applications,borderwidth= 5)
        self.table = ttk.Treeview(self.tableFrame, columns=('cp', 'datum_podani', 'jmeno_studenta', 'jmeno_skoly'), 
                            show='headings')

        self.table.heading('cp', text='Číslo přihlášky')
        self.table.heading('datum_podani', text='Datum podání')
        self.table.heading('jmeno_studenta', text='Jméno Studenta')
        self.table.heading('jmeno_skoly', text='Název školy')

        self.table.insert('', END, values=("001", "18/03/2024", "Jiří Matonoha", "SPSEI Ostrava"))
        self.table.insert('', END, values=("002", "18/03/2024", "Jiří Matonoha","Telekomka Ostrava"))
        self.table.bind('<<TreeviewSelect>>', self.item_selected)
        self.table.grid(row=0, column=0, sticky='nsew')

        scrollbar = ttk.Scrollbar(self.tableFrame, orient=VERTICAL, command=self.table.yview)
        self.table.configure(yscroll=scrollbar.set)
        scrollbar.grid(row=0, column=1, sticky='ns')
        self.tableFrame.pack(side="top")
        self.applications.pack(side="top")
        
        #Menu part
        self.menubar = Menu(root)
        self.filemenu = Menu(self.menubar, tearoff=0)
        self.filemenu.add_command(label="Konec", command=root.quit)
        self.menubar.add_cascade(label="Soubor", menu=self.filemenu)

        root.config(menu=self.menubar)
        
        #Bottom part
        self.bottomPartFrame = ttk.Frame(root)
        self.notebook = ttk.Notebook(root)
        self.notebook.pack(fill="both", expand=True)
        self.infoFrameAF = ttk.Frame(self.notebook, width=400, height=200)
        self.AFLabelNumber = ttk.Label(self.infoFrameAF, text="Číslo přihlášky")
        self.AFLabelNumber.grid(row = 0, column = 0)

        self.infoFrameStudent = ttk.Frame(self.notebook, width=400, height=200)
        self.SLabelNumber = ttk.Label(self.infoFrameStudent, text="Jméno studenta")
        self.SLabelNumber.grid(row = 0, column = 0)
        self.infoFrameHS = ttk.Frame(self.notebook, width=400, height=200)
        self.HSLabelNumber = ttk.Label(self.infoFrameHS, text="Název školy")
        self.HSLabelNumber.grid(row = 0, column = 0)
        
        self.notebook.add(self.infoFrameAF, text='Podrobnosti')
        self.notebook.add(self.infoFrameStudent, text='Student')
        self.notebook.add(self.infoFrameHS, text='Škola')
        
        self.controlFrame = ttk.Frame(self.bottomPartFrame, borderwidth = 5)
        self.insertButton = ttk.Button(self.controlFrame, text="Nový záznam", command=lambda: self.createFormWindow(root))
        self.insertButton.grid(row = 0, column = 0)
        self.controlFrame.pack(side="left", anchor="w", fill="both", expand=True)
        self.bottomPartFrame.pack(side = "bottom")
        #self.formWindow.grab_set()
root = Tk()
myApp = MyApp(root)
root.mainloop()
