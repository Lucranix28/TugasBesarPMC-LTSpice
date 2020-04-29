import tkinter as tk
import os
import matplotlib.pyplot as plt
import pandas as pd
from matplotlib import style
from tkinter import *
from tkinter import ttk
from PIL import Image,ImageTk

def validate_entry(inp):
    if inp != "" : 
        try:
            float(inp)
        except:
            return False
        return True
    else :
        return True

def ambil():
    V=entryV.get()
    C=entryC.get()
    Vc=entryVc.get()
    R=entryR.get()
    t_end  =entryEnd.get()
    
    print("Nilai Sumber Tegangan =" + V)
    print("Nilai Kapasitor =" + C)
    print("Nilai Tegangan Awal Kapasitor =" + Vc)
    print("Nilai Resistor =" + R)
    print("Waktu berakhir mencatat =" + t_end)
    
    if V=="" or C=="" or R=="" or t_end=="" or Vc=="" :
        label.configure(text = "Input Salah")
        label.configure(foreground = 'red')
    else :
        label.configure(text = "Plot Berhasil")
        label.configure(foreground = 'white')
        os.system("RC"+" "+V+" "+C+" "+R+" "+" "+Vc+" "+t_end)
    
        style.use("ggplot")
    
        df = pd.read_csv("out.csv")
        plt.plot(df['Waktu']*1000,df['Vc(V)'])
        plt.xlabel("Waktu(ms)")
        plt.ylabel('Vc(V)')
        
        plt.show()

def reset():
    plt.close('all')

def close_window (): 
    window.destroy()


window = tk.Tk()

frame =tk.Frame(window, bg ='#84a9ac')
frame.place(relwidth = 1, relheight = 1) 

c = tk.Frame(window,height =103,width=1000,bg='black')
c.place(relx=0.1,relwidth=0.8)

window.title("Mr.Spice")
window.geometry("640x640")

greeting = tk.Label(window,text="WELCOME TO",font=("verdana",10),fg="#f1f3f4",bg ='black')
greeting.pack(pady=5)
greeting2 = tk.Label(window,text="SPICY",font=("verdana",40,"italic","bold"),fg="#f1f3f4",bg ='black')
greeting2.pack()

im=Image.open("RC.png")
photo=ImageTk.PhotoImage(im)  
label = tk.Label(image=photo)
label.place(x=230,y=110)
 
promptV = tk.Label(text="Nilai Sumber Tegangan",bg ='#84a9ac')
promptV.place(x=100,y=250)
entryV = tk.Entry(fg="black", bg="white", width=25,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryV.place(x=90,y=275)
satuanV = tk.Label(window, text = "V",bg = '#84a9ac',fg='black')
satuanV.place(x=247,y=275)

promptR = tk.Label(text="Nilai Resistansi",bg ='#84a9ac')
promptR.place(x=120,y=305)
entryR = tk.Entry(fg="black", bg="white", width=25,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryR.place(x=90,y=330)
satuanR = tk.Label(window, text = "Ω",bg = '#84a9ac',fg='black')
satuanR.place(x=247,y=330)

promptC = tk.Label(text="Nilai Kapasitor",bg ='#84a9ac')
promptC.place(x=425,y=250)
entryC = tk.Entry(fg="black",bg="white", width=25,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryC.place(x=390,y=275)
satuanC = tk.Label(window, text = "μF",bg = '#84a9ac',fg='black')
satuanC.place(x=547,y=275)

promptVc = tk.Label(text="Tegangan Awal Kapasitor",bg ='#84a9ac')
promptVc.place(x=395,y=305)
entryVc = tk.Entry(fg="black",bg="white", width=25,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryVc.place(x=390,y=330)
satuanVc = tk.Label(window, text = "V",bg = '#84a9ac',fg='black')
satuanVc.place(x=547,y=330)


promptEnd = tk.Label(text="Waktu Berakhir Mencatat",bg ='#84a9ac')
promptEnd.place(x=250,y=360)
entryEnd = tk.Entry(fg="black",bg="white", width=25,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryEnd.place(x=240,y=385)
satuanT = tk.Label(window, text = "ms",bg = '#84a9ac',fg='black')
satuanT.place(x=397,y=385)


submit = tk.Button( text="Submit",width=10,height=1,bg="#f1f3f4",fg="#84a9ac",command =ambil)
submit.place(x=280,y=430)

label = ttk.Label(window, text = "Hello Tkinter")
label.configure(foreground = '#84a9ac')
label.configure(background = '#84a9ac')
label.place(x=374,y=433)

Reset = tk.Button( text="Reset",width=10,height=1,bg="#f1f3f4",fg="#84a9ac",command =reset)
Reset.place(x=280,y=465)

Quit = tk.Button(text = "Quit",width=10,height=1,bg="#30475e",fg="#f1f3f4", command = close_window)
Quit.place(x=280,y=500)

window.mainloop()

