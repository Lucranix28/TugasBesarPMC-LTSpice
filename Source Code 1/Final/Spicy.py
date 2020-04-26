import tkinter as tk
import os
import matplotlib.pyplot as plt
import pandas as pd
from matplotlib import style
from tkinter import ttk

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
        plt.plot(df['Waktu']*100,df['Vc(V)'])
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
 
promptV = tk.Label(text="Masukkan Nilai sumber tegangan",bg ='#84a9ac')
promptV.pack()
entryV = tk.Entry(fg="black", bg="white", width=50,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryV.pack()
satuanV = tk.Label(window, text = "V",bg = '#84a9ac',fg='black')
satuanV.place(x=473,y=123)

promptR = tk.Label(text="Masukkan Nilai resistansi",bg ='#84a9ac')
promptR.pack()
entryR = tk.Entry(fg="black", bg="white", width=50,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryR.pack()
satuanR = tk.Label(window, text = "Ω",bg = '#84a9ac',fg='black')
satuanR.place(x=473,y=163)

promptC = tk.Label(text="Masukkan Nilai Kapasitor",bg ='#84a9ac')
promptC.pack()
entryC = tk.Entry(fg="black",bg="white", width=50,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryC.pack()
satuanC = tk.Label(window, text = "μF",bg = '#84a9ac',fg='black')
satuanC.place(x=473,y=203)

promptVc = tk.Label(text="Masukkan Tegangan Awal Kapasitor",bg ='#84a9ac')
promptVc.pack()
entryVc = tk.Entry(fg="black",bg="white", width=50,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryVc.pack()
satuanVc = tk.Label(window, text = "V",bg = '#84a9ac',fg='black')
satuanVc.place(x=473,y=243)


promptEnd = tk.Label(text="Masukkan waktu berakhir mencatat",bg ='#84a9ac')
promptEnd.pack()
entryEnd = tk.Entry(fg="black",bg="white", width=50,validate='key', vcmd=(window.register(validate_entry), '%P'))
entryEnd.pack()
satuanT = tk.Label(window, text = "ms",bg = '#84a9ac',fg='black')
satuanT.place(x=473,y=283)


submit = tk.Button( text="Submit",width=10,height=1,bg="#f1f3f4",fg="#84a9ac",command =ambil)
submit.pack(padx=10,pady=10)

label = ttk.Label(window, text = "Hello Tkinter")
label.configure(foreground = '#84a9ac')
label.configure(background = '#84a9ac')
label.place(x=370,y=315)

Reset = tk.Button( text="Reset",width=10,height=1,bg="#f1f3f4",fg="#84a9ac",command =reset)
Reset.pack(padx=10,pady=10)

Quit = tk.Button(text = "Quit",width=10,height=1,bg="#30475e",fg="#f1f3f4", command = close_window)
Quit.pack(padx=10,pady=10)


window.mainloop()

