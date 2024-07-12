// main.cpp

#include "MatrizOrtogonal.h"
#include <iostream>

int main() {
  MatrizOrtogonal matriz(10, 10); // Ejemplo con matriz de 10x10

  matriz.insert(1, 1, 1);
  matriz.insert(2, 2, 2);
  matriz.insert(3, 3, 3);
  matriz.insert(4, 4, 4);

  std::cout << "Matriz original:" << std::endl;
  // Implementa la impresión de la matriz si es necesario
  // std::cout << matriz << std::endl;

  matriz.move(1, 1, 2, 2, 3, 3);

  std::cout << "Matriz modificada:" << std::endl;
  // Implementa la impresión de la matriz si es necesario
  // std::cout << matriz << std::endl;

  return 0;
}
