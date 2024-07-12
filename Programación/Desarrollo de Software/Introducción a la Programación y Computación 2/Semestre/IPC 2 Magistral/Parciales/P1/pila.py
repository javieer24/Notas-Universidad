class Pila:
    def __init__(self):
        self.pila = []

    def apilar(self, valor):
        self.pila.append(valor)

    def desapilar(self):
        if self.pila:
            return self.pila.pop()

    def sumatoria(self):
        return sum(self.pila)

def Balancear(pila1, pila2):
    suma1 = pila1.sumatoria()
    suma2 = pila2.sumatoria()
    if suma1 == suma2:
        return pila1, pila2
    elif abs(suma1 - suma2) % 2 == 1:
        return "Balanceo imposible de llevar a cabo"
    else:
        diferencia = abs(suma1 - suma2) // 2
        if suma1 > suma2:
            mayor = pila1
            menor = pila2
        else:
            mayor = pila2
            menor = pila1
        while diferencia > 0:
            valor = mayor.desapilar()
            menor.apilar(valor)
            diferencia -= valor
        return pila1, pila2

# Crear dos instancias de la clase Pila con los valores iniciales
pila_1 = Pila()
pila_1.apilar(3)
pila_1.apilar(2)
pila_1.apilar(1)
pila_1.apilar(1)

pila_2 = Pila()
pila_2.apilar(4)
pila_2.apilar(3)
pila_2.apilar(2)

# Llamar a la función Balancear y mostrar el resultado
resultado = Balancear(pila_1, pila_2)
if isinstance(resultado, str):
    print(resultado)
else:
    print("Pila 1:", resultado[0].pila, "Suma:", resultado[0].sumatoria())
    print("Pila 2:", resultado[1].pila, "Suma:", resultado[1].sumatoria())
