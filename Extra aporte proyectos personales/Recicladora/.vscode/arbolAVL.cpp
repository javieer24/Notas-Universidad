#include <cstdlib> // Para system() 
#include "arbolAVL.hpp"
#include "utilidades.hpp"
#include <iostream>
#define ESPACIO 10

int altura(NodoAVL* nodo) {
    return nodo ? nodo->altura : 0;
}

int obtenerBalance(NodoAVL* nodo) {
    return nodo ? altura(nodo->izquierda) - altura(nodo->derecha) : 0;
}

void actualizarAltura(NodoAVL* nodo) {
    nodo->altura = std::max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;
}

NodoAVL* rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierda;
    NodoAVL* T2 = x->derecha;
    x->derecha = y;
    y->izquierda = T2;
    actualizarAltura(y);
    actualizarAltura(x);
    return x;
}

NodoAVL* rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecha;
    NodoAVL* T2 = y->izquierda;
    y->izquierda = x;
    x->derecha = T2;
    actualizarAltura(x);
    actualizarAltura(y);
    return y;
}

NodoAVL* insertarNodoAVL(NodoAVL* nodo, Producto p) {
    if (!nodo) return new NodoAVL{p, nullptr, nullptr, 1};

    if (p.id < nodo->producto.id)
        nodo->izquierda = insertarNodoAVL(nodo->izquierda, p);
    else if (p.id > nodo->producto.id)
        nodo->derecha = insertarNodoAVL(nodo->derecha, p);
    else
        return nodo;

    actualizarAltura(nodo);
    int balance = obtenerBalance(nodo);

    // Rotaciones
    if (balance > 1 && p.id < nodo->izquierda->producto.id)
        return rotacionDerecha(nodo);
    if (balance < -1 && p.id > nodo->derecha->producto.id)
        return rotacionIzquierda(nodo);
    if (balance > 1 && p.id > nodo->izquierda->producto.id) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }
    if (balance < -1 && p.id < nodo->derecha->producto.id) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void mostrarAVL(NodoAVL* raiz, int espacio) {
    if (raiz) {
        espacio += ESPACIO;
        mostrarAVL(raiz->derecha, espacio);
        std::cout << std::endl;
        for (int i = ESPACIO; i < espacio; i++) std::cout << " ";
        std::cout << raiz->producto.id << " - " << raiz->producto.nombre << "\n";
        mostrarAVL(raiz->izquierda, espacio);
    }
}

void menuAVL() {
    NodoAVL* raiz = nullptr;
    int opcion;
    do {
        std::cout << "\033[2J\033[1;1H"; // Clear console (ANSI escape code)
        std::cout << "=== MENU ARBOL AVL ===\n";
        std::cout << "1. Insertar producto\n";
        std::cout << "2. Mostrar arbol\n";
        std::cout << "0. Volver al menu principal\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                raiz = insertarNodoAVL(raiz, crearProducto());
                break;
            case 2:
                mostrarAVL(raiz);
                break;
        }
        pausarPantalla();
    } while (opcion != 0);
}
