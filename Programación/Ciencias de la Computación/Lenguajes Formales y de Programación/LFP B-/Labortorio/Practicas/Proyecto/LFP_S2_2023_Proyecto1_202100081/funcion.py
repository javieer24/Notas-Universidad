from expression import Expression

class Funcion(Expression):

    def __init__(self, title, linea, column):
        self.title = title
        self.linea = linea
        self.column = column
    
    def ejecutar(self, getER):
        return self.title