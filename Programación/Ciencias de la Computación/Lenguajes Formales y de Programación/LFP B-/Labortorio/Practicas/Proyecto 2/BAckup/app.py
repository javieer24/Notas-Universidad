from tkinter import *
import tkinter as tk
from tkinter.ttk import Combobox
from tkinter import filedialog, messagebox


from Analizador import *
from Lexico import *

def Abrir():
    print('-- [ Abrir ] --')
    #Limpiar input
    inputtexto.delete('1.0', 'end')
    #Obtener ruta 
    rutaarchivo = filedialog.askopenfilename()
    print('Ruta archivo: "',rutaarchivo,'"')
    #Obtener Texto
    textoarchivo = ''
    try:
        with open(rutaarchivo, 'r') as archivo:
            textoarchivo = archivo.read()
    except Exception as e:
        print('• Error[Abrir()][Tk_ventana][CD001]: No se puede abrir el archivo \n')
        print(e)
    
    #Imprimir Texto
    if textoarchivo == '':
        print('No hay texto que procesar...')
    else:
        print('-------------------------')
        print(textoarchivo)
        print('-------------------------')
        #Añadir texto a input
        inputtexto.insert('1.0', str(textoarchivo))
    
    #Analizar
def Analizar():
    print('\n-- [ Analizar ] --')
    texto = str(inputtexto.get("1.0",END))
    txtconsola = analizador.analizadorBizData(texto)

    print('\n-----------[ CONSOLA ]------------')
    print(txtconsola)
    #Limpiar consola
    inputconsola.delete('1.0', 'end')
    #Agregar Texto
    inputconsola.insert('1.0', str(txtconsola))




raiz = Tk()
raiz.title('LFP Proyecto 2 | 202100081')
raiz.geometry('1150x600')

Label(raiz, pady=0,text='PROYECTO 2 | 202100081', font=("Consolas",14)).place(x=50,y=20)
Button(raiz,text='Abrir', bg='#DBE6A1', fg='#000000',font=("Consolas",12), command=Abrir).place(x=500,y=20, width=90, height= 35)
Button(raiz,text='Analizar', bg='#DBE6A1', fg='#000000',font=("Consolas",12), command=Analizar).place(x=610,y=20, width=120, height= 35)


opcionesarchivo = ['Reportes','Errores','Tokens','Arbol',]
listaopciones = Combobox(raiz, text='Archivo', values = opcionesarchivo, font=("Consolas",11))
listaopciones.place(x=750,y=20, width=130, height= 35)
listaopciones.current(0)
#Switch case
def seleccion(event):
    print('Seleccionando ->', listaopciones.get())
    sel = listaopciones.get()
    if sel == 'Errores':
        print('Errores')
    elif sel == 'Tokens':
        print('Tokens')
    elif sel == 'Arbol':
        print('Arbol')
    elif sel == 'Salir':
        print('Salir')
#Ejecuta la opcion cuando cambia de seleccion
listaopciones.bind('<<ComboboxSelected>>',seleccion)

#Input
inputtexto = Text(raiz, padx=40, wrap='none', width=75, height=31,)
inputtexto.place(x=10,y=80)

#Etiquetas Input
labelnumeracion = Label(raiz, pady=0,text=' 1.\n 2.\n 3.\n 4.\n 5.', font=("Consolas",10), bg="#FFFFFF").place(x=12,y=82)
labelnumeracion = Label(raiz, pady=0,text=' 6.\n 7.\n 8.', font=("Consolas",10), bg="#FFFFFF").place(x=12,y=160)
labelnumeracion = Label(raiz, pady=0,text=' 9.\n10.\n11.', font=("Consolas",10), bg="#FFFFFF").place(x=12,y=210)
labelnumeracion = Label(raiz, pady=0,text='12.\n13.\n14.', font=("Consolas",10), bg="#FFFFFF").place(x=12,y=258)
labelnumeracion = Label(raiz, pady=0,text='15.\n16.\n17.', font=("Consolas",10), bg="#FFFFFF").place(x=12,y=305)
labelnumeracion = Label(raiz, pady=0,text='18.\n19.\n20.\n21.', font=("Consolas",10), bg="#FFFFFF").place(x=12,y=355)
labelnumeracion = Label(raiz, pady=0,text='22.\n23.\n24.\n25.', font=("Consolas",10), bg="#FFFFFF").place(x=12,y=420)
labelnumeracion = Label(raiz, pady=0,text='26.\n27.\n28.\n29.', font=("Consolas",10), bg="#FFFFFF").place(x=12,y=480)
labelnumeracion = Label(raiz, pady=0,text='30.\n31.', font=("Consolas",10), bg="#FFFFFF").place(x=12,y=545)

#ConsolaTkinter
inputconsola = Text(raiz, wrap=WORD, width=55, height=31,)
inputconsola.place(x=700,y=80)

raiz.mainloop()






