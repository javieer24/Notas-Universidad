from expression import Expression

class Numero(Expression):
    
    def __init__(self, valor, fila, column):
        self.valor = valor
        super().__init__(fila, column)

    def ejecutar(self, getER):
        return self.valor