import menu
import inventario

# Bucle principal del programa
inventario_actual = {}
salir = False
while not salir:
    opcion = menu.mostrar_menu()
    if opcion == 1:
        inventario_actual = inventario.cargar_inventario_inicial()
    elif opcion == 2:
        inventario.cargar_instrucciones_movimientos(inventario_actual)
    elif opcion == 3:
        inventario.crear_informe_inventario(inventario_actual)
    elif opcion == 4:
        salir = True
    else:
        print("Ingrese una opcion valida")