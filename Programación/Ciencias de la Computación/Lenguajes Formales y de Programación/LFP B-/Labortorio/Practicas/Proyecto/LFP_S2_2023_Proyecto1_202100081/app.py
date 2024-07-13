import tkinter as tk
from tkinter import INSERT, ttk
from tkinter import filedialog, messagebox
from analizador_lexico import *
from errores import *
from aritmeticas import *
import files_json as JsonFile
from files_json import *
import os
import tkinter as messagebox

class App(tk.Tk):

    def __init__(self):
        super().__init__()

        #Window config
        self.title("Proyecto 1 - Analizador Lexico") # Titulo de ventana
        self.resizable(False, False) #Editable
        self.addWidgets() # Creamos los widgets
        self.file = None # Archivo global

    def addWidgets(self):

        #Configuracion ventana
        self.configure(bg="#b2d8d8") #Color de fondo
  
        # Funcion para abrir archivo
        def openFile():

            #Abrimos el archivo
            self.file = filedialog.askopenfilename() # Obtenemos ruta y nombre de archivo

            ruta, extension = os.path.splitext(self.file) # Parseamos el archivo para obtener ruta

            if extension == ".JSON" or extension == ".json": # Verificamos que sea .json

                fileOpen = open(self.file, 'r') # Abrimos el archivo

                #Leemos el contenido
                lectura = fileOpen.read() # Leemos el archivo
                fileOpen.close() # Cerramos el archivo
                txt_area.insert(INSERT, lectura) #insertamos el contenido en el text area
                
            else:
                messagebox.showerror(message="La extension del archivo no es '.json'", title="Error")
            
        # Funcion para guardar archivo
        def saveFile():

            fileOpen = open(self.file, 'w') # Abrimos el archivo de entrada
            content = txt_area.get(1.0, tk.END) # Tomamos el contenido del area de texto
            
            fileOpen.write(content) # Escribimos en el archivo los cambios
            fileOpen.close() # Cerramos el archivo

            messagebox.showinfo(message="Cambios Guardados", title="Guardar")
                
        # Funcion para guardar archivo con otro nombre
        def save_asFile():
            new_file = filedialog.asksaveasfilename(defaultextension="json", 
            filetypes=[("Archivos JSON", "*.json"), ("Todos los archivos", "*.*")]) #Cuadro de dialogo

            if not new_file: #Validar que se este guardando un archivo
                return messagebox.showerror("Error", "No se ha guardado ningun archivo") # En caos no se guarde

            messagebox.showinfo("Guardar archivo", "Archivo guardado correctamente")

            new_archivo = open(new_file, "w") # Abrimos el nuevo archivo
            txt_entrada = txt_area.get(1.0, tk.END) # Tomamos el contenido del area de texto 

            new_archivo.write(txt_entrada) # Escribimos el contenido en el nuevo archivo
            new_archivo.close() # Cerramos el archivo

        # Funcion para analizar archivo
        def parseFile():

            estructure = txt_area.get(1.0, tk.END) #Tomamos el texto del area de texto

            if str(estructure).isspace():
                messagebox.showerror("Archivo invalido", "Verifique que haya abierto un archivo, \n           o un archivo adecuado") # Si el text esta vacio
            
            else:
                # Proceso, para el analizador lexico
                variable = parse(estructure)
                n = 1
                print()

                texto = "" # Para almacenar el texto
                title_operaciones = "" # Para almacenar el titulo
                operaciones = [] # Para almacenar las operaciones
                expre = [] # Para almacenar las expresiones
                estilo = [] # Para almacenar los estilos 
                
                if variable:
                    for var in variable:
                        if isinstance(var, list):
                            for var_ in var:
                                if isinstance(var_, Aritmeticas):
                                    print(f"Operacion {n}: ")
                                    operaciones.append(f"Operacion {n}: ")
                                    print(f'{var_.ejecutar(True)} = {var_.ejecutar(False)}')
                                    expre.append(f'{var_.ejecutar(True)} = {var_.ejecutar(False)}')
                                    print()
                                    n+=1
                                elif isinstance(var_, Estilo):
                                    print(var_.ejecutar(False))
                                    estilo.append(var_.ejecutar(False))
                                    print()
                    
                        elif isinstance(var, Texto):
                            texto = var.ejecutar(False) 
                            print(var.ejecutar(False))
                            print()
                        elif isinstance(var, Funcion):
                            title_operaciones = var.ejecutar(False)
                            print(var.ejecutar(False))
                            print()
                
                JsonFile.create_ResultadosJSON(texto, title_operaciones, operaciones, expre, estilo)

                messagebox.showinfo("Analizador", "Archivo Analizado correctamente")
                
                operaciones =[]
                for var in variable:
                    if isinstance(var, list):
                        for var_ in var:
                            print(f"Operacion {n}: ")
                            operaciones.append(f"Operacion {n}: ")
                            print(var_.ejecutar(True))
                            n+=1
                return operaciones

        # Funcion para verificar errores
        def parse_errores_File():

            estructure = txt_area.get(1.0, tk.END) #Tomamos el texto del area de texto
            _error = [] # Para almacenar errores

            if str(estructure).isspace():
                messagebox.showerror("Archivo invalido", "Verifique que haya abierto un archivo, \n           o un archivo adecuado") # Si el text esta vacio

            else:
                #Errores
                print("Errores\n")
                cc = 1

                for var in errores_:
                    print(f"\tError {cc}:")
                    print(var.toString())
                    _error.append(list(var.toString()))
                    cc+=1
                
                messagebox.showinfo("Errores", "Archivo 'json' generado correctamente")

            print(_error)
            JsonFile.create_ErroresJson(_error)

        #Create buttons
        btn_abrir = tk.Button(self, text="ABRIR", command = openFile ,font=("Berlin Sans FB Demi", 13, "bold"), bg="#000000", fg="white")
        btn_guardar = tk.Button(self, text="GUARDAR", command=saveFile, font=("Berlin Sans FB Demi", 13, "bold"), bg="#000000", fg="white")
        btn_guardar_como = tk.Button(self, text="GUARDAR COMO", command=save_asFile, font=("Berlin Sans FB Demi", 13, "bold"), bg="#000000", fg="white")
        btn_analizar = tk.Button(self, text="ANALIZAR", command = parseFile, font=("Berlin Sans FB Demi", 13, "bold"), bg="#000000", fg="white")
        btn_errores = tk.Button(self, text="ERRORES", command = parse_errores_File,font=("Berlin Sans FB Demi", 13, "bold"), bg="#000000", fg="white")
        btn_salir = tk.Button(self, text="SALIR", command = lambda: self.quit(),  font=("Berlin Sans FB Demi", 13, "bold"), bg="#000000", fg="white")


        #Create Text area
        txt_area = tk.Text(self, bg="#b0bec5", font=("Calisto MT", 12), padx=20, pady=20)


        # Eventos de combobox
        def selection_changed(event):
            selection = cmb_ayuda.get()
            if selection == "Autor":
                messagebox.showinfo(
                    title="Autor",
                message="Curso: Laboratorio de Lnguajes Formales y de Programación \nSeccion: B- \nNombre: Javier Andrés Monjes Solórzano \nCarnet: 202100081"
                )
    
        
        #Create second combobox
        style = ttk.Style()
        style.theme_create('combostyle', parent='alt',
                                settings = {'TCombobox':
                                            {'configure':
                                            {'selectbackground': '#000000',
                                            'fieldbackground': '#87CEEB',
                                            'background': '#000000'
                                            }}})
        style.theme_use('combostyle') 
        options = ["Ayuda", "Manual de Usuario", "Manual Tecnico", "Autor"] #Lista de opciones
        cmb_ayuda = ttk.Combobox(self, values = options, foreground="White",  font= ("Berlin Sans FB Demi", 13, "bold"), justify = "center", state = "readonly")
        cmb_ayuda.current(0)

        cmb_ayuda.bind("<<ComboboxSelected>>", selection_changed)

        #Ubicacion widgets
        btn_abrir.grid(row=0, column=0, sticky="nsew")
        btn_guardar.grid(row=0, column=1, sticky="nsew")
        btn_guardar_como.grid(row=0, column=2, sticky="nsew")
        btn_analizar.grid(row=0, column=3, sticky="nsew")
        btn_errores.grid(row=0, column=4, sticky="nsew")
        btn_salir.grid(row=2, column=5, sticky="nsew", padx=15, pady=15)
        cmb_ayuda.grid(row=0, column=5, sticky="nsew")
        txt_area.grid(row=1, column=0, columnspan=6, padx=15, pady=15)
    
if __name__ == "__main__":
    app = App()
    app.mainloop()