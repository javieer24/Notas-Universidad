#ifndef ESTRUCTURAS_HPP
#define ESTRUCTURAS_HPP

#include <string>

struct Producto {
    int id;
    std::string nombre;
    float peso;
};

struct NodoPila {
    Producto producto;
    NodoPila* siguiente;
};

struct NodoCola {
    Producto producto;
    NodoCola* siguiente;
};

struct NodoLista {
    Producto producto;
    NodoLista* siguiente;
    NodoLista* anterior;
};

struct NodoABB {
    Producto producto;
    NodoABB* izquierda;
    NodoABB* derecha;
};

struct NodoAVL {
    Producto producto;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;
};

#endif
