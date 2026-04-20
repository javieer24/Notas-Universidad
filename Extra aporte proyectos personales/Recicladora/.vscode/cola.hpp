#ifndef COLA_HPP
#define COLA_HPP

#include "estructuras.hpp"

void menuCola();
void encolar(NodoCola*& frente, NodoCola*& fin, Producto p);
void desencolar(NodoCola*& frente, NodoCola*& fin);
void mostrarCola(NodoCola* frente);

#endif
