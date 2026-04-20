// Árbol Binario de Búsqueda (ABB) con visualización vertical y recorridos centrados
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct ProductoABB {
    int id;
    string nombre;
    string categoria;
    ProductoABB* izquierda;
    ProductoABB* derecha;
};

ProductoABB* crearProductoABB(int id, string nombre, string categoria) {
    ProductoABB* nuevo = new ProductoABB();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->categoria = categoria;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    return nuevo;
}

ProductoABB* insertarABB(ProductoABB* raiz, int id, string nombre, string categoria) {
    if (raiz == nullptr) {
        return crearProductoABB(id, nombre, categoria);
    }
    if (id < raiz->id) {
        raiz->izquierda = insertarABB(raiz->izquierda, id, nombre, categoria);
    } else if (id > raiz->id) {
        raiz->derecha = insertarABB(raiz->derecha, id, nombre, categoria);
    }
    return raiz;
}

void mostrarArbolABB(ProductoABB* raiz, string prefijo = "", bool esIzquierda = false, bool esRaiz = true) {
    if (raiz == nullptr) return;

    if (raiz->derecha) {
        mostrarArbolABB(raiz->derecha, prefijo + (esIzquierda ? "│   " : "    "), false, false);
    }

    cout << prefijo;
    if (esRaiz) {
        cout << "└── ";
    } else {
        cout << (esIzquierda ? "├── " : "└── ");
    }

    stringstream ss;
    ss << raiz;
    cout << "[" << ss.str() << "] ID: " << raiz->id << ", Nombre: " << raiz->nombre << ", Categoría: " << raiz->categoria << endl;

    if (raiz->izquierda) {
        mostrarArbolABB(raiz->izquierda, prefijo + (esIzquierda ? "│   " : "    "), true, false);
    }
}

void recorridoInordenABB(ProductoABB* raiz, stringstream& salida) {
    if (raiz != nullptr) {
        recorridoInordenABB(raiz->izquierda, salida);
        salida << raiz->id << " (" << raiz->nombre << ")  ";
        recorridoInordenABB(raiz->derecha, salida);
    }
}

void mostrarRecorridoCentradoABB(ProductoABB* raiz) {
    stringstream recorrido;
    recorridoInordenABB(raiz, recorrido);
    string linea = recorrido.str();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int anchoConsola = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int margen = max(0, (anchoConsola - (int)linea.length()) / 2);
    cout << string(margen, ' ') << linea << endl;
}

void menuABB() {
    ProductoABB* raiz = nullptr;
    int opcion, id;
    string nombre, categoria;

    do {
        system("cls");
        cout << "\n=== MENÚ ÁRBOL BINARIO DE BÚSQUEDA (ABB) ===\n";
        cout << "1. Insertar producto\n";
        cout << "2. Mostrar árbol ABB vertical\n";
        cout << "3. Mostrar recorrido inorden centrado\n";
        cout << "0. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "\nIngrese ID del producto: "; cin >> id;
                cin.ignore();
                cout << "Nombre del producto: "; getline(cin, nombre);
                cout << "Categoría: "; getline(cin, categoria);
                raiz = insertarABB(raiz, id, nombre, categoria);
                break;
            case 2:
                cout << "\nVisualización vertical del árbol ABB:\n\n";
                mostrarArbolABB(raiz);
                cout << "\nPresione una tecla para continuar...\n";
                getch();
                break;
            case 3:
                cout << "\nRecorrido inorden centrado:\n\n";
                mostrarRecorridoCentradoABB(raiz);
                cout << "\n\nPresione una tecla para continuar...\n";
                getch();
                break;
            case 0:
                break;
            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                getch();
        }
    } while (opcion != 0);
}
