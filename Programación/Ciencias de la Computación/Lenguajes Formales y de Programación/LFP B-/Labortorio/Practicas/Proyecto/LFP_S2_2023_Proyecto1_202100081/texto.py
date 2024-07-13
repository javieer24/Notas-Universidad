from expression import Expression

class Texto(Expression):

    def __init__(self, texto, linea, column):
        self.texto = texto
        self.linea = linea
        self.column = column
    
    def ejecutar(self, getER):
        return self.texto