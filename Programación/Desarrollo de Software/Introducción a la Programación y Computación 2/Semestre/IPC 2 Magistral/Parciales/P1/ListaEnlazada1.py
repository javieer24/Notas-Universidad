class Nodo:
    def __init__(self, valor):
        self.valor = valor
        self.siguiente = None

class ListaEnlazada:
    def __init__(self):
        self.primero = None

    def insertar(self, valor):
        nuevo_nodo = Nodo(valor)
        if self.primero is None:
            self.primero = nuevo_nodo
        else:
            actual = self.primero
            while actual.siguiente:
                actual = actual.siguiente
            actual.siguiente = nuevo_nodo

    def recorrer(self):
        actual = self.primero
        while actual:
            print(actual.valor, end=" -> ")
            actual = actual.siguiente
        print("None")

    def combinar_listas(self, lista1, lista2):
        actual1 = lista1.primero
        actual2 = lista2.primero

        while actual1 and actual2:
            if actual1.valor <= actual2.valor:
                self.insertar(actual1.valor)
                actual1 = actual1.siguiente
            else:
                self.insertar(actual2.valor)
                actual2 = actual2.siguiente

        while actual1:
            self.insertar(actual1.valor)
            actual1 = actual1.siguiente

        while actual2:
            self.insertar(actual2.valor)
            actual2 = actual2.siguiente

    def ordenar(self):
        actual = self.primero
        while actual:
            siguiente = actual.siguiente
            while siguiente:
                if siguiente.valor < actual.valor:
                    actual.valor, siguiente.valor = siguiente.valor, actual.valor
                siguiente = siguiente.siguiente
            actual = actual.siguiente

# Crea las listas
lista1 = ListaEnlazada()
lista1.insertar(7)
lista1.insertar(9)
lista1.insertar(11)
lista1.insertar(17)

lista2 = ListaEnlazada()
lista2.insertar(11)
lista2.insertar(12)
lista2.insertar(14)

# Crea la lista resultado
lista_resultado = ListaEnlazada()

# Combina y ordenar las listas
lista_resultado.combinar_listas(lista1, lista2)
lista_resultado.ordenar()

# Recorre y muestra la lista resultado
lista_resultado.recorrer()

