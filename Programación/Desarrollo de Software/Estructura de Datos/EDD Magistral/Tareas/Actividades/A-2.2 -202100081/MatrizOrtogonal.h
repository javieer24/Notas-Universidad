// MatrizOrtogonal.h

#ifndef MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_H

#include "Nodo.h"
using byte = unsigned char;

class MatrizOrtogonal {
public:
  MatrizOrtogonal(int f, int c);
  ~MatrizOrtogonal();
  
  void insert(int info, int i, int j);
  void move(byte F1, byte C1, byte F2, byte C2, byte FD, byte CD);

private:
  Nodo **filas; // 1..256
  Nodo **cols;  // ..256
  
  Nodo *buscar(int x, int y);
  void eliminarNodo(Nodo* nodo);
  void insertarNodo(Nodo* nodo);
};

#endif // MATRIZORTOGONAL_H
