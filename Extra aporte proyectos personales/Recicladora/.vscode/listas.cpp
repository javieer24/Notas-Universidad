#include <cstdlib> // Para system() 
#include "listas.hpp"
#include "utilidades.hpp"
#include <iostream>

void insertarLista(NodoLista*& cabeza, Producto p) {
    NodoLista* nuevo = new NodoLista{p, nullptr, nullptr};
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        NodoLista* actual = cabeza;
        while (actual->siguiente) actual = actual->siguiente;
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }
}

void eliminarLista(NodoLista*& cabeza, int id) {
    NodoLista* actual = cabeza;
    while (actual && actual->producto.id != id) {
        actual = actual->siguiente;
    }
    if (actual) {
        if (actual->anterior) actual->anterior->siguiente = actual->siguiente;
        else cabeza = actual->siguiente;
        if (actual->siguiente) actual->siguiente->anterior = actual->anterior;
        delete actual;
    }
}

void mostrarLista(NodoLista* cabeza) {
    while (cabeza) {
        std::cout << "ID: " << cabeza->producto.id << ", Nombre: " << cabeza->producto.nombre << "\n";
        cabeza = cabeza->siguiente;
    }
}

void menuLista() {
    NodoLista* lista = nullptr;
    int opcion;
    do {
        std::cout << "=== MENU LISTA ===\n";
        std::cout << "1. Insertar producto\n";
        std::cout << "2. Eliminar producto por ID\n";
        std::cout << "3. Mostrar lista\n";
        std::cout << "0. Volver al menu principal\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                insertarLista(lista, crearProducto());
                break;
            case 2:
                int id;
                std::cout << "Ingrese ID a eliminar: ";
                std::cin >> id;
                eliminarLista(lista, id);
                break;
            case 3:
                mostrarLista(lista);
                break;
        }
        pausarPantalla();
    } while (opcion != 0);
}
