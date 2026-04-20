#ifndef PILA_HPP
#define PILA_HPP

#include "estructuras.hpp"

void menuPila();
void push(NodoPila*& cima, Producto p);
void pop(NodoPila*& cima);
void mostrarPila(NodoPila* cima);

#endif
