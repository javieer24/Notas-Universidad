#include <cstdlib> // Para system() 
#include "pila.hpp"
#include "utilidades.hpp"
#include <iostream>

void push(NodoPila*& cima, Producto p) {
    NodoPila* nuevo = new NodoPila{p, cima};
    cima = nuevo;
}

void pop(NodoPila*& cima) {
    if (cima) {
        NodoPila* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

void mostrarPila(NodoPila* cima) {
    while (cima) {
        std::cout << "ID: " << cima->producto.id << ", Nombre: " << cima->producto.nombre << "\n";
        cima = cima->siguiente;
    }
}

void menuPila() {
    NodoPila* pila = nullptr;
    int opcion;
    do {
        std::cout << "=== MENU PILA ===\n";
        std::cout << "1. Agregar producto\n";
        std::cout << "2. Eliminar producto\n";
        std::cout << "3. Mostrar pila\n";
        std::cout << "0. Volver al menu principal\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                push(pila, crearProducto());
                break;
            case 2:
                pop(pila);
                break;
            case 3:
                mostrarPila(pila);
                break;
        }
        pausarPantalla();
    } while (opcion != 0);
}
