class Nodo:
    def __init__(self, valor):
        self.valor = valor
        self.siguiente = None

class ListaEnlazada:
    def __init__(self):
        self.cabeza = None

    def agregar(self, valor):
        nuevo_nodo = Nodo(valor)
        if self.cabeza is None:
            self.cabeza = nuevo_nodo
        else:
            actual = self.cabeza
            while actual.siguiente is not None:
                actual = actual.siguiente
            actual.siguiente = nuevo_nodo

    def recorrer(self):
        actual = self.cabeza
        while actual is not None:
            print(actual.valor, end=" -> ")
            actual = actual.siguiente
        print("None")

    def CombinarListas(self, lista):
        actual = self.cabeza
        while actual.siguiente is not None:
            actual = actual.siguiente
        actual.siguiente = lista.cabeza

    def Ordenar(self):
        if self.cabeza is None:
            return
        cambio = True
        while cambio:
            cambio = False
            previo = None
            actual = self.cabeza
            siguiente = self.cabeza.siguiente
            while siguiente is not None:
                if actual.valor > siguiente.valor:
                    cambio = True
                    if previo is None:
                        temp = siguiente.siguiente
                        self.cabeza = siguiente
                        siguiente.siguiente = actual
                        actual.siguiente = temp
                    else:
                        temp = siguiente.siguiente
                        previo.siguiente = siguiente
                        siguiente.siguiente = actual
                        actual.siguiente = temp
                    previo = siguiente
                    siguiente = actual.siguiente
                else:
                    previo = actual
                    actual = siguiente
                    siguiente = siguiente.siguiente

# Crea las instancias de ListaEnlazada con los valores iniciales
lista1 = ListaEnlazada()
lista1.agregar(7)
lista1.agregar(9)
lista1.agregar(11)
lista1.agregar(17)

lista2 = ListaEnlazada()
lista2.agregar(11)
lista2.agregar(12)
lista2.agregar(14)

# Combina y ordena las listas y muestra el resultado
lista1.CombinarListas(lista2)
lista1.Ordenar()
lista1.recorrer()