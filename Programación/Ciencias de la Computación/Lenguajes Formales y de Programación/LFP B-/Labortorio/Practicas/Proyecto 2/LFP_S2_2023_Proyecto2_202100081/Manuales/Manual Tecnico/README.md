# **Manual Técnico**

Requisitos minimos del Sistema Operativo para ejecutar el programa:

- Windows 10 (8u51 y superiores)
- Windows 8.x (escritorio)
- Windows 7 SP1
- Windows Vista SP2
- RAM: 128MB
- Espacio en Disco: 124 MB para python
- Procesador: Minimo Pentium 2 a 266 M

## **Descripción General**

El proyecto #2, llamado "BizData", es un proyecto de desarrollo de software que tiene como objetivo principal la implementación de un analizador léxico y sintáctico para un lenguaje de programación de propósito general. Este analizador será utilizado en la plataforma BizData, diseñada para ayudar a las pequeñas empresas a tomar decisiones estratégicas basadas en el análisis profundo de sus datos comerciales.

El analizador léxico y sintáctico, que será desarrollado en Python, debe ser capaz de identificar los tokens del lenguaje y los errores léxicos. Además, debe ser capaz de ejecutar las instrucciones del lenguaje de acuerdo con su sintaxis y generar un archivo HTMl con los resultados de la ejecución.

El lenguaje que se va a analizar tiene una estructura específica para la importación de datos, la declaración de claves y registros, y la inclusión de comentarios. También incluye varias instrucciones para la generación de reportes, como imprimir, contar registros, calcular promedios, sumar valores de un campo específico, encontrar valores máximos y mínimos, y exportar reportes en formato HTML.

En resumen, el proyecto BizData es una oportunidad para que los estudiantes apliquen los conceptos aprendidos en clase y en el laboratorio sobre gramáticas independientes de contexto, árboles de derivación y ejecución de instrucciones en un lenguaje de programación.


# Estructura Proyecto 2 carpetas  y archivos

~~~
LFP_S2_2023_Proyecto1_201906795
├── Arbol_JFLAP
│   └── Imagenes, AFD, Gramaticas para los manuales( no lo hice no me dio tiempo jajaj)
├── Analizador
│   └── analizador.py
├── Lexico
│   └── Lexico.py
├── Manuales
│   └── Manual Tecnico
│   └─Manual_de_Usuario
├── Sintactico
│   └── analizadorSintactico.py
├── Funciones
│   └── funciones.py
└── app.py.py
└── README.md
~~~


## **Diccionario de librerías**

### Libreria Tkinter:
- Tkinter es una libreria que funciona para la creación y el desarrollo de aplicaciones de escritorio. Esta librería facilita el posicionamiento y desarrollo de una interfaz gráfica de escritorio con python. TK se describe a sí mismo como el único toolkit o kit de herramientas para el desarrollo de una interfaz gráfica de usuario.

### Libreria FileDialog:
- FileDialog es una libreria que funciona para la creación y el desarrollo de aplicaciones de escritorio. Esta librería facilita el posicionamiento y desarrollo de una interfaz gráfica de escritorio con python. FileDialog se describe a sí mismo como el único toolkit o kit de herramientas para el desarrollo de una interfaz gráfica de usuario.

### Libreria MessageBox:
- MessageBox es una libreria que funciona para la creación y el desarrollo de aplicaciones de escritorio. Esta librería facilita el posicionamiento y desarrollo de una interfaz gráfica de escritorio con python. MessageBox se describe a sí mismo como el único toolkit o kit de herramientas para el desarrollo de una interfaz gráfica de usuario.

### Libreria Combobox:
- Combobox es una libreria que funciona para la creación y el desarrollo de aplicaciones de escritorio. Esta librería facilita el posicionamiento y desarrollo de una interfaz gráfica de escritorio con python. Combobox se describe a sí mismo como el único toolkit o kit de herramientas para el desarrollo de una interfaz gráfica de usuario.

## **Diccionario de Archivos**

### **App**
```js
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

```
El archivo app.py es una interfaz gráfica de usuario (GUI) para un analizador sintáctico para un lenguaje de programación llamado "BizData". La GUI consta de los siguientes elementos:

Un cuadro de texto para ingresar el código BizData
Un botón para abrir un archivo BizData
Un botón para analizar el código BizData
Un botón para guardar el código BizData
Un botón para guardar el código BizData como un nuevo archivo
Un cuadro de texto para mostrar el resultado del análisis
El código BizData se ingresa en el cuadro de texto de la izquierda. El botón "Abrir" abre un archivo BizData existente. El botón "Analizar" analiza el código BizData ingresado o el código BizData del archivo abierto. El botón "Guardar" guarda el código BizData ingresado en el archivo original. El botón "Guardar como" guarda el código BizData ingresado en un nuevo archivo. El cuadro de texto de la derecha muestra el resultado del análisis.

El código BizData es un lenguaje de programación sencillo que se utiliza para representar datos de negocios. El analizador sintáctico para el lenguaje BizData se implementa en Python. El analizador sintáctico se basa en un parser descendente recursivo.

* Abrir(): Abre un archivo BizData existente.
* Analizar(): Analiza el código BizData ingresado o el código BizData del archivo abierto.
* Guardar(): Guarda el código BizData ingresado en el archivo original.
* GuardarComo(): Guarda el código BizData ingresado en un nuevo archivo.
* crearTextoHTML(): Crea un archivo HTML con un informe de errores.
* ReporteErrores(): Crea un archivo HTML con un informe de errores.
* Salir(): Cierra la ventana de la GUI.



### **Analizador**
```js

from Lexico import *
from Sintactico import *
from Funciones import *

AnalizadorErrores = []


def analizadorBizData(texto):
    global AnalizadorErrores
    print('Analizando la información...')
    print(texto)
    #Pasa por el analizador  Lexico y Obtiene los Tokens
    tokens = lexico.GetTokens(texto)
    lexico.imprimirlistatokens()
    lexico.imprimirerroreslexicos()
    
    if len(tokens) >0:
       #Pasar al analizador Sintactico y obtener Estructuras
        instrucciones = Sintactico.GetInstrucciones(tokens)
        Sintactico.imprimirErrores()
        Sintactico.imprimirlistaSintactico()
        #[A]Obtener Errores
        #[A1]Obtener Errores Lexicos
        erroresLexicos = Sintactico.GetErrores()
        #[A2]Obtener Errores Sintacticos
        erroresSintactico = Sintactico.GetErrores()
        #[A3]Unir Errores
        nuevalista = unirdoslistas(erroresLexicos, erroresSintactico) 
        AnalizadorErrores = nuevalista
        # imprimirErrores()

        #Ejecutar instrucciones
        txtconsola = funciones.ejecutar(instrucciones)
        #funciones.imprimirInstrucciones()
        #Retornar informacion consola
        return txtconsola
        



def imprimirErrores():
    global AnalizadorErrores
    print('\n------------[ ERRORES ]----------------\n')
    for i in AnalizadorErrores:
        print(i)
    print('\n---------------------------------------')


def unirdoslistas(lista1, lista2):
    newlist = []
    for i in lista1:
        newlist.append(i)
    for j in lista2:
        newlist.append(j)

    return newlist    
```

El archivo analizador.py es un analizador sintáctico para un lenguaje de programación llamado "BizData". El analizador es responsable de dividir el código fuente de BizData en tokens, que son unidades de código individuales. Una vez que el código fuente se ha dividido en tokens, el analizador puede verificar que el código esté bien formado y que siga las reglas de sintaxis del lenguaje BizData.

El archivo analizador.py contiene las siguientes funciones principales:

analizadorBizData(): Esta función es el punto de entrada al analizador. Recibe el código fuente de BizData como entrada y devuelve una lista de instrucciones, que son unidades de código que pueden ser ejecutadas por el intérprete de BizData.
GetInstrucciones(): Esta función toma una lista de tokens como entrada y devuelve una lista de instrucciones.
ErroresSintactico(): Esta función es una clase que representa un error sintáctico.
El archivo analizador.py es un componente importante de un compilador o intérprete para el lenguaje BizData. El analizador es responsable de verificar que el código fuente sea válido y que pueda ser ejecutado por el compilador o intérprete.

### **Lexico**
```js


from tkinter import messagebox as MessageBox


#Variables

tokens = []
linea = 1
columna = 1
listaerrores = []
listadocaracteresbuscados = ['{','}',':','[',']',',','(',')',';','=','"',"'",'#','_','-','.']
listaabecedario = ['A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z','Ñ','ñ']

flagcomillas = False



def evaluartexto(texto):
    global tokens, linea, columna, listaerrores, listadocaracteresbuscados, flagcomillas
    #IDtoken
    id = -1
    #Iterador
    c=0
    #Numero maximo de iteraciones
    maxiter = len(texto)
    while c < maxiter:
        id += 1
        #Obtener caracter
        caracter = texto[c]
        #Evaluar
        
        if caracter == '"' or caracter == "'":
            #Guardar inicio
            templinea = linea
            tempcolumna = columna
            #Evaluar si es un comentario multilinea
            caractersig = texto[c+1:c+2]
            if caractersig == '"' or caractersig == "'":
                caractersig2 = texto[c+2:c+3]
                if caractersig2 == '"' or caractersig2 == "'":
                    print('Comentario multilinea')
                    #obtener texto entre comillas
                    textoaevaluar = texto[c+3:]
                    string, pos, lineasextra, columnastring = obtenercomentariomultilinea(textoaevaluar, c,columna)
                    #Aumentar contador y columna
                    c = pos + 4
                    columna = columnastring
                    linea = linea + lineasextra
                    #Almacenar token
                    tokens.append([id,string,templinea,tempcolumna,'Comentario_multilinea',linea, columna])
                    print('token: ', string, ' linea:', linea,' columna: ',columna)
            else:
                #Almacena token
                tokens.append([id,caracter,linea,columna,'token'])
                print('token: ', caracter, ' linea:', linea,' columna: ',columna)
                columna += 1
                c += 1
                #Activar bandera
                if flagcomillas == False:
                    flagcomillas = True
                else:
                    flagcomillas = False
       
        elif caracter == '#':
            #Guardar inicio
            templinea = linea
            tempcolumna = columna
            #Si es un texto un posible token
            textoaevaluar = texto[c+1:]
            string, pos = obtenercomentario(textoaevaluar, c)
            string = '#'+string
            #Aumentar contador y columna
            c = pos + 1
            columna = len(string) + 1
            #Almacenar token
            tokens.append([id,string,templinea,tempcolumna,'Comentario_simple',linea, columna])
            print('token: ', string, ' linea:', linea,' columna: ',columna)
        
        elif caracter == '\n':
            #Almacena token
            tokens.append([id,caracter,linea,columna,'salto_linea'])
            print('token: ', caracter, ' linea:', linea,' columna: ',columna)
            #Si es un Salto de linea | Aumenta la linea | Reinicia columnas
            linea += 1
            columna = 1
            c += 1
        
        elif caracter.isspace():
            #Si es algun tipo de espacio
            if caracter == '\t':
                #Si es un Tabulador | Aumenta la columna en 4
                columna += 4
            else:
                #Si es un espacio | Aumenta la columna
                #Validar si esta dentro de comillas
                if flagcomillas == True:
                    #Almacena token
                    tokens.append([id,caracter,linea,columna,'espacio'])
                columna += 1
            #Contador
            c += 1
        
        elif caracter in listadocaracteresbuscados:
            #Almacena token
            tokens.append([id,caracter,linea,columna,'token'])
            print('token: ', caracter, ' linea:', linea,' columna: ',columna)
            #Aumenta columna
            columna += 1
            #Contador
            c += 1
        
        elif caracter in listaabecedario:
            #Almacena token
            tokens.append([id,caracter,linea,columna,'token'])
            print('token: ', caracter, ' linea:', linea,' columna: ',columna)
            #Aumenta columna
            columna += 1
            #Contador
            c += 1
       
        elif caracter.isdigit():
            #Almacenar token
            tokens.append([id,caracter,linea, columna,'Numero'])
            print('token: ', caracter, ' linea:', linea,' columna: ',columna)
            #Aumenta columnas
            columna += 1
            #Contador
            c += 1
       
        else:
            #Caracter Desconocido
            print("\033[1;31;40m Error: caracter desconocido:", caracter," |Linea:",linea," |Columna:",columna,"\033[0m")
            #Almacenar error
            listaerrores.append([caracter, linea, columna,'error lexico'])
            #Aumentar contador y columna
            c += 1
            columna += 1



def obtenercomentariomultilinea(text, a, columna):
    #Texto
    string = ''
    lineasextra = 0
    #Evaluar caracter por carcater
    c = 0
    for newcaracter in text:
        columna += 1
        if newcaracter == "\n":
            lineasextra +=1
            columna = 1
        elif newcaracter == '"' or newcaracter == "'":
            caractersig = text[c+1:c+2]
            if caractersig == '"' or caractersig == "'":
                caractersig2 = text[c+2:c+3]
                if caractersig2 == '"' or caractersig2 == "'":
                    columna += 1
                    a += 2            
                    return [string, a, lineasextra, columna]
        #Forma el texto
        string += newcaracter
        a += 1
        c += 1
    print("Error: No se encontraron comillas doble que cerraran el texto.")



def obtenercomentario(text, a):
    #Texto
    string = ''
    #Evaluar caracter por carcater
    for caracter in text:
        if caracter == '\n':
            return [string, a]
        #Forma el texto
        string += caracter
        a += 1
    print("Error: Al obtenrecomentario().")



def obtenernumero(texto, a):
    numero = ""
    isDecimal = False
    for newcaracter in texto:
        if newcaracter.isdigit():
            numero += newcaracter
            a += 1
        elif newcaracter == "." and not isDecimal:
            numero += newcaracter
            a += 1
            isDecimal = True
        else:
            break
    if isDecimal:
        return [float(numero), a]
    return [int(numero), a]




def enumerartokens():
    global tokens
    for i in range(0,len(tokens)):
        Token = tokens[i]
        #Cambiar ID
        tokens[i][0] = i
        Token = tokens[i]


def imprimirerroreslexicos():
    print('--------- [ ERRORES LEXICOS ] ---------\n')
    for i in listaerrores:
        print(i)



def imprimirlistatokens():
    print('--------- [ TOKENS ] ---------\n')
    for i in tokens:
        print(i)
        
        
def GetErrores():
    return listaerrores


def GetTokens(texto):
    #Valida el tamaño del texto
    if len(texto) < 0:
        MessageBox.showerror('Error - lexico()','No hay informacion necesarioa para procesarlo')
        return
    #Reinicia los valores
    global tokens, linea, columna, listaerrores, flagcomillas
    tokens = []
    linea = 1
    columna = 1
    listaerrores = []
    flagcomillas = False
    #Analiza el Texto
    evaluartexto(texto)
    
    #Pone un ID CORRECTO
    enumerartokens()
    
    return tokens

```
lexico.py para el lenguaje BizData es un programa que se encarga de dividir el texto de un programa BizData en unidades más pequeñas llamadas tokens. Los tokens son los elementos básicos de un lenguaje de programación, y el analizador léxico es el encargado de identificarlos y clasificarlos.

Las principales funciones del analizador léxico para el lenguaje BizData son:

Identificar los tokens del lenguaje BizData.
Clasificar los tokens.
Generar un informe de errores.

### **Sintactico**
```js


listaSintactico = []
listaErroresSintactico = []
listatokens = []
listaClaves = []
templistaClaves = []
templistatokens = []
listaRegistros = []
templistaRegistros = []
templista = []
frenogramaticaR = False
listasimbolos = ['{','}',':','[',']',',','(',')',';','=','"',"'",'#','_','-','.']
listaletras = ['A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z','Ñ','ñ']
listanumeros = ['0','1','2','3','4','5','6','7','8','9','.']


def imprimirErrores():
    print('\n----------------------------- [ Errores | Sintactico]----------------------------- \n')
    for i in listaErroresSintactico: 
        print(i)


def imprimirlistaSintactico():
    print('\n----------------------------- [ Lista Sintactico | Instrucciones]----------------------------- \n')
    for i in listaSintactico:
        print(i)
    print('\n')


def enumerarlistatokens():
    global listatokens
    print('\n-----------------------------  [ NUEVA LISTA TOKENS] ----------------------------- \n')
    for i in range(0,len(listatokens)):
        Token = listatokens[i]
        #Cambiar ID
        listatokens[i][0] = i
        Token = listatokens[i]
        print(Token)
    print('\n-----------------------------  [ FIN ] ----------------------------- \n')


def obtenernumero(a):
    global listatokens, listanumeros
    inicio = a
    fin = a
    txtnumero = ''
    #-----
    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        #Busca si esta en el listado de numeros
        if token in listanumeros:
            txtnumero += token
            a += 1
            fin = a
        else:
            fin = a
            a = maxiteraciones 
    #-----
    #Convierte txtnumero
    if len(txtnumero) <= 0:
        return [None,fin]
    else:
        try:
            numero = float(txtnumero)
            return [numero, fin]
        except:
            return [None, fin]



def obtenertexto(a):
    global listatokens
    inicio = a
    texto = ''
    #-----
    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        if token == '"' or token == "'":
            a += 1
            return [texto,a]
        else:
            texto += token
            a += 1


def fininstruccion(a,tokenesperado):
    global listatokens, listaErroresSintactico
    inicio = a
    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        if token == ';' or token == '\n':
            a += 1
            #Validador para que no se salga de lista 
            if a >= maxiteraciones:
                a -= 1
            #Agregar a errores
            listaErroresSintactico.append([listatokens[inicio][1],str(tokenesperado),listatokens[inicio][2],listatokens[inicio][3],'error Sintactico',listatokens[a-1][2],listatokens[a-1][3]])
            
    
            return a
        else:
            a += 1

def fininstruccionPornumero(start,a,tokenesperado,fin):
    global listatokens, listaErroresSintactico
    inicio = start
    #Obtener numero
    txtnumero=''
    for i in range(start,fin,1):
        txtnumero += listatokens[i][1]
    

    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        if token == ';' or token == '\n':
            a += 1
            #Agregar a errores
            listaErroresSintactico.append([str(txtnumero),str(tokenesperado),listatokens[inicio][2],listatokens[inicio][3],'error Sintactico',listatokens[inicio][2],listatokens[a-1][3]])
            return a
        else:
            a += 1


def obtenertextoentrecomillasLista(c):
    global templistaClaves
    Token = listatokens[c][1]
    if Token == '"':
        AFDTexto = AFDTextoentrecomillas(c)
        if AFDTexto == True:
            texto, a = obtenertexto(c+1)
            c = a
            templistaClaves.append(texto)
            token = listatokens[c][1]
            if listatokens[c][1] == ']':
                return c
            elif listatokens[c][1] == ',':
                if listatokens[c+1][1] == '"':
                    c = obtenertextoentrecomillasLista(c+1)
                else:
                    c = fininstruccion(c+1,'"')  
            else:
                # c = fininstruccion(c,',')
                return c
        else:
            c = ErrorAFDTextoentrecomillas(c+1,'"')
            #Validar si es el ultimo dato de la fila
            token = listatokens[c-1][1]
            if token == ']':
                c = c
            else:
                # c = fininstruccion(c,']')  
                c = c
    else:
        c = fininstruccion(c,'"')
    return c


def quitarespaciosysaltosdelinea(c,tokenabuscarparaparar):
    global templistatokens
    #Agregar tokens a nueva lista
    for i in listatokens:
        templistatokens.append(i)
    # templistatokens = listatokens
    inicio = c
    fin = 0
    maxiteraciones = len(templistatokens)
    while c < maxiteraciones:
        token = templistatokens[c][1]
        #Break
        if token == tokenabuscarparaparar:
            fin = c
            c = maxiteraciones
        elif token.isspace():
            #Remover
            templistatokens.pop(c)
            maxiteraciones -= 1
        else:
            #Aumentar contador
            c += 1


    #Validar
    if fin <= 0:
        return [False, fin]
    else:
        return [True, fin]


def ErrorAFDTextoentrecomillas(a,tokenesperado):
    global listatokens, listaErroresSintactico
    inicio = a
    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        #Salida
        if token == ')' or token == ';' or token == '\n' or token == ']' or token == ',':
            a += 1
            #Agregar a errores
            listaErroresSintactico.append([listatokens[a-1][1],str(tokenesperado),listatokens[a-1][2],listatokens[a-2][3],'error Sintactico',listatokens[a-1][2],listatokens[a-1][3]])
            return a
        else:
            a += 1



def AFDTextoentrecomillas(c):
    global listatokens
    #iterador
    maxiteraciones = len(listatokens)
    #TEXTO
    texto = ''
    #Estados
    #q1,q2,q3,q4,q5
    inicio = 0
    final = 5
    estado = inicio

    if listatokens[c][1] == '"':
        estado = 1
        c+=1
        while c < maxiteraciones:
            #Token
            token = listatokens[c][1]
            #Salida
            if token == ')' or token == ';' or token == '\n' or token == ']' or token == ',':
                return False
            elif token == '"':
                estado = 5
                c+=1
                return True
            elif token in listaletras:
                estado = 2
                c+=1
            elif token in listasimbolos:
                estado = 3
                c+=1
            elif token.isdigit():
                estado = 4
                c+=1
            else:
                c+=1
        
        return False


def AFDListaTexto(c):
    global listatokens
    #iterador
    maxiteraciones = len(listatokens)
    #TEXTO
    texto = ''
    #Estados
    #q1,q2,q3,q4,q5,q6,q7,q8,q9
    inicio = 1
    final = 7
    estado = inicio

    if listatokens[c][1] == '[':
        estado = 2
        texto += '['
        c+=1
        if listatokens[c][1] == '"':
            estado = 3
            texto += '"'
            c+=1
            while c < maxiteraciones:
                #Token
                token = listatokens[c][1]
                if token == ')' or token == ';' or token == '\n':
                    return False
                elif token == '"':
                    estado = 5
                    texto += '"'
                    c+=1
                    break
                elif token in listaletras or token in listasimbolos or token in listanumeros:
                    estado = 4
                    texto += token
                    c+=1
                else:
                    c+=1
        
        token2 = listatokens[c][1]
        if token2 == ']':
            estado = 7
            texto += ']'
            c+=1
            return True
        elif listatokens[c][1] == ',':
            estado = 6
            texto += ','
            c+=1
            if listatokens[c][1] == '"':
                estado = 8
                texto += '"'
                c+=1
                while c < maxiteraciones:
                    token = listatokens[c][1]
                    if token == '"':
                        estado = 5
                        texto += '"'
                        c+=1
                        break
                    elif token in listaletras or token in listasimbolos or token in listanumeros:
                        estado = 9
                        texto += token
                        c+=1
                    else:
                        c+=1

        token2 = listatokens[c][1]
        if token2 == ']':
            estado = 7
            texto += ']'
            c+=1
            return True 
        
    return False


def getTextoentrecomillas(c):
    global listatokens
    #iterador
    maxiteraciones = len(listatokens)
    #TEXTO
    texto = ''
    if listatokens[c][1] == '"':
        c+=1
        while c < maxiteraciones:
            #Token
            token = listatokens[c][1]
            if token == '"':
                c+=1
                return texto, c
            elif token in listaletras or token in listasimbolos:
                #Añadir token
                texto += token
                c+=1
            else:
                c+=1


def Gramaticatokeni(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'i':
        if listatokens[c+1][1] == 'm':
            if listatokens[c+2][1] == 'p':
                if listatokens[c+3][1] == 'r':
                    if listatokens[c+4][1] == 'i':
                        if listatokens[c+5][1] == 'm':
                            if listatokens[c+6][1] == 'i':
                                if listatokens[c+7][1] == 'r':
                                    if listatokens[c+8][1] == '(':
                                        c = GramaticaEspecialtextoentreparentesisycomillas(c+8,'imprimir')
                                    else:
                                        if listatokens[c+8][1] == 'l':
                                            if listatokens[c+9][1] == 'n':
                                                if listatokens[c+10][1] == '(':
                                                    c = GramaticaEspecialtextoentreparentesisycomillas(c+10,'imprimirln')
                                                else:
                                                    c = fininstruccion(c+10,'(')
                                            else:
                                                c = fininstruccion(c+9,'n')
                                        else:
                                            c = fininstruccion(c+8,'( | l ')
                                else:
                                    c = fininstruccion(c+7,'r')
                            else:
                                c = fininstruccion(c+6,'i')
                        else:
                            c = fininstruccion(c+5,'m')
                    else:
                        c = fininstruccion(c+4,'i')
                else:
                    c = fininstruccion(c+3,'r')
            else:
                c = fininstruccion(c+2,'p')
        else:
            c = fininstruccion(c+1,'m')
    
    return c


def GramaticatokenC(c):
    global listaSintactico, listatokens, listaClaves, templistaClaves

    #Remover espacios, tabulaciones y saltos de linea
    flagsinespacios, fin = quitarespaciosysaltosdelinea(c,']')
    #Nueva lista
    if flagsinespacios == True:
        #Remplazar lista sin espacios y saltos de linea para la gramatica C
        listatokens = templistatokens
        #Cambiar id listas
        enumerarlistatokens()

    #Evaluar
    if listatokens[c][1] == 'C':
        if listatokens[c+1][1] == 'l':
            if listatokens[c+2][1] == 'a':
                if listatokens[c+3][1] == 'v':
                    if listatokens[c+4][1] == 'e':
                        if listatokens[c+5][1] == 's':
                            if listatokens[c+6][1] == '=':
                                if listatokens[c+7][1] == '[':
                                    c = GramaticaEspecialListadeTextoentrecorchetes(c+7,'Claves')
                                else:
                                    c = fininstruccion(c+7,'[')
                            else:
                                c = fininstruccion(c+6,'s')
                        else:
                            c = fininstruccion(c+5,'e')
                    else:
                        c = fininstruccion(c+4,'v')
                else:
                    c = fininstruccion(c+3,'a')
            else:
                c = fininstruccion(c+2,'l')
        else:
            c = fininstruccion(c+1,'C')
    return c


def Gramaticatokenc(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'c':
        if listatokens[c+1][1] == 'o':
            if listatokens[c+2][1] == 'n':
                if listatokens[c+3][1] == 't':
                    if listatokens[c+4][1] == 'e':
                        if listatokens[c+5][1] == 'o':
                            if listatokens[c+6][1] == '(':
                                if listatokens[c+7][1] == ')':
                                    if listatokens[c+8][1] == ';':
                                        c = c+9
                                        listaSintactico.append(['conteo',None])
                                    else:
                                        c = fininstruccion(c+7,')')
                                else:
                                    c = fininstruccion(c+7,')')
                            else:
                                c = fininstruccion(c+6,'(')
                        else:
                            c = fininstruccion(c+5,'d')
                    else:
                        if listatokens[c+4][1] == 'a':
                            if listatokens[c+5][1] == 'r':
                                if listatokens[c+6][1] == 's':
                                    if listatokens[c+7][1] == 'i':
                                        if listatokens[c+8][1] == '(':
                                            if listatokens[c+9][1] == '"':
                                                AFDTexto = AFDTextoentrecomillas(c+9)
                                                if AFDTexto == True:
                                                    texto, a = obtenertexto(c+10)
                                                    c = a
                                                    if listatokens[c][1] == ',':
                                                        numero, a = obtenernumero(c+1)
                                                        inicio = c
                                                        c = a
                                                        if numero != None:  
                                                            if listatokens[c][1] == ')':
                                                                if listatokens[c+1][1] == ';':
                                                                    c=c+2
                                                                    print('\nexportarsi○\n')
                                                                    listaSintactico.append(['contarsi',[texto, numero]])
                                                                else:
                                                                    c = fininstruccion(c+1,';')    
                                                            else:
                                                                c = fininstruccion(c,')')    
                                                        else:
                                                            if listatokens[c][1] == '"':
                                                                AFDTexto = AFDTextoentrecomillas(c)
                                                                if AFDTexto == True:
                                                                    texto2, a = obtenertexto(c+1)
                                                                    c = a
                                                                    if listatokens[c][1] == ')':
                                                                        if listatokens[c+1][1] == ';':
                                                                            c += 2
                                                                            print('\nexportarsi○\n')
                                                                            listaSintactico.append(['contarsi',[texto, texto2]])
                                                                        else:
                                                                            c = fininstruccion(c+1,';')
                                                                    else:
                                                                        c = fininstruccion(c,')')
                                                                else:
                                                                    c = ErrorAFDTextoentrecomillas(c,'"')
                                                                    c = fininstruccion(c,'"')  
                                                            
                                                            # c = fininstruccionPornumero(inicio+1,c,'"|NUMERO',c)
                                                    else:
                                                        c = fininstruccion(c,',')
                                                else:
                                                    c = ErrorAFDTextoentrecomillas(c+9,'"')
                                                    c = fininstruccion(c,')')
                                            else:
                                                c = fininstruccion(c+9,'"')
                                        else:
                                            c = fininstruccion(c+8,'(')
                                    else:
                                        c = fininstruccion(c+7,'i')
                                else:
                                    c = fininstruccion(c+6,'s')
                            else:
                                c = fininstruccion(c+5,'r')
                        else:
                            c = fininstruccion(c+4,'e|a')
                else:
                    c = fininstruccion(c+3,'m')
            else:
                c = fininstruccion(c+2,'o')
        else:
            c = fininstruccion(c+1,'r')
    return c


def Gramaticatokend(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'd':
        if listatokens[c+1][1] == 'a':
            if listatokens[c+2][1] == 't':
                if listatokens[c+3][1] == 'o':
                    if listatokens[c+4][1] == 's':
                        if listatokens[c+5][1] == '(':
                            if listatokens[c+6][1] == ')':
                                if listatokens[c+7][1] == ';':
                                    c = c+8
                                    listaSintactico.append(['datos',None])
                                else:
                                    c = fininstruccion(c+7,';')
                            else:
                                c = fininstruccion(c+6,')')
                        else:
                            c = fininstruccion(c+5,'(')
                    else:
                        c = fininstruccion(c+4,'s')
                else:
                    c = fininstruccion(c+3,'o')
            else:
                c = fininstruccion(c+2,'t')
        else:
            c = fininstruccion(c+1,'a')
    return c


def Gramaticatokene(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'e':
        if listatokens[c+1][1] == 'x':
            if listatokens[c+2][1] == 'p':
                if listatokens[c+3][1] == 'o':
                    if listatokens[c+4][1] == 'r':
                        if listatokens[c+5][1] == 't':
                            if listatokens[c+6][1] == 'a':
                                if listatokens[c+7][1] == 'r':
                                    if listatokens[c+8][1] == 'R':
                                        if listatokens[c+9][1] == 'e':
                                            if listatokens[c+10][1] == 'p':
                                                if listatokens[c+11][1] == 'o':
                                                    if listatokens[c+12][1] == 'r':
                                                        if listatokens[c+13][1] == 't':
                                                            if listatokens[c+14][1] == 'e':
                                                                if listatokens[c+15][1] == '(':
                                                                    c = GramaticaEspecialtextoentreparentesisycomillas(c+15,'exportarReporte')
                                                                else:
                                                                    c = fininstruccion(c+8,'(')
                                                            else:
                                                                c = fininstruccion(c+14,'e')
                                                        else:
                                                            c = fininstruccion(c+13,'t')
                                                    else:
                                                        c = fininstruccion(c+12,'r')
                                                else:
                                                    c = fininstruccion(c+11,'o')
                                            else:
                                                c = fininstruccion(c+10,'p')
                                        else:
                                            c = fininstruccion(c+9,'e')
                                    else:
                                        c = fininstruccion(c+8,'R')
                                else:
                                    c = fininstruccion(c+7,'r')
                            else:
                                c = fininstruccion(c+6,'a')
                        else:
                            c = fininstruccion(c+5,'t')
                    else:
                        c = fininstruccion(c+4,'r')
                else:
                    c = fininstruccion(c+3,'o')
            else:
                c = fininstruccion(c+2,'p')
        else:
            c = fininstruccion(c+1,'x')
    return c


def Gramaticatokenm(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'm':
        if listatokens[c+1][1] == 'a':
            if listatokens[c+2][1] == 'x':
                if listatokens[c+3][1] == '(':
                    c = GramaticaEspecialtextoentreparentesisycomillas(c+3,'maximo')
                else:
                    c = fininstruccion(c+3,'(')
            else:
                c = fininstruccion(c+2,'x')
        else:
            if listatokens[c+1][1] == 'i':
                if listatokens[c+2][1] == 'n':
                    if listatokens[c+3][1] == '(':
                        c = GramaticaEspecialtextoentreparentesisycomillas(c+3,'minimo')
                    else:
                        c = fininstruccion(c+3,'(')
                else:
                    c = fininstruccion(c+2,'n')
            else:
                c = fininstruccion(c+1,'a|i')
    return c


def Gramaticatokenp(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'p':
        if listatokens[c+1][1] == 'r':
            if listatokens[c+2][1] == 'o':
                if listatokens[c+3][1] == 'm':
                    if listatokens[c+4][1] == 'e':
                        if listatokens[c+5][1] == 'd':
                            if listatokens[c+6][1] == 'i':
                                if listatokens[c+7][1] == 'o':
                                    if listatokens[c+8][1] == '(':
                                        c = GramaticaEspecialtextoentreparentesisycomillas(c+8,'promedio')
                                    else:
                                        c = fininstruccion(c+8,'(')
                                else:
                                    c = fininstruccion(c+7,'o')
                            else:
                                c = fininstruccion(c+6,'i')
                        else:
                            c = fininstruccion(c+5,'d')
                    else:
                        c = fininstruccion(c+4,'e')
                else:
                    c = fininstruccion(c+3,'m')
            else:
                c = fininstruccion(c+2,'o')
        else:
            c = fininstruccion(c+1,'r')
    return c


def GramaticatokenR(c):
    global listaSintactico, listatokens, listaClaves, templistaClaves, templistaRegistros, listaRegistros, frenogramaticaR
    #Reiniciar Valor
    frenogramaticaR = False
    #Remover espacios, tabulaciones y saltos de linea
    flagsinespacios, fin = quitarespaciosysaltosdelinea(c,']')
    #Nueva lista
    if flagsinespacios == True:
        #Remplazar lista sin espacios y saltos de linea para la gramatica C
        listatokens = templistatokens
        #Cambiar id listas
        enumerarlistatokens()

    #Evaluar
    if listatokens[c][1] == 'R':
        if listatokens[c+1][1] == 'e':
            if listatokens[c+2][1] == 'g':
                if listatokens[c+3][1] == 'i':
                    if listatokens[c+4][1] == 's':
                        if listatokens[c+5][1] == 't':
                            if listatokens[c+6][1] == 'r':
                                if listatokens[c+7][1] == 'o':
                                    if listatokens[c+8][1] == 's':
                                        if listatokens[c+9][1] == '=':
                                            if listatokens[c+10][1] == '[':
                                                c = Gramaticallaves(c+11)
                                                #Salida
                                                if frenogramaticaR == True:
                                                    return c
                                                if listatokens[c][1] == ']':
                                                    c += 1
                                                    print('OK')
                                                    print('Registros: ', templistaRegistros)
                                                    #Añadir registros
                                                    for i in templistaRegistros:
                                                        listaRegistros.append(i)
                                                    #Guardar instruccion
                                                    listaSintactico.append(['Registros',listaRegistros])
                                                else:
                                                    c = fininstruccion(c,']')
                                            else:
                                                c = fininstruccion(c+10,'[')
                                        else:
                                            c = fininstruccion(c+9,'=')
                                    else:
                                        c = fininstruccion(c+8,'s')
                                else:
                                    c = fininstruccion(c+7,'o')
                            else:
                                c = fininstruccion(c+6,'r')
                        else:
                            c = fininstruccion(c+5,'t')
                    else:
                        c = fininstruccion(c+4,'s')
                else:
                    c = fininstruccion(c+3,'i')
            else:
                c = fininstruccion(c+2,'g')
        else:
            c = fininstruccion(c+1,'e')
    return c


def Gramaticatokens(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 's':
        if listatokens[c+1][1] == 'u':
            if listatokens[c+2][1] == 'm':
                if listatokens[c+3][1] == 'a':
                    if listatokens[c+4][1] == 'r':
                        if listatokens[c+5][1] == '(':
                            c = GramaticaEspecialtextoentreparentesisycomillas(c+5,'sumar')
                        else:
                            c = fininstruccion(c+5,'(')
                    else:
                        c = fininstruccion(c+4,'r')
                else:
                    c = fininstruccion(c+3,'a')
            else:
                c = fininstruccion(c+2,'m')
        else:
            c = fininstruccion(c+1,'u')
    return c




def GramaticaEspecialtextoentreparentesisycomillas(c,funcion):
    global listaSintactico, listatokens
    if listatokens[c][1] == '(':
        if listatokens[c+1][1] == '"':
            AFDTexto = AFDTextoentrecomillas(c+1)
            if AFDTexto == True:
                texto, a = obtenertexto(c+2)
                c = a
                if listatokens[c][1] == ')':
                    if listatokens[c+1][1] == ';':
                        c += 2
                        listaSintactico.append([funcion,texto])
                    else:
                        c = fininstruccion(c+1,';')
                else:
                    c = fininstruccion(c,')')
            else:
                c = ErrorAFDTextoentrecomillas(c+6,'"')
                c = fininstruccion(c,')')  
        else:
            c = fininstruccion(c+1,'"')
    else:
        c = fininstruccion(c,'(')
    
    return c


def GramaticaEspecialListadeTextoentrecorchetes(c,funcion):
    if listatokens[c][1] == '[':
        if listatokens[c+1][1] == '"':
            c = obtenertextoentrecomillasLista(c+1)
            if listatokens[c][1] == ']' and listatokens[c-1][1] != ',':
                c +=1
                print('\n Claves',templistaClaves,'\n')
                #Almacenar Claves
                listaClaves = templistaClaves
                #Agregar a lista instrucciones
                listaSintactico.append([funcion,listaClaves])
            else:
                c = fininstruccion(c,']')
        else:
            c = fininstruccion(c+1,'"')
    else:
        c = fininstruccion(c,'[')
    
    return c


def Gramaticallaves(c):
    if listatokens[c][1] == '{':
        c = GramaticaEspecialListadeRegistro(c+1)
        #Salida
        if frenogramaticaR == True:
            return c
        if listatokens[c][1] == '}':
            if listatokens[c+1][1] == '{':
                c=c+1
                c = Gramaticallaves(c)
            elif listatokens[c+1][1] == ']':
                #Salida
                c=c+1
            else:
                c = fininstruccion(c,'{|]')             
        else:
            c = fininstruccion(c,'}')        
    
    else:
        c = fininstruccion(c,'{')
    return c


def obtenertextoentrecomillasRegistro(c):
    global frenogramaticaR
    Token = listatokens[c][1]
    texto, a = ['',c]
    if Token == '"':
        AFDTexto = AFDTextoentrecomillas(c)
        if AFDTexto == True:
            texto, a = obtenertexto(c+1)
            c = a
            return [texto, c]
        else:
            c = ErrorAFDTextoentrecomillas(c+1,'"')
            #Validar si es el ultimo dato de la fila
            token = listatokens[c-1][1]
            token2 = listatokens[c][1]
            c = fininstruccion(c,'"|,')
            frenogramaticaR = True
    else:
        c = fininstruccion(c,'"')
    
    return [texto, c]




def GramaticaEspecialListadeRegistro(c):
    global templista, templistaRegistros, frenogramaticaR
    Token = listatokens[c][1]
    #[ CASO 1] [TEXTO ENTRE COMILLAS]----------------------------- 
    if Token == '"':
        texto, a = obtenertextoentrecomillasRegistro(c)
        #Añadir registro
        templista.append(texto)
        c = a
        token3 = listatokens[c][1]
        #Salida
        if frenogramaticaR == True:
            return c
        if token3 == '}':   
            #Añadir registro
            templistaRegistros.append(templista)
            #Limpiar
            templista = []
        elif token3 == ',':
            token4 = listatokens[c+1][1]
            if token4 == '"' or token4 in listanumeros:
                c = GramaticaEspecialListadeRegistro(c+1)
            else:
                c = fininstruccion(c+1,'"|NUMERO')
    #[ CASO 2] [NUMERO] ----------------------------- 
    elif Token in listanumeros:
        token2 = listatokens[c][1]
        inicio = c
        numero, a = obtenernumero(c)
        #Añadir registro
        templista.append(numero)
        c = a
        token3 = listatokens[c][1]
        #Salida
        if frenogramaticaR == True:
            return c
        if numero == None:
            c = inicio
            c = fininstruccion(c,'NUMERO_VALIDO')
            frenogramaticaR = True
            return c
        if token3 == '}':   
            #Añadir registro
            templistaRegistros.append(templista)
            #Limpiar
            templista = []
        elif token3 == ',':
            token4 = listatokens[c+1][1]
            if token4 == '"' or token4 in listanumeros:
                c = GramaticaEspecialListadeRegistro(c+1)
            else:
                c = fininstruccion(c+1,'"|NUMERO')

    else:
        frenogramaticaR = True
        c = fininstruccion(c+1,'"|NUMERO')
    
    return c


def evaluartokens(tokens):
    global listaSintactico, listatokens
    #Almacenar Tokens
    listatokens = tokens
    print('\n-----------------------------  [ EVALUAR TOKENS ] ----------------------------- ')
    #Iterador
    c = 0
    maxiteraciones = len(listatokens)
    while c < maxiteraciones:
        Token = listatokens[c][1]

        #Ignorar Comentarios
        if listatokens[c][4] == 'Comentario_multilinea' or listatokens[c][3] == 'Comentario_simple':
            c += 1    
        #[ c ] 
        elif Token == 'C':
            c = GramaticatokenC(c)
            #Se actualizo la lista quitando algunos espacios y saltos de linea
            maxiteraciones = len(listatokens)
        #[ c ]
        elif Token == 'c':
            c = Gramaticatokenc(c)
        #[ m ] 
        elif Token == 'm':
            c = Gramaticatokenm(c)
        #[ d ] 
        elif Token == 'd':
            c = Gramaticatokend(c)
        #[ e ] 
        elif Token == 'e':
            c = Gramaticatokene(c)
        #[ i ] 
        elif Token == 'i':
            c = Gramaticatokeni(c)
        #[ p ] 
        elif Token == 'p':
            c = Gramaticatokenp(c)
        #[ p ] 
        elif Token == 'R':
            #Reiniciar valores
            global templistaClaves, templistatokens, templistaRegistros, templista, frenogramaticaR
            templistaClaves = []
            templistatokens = []
            templistaRegistros = []
            templista = []
            frenogramaticaR = False
            #Evaluar
            c = GramaticatokenR(c)
            #Se actualizo la lista quitando algunos espacios y saltos de linea
            maxiteraciones = len(listatokens)
        #[ s ] 
        elif Token == 's':
            c = Gramaticatokens(c)
        #
        else:
            print('Token:', listatokens[c])
            c += 1
    

def GetErrores():
    return listaErroresSintactico



def GetInstrucciones(tokens):
    global listaSintactico, listaErroresSintactico, listaClaves, templistaClaves,templistatokens, listatokens, listaRegistros,templistaRegistros,templista,frenogramaticaR
    listaSintactico = []
    listaErroresSintactico = []
    listatokens = []
    listaClaves = []
    templistaClaves = []
    templistatokens = []
    listaRegistros = []
    templistaRegistros = []
    templista = []
    frenogramaticaR = False
    

    

    #Evaluar tokens
    evaluartokens(tokens)

    return listaSintactico


```

El código de Sintactico.py utiliza un enfoque recursivo para analizar los tokens de un programa. El método evaluartokens() es el punto de entrada del análisis. Este método itera sobre la lista de tokens y llama a la función adecuada para analizar cada token.

* Funciones para evaluar tokens


    * evaluartokens(tokens): Evalua los tokens en una lista y agrega las instrucciones a la lista listaSintactico.
    * GetInstrucciones(tokens): Devuelve la lista de instrucciones de la lista listaSintactico.
* Funciones para analizar tokens
    *Gramaticatoken(c): Analiza un token y agrega la instrucción a la lista listaSintactico.

* Funciones para analizar cadenas entre comillas

    * GramaticaEspecialListadeTextoentrecorchetes('', funcion): Analiza una lista de cadenas entre corchetes para una función determinada.
    * GramaticaEspecialListadeRegistro(): Analiza una lista de registros entre llaves.
    * obtenertextoentrecomillasRegistro(): Obtiene el texto entre comillas para un registro.
* Otros

    * fininstruccion(c, token): Devuelve un error si el token actual no es el esperado.
    * ErrorAFDTextoentrecomillas(c+1, '"'): Devuelve un error si el texto entre comillas no es válido.


---

### **Funciones**
```js
from tkinter import *
from tkinter import messagebox as MessageBox

from lexico import *
from Sintactico import *


listainstrucciones = []
txtresultado = ''

Claves = []
Registros = []
flagClavesyRegistros = False
tempLista = []
listaAcciones = []



def agregar_claves(listaclaves):
    global Claves
    #Limpiar Clave anteriores
    Claves = []
    #Agregar claves
    for i in listaclaves:
        Claves.append(i)
    #Imprimir Resultado
    print('\n---[Claves]---')
    print(Claves,'\n')


def agregar_registros(listaregistros):
    global Registros, flagClavesyRegistros
    #Validar
    if len(Claves) <= 0:
        MessageBox.showerror('Error - instrucciones','No hay claves que evaluar')
    else:
        #Limpiar
        Registros = []
        #Filtrar 
        templista = []
        #Obtener elemento lista
        for registro in listaregistros:
            #Almacenar registro en variable temporal
            #Recorrer item por item y almacenar los necesarios
            for i in range(0,len(Claves)):
                item = registro[i]
                templista.append(item)
            #Se obtubo un nuevo listao agregarlo al registro
            Registros.append(templista)
            templista = []
        #Imprimir Resultado
        print('\n---[Registros]---')
        print(Registros)
        flagClavesyRegistros = True


def funcion_conteo():
    global flagClavesyRegistros,listaAcciones
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += '\nconteo();\n'
        Registrosnumeros = len(Registros)
        mensaje += str(Registrosnumeros)+'\n'
        listaAcciones.append('conteo();<br>'+str(Registrosnumeros))
    
    return mensaje


def funcion_promedio(filtro):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += 'promedio("'+str(filtro)+'");\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #Obtener promedio
            #formula:   [lista(0)+lista(1)...lista(n)]/n
            # Numerador / Denominador
            bandera = True
            numerador = 0
            for i in tempLista:
                numero = 0
                try:
                    numero = float(i)
                except:
                    bandera = False
                    MessageBox.showerror('Error | promedio','Error al convertir este valor: '+str(i)+' en valor numerico')        
                    break
                numerador += numero
            if bandera == True:
                #Denominador
                denominador = len(tempLista)
                #Promedio
                promedio = numerador / denominador
                promedio = round(promedio, 2)
                #Agregar mensaje
                mensaje += str(promedio)+'\n'
                listaAcciones.append('promedio("'+str(filtro)+'");<br>'+str(promedio))
            else:
                mensaje += '-[ Error promedio ]-\n'

                
        else:
            MessageBox.showerror('Error | promedio','NO se encontro el valor '+str(filtro)+' entre las Claves, por lo tanto no se puede filtrar y promediar')


    return mensaje


def funcion_contarsi(informacion):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    filtro, valor = informacion
    if flagClavesyRegistros == True:
        mensaje += 'contarsi("'+str(filtro)+'",'+str(valor)+');\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #Contar si
            contador = 0
            for objetivo in tempLista:
                if  objetivo == valor:
                    contador += 1
            
            #Resultado
            mensaje += str(contador)+'\n'
            listaAcciones.append('contarsi("'+str(filtro)+'",'+str(valor)+');<br>'+str(contador))
                
        else:
            MessageBox.showerror('Error | contar si','NO se encontro el valor -->| '+str(filtro)+' |<-- entre las Claves, por lo tanto no se puede filtrar')


    return mensaje


def funcion_datos():
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        try:
            mensaje += '\n' + '-- [ datos(); ] --\n\n'
            
            #Titulo
            espaciado = '{:>0}'
            for i in range(0,len(Claves)):
                #Obtener tamaño
                largo = len(Claves[i])
                #Validar
                if largo <= 15:
                    espaciado += "{:>"+str(largo+3)+"}"
                else:
                    espaciado += "{:>18}"
            #Asignar formato
            row_format ="{:>12}" * (len(Claves)+1)
            row_format = espaciado 
            titular = row_format.format("", *Claves)
            mensaje += str(titular) + '\n'
            #Filas
            for i in range(0,len(Registros)):
                fila = row_format.format("", *Registros[i])
                mensaje += str(fila) + '\n'



            mensaje += '\n------------------------\n'
        
        except Exception:
            MessageBox.showerror('Error | datos()','Error al mostrar los datos();')


    return mensaje


def funcion_sumar(filtro):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += 'sumar("'+str(filtro)+'");\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #sumar
            bandera = True
            suma = 0
            for i in tempLista:
                numero = 0
                try:
                    numero = float(i)
                except:
                    bandera = False
                    MessageBox.showerror('Error | sumar','Error al convertir este valor: '+str(i)+' en valor numerico')        
                    break
                suma += numero
            if bandera == True:
                suma = round(suma, 2)
                #Agregar mensaje
                mensaje += str(suma)+'\n'
                listaAcciones.append('sumar("'+str(filtro)+'");<br>'+str(suma))
            else:
                mensaje += '-[ Error Suma ]-\n'

                
        else:
            MessageBox.showerror('Error | sumar','NO se encontro el valor -->| '+str(filtro)+' |<-- entre las Claves, por lo tanto no se puede filtrar')


    return mensaje


def funcion_maximo(filtro):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += 'maximo("'+str(filtro)+'");\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #Validar numeros
            bandera = True
            suma = 0
            for i in tempLista:
                numero = 0
                try:
                    numero = float(i)
                except:
                    bandera = False
                    MessageBox.showerror('Error | maximo','Error al convertir este valor: '+str(i)+' en valor numerico')        
                    break
                
            if bandera == True:
                #Obtener numero maximo
                maximo = max(tempLista)
                maximo = round(maximo,2)
                
                #Agregar mensaje
                mensaje += str(maximo)+'\n'
                listaAcciones.append('maximo("'+str(filtro)+'");<br>'+str(maximo))
            else:
                mensaje += '-[ Error maximo ]-\n'

                
        else:
            MessageBox.showerror('Error | maximo','NO se encontro el valor -->| '+str(filtro)+' |<-- entre las Claves, por lo tanto no se puede filtrar')


    return mensaje


def funcion_minimo(filtro):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += 'minimo("'+str(filtro)+'");\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #Validar numeros
            bandera = True
            suma = 0
            for i in tempLista:
                numero = 0
                try:
                    numero = float(i)
                except:
                    bandera = False
                    MessageBox.showerror('Error | minimo','Error al convertir este valor: '+str(i)+' en valor numerico')        
                    break
                
            if bandera == True:
                #Obtener numero maximo
                minimo = min(tempLista)
                minimo = round(minimo,2)
                
                #Agregar mensaje
                mensaje += str(minimo)+'\n'
                listaAcciones.append('minimo("'+str(filtro)+'");<br>'+str(minimo))
            else:
                mensaje += '-[ Error minimo ]-\n'

                
        else:
            MessageBox.showerror('Error | minimo','NO se encontro el valor -->| '+str(filtro)+' |<-- entre las Claves, por lo tanto no se puede filtrar')


    return mensaje


def funcion_exportarReporte(nombre):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        try:
            nombre = str(nombre)
            #Crear Cuadro HTML
            txthtml = crearTextoHTML(nombre)
                       
            #Crear Archivo HTML
            ruta = 'Reporte.html'
            archivo = open(ruta,'w')
            archivo.write(txthtml)
            archivo.close()

            mensaje += '¡Reporte creado exitosamente!\nReporte.html'
            

        except Exception as e:
            mensaje += '--[Error al crear Reporte]--'
            MessageBox.showerror('Error | Reporte','Ocurrio un error al crear el reporte ver CMD.')
            print('Error:')
            print(e)
    else:
        mensaje += '--[Error al crear Reporte]--'
    return mensaje


def crearTextoHTML(nombre):
    
    txthtml = ''
    if flagClavesyRegistros == True:
        #Inicio
        txthtml = '''<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    <title>Proyecto 2 - BizData</title>
  </head>
  <body>
    <div class="container" style="justify-content:center;">
        <h1> '''+str(nombre)+'''</h1>
        <h5> Javier Monjes - 202100081</h5>
        <br>
    </div>
    <div class="container">
        <table class="table table-bordered">
            <thead class="thead-light">
            <tr>'''

        #----------------------------------------------------------------
        #Titulo Tabla [ CLAVES ]
        for titulo in Claves:
            txthtml += '''                <th scope="col" style="text-align:center;">'''+str(titulo)+'''</th>'''

        txthtml += '''</tr>
            </thead>'''
        #----------------------------------------------------------------


        #----------------------------------------------------------------
        #Filas Tabla
        txthtml += '''<tbody>'''
        
        for registro in Registros:
            txthtml += '''<tr>'''
            for valor in registro:
                txthtml += '''<th scope="row" style="text-align:center;">'''+str(valor)+'''</th>'''
            txthtml += '''</tr>'''

        txthtml += '''</tbody>
        </table>
    </div>
    <br>'''
        #----------------------------------------------------------------


        #----------------------------------------------------------------
        #Funciones
        txthtml += '''<div class="container">'''

        for accion in listaAcciones:
            txthtml += '''<div class="row">
                <div class="alert alert-secondary col" role="alert">
                    '''+str(accion)+'''
                </div>
            </div>'''

        txthtml += '''</div>'''

        #----------------------------------------------------------------

        #Final
        txthtml += '''</body>
</html>'''
    return txthtml


def imprimir(texto):
    print(texto)


def imprimirInstrucciones():
    print('\n----------------------------- [ Instrucciones ] ----------------------------- ')
    for i in listainstrucciones: 
        print(i)


def evaluarinstrucciones():
    try:
        global listainstrucciones, txtresultado
        c = 0
        maxiteraciones = len(listainstrucciones)
        print('\n-----------------------------  [ EVALUANDO... ]  ----------------------------- ')
        while c < maxiteraciones:
            instruccion = listainstrucciones[c] 
            print('•Instruccion: ',instruccion[0], 'Contenido: ', instruccion[1])
            #[ imprimir ] 
            if instruccion[0] == 'imprimir':
                print('♦ Imprimir: ', instruccion[1])
                txtresultado +=  instruccion[1] + ' '
            #[ imprimirln ]
            elif instruccion[0] == 'imprimirln':
                print('♦ Imprimirln: ', instruccion[1])
                txtresultado +=  instruccion[1]+' \n'
            #[ Claves ]
            elif instruccion[0] == 'Claves':
                print('♦ Claves=', instruccion[1])
                #Añadir CLAVES
                agregar_claves(instruccion[1])
                txtlista = '['
                contador = 0
                for i in Claves:
                    if contador < len(Claves) - 1:
                        txtlista += str(i)+', '
                    else:
                        txtlista += str(i)
                    contador += 1

                txtlista += ']\n'
                
                txtresultado += 'Claves=' + txtlista
            #[ contar si ] 
            elif instruccion[0] == 'contarsi':
                print('♦ Contarsi: '+instruccion[1][0]+' valor:'+str(instruccion[1][1]))
                txtresultado += funcion_contarsi(instruccion[1])
            #[ conteo ] 
            elif instruccion[0] == 'conteo':
                print('♦ Conteo')
                txtresultado += funcion_conteo()
                
            #[ datos ] 
            elif instruccion[0] == 'datos':
                print('♦ Mostrar Datos:')
                txtresultado += funcion_datos()
            #[ exportarReporte ]
            elif instruccion[0] == 'exportarReporte':
                print('♦ ExportarReporte("'+instruccion[1]+'")')
                txtresultado += funcion_exportarReporte(instruccion[1])
            #[ maximo ] 
            elif instruccion[0] == 'maximo':
                print('♦ Maximo("'+instruccion[1]+'")')
                txtresultado += funcion_maximo(instruccion[1])
            #[ Minimo ] 
            elif instruccion[0] == 'minimo':
                print('♦ Maximo("'+instruccion[1]+'")')
                txtresultado += funcion_minimo(instruccion[1])
            #[ promedio ] 
            elif instruccion[0] == 'promedio':
                print('♦ Promedio("'+instruccion[1]+'")')
                txtresultado += str(funcion_promedio(instruccion[1]))
                
            #[ Registros ] 
            elif instruccion[0] == 'Registros':
                print('♦Registros=',instruccion[1])
                agregar_registros(instruccion[1])
                txtresultado += '\n----[ Registros ]----\n'
                for i in Registros:
                    txtresultado += str(i)+'\n'
                txtresultado += '\n---------------------\n'
            #[ sumar ] 
            elif instruccion[0] == 'sumar':
                print('♦ Sumar("'+instruccion[1]+'")')
                txtresultado += funcion_sumar(instruccion[1])
                


            c += 1
    except Exception as e:
        print("\033[1;31;40m Error: Ocurrio un error al ejecutar alguna instruccion \033[0m")
        MessageBox.showerror('Error - instrucciones','Ocurrio un error al ejecutar alguna instruccion, favor ver consola CMD')
        print(e)



def ejecutar(oldlistainstrucciones):
    global listainstrucciones, txtresultado, Claves, Registros, flagClavesyRegistros, tempLista, listaAcciones
    txtresultado = ''
    listainstrucciones = oldlistainstrucciones
    

    #Reinicar valores
    Claves = []
    Registros = []
    flagClavesyRegistros = False
    tempLista = []
    listaAcciones = []
    
    #Evaluar
    evaluarinstrucciones()

    


    return txtresultado

```

El archivo funciones.py contiene las funciones que se utilizan para evaluar las instrucciones del lenguaje BizData. Estas funciones son:

imprimir(): Imprime un texto en la consola.
imprimirln(): Imprime un texto en la consola y agrega un salto de línea.
Claves(): Agrega una lista de claves a la aplicación.
contarsi(): Cuenta la cantidad de veces que aparece un valor en una lista.
conteo(): Cuenta la cantidad de elementos en una lista.
datos(): Muestra los datos de la aplicación.
exportarReporte(): Exporta un reporte de los datos de la aplicación.
maximo(): Devuelve el valor máximo de una lista.
minimo(): Devuelve el valor mínimo de una lista.
promedio(): Devuelve el promedio de una lista.
Registros(): Agrega una lista de registros a la aplicación.
sumar(): Devuelve la suma de los elementos de una lista.

Las funciones del archivo funciones.py se dividen en dos categorías:

Funciones básicas: Estas funciones realizan operaciones básicas, como imprimir un texto, contar la cantidad de elementos de una lista, o devolver el valor máximo de una lista.
Funciones de BizData: Estas funciones son específicas del lenguaje BizData, como agregar una lista de claves a la aplicación, o exportar un reporte de los datos de la aplicación.
Las funciones básicas son utilizadas por las funciones de BizData para realizar sus operaciones. Por ejemplo, la función contarsi() utiliza la función len() para contar la cantidad de elementos de una lista.

En resumen, el archivo funcion.py proporciona las funciones necesarias para evaluar las instrucciones del lenguaje BizData. Estas funciones se dividen en dos categorías: funciones básicas y funciones de BizData.


### Expresion Regular
Las expresiones regulares son una forma de especificar un conjunto de cadenas. Se utilizan en una variedad de aplicaciones, como la búsqueda de texto, la coincidencia de patrones y la generación de texto.

Una expresión regular se compone de caracteres, operadores y caracteres especiales. Los caracteres pueden ser cualquier carácter del alfabeto. Los operadores se utilizan para combinar caracteres y para especificar condiciones. Los caracteres especiales tienen significados especiales.

### Metodo del arbol
El método del árbol es un enfoque para analizar lenguajes formales. En este enfoque, el programa se representa como un árbol. El análisis se realiza siguiendo el árbol, verificando que cada nodo del árbol sea válido.

El método del árbol es un enfoque poderoso para el análisis de lenguajes formales. Es eficiente y puede ser utilizado para analizar lenguajes complejos.

## Gramatica
Una gramática es una descripción formal de un lenguaje. Una gramática consta de un conjunto de reglas que especifican cómo se pueden generar las cadenas de un lenguaje.

Las gramáticas se utilizan en una variedad de aplicaciones, como la traducción automática, la generación de código y la verificación de modelos.

## Gramatica central
Una gramática central es una gramática que se utiliza para representar un lenguaje formal. Una gramática central consta de un conjunto de reglas que especifican cómo se pueden generar las cadenas de un lenguaje.

Las gramáticas centrales se utilizan en una variedad de aplicaciones, como la traducción automática, la generación de código y la verificación de modelos.