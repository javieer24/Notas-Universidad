#include <iostream>

#define N 100 // Puede cambiar este valor según su necesidad

class ArbolLex {
public:
  ArbolLex() {
    // Inicializar el árbol con -1
    for (int i = 0; i < N; ++i) {
      Arbol[i] = -1;
    }
  }

  void insertar(int indice, int valor) {
    if (indice < N) {
      Arbol[indice] = valor;
    }
  }

  void imprimir() {
    imprimirAux(0);
  }

private:
  int Arbol[N];

  void imprimirAux(int indice) {
    if (indice >= N || Arbol[indice] == -1) {
      return;
    }

    // Recorrido en orden: primero el subárbol izquierdo, luego el nodo actual, luego el subárbol derecho
    imprimirAux(2 * indice + 1); // Subárbol izquierdo

    std::cout << "Índice: " << indice << ", Llave: " << Arbol[indice] << std::endl;

    imprimirAux(2 * indice + 2); // Subárbol derecho
  }
};

int main() {
  ArbolLex arbol;

  // Insertar algunos valores en el árbol
  arbol.insertar(0, 10);
  arbol.insertar(1, 20);
  arbol.insertar(2, 30);
  arbol.insertar(3, 40);
  arbol.insertar(4, 50);

  // Imprimir el árbol
  arbol.imprimir();

  return 0;
}
