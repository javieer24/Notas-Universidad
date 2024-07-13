import os

titulo = "Practica 1 - Lenguajes formales y de programacion"

# Función para mostrar el menú principal y obtener la opción seleccionada por el usuario
def mostrar_menu():
    # Limpia la pantalla
    os.system("cls")
    
    # Muesstra el título del programa
    print("+", len(titulo)*"-","+",sep="")
    print("|", titulo, "|")
    print("+", len(titulo)*"-","+",sep="")
    
    # Muestra las opciones del menú
    print("\n# Sistema de inventario :\n")
    print("1.Cargar el inventario inicial")
    print("2.Cargar las instrucciones de los movimientos")
    print("3.Crear informe de inventario")
    print("4.Salir")
    
    # Obtiene la opción seleccionada por el usuario
    opcion = int(input("Ingrese una opcion: "))
    
    # Devuelve la opción seleccionada
    return opcion
