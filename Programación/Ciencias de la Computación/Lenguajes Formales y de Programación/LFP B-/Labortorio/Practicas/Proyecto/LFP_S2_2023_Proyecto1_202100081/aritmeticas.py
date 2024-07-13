from expression import *
from operador import Operador
from generador import Generador
import math

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