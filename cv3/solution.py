# -*- coding: utf-8 -*-
"""
Created on Sun Mar 10 21:44:08 2024

@author: msi pc
"""
from tkinter import *
import tkinter.font
from tkinter import ttk
from tkcalendar import DateEntry
from ttkthemes import ThemedTk
from PIL import Image, ImageTk

class MyApp:
    def item_selected(self, event):
        for selected_item in self.table.selection():
            self.showImage("school", self.table.item(selected_item)["values"][3])
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
    def showImage(self, target, value):
        self.image_label.destroy()
        image_path = "./no_image.png"
        if(target == "school"):
            if(value == "SPSEI Ostrava"):
                image_path = "./spsei_logo.jpg"
            elif(value == "Telekomka Ostrava"):
                image_path = "./telekom.png"
        elif(target == "student"):
            pass
        
        img = Image.open(image_path)
        resized_img = img.resize((200, 100))  # Resize image (optional)
        self.img_tk = ImageTk.PhotoImage(resized_img if resized_img else img)
        self.image_label = ttk.Label(self.ImageFrameStudent, image=self.img_tk)
        self.image_label.grid(row = 3, column = 2, sticky="e")
    def __init__(self, root):
        root.geometry("850x600")
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
        #Application Form info part
        self.infoFrameAF = ttk.Frame(self.notebook, width=400, height=200)
        self.AFLabelNumber = ttk.Label(self.infoFrameAF, text="Číslo přihlášky:")
        self.AFLabelNumber.grid(row = 0, column = 0, padx=5, sticky="w")
        self.AFEntryNumber = ttk.Entry(self.infoFrameAF, text="", width=5)
        self.AFEntryNumber.grid(row = 0, column = 1, sticky="w")
        self.AFLabelDate = ttk.Label(self.infoFrameAF, text="Datum podání:")
        self.AFLabelDate.grid(row = 1, column = 0, padx=5, sticky="w")
        #self.AFDateEntryDate = DateEntry(self.infoFrameAF, text="")
        self.AFEntryDate = ttk.Entry(self.infoFrameAF, text="")
        self.AFEntryDate.grid(row = 1, column = 1)
        self.AFLabelStudent = ttk.Label(self.infoFrameAF, text="Jméno studenta:")
        self.AFLabelStudent.grid(row = 2, column = 0, padx=5, sticky="w")
        self.AFEntryStudent = ttk.Entry(self.infoFrameAF, text="")
        self.AFEntryStudent.grid(row = 2, column = 1)
        self.AFLabelSchool = ttk.Label(self.infoFrameAF, text="Název školy:")
        self.AFLabelSchool.grid(row = 3, column = 0, padx = 5, sticky="w")
        self.AFEntrySchool = ttk.Entry(self.infoFrameAF, text="")
        self.AFEntrySchool.grid(row = 3, column = 1)
        
        #Student part
        self.infoFrameStudentDiv = ttk.Frame(self.notebook, width=400, height=200) 
        self.infoFrameStudent = ttk.Frame(self.infoFrameStudentDiv)
        self.SLabelName = ttk.Label(self.infoFrameStudent, text="Jméno studenta:")
        self.SLabelName.grid(row = 0, column = 0, padx=5, sticky="w")
        self.SEntryName = ttk.Entry(self.infoFrameStudent, text="")
        self.SEntryName.grid(row = 0, column = 1)
        self.SLabelGender = ttk.Label(self.infoFrameStudent, text="Pohlaví:")
        self.SLabelGender.grid(row = 1, column = 0, padx=5, sticky="w")
        self.SEntryGender = ttk.Entry(self.infoFrameStudent, text="", width=3)
        self.SEntryGender.grid(row = 1, column = 1, sticky="w")
        self.SLabelStreet = ttk.Label(self.infoFrameStudent, text="Ulice: ")
        self.SLabelStreet.grid(row = 2, column = 0, padx=5, sticky="w")
        self.SEntryStreet = ttk.Entry(self.infoFrameStudent, text="")
        self.SEntryStreet.grid(row = 2, column = 1, sticky="w")
        self.infoFrameStudent.pack(side="left", fill="both", expand=True)
        self.ImageFrameStudent = ttk.Frame(self.infoFrameStudentDiv)
        image_path = "./no_image.png"
        img = Image.open(image_path)
        resized_img = img.resize((200, 100))  # Resize image (optional)
        self.img_tk = ImageTk.PhotoImage(resized_img if resized_img else img)
        self.image_label = ttk.Label(self.ImageFrameStudent, image=self.img_tk)
        self.image_label.grid(row = 3, column = 2, sticky="e")
        self.ImageFrameStudent.pack(side="left", fill="both", padx=5)
        self.infoFrameHS = ttk.Frame(self.notebook, width=400, height=200)
        self.HSLabelNumber = ttk.Label(self.infoFrameHS, text="Název školy")
        self.HSLabelNumber.grid(row = 0, column = 0)
        
        
        self.notebook.add(self.infoFrameAF, text='Podrobnosti')
        self.notebook.add(self.infoFrameStudentDiv, text='Student')
        self.notebook.add(self.infoFrameHS, text='Škola')
        
        self.controlFrame = ttk.Frame(self.bottomPartFrame, borderwidth = 5)
        self.insertButton = ttk.Button(self.controlFrame, text="Přidat", command=lambda: self.createFormWindow(root))
        self.insertButton.grid(row = 0, column = 0)
        self.editButton = ttk.Button(self.controlFrame, text="Upravit")
        self.editButton.grid(row = 0, column = 1)
        self.deleteButton = ttk.Button(self.controlFrame, text="Odstranit")
        self.deleteButton.grid(row = 0, column = 2)
        self.controlFrame.pack(side="left", anchor="w", fill="both", expand=True)
        self.bottomPartFrame.pack(side = "bottom")
        #self.formWindow.grab_set()
#root = Tk()
root = ThemedTk(theme="yaru")
myApp = MyApp(root)
root.mainloop()
