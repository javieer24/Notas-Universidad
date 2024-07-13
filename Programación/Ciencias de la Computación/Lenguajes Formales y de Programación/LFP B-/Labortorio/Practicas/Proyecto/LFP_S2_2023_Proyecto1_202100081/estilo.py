from expression import Expression

class Estilo(Expression):
    
        def __init__(self, instruccion, color, tamanio, line, column):
            self.instruccion = instruccion
            self.color = color
            self.tamanio = tamanio
            self.line = line
            self.column = column
    
        def ejecutar(self, getER):
            return self.instruccion, self.color, self.tamanio