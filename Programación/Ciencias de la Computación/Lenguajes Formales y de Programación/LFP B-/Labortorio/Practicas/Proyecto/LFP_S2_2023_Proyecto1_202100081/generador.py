class Generador:

    generador = None

    def getInstance(self):
        if Generador.generador is None:
            Generador.generador = Generador()
        return Generador.generador
        
    def addExpresion(self, n1, n2, tipo):
        return f'({n1} {tipo} {n2})'
    
    def addRaiz(self, n1, n2):
        return f'{n1}^(1/{n2})'

    def addReverse(self, n1):
        return f'( {n1}^(-1) )'
    
    def addSen(self, n1):
        return f'( sen({n1}) )'
    
    def addCos(self, n1):
        return f'( cos({n1}) )'
    
    def addTan(self, n1):
        return f'( tan({n1}) )'