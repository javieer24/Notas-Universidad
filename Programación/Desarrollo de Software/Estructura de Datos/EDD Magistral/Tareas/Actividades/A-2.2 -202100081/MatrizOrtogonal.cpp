// MatrizOrtogonal.cpp

#include "MatrizOrtogonal.h"

MatrizOrtogonal::MatrizOrtogonal(int f, int c) {
  filas = new Nodo *[f];
  cols = new Nodo *[c];
  for (int i = 0; i < f; ++i) filas[i] = nullptr;
  for (int j = 0; j < c; ++j) cols[j] = nullptr;
}

MatrizOrtogonal::~MatrizOrtogonal() {
  // Implementación de destructor para liberar memoria
}

void MatrizOrtogonal::insert(int info, int i, int j) {
  Nodo* nuevo = new Nodo();
  nuevo->info = info;
  nuevo->i = i;
  nuevo->j = j;
  insertarNodo(nuevo);
}

void MatrizOrtogonal::move(byte F1, byte C1, byte F2, byte C2, byte FD, byte CD) {
  // Implementación para mover bloques de nodos
  for (int i = F1; i <= F2; ++i) {
    for (int j = C1; j <= C2; ++j) {
      Nodo* nodo = buscar(i, j);
      if (nodo != nullptr) {
        eliminarNodo(nodo);
        nodo->i = FD + (i - F1);
        nodo->j = CD + (j - C1);
        insertarNodo(nodo);
      }
    }
  }
}

Nodo* MatrizOrtogonal::buscar(int x, int y) {
  Nodo *recorre = filas[x];
  while (recorre != nullptr && recorre->j < y) {
    recorre = recorre->der;
  }
  return (recorre != nullptr && recorre->j == y) ? recorre : nullptr;
}

void MatrizOrtogonal::eliminarNodo(Nodo* nodo) {
  if (nodo->izq != nullptr) nodo->izq->der = nodo->der;
  if (nodo->der != nullptr) nodo->der->izq = nodo->izq;
  if (nodo->arriba != nullptr) nodo->arriba->abajo = nodo->abajo;
  if (nodo->abajo != nullptr) nodo->abajo->arriba = nodo->arriba;
  if (filas[nodo->i] == nodo) filas[nodo->i] = nodo->der;
  if (cols[nodo->j] == nodo) cols[nodo->j] = nodo->abajo;
}

void MatrizOrtogonal::insertarNodo(Nodo* nodo) {
  int x = nodo->i;
  int y = nodo->j;

  Nodo* antFila = nullptr;
  Nodo* recorreFila = filas[x];
  while (recorreFila != nullptr && recorreFila->j < y) {
    antFila = recorreFila;
    recorreFila = recorreFila->der;
  }

  nodo->izq = antFila;
  nodo->der = recorreFila;
  if (antFila != nullptr) antFila->der = nodo;
  if (recorreFila != nullptr) recorreFila->izq = nodo;
  if (filas[x] == nullptr || filas[x]->j > y) filas[x] = nodo;

  Nodo* antCol = nullptr;
  Nodo* recorreCol = cols[y];
  while (recorreCol != nullptr && recorreCol->i < x) {
    antCol = recorreCol;
    recorreCol = recorreCol->abajo;
  }

  nodo->arriba = antCol;
  nodo->abajo = recorreCol;
  if (antCol != nullptr) antCol->abajo = nodo;
  if (recorreCol != nullptr) recorreCol->arriba = nodo;
  if (cols[y] == nullptr || cols[y]->i > x) cols[y] = nodo;
}
