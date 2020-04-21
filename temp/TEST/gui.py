import tkinter as tk
import os
#import matplotlib.pyplot as plt
import pandas as pd


def ambil():
    V=entryV.get()
    C=entryC.get()
    R=entryR.get()
    t_start=entryStart.get()
    t_end  =entryEnd.get()
    t_each =entryEach.get()
    
    print("Nilai Sumber Tegangan =" + V)
    print("Nilai Sumber Kapasitor =" + C)
    print("Nilai Sumber Resistor =" + R)
    print("waktu mulai mencatat =" + t_start)
    print("waktu berakhir mencatat =" + t_end)
    print("waktu ketelitian mencatat =" + t_each)
    os.system("main3"+" "+V+" "+C+" "+R+" "+t_start+" "+t_end+" "+t_each)
    

window = tk.Tk()
window.title("Mr.Spice")
window.geometry("640x640+0+0")

greeting = tk.Label(text="WELCOME TO",font=("arial",40,"bold"))
greeting.pack()
greeting2 = tk.Label(text="SPICY",font=("arial",40,"bold"))
greeting2.pack()

 
promptV = tk.Label(text="Masukkan nilai sumber tegangan")
promptV.pack()
entryV = tk.Entry(fg="black", bg="white", width=50)
entryV.pack()


promptR = tk.Label(text="Masukkan nilai resistansi")
promptR.pack()
entryR = tk.Entry(fg="black", bg="white", width=50)
entryR.pack()


promptC = tk.Label(text="Masukkan nilai Kapasitor")
promptC.pack()
entryC = tk.Entry(fg="black",bg="white", width=50)
entryC.pack()

promptStart = tk.Label(text="Masukkan waktu mulai mencatat")
promptStart.pack()
entryStart = tk.Entry(fg="black",bg="white", width=50)
entryStart.pack()


promptEnd = tk.Label(text="Masukkan waktu berakhir mencatat")
promptEnd.pack()
entryEnd = tk.Entry(fg="black",bg="white", width=50)
entryEnd.pack()

promptEach = tk.Label(text="Masukkan waktu ketelitian mencatat")
promptEach.pack()
entryEach = tk.Entry(fg="black",bg="white", width=50)
entryEach.pack()

button = tk.Button( text="Submit",width=25,height=5,bg="black",fg="white",command =ambil)
button.pack()

#df = pd.read_csv ("Data.csv")

#plt.plot('time','Vo')
#plt.xlabel('time')
#plt.ylabel('Vo')
#plt.show()


window.mainloop()


