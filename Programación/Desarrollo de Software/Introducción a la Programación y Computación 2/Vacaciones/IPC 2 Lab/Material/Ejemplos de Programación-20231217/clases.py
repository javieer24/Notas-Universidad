class Poligromo:
    def __init__(self,b,h):
        self.b=b
        self.h=h

class Rectangulo(Poligromo):
    def area(self):
        return self.b*self.h
    
class Tringulo(Poligromo):
     def area(self):
         return (self.b*self.h/2)
     
rectangulo = Rectangulo(5,8)
tringulo=Tringulo(20,12)

print("Area rectangulo", rectangulo.area())
print("Area tringulo", tringulo.area())
  