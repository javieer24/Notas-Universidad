#include <cstdlib> // Para system() 
#include "arbolABB.hpp"
#include "utilidades.hpp"
#include <iostream>
#define ESPACIO 10

void insertarABB(NodoABB*& raiz, Producto p) {
    if (!raiz) {
        raiz = new NodoABB{p, nullptr, nullptr};
    } else if (p.id < raiz->producto.id) {
        insertarABB(raiz->izquierda, p);
    } else if (p.id > raiz->producto.id) {
        insertarABB(raiz->derecha, p);
    }
}

void mostrarABB(NodoABB* raiz, int espacio) {
    if (raiz) {
        espacio += ESPACIO;
        mostrarABB(raiz->derecha, espacio);
        std::cout << std::endl;
        for (int i = ESPACIO; i < espacio; i++) std::cout << " ";
        std::cout << raiz->producto.id << " - " << raiz->producto.nombre << "\n";
        mostrarABB(raiz->izquierda, espacio);
    }
}

void menuABB() {
    NodoABB* raiz = nullptr;
    int opcion;
    do {
        std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the console
        std::cout << "=== MENU ARBOL ABB ===\n";
        std::cout << "1. Insertar producto\n";
        std::cout << "2. Mostrar arbol\n";
        std::cout << "0. Volver al menu principal\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                insertarABB(raiz, crearProducto());
                break;
            case 2:
                mostrarABB(raiz);
                break;
        }
        pausarPantalla();
    } while (opcion != 0);
}
