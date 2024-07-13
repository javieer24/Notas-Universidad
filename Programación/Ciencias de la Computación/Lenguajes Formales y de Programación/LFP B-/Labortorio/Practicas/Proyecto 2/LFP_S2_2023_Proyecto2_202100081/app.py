from tkinter import *
from tkinter import ttk
import tkinter as tk
from tkinter.ttk import Combobox
from tkinter import filedialog, messagebox
from tkinter import messagebox as MessageBox


from Analizador import *
from Lexico import *
from Sintactico import *



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
        print('• Error[Abrir()]: No se puede abrir el archivo \n')
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
    
    inputconsola.config(state=NORMAL)
    
    print('\n-- [ Analizar ] --')
    texto = str(inputtexto.get("1.0",END))
    txtconsola = analizador.analizadorBizData(texto)

    print('\n-----------[ CONSOLA ]------------')
    print(txtconsola)
    #Limpiar consola
    inputconsola.delete('1.0', 'end')
    #Agregar Texto
    inputconsola.config(state=DISABLED)



    
def Salir():
    print('Saliendo...')
    raiz.destroy()
    

def Guardar():
    rutaarchivo = filedialog.askopenfilename()
        # Abrimos el archivo de entrada
    fileOpen = open(rutaarchivo, 'w')
    # Tomamos el contenido del área de texto
    content = inputtexto.get(1.0, tk.END)
    # Escribimos en el archivo los cambios
    fileOpen.write(content)
    # Cerramos el archivo
    fileOpen.close()
    messagebox.showinfo(message="Cambios Guardados", title="Guardar")
    print('Guardando...')
    
def GuardarComo():
    new_file = filedialog.asksaveasfilename(defaultextension="txt", 
    filetypes=[("Archivos", "*.txt"), ("Todos los archivos", "*.*")]) #Cuadro de dialogo

    if not new_file: #Validar que se esté guardando un archivo
        return messagebox.showerror("Error", "No se ha guardado ningún archivo") # En caso de que no se guarde

    messagebox.showinfo("Guardar archivo", "Archivo guardado correctamente")

    # Abrimos el nuevo archivo
    new_archivo = open(new_file, "w")
    # Tomamos el contenido del área de texto 
    txt_entrada = inputtexto.get(1.0, tk.END)
    # Escribimos el contenido en el nuevo archivo
    new_archivo.write(txt_entrada)
    # Cerramos el archivo
    new_archivo.close()
    print('Guardando como...')


def ReporteErrores():
    try:
        print('Report Errores')
        #Obtiene listas errores
        ErroresLexicos = lexico.GetErrores()
        ErroresSintactico = Sintactico.GetErrores()

        
        #Validar
        if len(ErroresLexicos) <= 0 and len(ErroresSintactico) <= 0:
            #No hay Errores
            MessageBox.showinfo('Error | Reporte Errores','No hay errores que mostrar.')
        else:
            print('--- [Errores Lexicos] ---')
            print(ErroresLexicos)
            print('--- [Errores Sintacticos] ---')
            print(ErroresSintactico)
            #Crea archivo HTML
            txthtml = crearTextoHTML('Reporte Errores',['No.','Token','Fila I.','Columna I.','Fila F.','Columna F.','Tipo de Error'],ErroresLexicos)
            #Crear Archivo HTML
            ruta = 'Reporte_Errores.html'
            archivo = open(ruta,'w')
            archivo.write(txthtml)
            archivo.close()

            print('¡Reporte creado exitosamente!\nReporte_Errores.html')


        #Mensaje
    except Exception as e:
        print('Error ', e)



def crearTextoHTML(nombre,Titulos,Registros):
    
    txthtml = ''

    #Inicio
    txthtml = '''<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
<title>Proyecto 2</title>
</head>
<body>
<div class="container">
    <h1>'''+str(nombre)+'''</h1>
    <h5>BizData-Javier Monjes - 202100081</h5>
    <br>
</div>
<div class="container">
    <table class="table table-bordered">
        <thead class="thead-light">
        <tr>'''

    #----------------------------------------------------------------
    #Titulo Tabla [ CLAVES ]
    for titulo in Titulos:
        txthtml += '''                <th scope="col">'''+str(titulo)+'''</th>'''

    txthtml += '''</tr>
        </thead>'''
    #----------------------------------------------------------------


    #----------------------------------------------------------------
    #Filas Tabla
    txthtml += '''<tbody>'''

    contadorerrores = 0
    for i in range(0,len(Registros)):
        txthtml += '''<tr>'''
        registro = Registros[i]
        contador = 0
        for c in range(0,len(registro)+3):
            
            if contador == 0:
                txthtml += '''<th scope="row">'''+str(contadorerrores)+'''</th>'''    
            elif contador > 0 and contador < len(registro):
                txthtml += '''<th scope="row">'''+str(registro[contador-1])+'''</th>'''
            elif contador == 6:
                txthtml += '''<th scope="row">'''+str(registro[len(registro)-1])+'''</th>'''
            else:
                txthtml += '''<th scope="row">'''+str('--')+'''</th>'''
            contador += 1
            
        contadorerrores += 1


        txthtml += '''</tr>'''

    # for registro in Registros:
    #     txthtml += '''<tr>'''
    #     for valor in registro:
    #         txthtml += '''<th scope="row">'''+str(valor)+'''</th>'''
    #     txthtml += '''</tr>'''

    txthtml += '''</tbody>
    </table>
</div>
<br>'''
    #----------------------------------------------------------------


    # #----------------------------------------------------------------
    # #Funciones
    # txthtml += '''<div class="container">'''

    # for accion in listaAcciones:
    #     txthtml += '''<div class="row">
    #         <div class="alert alert-secondary col" role="alert">
    #             '''+str(accion)+'''
    #         </div>
    #     </div>'''

    # txthtml += '''</div>'''

    #----------------------------------------------------------------

    #Final
    txthtml += '''</body>
</html>'''
    return txthtml





raiz = Tk()
raiz.title('LFP Proyecto 2 |BizData| 202100081')
raiz.geometry('1150x600')

Label(raiz, pady=0,text='BizData', font=("Broadway",18, "bold")).place(x=575,y=10)
Button(raiz,text='Abrir', bg='#5d9b9b', fg='#eae6ca',font=("Californian FB",12), command=Abrir).place(x=15,y=40, width=90, height= 35)
Button(raiz,text='Analizar', bg='#5d9b9b', fg='#eae6ca',font=("Californian FB",12), command=Analizar).place(x=745,y=40, width=120, height= 35)
Button(raiz,text='Salir', bg='#5d9b9b', fg='#eae6ca',font=("Californian FB",12), command=Salir).place(x=1040,y=10, width=90, height= 35)
Button(raiz,text='Guardar', bg='#5d9b9b', fg='#eae6ca',font=("Californian FB",12), command=Guardar).place(x=122,y=40, width=90, height= 35)
Button(raiz,text='Guardar Como', bg='#5d9b9b', fg='#eae6ca',font=("Californian FB",12), command=GuardarComo).place(x=230,y=40, width=120, height= 35)


opcionesarchivo = ['Reportes','Errores','Tokens','Arbol',]
listaopciones = Combobox(raiz, text='Archivo', values = opcionesarchivo, font=("Californian FB",12, "bold"))
listaopciones.place(x=890,y=40, width=130, height= 35)
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
labelnumeracion = Label(raiz, pady=0,text=' 1.\n 2.\n 3.\n 4.\n 5.', font=("Lucida Sans",10), bg="#FFFFFF").place(x=12,y=82)
labelnumeracion = Label(raiz, pady=0,text=' 6.\n 7.\n 8.', font=("Lucida Sans",10), bg="#FFFFFF").place(x=12,y=160)
labelnumeracion = Label(raiz, pady=0,text=' 9.\n10.\n11.', font=("Lucida Sans",10), bg="#FFFFFF").place(x=12,y=210)
labelnumeracion = Label(raiz, pady=0,text='12.\n13.\n14.', font=("Lucida Sans",10), bg="#FFFFFF").place(x=12,y=258)
labelnumeracion = Label(raiz, pady=0,text='15.\n16.\n17.', font=("Lucida Sans",10), bg="#FFFFFF").place(x=12,y=305)
labelnumeracion = Label(raiz, pady=0,text='18.\n19.\n20.\n21.', font=("Lucida Sans",10), bg="#FFFFFF").place(x=12,y=355)
labelnumeracion = Label(raiz, pady=0,text='22.\n23.\n24.\n25.', font=("Lucida Sans",10), bg="#FFFFFF").place(x=12,y=420)
labelnumeracion = Label(raiz, pady=0,text='26.\n27.\n28.\n29.', font=("Lucida Sans",10), bg="#FFFFFF").place(x=12,y=480)
labelnumeracion = Label(raiz, pady=0,text='30.\n31.', font=("Lucida Sans",10), bg="#FFFFFF").place(x=12,y=545)

#ConsolaTkinter
inputconsola = Text(raiz, wrap=WORD, width=55, height=31,)
inputconsola.place(x=700,y=80)

raiz.mainloop()




