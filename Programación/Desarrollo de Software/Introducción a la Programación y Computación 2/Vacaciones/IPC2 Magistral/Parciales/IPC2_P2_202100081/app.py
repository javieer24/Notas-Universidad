import xml.etree.ElementTree as ET
import PySimpleGUI as sg
from graphviz import Digraph

class Producto:
    def __init__(self, nombre, precio, cantidad):
        self.nombre = nombre
        self.precio = precio
        self.cantidad = cantidad
        self.next = None

class ListaEnlazada:
    def __init__(self):
        self.head = None

    def agregar_producto(self, producto):
        if not self.head:
            self.head = producto
        else:
            last_node = self.head
            while last_node.next:
                last_node = last_node.next
            last_node.next = producto

    def mostrar_productos(self):
        node = self.head
        while node:
            print(f'Nombre: {node.nombre}, Precio: {node.precio}, Cantidad: {node.cantidad}')
            node = node.next

    def buscar_producto(self, nombre):
        node = self.head
        while node:
            if node.nombre == nombre:
                return node
            print(f'Nombre: {node.nombre}, Precio: {node.precio}, Cantidad: {node.cantidad}')
            node = node.next
        return None


    def eliminar_producto(self, nombre):
        if self.head is None:
            return

        if self.head.nombre == nombre:
            self.head = self.head.next
            return

        node = self.head
        while node.next:
            if node.next.nombre == nombre:
                node.next = node.next.next
                return
            node = node.next

    def generar_grafo(self):
        dot = Digraph(comment='Lista Enlazada')
        node = self.head
        i = 0
        while node:
            dot.node(str(i), f'Nombre: {node.nombre}\nPrecio: {node.precio}\nCantidad: {node.cantidad}')
            if node.next is not None:
                dot.edge(str(i), str(i+1))
            i += 1
            node = node.next
        dot.format = 'png'
        dot.render('lista_enlazada.dot', view=True)
        
def leer_xml(file):
    tree = ET.parse(file)
    root = tree.getroot()
    lista = ListaEnlazada()
    for producto in root.findall('producto'):
        nombre = producto.find('nombre').text
        precio = float(producto.find('precio').text)
        cantidad = int(producto.find('cantidad').text)
        lista.agregar_producto(Producto(nombre, precio, cantidad))
    return lista
        
def main():
    lista = leer_xml('productos.xml')
    layout = [[sg.Text('Menú')],
              [sg.Button('Mostrar productos')],
              [sg.Button('Buscar producto')],
              [sg.Button('Agregar producto')],
              [sg.Button('Eliminar producto')],
              [sg.Button('Generar grafo')],
              [sg.Exit()]]
    window = sg.Window('Menú', layout)
    while True:
        event, values = window.read()
        if event in (None, 'Exit'):
            break
        elif event == 'Mostrar productos':
            lista.mostrar_productos()
            node = lista.head
            productos = []
            while node:
                productos.append(f'Nombre: {node.nombre}, Precio: {node.precio}, Cantidad: {node.cantidad}')
                node = node.next
            layout_productos = [[sg.Text(producto)] for producto in productos]
            layout_productos.append([sg.Button('Cerrar')])
            window_productos = sg.Window('Productos', layout_productos)
            while True:
                event_productos, values_productos = window_productos.read()
                if event_productos in (None, 'Cerrar'):
                    break
            window_productos.close()
        elif event == 'Buscar producto':
            nombre = sg.popup_get_text('Nombre del producto')
            producto = lista.buscar_producto(nombre)
            if producto:
                sg.popup(f'Nombre: {producto.nombre}\nPrecio: {producto.precio}\nCantidad: {producto.cantidad}')
            else:
                sg.popup('Producto no encontrado')
        elif event == 'Agregar producto':
            nombre = sg.popup_get_text('Nombre del producto')
            precio = float(sg.popup_get_text('Precio del producto'))
            cantidad = int(sg.popup_get_text('Cantidad del producto'))
            lista.agregar_producto(Producto(nombre, precio, cantidad))
        elif event == 'Eliminar producto':
            nombre = sg.popup_get_text('Nombre del producto')
            lista.eliminar_producto(nombre)
        elif event == 'Generar grafo':
            lista.generar_grafo()
    window.close()

if __name__ == "__main__":
    main()