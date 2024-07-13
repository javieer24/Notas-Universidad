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

El presente proyecto consiste en el desarrollo de un analizador léxico para un lenguaje de programación de propósito general. El analizador debe ser capaz de identificar los tokens del lenguaje, así como los errores léxicos. Además, debe ser capaz de ejecutar las instrucciones del lenguaje de acuerdo con su sintaxis, y generar un archivo JSON con los resultados de la ejecución.

## **Paradigma de Programación**

Todo el desarrollo del programa esta basado en el paradigma de programacion orientado a objetos, esto es, un modelo o un estilo de programación que proporciona unas guías acerca de cómo trabajar con él y que está basado en el concepto de clases y objetos.

Es por ello que durante toda la realizacion del programa se implemento el uso de clases, clases abstractas y objetos de las mismas.

## **Diccionario de librerías**

### Libreria Tkinter:
- Tkinter es una libreria que funciona para la creación y el desarrollo de aplicaciones de escritorio. Esta librería facilita el posicionamiento y desarrollo de una interfaz gráfica de escritorio con python. TK se describe a sí mismo como el único toolkit o kit de herramientas para el desarrollo de una interfaz gráfica de usuario.

### Módulo "os"
- Este módulo provee una manera versátil de usar funcionalidades dependientes del sistema operativo. Si se desea manipular rutas, se realiza gracias al modulo os.path

### Módulo "enum"
- El módulo enum define un tipo de enumeración con capacidades de iteración y comparación. Puede ser usado para creae símbolos bien definidos para valores, en lugar de usar enteros literales o cadenas


### Módulo "abc"
- Este módulo proporciona la infraestructura para definir clases de base abstracta (CBAs) en Python

### Librería "math"
- Este módulo proporciona acceso a las funciones matemáticas definidas en el estándar de C. Estas funciones no pueden ser usadas con números complejos; usa las funciones con el mismo nombre del módulo cmath si requieres soporte para números complejos.

## Diccionario de Variables Globales

```js
global errores_ []
global self.file = None
```

Se inicializa una lista global, la cual es la encargada de almacenar todos los errores encontrado al analizar el archivo.

- errores_ = [ ] - Esta lista almacena una serie de objetos, los cuales contienen, el lexema, tipo, fila y columna de cada error, analizado en el programa.

- self.file = None - Esta variable es la encargada de almacenar la ruta del archivo que ha sido abierto, para poder manejarlo de manera global durante todo el programa.

## **Diccionario de Clases**

### **Class App**

```js
class App(tk.Tk):

    def __init__(self):
        super().__init__()

        #Window config
        self.title("Proyecto 1 - Analizador Lexico") # Titulo de ventana
        self.resizable(False, False) #Editable
        self.addWidgets() # Creamos los widgets
        self.file = None # Archivo globalclass App(tk.Tk):

    def __init__(self):
        super().__init__()

        #Window config
        self.title("Proyecto 1 - Analizador Lexico") # Titulo de ventana
        self.resizable(False, False) #Editable
        self.addWidgets() # Creamos los widgets
        self.file = None # Archivo global
```

La clase App es la clase principal, la cual hereda de la clase Tk.tk, la cual es necesaria para crear la ventana principal en donde se añaden todas las demas ventanas para formar toda la ingerfaz grafica del programa, ademas de iniciar la variable self.file

### **Class Aritmeticas**

```js
class Aritmeticas(Expression):
    
    def __init__(self, left, right, tipo, fila, column):
        self.left = left
        self.right = right
        self.tipo = tipo
        super().__init__(fila, column)
    
    def ejecutar(self, getER):
        genAux = Generador()
        generador = genAux.getInstance()
        
        izq = self.left.ejecutar(getER)

        if self.right != None:

            der = self.right.ejecutar(getER)

            if self.tipo == Operador.SUMA:
                return generador.addExpresion(izq, der, '+') if getER else izq+der

            elif self.tipo == Operador.RESTA:
                return generador.addExpresion(izq, der, '-') if getER else izq-der
                # return izq - der

            elif self.tipo == Operador.MULTIPLICACION:
                return generador.addExpresion(izq, der, '*') if getER else izq*der
                # return izq * der

            elif self.tipo == Operador.DIVISION:
                if der != 0:
                    return generador.addExpresion(izq, der, '/') if getER else izq/der
                    # return izq / der
                else:
                    print("Error: Division por cero")
                    return None

            elif self.tipo == Operador.POTENCIA:
                return generador.addExpresion(izq, der, '^') if getER else izq**der
                # return izq ** der

            elif self.tipo == Operador.MOD:
                return generador.addExpresion(izq, der, '%') if getER else izq%der
                # return izq % der
            
            elif self.tipo == Operador.RAIZ:
                return generador.addRaiz(izq, der) if getER else izq ** (1/der)
                # return pow(izq, (1/der))
        else:
            if self.tipo == Operador.INVERSO:
                return generador.addReverse(izq) if getER else izq**(-1)
                # return izq^(-1)
            elif self.tipo == Operador.SENO:
                return generador.addSen(izq) if getER else math.sin(izq)
                # return sen(izq)
            elif self.tipo == Operador.COSENO:
                return generador.addCos(izq) if getER else math.cos(izq)
                # return cos(izq)
            elif self.tipo == Operador.TANGENTE:
                return generador.addTan(izq) if getER else math.tan(izq)
                # return tan(izq)
```

La clase Aritmeticas, es la encargada de realizar cada una de las operaciones que pueden venir en el archivo de entrada. Realizando operaciones como suma, resta, multiplicacion, division, etc. Como tambien operaciones trigonometricas, como por ejemplo: seno, coseno, tangente.

### **Class Generador**

```js
class Generador:

    generador = None

    def getInstance(self):
        if Generador.generador is None:
            Generador.generador = Generador()
        return Generador.generador
        
    def addExpresion(self, n1, n2, tipo):
        return f'({n1} {tipo} {n2})'
    
    def addRaiz(self, n1, n2):
        return f'{n1}^(1/{n2})'

    def addReverse(self, n1):
        return f'( {n1}^(-1) )'
    
    def addSen(self, n1):
        return f'( sen({n1}) )'
    
    def addCos(self, n1):
        return f'( cos({n1}) )'
    
    def addTan(self, n1):
        return f'( tan({n1}) )'
```

La clase Generador, es la encargada de generar la expresion regular de las operaciones para visualizar su contenido de manera mas intuitiva y elegante al usuario.

### **Class Expression**

```js

class Expression(ABC):

    def __init__(self, fila, column):
        self.fila = fila
        self.column = column
    
    @abstractmethod
    def ejecutar(self, getER):
        pass
```

La clase expression es una de las mas importantes, ya que es la encargada de inicializar todas las clases abstractas dentro del programa, y asi manejar una recursividad dentro de las operaciones y numeros, que se agregan en el archivo de entrada.

### **Class Estilo**

```js

class Estilo(Expression):
    
        def __init__(self, instruccion, color, tamanio, line, column):
            self.instruccion = instruccion
            self.color = color
            self.tamanio = tamanio
            self.line = line
            self.column = column
    
        def ejecutar(self, getER):
            return self.instruccion, self.color, self.tamanio
```

La clase estilo, es una clase abstracta, que hereda de la clase Expresion. Esta tiene la unica finalidad de almacenar en objetos todos los datos pertenecientes a la funcion de Estilo contenidos en filas y columnas en el archivo de entrada.

### **Class Texto**

```js

class Texto(Expression):

    def __init__(self, texto, linea, column):
        self.texto = texto
        self.linea = linea
        self.column = column
    
    def ejecutar(self, getER):
        return self.texto
```
La clase Texto, es una clase abstracta, que hereda de la clase Expresion. Esta tiene la unica finalidad de almacenar en objetos todos los datos pertenciencas a la funcion de Texto. contenidos en filas y columnas en el archivo de entrada.

### **Class JsonFile**

```js
class JsonFile:

    def create_ResultadosJSON(texto, title_operaciones, operaciones, expre, estilo):

        data = {
            "title": title_operaciones,
            "description": texto,
            "operaciones": []
        }

        for num, op in zip(operaciones, expre):
            data["operaciones"].append({
                "numero": num,
                "expresion": op
            })

        json.dump(data, open("jsons/RESULTADOS_202100081.json", 'w'))

    def create_ErroresJSON(errores):

        data = {
            "errores": []
        }

        for error in errores:
            data["errores"].append({
                "lexema": error[0],
                "tipo": error[1],
                "fila": error[2],
                "columna": error[3]
            })

        json.dump(data, open("jsons/ERRORES_202100081", 'w'))

```

La clase JsonFile, es la encargada de recibir los atributos que se le han enviado desde el analizador lexico, con el unico fin de generar un archivo json que sea legible e intuitivo para el usuario, transformando toda la informacion en este lenguaje, y asi poder generar un archivo json.

## **Diccionario de Funciones**

### **Función openFile**

```js
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
            
```

La función openFile, añade a la variable global self.file, la ruta del archivo que se va abrir al momento de llamar al modulo filedialog(). Posteriormente verifica que el archivo que se va abrir sea con extension JSON, de lo contrario, no se podra abrir ningun archivo.

Esta funcion es la encargada de añadir todo el contenido del archivo en el area de texto, que se encuentra en el programa.

### **Función saveFile**

```js
       # Funcion para guardar archivo
        def saveFile():

            fileOpen = open(self.file, 'w') # Abrimos el archivo de entrada
            content = txt_area.get(1.0, tk.END) # Tomamos el contenido del area de texto
            
            fileOpen.write(content) # Escribimos en el archivo los cambios
            fileOpen.close() # Cerramos el archivo

            messagebox.showinfo(message="Cambios Guardados", title="Guardar")
                
```

Esta funcion es la encargada de guardar los cambios que se hagan en el area de texto, en el archivo original que ha sido abierto, guardando todo con el mismo nombre de archivo.

### **Función save_asFile**

```js
        # Funcion para guardar archivo con otro nombre
        def save_asFile():
            new_file = filedialog.asksaveasfilename(defaultextension="xml", 
            filetypes=[("Archivos JSON", "*.json"), ("Todos los archivos", "*.*")]) #Cuadro de dialogo

            if not new_file: #Validar que se este guardando un archivo
                return messagebox.showerror("Error", "No se ha guardado ningun archivo") # En caos no se guarde

            messagebox.showinfo("Guardar archivo", "Archivo guardado correctamente")

            new_archivo = open(new_file, "w") # Abrimos el nuevo archivo
            txt_entrada = txt_area.get(1.0, tk.END) # Tomamos el contenido del area de texto 

            new_archivo.write(txt_entrada) # Escribimos el contenido en el nuevo archivo
            new_archivo.close() # Cerramos el archivo

```

Esta funcion abre un cuadro de dialogo, el cual sirve para guardar un archivo con otro nombre o con el mismo nombre del archivo original, dentro de cualquier parte del ordenador.

### **Función parseFile**

```js
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
```

Primeramente esta función es la encargada de verificar que dentro del area de texto se encuentre un archivo por analizar, con la estructura indicada.

Posteriormente crea una variable y se la envia al analizador lexico, para la generacion de tokens, y lexemas que se utilizaran a lo largo de todo el programa.

Luego mediante iteraciones se obtienen cada uno de los parametros pertencientes a Tipo, Funcion y Texto que se encuentran en el archivo de entrada, y alamcena sus datos en listas nativas, para enviarselos al modulo de generacion de archivos json.

### **Función parse_errores_file**

```js
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
            JsonFile.create_ErroresHtml(_error)

```

Esta funcion es la encargada primeramente de verificar que el area de texto no se encuentre vacia. Posterior a ello, itera en la lista de errores global que ha sido creada en el analizador lexico. Esto con el fin de poder mandar esta lista a la clase json, y poder generar la tabla necesaria para verificar cada uno de los errores pertenecientes en el archivo de entrada.


