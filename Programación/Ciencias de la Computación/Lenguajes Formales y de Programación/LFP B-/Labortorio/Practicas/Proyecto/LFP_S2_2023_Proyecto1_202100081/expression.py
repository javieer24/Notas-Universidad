from abc import ABC, abstractmethod

class Expression(ABC):

    def __init__(self, fila, column):
        self.fila = fila
        self.column = column
    
    @abstractmethod
    def ejecutar(self, getER):
        pass