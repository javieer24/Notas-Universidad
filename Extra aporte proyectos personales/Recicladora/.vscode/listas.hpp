#ifndef LISTAS_HPP
#define LISTAS_HPP

#include "estructuras.hpp"

void menuLista();
void insertarLista(NodoLista*& cabeza, Producto p);
void eliminarLista(NodoLista*& cabeza, int id);
void mostrarLista(NodoLista* cabeza);

#endif
