import os
from tkinter import filedialog

# Función para cargar el inventario inicial desde un archivo .inv
def cargar_inventario_inicial():
    # Crea un diccionario vacío para almacenar el inventario
    inventario = {}
    
    # Mostrar un cuadro de diálogo para seleccionar el archivo .inv
    archivo_inv = filedialog.askopenfilename(title="Seleccione el archivo .inv", filetypes=(("Archivos INV", "*.inv"), ("Todos los archivos", "*.*")))
    
    # Verifica si el archivo existe
    if os.path.exists(archivo_inv):
        # Abre el archivo en modo lectura
        with open(archivo_inv, "r") as f:
            # Lee cada línea del archivo
            for linea in f:
                try:
                    # Separa la instrucción y los datos
                    instruccion, datos = linea.strip().split(" ")
                except ValueError:
                    # Si ocurre un error al separar la instrucción y los datos, mostrar un mensaje de error y continuar con la siguiente línea
                    print(f"Error: La línea '{linea}' no está formateada correctamente")
                    continue
                
                # Verifica si la instrucción es crear_producto
                if instruccion == "crear_producto":
                    # Separar los datos en nombre, cantidad, precio_unitario y ubicacion
                    nombre, cantidad, precio_unitario, ubicacion = datos.split(";")
                    
                    # Convierte cantidad y precio_unitario a números
                    cantidad = int(cantidad)
                    precio_unitario = float(precio_unitario)
                    
                    # Verifica si el producto ya existe en el inventario
                    if nombre not in inventario:
                        # Si no existe, crear un nuevo producto en el inventario con cantidad 0
                        inventario[nombre] = {"cantidad": 0, "precio_unitario": precio_unitario, "ubicacion": ubicacion}
                    
                    # Incrementar la cantidad del producto en el inventario
                    inventario[nombre]["cantidad"] += cantidad
    
    else:
        # Si el archivo no existe, mostrar un mensaje de error
        print(f"Error: El archivo {archivo_inv} no existe")
    
    # Devuelve el inventario cargado
    return inventario

# Función para cargar instrucciones de movimientos desde un archivo .mov
def cargar_instrucciones_movimientos(inventario):
    # Crea dos listas vacías para almacenar información sobre los movimientos de productos
    lista_mov = []
    lista_mov2 = []
    
    # Muestra un cuadro de diálogo para seleccionar el archivo .mov
    archivo_mov = filedialog.askopenfilename(title="Seleccione el archivo .mov", filetypes=(("Archivos MOV", "*.mov"), ("Todos los archivos", "*.*")))
    
    # Verificar si el archivo existe
    if os.path.exists(archivo_mov):
        # Abre el archivo en modo lectura
        with open(archivo_mov, "r") as f:
            # Lee cada línea del archivo
            for linea in f:
                try:
                    # Separa la instrucción y los datos
                    instruccion, datos = linea.strip().split(" ")
                except ValueError:
                    # Si ocurre un error al separar la instrucción y los datos, mostrar un mensaje de error y continuar con la siguiente línea
                    print(f"Error: La línea '{linea}' no está formateada correctamente")
                    continue
                
                # Verifica si la instrucción es agregar_stock o vender_producto
                if instruccion == "agregar_stock":
                    # Separa los datos en nombre, cantidad y ubicacion
                    nombre, cantidad, ubicacion = datos.split(";")
                    
                    # Convierte cantidad a número entero
                    cantidad = int(cantidad)
                    
                    # Agrega información sobre el movimiento a la lista lista_mov
                    lista_mov.append([nombre, cantidad, ubicacion])
                    
                    # Verifica si el producto existe en el inventario y si la ubicación es correcta
                    if nombre in inventario and inventario[nombre]["ubicacion"] == ubicacion:
                        # Incrementar la cantidad del producto en el inventario
                        inventario[nombre]["cantidad"] += cantidad
                    else:
                        # Si el producto no existe o la ubicación es incorrecta, mostrar un mensaje de error
                        print(f"Error: El producto {nombre} no existe en la ubicación {ubicacion}")
                
                elif instruccion == "vender_producto":
                    # Separar los datos en nombre, cantidad y ubicacion
                    nombre, cantidad, ubicacion = datos.split(";")
                    
                    # Convierte la cantidad a número entero
                    cantidad = int(cantidad)
                    
                    # Agrega información sobre el movimiento a la lista lista_mov2
                    lista_mov2.append([nombre, cantidad, ubicacion])
                    
                    # Verifica si el producto existe en el inventario y si la ubicación es correcta
                    if nombre in inventario and inventario[nombre]["ubicacion"] == ubicacion:
                        # Verificar si hay suficiente cantidad del producto en el inventario
                        if cantidad <= inventario[nombre]["cantidad"]:
                            # Decrementar la cantidad del producto en el inventario
                            inventario[nombre]["cantidad"] -= cantidad
                        else:
                            # Si no hay suficiente cantidad, mostrar un mensaje de error
                            print(f"Error: La cantidad a vender es mayor a la cantidad disponible en la ubicación {ubicacion}")
                    else:
                        # Si el producto no existe o la ubicación es incorrecta, mostrar un mensaje de error
                        print(f"Error: El producto {nombre} no existe en la ubicación {ubicacion}")
    
    else:
        # Si el archivo no existe, mostrar un mensaje de error
        print(f"Error: El archivo {archivo_mov} no existe")

# Función para crear un informe de inventario en un archivo .txt
def crear_informe_inventario(inventario):
    # Mostrar un cuadro de diálogo para guardar el archivo .txt
    archivo_txt = filedialog.asksaveasfilename(title="Guardar informe como...", filetypes=(("Archivos TXT", "*.txt"), ("Todos los archivos", "*.*")), defaultextension=".txt")
    
    # Abre el archivo en modo escritura
    with open(archivo_txt, "w") as f:
        # Escribir el encabezado del informe
        f.write("informe de Inventario\n")
        f.write("Producto\tCantidad\tPrecio Unitario\tValor Total\tUbicación\n")
        f.write("-----------------------------------------------------------------------------------------------\n")
        
        # Escribe información sobre cada producto en el inventario
        for nombre, datos in inventario.items():
            cantidad = datos["cantidad"]
            precio_unitario = datos["precio_unitario"]
            valor_total = cantidad * precio_unitario
            ubicacion = datos["ubicacion"]
            f.write(f"{nombre}\t{cantidad}\t${precio_unitario}\t${valor_total}\t{ubicacion}\n")
