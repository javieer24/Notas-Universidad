# La clase Pedido representa un pedido individual de un cliente
class Pedido:
    def __init__(self, cliente, panes):
        self.cliente = cliente  # El nombre del cliente que hizo el pedido
        self.panes = panes  # Un diccionario de los tipos de pan y sus cantidades
        self.completado = False  # Un indicador de si el pedido ha sido completado o no

    # Esta función se llama cuando se imprime un objeto Pedido
    def __str__(self):
        estado = 'Completado' if self.completado else 'Pendiente'
        return f"Cliente: {self.cliente}, Panes: {self.panes}, Estado: {estado}"

# La clase Panaderia representa la panadería y gestiona los pedidos
class Panaderia:
    def __init__(self, productos):
        self.pedidos = []  # Una lista para almacenar los pedidos
        self.productos = productos  # Una lista de los productos disponibles en la panadería

    # Este método permite agregar un nuevo pedido a la lista de pedidos
    def nuevo_pedido(self, cliente, panes):
        pedido = Pedido(cliente, panes)
        self.pedidos.append(pedido)

    # Este método procesa el primer pedido pendiente en la lista de pedidos
    def procesar_pedido(self):
        if not self.pedidos:
            print("No hay pedidos pendientes.")
            return
        for pedido in self.pedidos:
            if not pedido.completado:
                pedido.completado = True
                print(f"Pedido de {pedido.cliente} completado.")
                return
        print("Todos los pedidos han sido completados.")

    # Este método muestra todos los pedidos en la lista de pedidos
    def mostrar_pedidos(self):
        if not self.pedidos:
            print("No hay pedidos para mostrar.")
            return
        for pedido in self.pedidos:
            print(pedido)

    # Este método muestra todos los productos disponibles en la panadería
    def mostrar_productos(self):
        for producto in self.productos:
            print(producto)

# Crea una instancia de Panaderia con algunos productos
panaderia = Panaderia(["baguette", "pan campesino", "pan de queso", "pan de ajo", "pan de higo", "pan de banano"])

print("Bienvenido a La panadería 'El Pan Nuestro'")

# Un bucle para el menú interactivo
while True:
    print("\n1. Ver productos")
    print("2. Hacer un pedido")
    print("3. Procesar un pedido")
    print("4. Ver pedidos")
    print("5. Salir")
    opcion = input("Elige una opción: ")

    if opcion == "1":
        panaderia.mostrar_productos()
    elif opcion == "2":
        cliente = input("Ingresa el nombre del cliente: ")
        panes = {}
        while True:
            pan = input("Ingresa el tipo de pan (o 'salir' para terminar): ")
            if pan == "salir":
                break
            cantidad = int(input("Ingresa la cantidad de este pan: "))
            if pan in panes:
                panes[pan] += cantidad
            else:
                panes[pan] = cantidad
        panaderia.nuevo_pedido(cliente, panes)
    elif opcion == "3":
        panaderia.procesar_pedido()
    elif opcion == "4":
        panaderia.mostrar_pedidos()
    elif opcion == "5":
        break
