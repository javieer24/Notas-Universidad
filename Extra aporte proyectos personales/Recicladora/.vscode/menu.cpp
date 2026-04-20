#include "menu.hpp"
#include "pila.hpp"
#include "cola.hpp"
#include "listas.hpp"
#include "arbolABB.hpp"
#include "arbolAVL.hpp"
#include "utilidades.hpp"
#include <iostream>
#include <cstdlib> // For system("cls")

void menuPrincipal() {
    int opcion;
    do {
        std::cout << "\033[2J\033[1;1H"; // ANSI escape codes to clear the screen
        std::cout << "==== SISTEMA DE RECICLAJE ====\n";
        std::cout << "1. Gestionar Pila\n";
        std::cout << "2. Gestionar Cola\n";
        std::cout << "3. Gestionar Listas\n";
        std::cout << "4. Gestionar Arbol ABB\n";
        std::cout << "5. Gestionar Arbol AVL\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                menuPila();
                break;
            case 2:
                menuCola();
                break;
            case 3:
                menuLista();
                break;
            case 4:
                menuABB();
                break;
            case 5:
                menuAVL();
                break;
        }
    } while (opcion != 0);
}
