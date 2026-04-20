#include "utilidades.hpp"
#include <iostream>
#include <limits>
#include <conio.h>

Producto crearProducto() {
    Producto p;
    std::cout << "Ingrese ID del producto: ";
    std::cin >> p.id;
    std::cin.ignore();
    std::cout << "Ingrese nombre del producto: ";
    getline(std::cin, p.nombre);
    std::cout << "Ingrese peso del producto (kg): ";
    std::cin >> p.peso;
    return p;
}

void pausarPantalla() {
    std::cout << "\nPresione una tecla para continuar...\n";
    _getch();
}
