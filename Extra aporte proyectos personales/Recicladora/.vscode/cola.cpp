#include <cstdlib> // Para system() 
#include "cola.hpp"
#include "utilidades.hpp"
#include <iostream>

void encolar(NodoCola*& frente, NodoCola*& fin, Producto p) {
    NodoCola* nuevo = new NodoCola{p, nullptr};
    if (!frente) {
        frente = fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
}

void desencolar(NodoCola*& frente, NodoCola*& fin) {
    if (frente) {
        NodoCola* temp = frente;
        frente = frente->siguiente;
        if (!frente) fin = nullptr;
        delete temp;
    }
}

void mostrarCola(NodoCola* frente) {
    while (frente) {
        std::cout << "ID: " << frente->producto.id << ", Nombre: " << frente->producto.nombre << "\n";
        frente = frente->siguiente;
    }
}

void menuCola() {
    NodoCola* frente = nullptr;
    NodoCola* fin = nullptr;
    int opcion;
    do {
        std::cout << "=== MENU COLA ===\n";
        std::cout << "1. Encolar producto\n";
        std::cout << "2. Desencolar producto\n";
        std::cout << "3. Mostrar cola\n";
        std::cout << "0. Volver al menu principal\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                encolar(frente, fin, crearProducto());
                break;
            case 2:
                desencolar(frente, fin);
                break;
            case 3:
                mostrarCola(frente);
                break;
        }
        pausarPantalla();
    } while (opcion != 0);
}
