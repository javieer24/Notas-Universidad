class Errores():

    def __init__(self, lexema, tipo, columna, fila):
        self.lexema = lexema
        self.tipo = tipo
        self.columna = columna
        self.fila = fila
    

    def toString(self):
        
        return self.lexema, self.tipo, self.columna, self.fila