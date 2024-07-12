#Crear un nodo
class node:
     def __init__(self, data=None,next=None):
          self.data=data
          self.next= next
          

#crear lista simple
class lista_simple:
     def __init__(self) :
         self.head=None
    
     #Metodos para ingresar al frente de la lista
     def ingresar_al_frente(self,data):
          self.head=node(data=data,next=self.head)
    
     #Metodo para verificar si esta vacia
     def es_vacia(self):
         return self.head==None
     
     #Metodo para ingresar al final de la lista
     def ingresar_al_final(self,data):
         if not self.head:
            self.head = node(data=data)
            return
         curr = self.head
         while curr.next:
             curr =curr.next
         curr.next=node(data=data)
    
    #Metodo para eliminar nodos
     def borrar_nodo(self,key):
         curr= self.head
         prev =None
         while curr and curr.data !=key:
             prev =curr
             curr= curr.next
         if prev is None:
              self.nead=curr.next
         elif curr:
              prev.next=curr.next
              curr.next=None

    #Metodos para obtener el ultimo
     def obtener_ultimo(self):
        temp=self.head
        while(temp.next is not None):
            temp = temp.next
        return temp.data
    
    #Metodos para mostar los nodos
     def mostar_lista(self):
          node= self.head
          while node != None:
              print(node.data, end =" =>")
              node=node.next      
      


Ls= lista_simple()
Ls.ingresar_al_frente(5)
Ls.ingresar_al_final(8)
Ls.ingresar_al_frente(9)

Ls.mostar_lista()
      
     
          
      