class Pila:
    def __init__(self):
        self.pila = []

    def apilar(self, edad):
        self.pila.append(edad)

    def desapilar(self):
        if self.pila:
            return self.pila.pop()

    def sumar_edades(self):
        return sum(self.pila)

def Balancear(pila_1, pila_2):
    suma_pila_1 = pila_1.sumar_edades()
    suma_pila_2 = pila_2.sumar_edades()
    if suma_pila_1 == suma_pila_2:
        return pila_1, pila_2
    elif abs(suma_pila_1 - suma_pila_2) % 2 == 1:
        return "Balanceo imposible de llevar a cabo"
    else:
        diferencia = abs(suma_pila_1 - suma_pila_2) // 2
        if suma_pila_1 > suma_pila_2:
            mayor = pila_1
            menor = pila_2
        else:
            mayor = pila_2
            menor = pila_1
        while diferencia > 0:
            valor = mayor.desapilar()
            menor.apilar(valor)
            diferencia -= valor
        return pila_1, pila_2

# Crear las instancias de Pila con los valores iniciales
pila_1 = Pila()
pila_2 = Pila()

# Apilar las edades en las pilas
edades_pila_1 = [3, 2, 1, 1]
edades_pila_2 = [4, 3, 2]

for edad in edades_pila_1:
    pila_1.apilar(edad)

for edad in edades_pila_2:
    pila_2.apilar(edad)

# Llamar a la función Balancear y mostrar los resultados
resultado = Balancear(pila_1, pila_2)
if isinstance(resultado, str):
    print(resultado)
else:
    print("Pila 1 resultante:", resultado[0].pila)
    print("Pila 2 resultante:", resultado[1].pila)
