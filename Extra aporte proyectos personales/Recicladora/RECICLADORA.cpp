#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <cstdint>
#include <cstddef>   
#include <cstdlib>
#include <thread>   // Para sleep_for
#include <chrono>   // Para milliseconds

constexpr auto ENTER = 13;

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// Declaraci�n de structs
struct Proveedor {
    int id;
    string nombre;
    string direccion;
    string telefono;
    string email;
    string empresa;
    string tipoProducto;
    string pais;
    Proveedor* izquierda;
    Proveedor* derecha;
};

// Puntero global para la ra�z del �rbol ABB
Proveedor* raiz = nullptr;
// Struct para los datos de la direcci�n
struct Direccion {
    string direccion;
    string ciudad;
    string codigoPostal;
};

// Struct para los datos de contacto
struct Contacto {
    string telefono;
    string correo;
};

// Struct para los datos del Conductor
struct DatosConductor {
    string nombre;
    string apellido;
    int edad;
    Contacto contacto; // vinculo con el struct Contacto
    string tipoLicencia;
    int anosExperiencia;
    string estadoCivil;
    Direccion direccion; // vinculo con el struct Direccion
};

// Struct para los datos del Material
struct Material {
    string tipoMaterial;
    bool esReciclable;
};

// Struct para la fecha de recolecci�n
struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Struct para los datos de Lotes de Basura
struct LoteBasura {
    Material material; // vinculo con el struct Material
    float cantidad = 0;
    Fecha fechaRecoleccion; // vinculo con el struct Fecha
    string origen;
    string estadoClasificacion;
    string metodoRecoleccion;
    string tiempoRecoleccion;
    string empresaTransportista;
    string destinoFinal;
};

// Struct para los datos del Motor del Veh�culo
struct Motor {
    string numeroMotor;
    string tipo;
    float capacidad;
};

// Struct para los datos de Veh�culos
struct DatosVehiculo {
    string matricula;
    string tipo;
    float capacidadCarga = 0.0;
    string marca;
    string modelo;
    Fecha anioFabricacion;
    string color;
    string numeroChasis;
    Motor motor; // vinculo con el struct Motor
    DatosConductor conductor; // vinculo con el struct DatosConductor
};

// Estructura para Lista simplemente enlazada
struct NodoSimple {
    int dato;
    NodoSimple* siguiente;
};

// Estructura para Lista doblemente enlazada
struct NodoDoble {
    int dato;
    NodoDoble* anterior;
    NodoDoble* siguiente;
};

// Estructura para Lista simplemente enlazada circular
struct NodoCircular {
    int dato;
    NodoCircular* siguiente;
};

struct ProductoGenerado {
    int iD;
    string nombre;
    float peso;
};

struct Empleado {
    int iD;
    string nombre;
    string puesto;
};

struct Turno {
    int iD;
    string nombre;
    string horario;
};
struct RutaRecoleccionAVL {
    int idRuta; // Clave para el �rbol AVL
    string nombreRuta;
    string conductorAsignado;
    string camionAsignado;
    string frecuenciaRecoleccion;
    string diaOperacion;
    string horaInicioEstimada;
    string horaFinEstimada;
    RutaRecoleccionAVL* izquierda;
    RutaRecoleccionAVL* derecha;
    int altura;
};
// Struct principal Nodo que contiene a LoteBasura y DatosVehiculo
struct Nodo {
    int id;
    LoteBasura lote;
    DatosVehiculo vehiculo;
    ProductoGenerado producto;
    Empleado empleado;
    Turno turno;
    RutaRecoleccionAVL rutaRecoleccion;
    Nodo* siguiente;
    Nodo* anterior; // Solo para la lista doblemente enlazada
};
//ARBOL AVL rutas de recoleccion 
int alturaAVL(RutaRecoleccionAVL* nodo);
int obtenerFactorEquilibrioAVL(RutaRecoleccionAVL* nodo);
RutaRecoleccionAVL* rotacionDerechaAVL(RutaRecoleccionAVL* y);
RutaRecoleccionAVL* rotacionIzquierdaAVL(RutaRecoleccionAVL* x);
RutaRecoleccionAVL* rotacionIzquierdaDerechaAVL(RutaRecoleccionAVL* z);
RutaRecoleccionAVL* rotacionDerechaIzquierdaAVL(RutaRecoleccionAVL* z);
RutaRecoleccionAVL* insertarAVL(RutaRecoleccionAVL* nodo, int idRuta, const string& nombreRuta, const string& conductorAsignado, const string& camionAsignado, const string& frecuenciaRecoleccion, const string& diaOperacion, const string& horaInicioEstimada, const string& horaFinEstimada);
RutaRecoleccionAVL* eliminarAVL(RutaRecoleccionAVL* raiz, int idRuta);
RutaRecoleccionAVL* minimoValorNodoAVL(RutaRecoleccionAVL* nodo);
RutaRecoleccionAVL* buscarRutaAVL(RutaRecoleccionAVL* raiz, int idRuta);
void mostrarArbolAVL(RutaRecoleccionAVL* nodo, int x = 40, int y = 2, int nivel = 0);
void vaciarArbolAVL(RutaRecoleccionAVL*& raiz);
bool modificarRutaAVL(RutaRecoleccionAVL* raiz, int idRuta, const string& nuevoNombreRuta, const string& nuevoConductorAsignado, const string& nuevoCamionAsignado, const string& nuevaFrecuenciaRecoleccion, const string& nuevoDiaOperacion, const string& nuevaHoraInicioEstimada, const string& nuevaHoraFinEstimada);
void recorrerPreordenAVL(RutaRecoleccionAVL* nodo);
void recorrerInordenAVL(RutaRecoleccionAVL* nodo);
void recorrerPostordenAVL(RutaRecoleccionAVL* nodo);
void IngresarDatosRutaAVL();
void MostrarSubMenuArbolAVL();


// Declaraci�n de funciones
void IngresarDatosPila();
void IngresarDatosCola();
void VerDatosPila();
void VerDatosCola();
void ModificarDatoPila();
void ModificarDatoCola();
void BuscarDatoPila();
void BuscarDatoCola();
void EliminarDatoPila();
void EliminarDatoCola();
void MostrarMenuPrincipal();
void MostrarSubMenuPila();
void MostrarSubMenuCola();
void PantallaDeInicio();
void EliminarEnListaSimple(int datoEliminar);
void EliminarEnListaDoble(int datoELiminar);
void EliminarEnListaCircular(int datoEliminar);
void VaciarListaSimple();
void VaciarListaDoble();
void VaciarListaCircular();
void NavegarMenu(int& opcion, int maxOpcion, const string& menuType);
void imagen1();
void imagen2();
void InsertarProductoGenerado(ProductoGenerado producto);
void InsertarEmpleado(Empleado empleado);
void InsertarTurno(Turno turno);
void VerListaSimple();
void VerListaDoble();
void VerListaCircular();
void IngresarDatosABB();
void MostrarArbolABB(Proveedor* nodo, int x = 40, int y = 2, int nivel = 0);
Proveedor* BuscarProveedor(Proveedor* nodo, int id);
Proveedor* EliminarProveedor(Proveedor* nodo, int id);
Proveedor* MinimoValorNodo(Proveedor* nodo);
void MostrarSubMenuABB();
void gotoxy(int x, int y);
void RecorrerPreorden(Proveedor* nodo);
void RecorrerInorden(Proveedor* nodo);
void RecorrerPostorden(Proveedor* nodo);
void VaciarArbolABB(Proveedor*& nodo);


void centrarTexto(const string& texto, int y);

// Punteros globales para la PILA y COLA
Nodo* cimaPila = nullptr;
Nodo* frenteCola = nullptr;
Nodo* finalCola = nullptr;

// Punteros globales para las listas
Nodo* cabezaSimple = nullptr;
Nodo* cabezaDoble = nullptr;
Nodo* colaDoble = nullptr;
Nodo* cabezaCircular = nullptr;

// Puntero global para la ra�z del �rbol AVL de rutas
RutaRecoleccionAVL* raizAVL = nullptr;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool mostrarImagenYVerificarSalida(void (*imagenFuncion)()) {
    imagenFuncion();
    sleep_for(milliseconds(500));  // Espera 500 ms
    system("cls");
    return _kbhit() && _getch() == ENTER;  // Verifica si se presiono ENTER
}

// Funcion para mostrar la imagen de inicio
void imagenInicio() {
    while (true) {
        if (mostrarImagenYVerificarSalida(imagen1)) break;
        if (mostrarImagenYVerificarSalida(imagen2)) break;
    }  // Llama al menu principal
}
void MostrarSubMenuListaSimple() {
    int opcion = 1;
    do {
        system("cls");
        int centroX = 40; // Centrar horizontalmente
        int inicioY = 5; // Posici�n inicial vertical
        gotoxy(centroX, inicioY); cout << "===============================";
        gotoxy(centroX, inicioY + 1); cout << " Modulo de Lista Simple Enlazada ";
        gotoxy(centroX, inicioY + 2); cout << "===============================";
        gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : " ") << "1 - Insertar dato en la lista" << (opcion == 1 ? " <<" : "");
        gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : " ") << "2 - Eliminar dato de la lista" << (opcion == 2 ? " <<" : "");
        gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : " ") << "3 - Vaciar la lista" << (opcion == 3 ? " <<" : "");
        gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : " ") << "4 - Ver lista" << (opcion == 4 ? " <<" : "");
        gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : " ") << "5 - Regresar al menu principal" << (opcion == 5 ? " <<" : "");
        gotoxy(centroX, inicioY + 10); cout << "Use las flechas para navegar y Enter para seleccionar.";
        NavegarMenu(opcion, 5, "LISTA SIMPLE");
        switch (opcion) {
        case 1: {
            gotoxy(centroX, inicioY + 12); cout << "Ingrese los datos: " << endl;
            Empleado empleado;
            cout << "Ingrese ID del empleado: ";
            cin >> empleado.iD;
            cout << "Ingrese nombre del empleado: ";
            cin.ignore();
            getline(cin, empleado.nombre);
            cout << "Ingrese puesto del empleado: ";
            getline(cin, empleado.puesto);
            InsertarEmpleado(empleado);
            break;
        }
        case 2: {
            int datoEliminar;
            gotoxy(centroX, inicioY + 12); cout << "Ingrese el dato que desea eliminar: ";
            cin >> datoEliminar;
            EliminarEnListaSimple(datoEliminar);
            break;
        }
        case 3:
            VaciarListaSimple();
            break;
        case 4:
            VerListaSimple();
            break;
        case 5:
            return; // Salir del submen�
        default:
            break;
        }
    } while (opcion != 5);
}
void MostrarSubMenuListaDoble() {
    int opcion = 1;
    do {
        system("cls");
        int centroX = 40; // Centrar horizontalmente
        int inicioY = 5; // Posici�n inicial vertical
        gotoxy(centroX, inicioY); cout << "===============================";
        gotoxy(centroX, inicioY + 1); cout << " Modulo de Lista Doblemente Enlazada ";
        gotoxy(centroX, inicioY + 2); cout << "===============================";
        gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : " ") << "1 - Insertar dato en la lista" << (opcion == 1 ? " <<" : "");
        gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : " ") << "2 - Eliminar dato de la lista" << (opcion == 2 ? " <<" : "");
        gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : " ") << "3 - Vaciar la lista" << (opcion == 3 ? " <<" : "");
        gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : " ") << "4 - Ver lista" << (opcion == 4 ? " <<" : "");
        gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : " ") << "5 - Regresar al menu principal" << (opcion == 5 ? " <<" : "");
        gotoxy(centroX, inicioY + 10); cout << "Use las flechas para navegar y Enter para seleccionar.";
        NavegarMenu(opcion, 5, "LISTA DOBLE");
        switch (opcion) {
        case 1: {
            gotoxy(centroX, inicioY + 12); cout << "Ingrese los datos: " << endl;
            ProductoGenerado producto;
            cout << "Ingrese ID del producto: ";
            cin >> producto.iD;
            cout << "Ingrese nombre del producto: ";
            cin.ignore();
            getline(cin, producto.nombre);
            cout << "Ingrese peso del producto: ";
            cin >> producto.peso;
            InsertarProductoGenerado(producto);
            break;
        }
        case 2: {
            int datoEliminar;
            gotoxy(centroX, inicioY + 12); cout << "Ingrese el dato que desea eliminar: ";
            cin >> datoEliminar;
            EliminarEnListaDoble(datoEliminar);
            break;
        }
        case 3:
            VaciarListaDoble();
            break;
        case 4:
            VerListaDoble();
            break;
        case 5:
            return; // Salir del submen�
        default:
            break;
        }
    } while (opcion != 5);
}

void MostrarSubMenuListaCircular() {
    int opcion = 1;
    do {
        system("cls");
        int centroX = 40; // Centrar horizontalmente
        int inicioY = 5; // Posici�n inicial vertical

        gotoxy(centroX, inicioY); cout << "===============================";
        gotoxy(centroX, inicioY + 1); cout << " Modulo de Lista Circular Enlazada ";
        gotoxy(centroX, inicioY + 2); cout << "===============================";
        gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : " ") << "1 - Insertar dato en la lista" << (opcion == 1 ? " <<" : "");
        gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : " ") << "2 - Eliminar dato de la lista" << (opcion == 2 ? " <<" : "");
        gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : " ") << "3 - Vaciar la lista" << (opcion == 3 ? " <<" : "");
        gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : " ") << "4 - Ver lista" << (opcion == 4 ? " <<" : "");
        gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : " ") << "5 - Regresar al menu principal" << (opcion == 5 ? " <<" : "");
        gotoxy(centroX, inicioY + 10); cout << "Use las flechas para navegar y Enter para seleccionar.";

        NavegarMenu(opcion, 5, "LISTA CIRCULAR");
        switch (opcion) {
        case 1: {
            gotoxy(centroX, inicioY + 12); cout << "Ingrese los datos:" << endl;
            Turno turno;
            cout << "Ingrese ID del turno: ";
            cin >> turno.iD;
            cout << "Ingrese nombre del turno: ";
            cin.ignore();
            getline(cin, turno.nombre);
            cout << "Ingrese horario del turno: ";
            getline(cin, turno.horario);
            InsertarTurno(turno);
            break;
        }
        case 2: {
            int datoEliminar;
            gotoxy(centroX, inicioY + 12); cout << "Ingrese el dato que desea eliminar: ";
            cin >> datoEliminar;
            EliminarEnListaCircular(datoEliminar);
            break;
        }
        case 3:
            VaciarListaCircular();
            break;
        case 4:
            VerListaCircular();
            break;
        case 5:
            return; // Salir del submen�
        default:
            break;
        }
    } while (opcion != 5);
}

int main() {
    int opcion = 1;
    imagenInicio();
    //PantallaDeInicio();
    MostrarMenuPrincipal();
    
    NavegarMenu(opcion, 8, "PRINCIPAL");
    return 0;
}

// Funci�n para mostrar la pantalla de inicio
void PantallaDeInicio() {
    system("cls");
    int centroX = 40; // Coordenada para centrar horizontalmente
    int inicioY = 5;  // Coordenada para la posici�n inicial vertical

    gotoxy(centroX, inicioY);     cout << "*******************************************";
    gotoxy(centroX, inicioY + 1); cout << "*           SISTEMA DE RECICLADORA        *";
    gotoxy(centroX, inicioY + 2); cout << "*******************************************";
    gotoxy(centroX, inicioY + 4); cout << "Transformando residuos en recursos";
    gotoxy(centroX, inicioY + 5); cout << "===========================================";
    gotoxy(centroX, inicioY + 6); cout << "                 Integrantes               ";
    gotoxy(centroX, inicioY + 7); cout << "===========================================";
    gotoxy(centroX, inicioY + 8); cout << "Fatima Lourdes Santos Guzman 5090-23-5148";
    gotoxy(centroX, inicioY + 9); cout << "Gadely Gardenia Jimenez Cuyuch 5090-23-6542";
    gotoxy(centroX, inicioY + 10); cout << "Stephanie Cristina Saban Carcamo 5090-23-11167";
    gotoxy(centroX, inicioY + 11); cout << "===========================================";
    gotoxy(centroX, inicioY + 12); cout << "                  Seccion: A               ";
    gotoxy(centroX, inicioY + 13); cout << "===========================================";
    gotoxy(centroX, inicioY + 15); cout << "Recicla hoy para un mejor futuro";
    gotoxy(centroX, inicioY + 17); cout << "===========================================";

    system("color DF"); // Cambia los colores de fondo y texto (personalizable)
    gotoxy(centroX, inicioY + 19); system("PAUSE");
}
// Funci�n para mostrar el men� principal
void MostrarMenuPrincipal() {
    int opcion = 1;
    do {
        system("cls");
        int centroX = 40;
        int inicioY = 5;
        gotoxy(centroX, inicioY); cout << "===============================";
        gotoxy(centroX, inicioY + 1); cout << " Menu Principal Recicladora ";
        gotoxy(centroX, inicioY + 2); cout << "===============================";
        gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : " ") << "1 - Modulo de datos de lotes de basura (PILA)" << (opcion == 1 ? " <<" : "");
        gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : " ") << "2 - Modulo de datos de vehiculos (COLA)" << (opcion == 2 ? " <<" : "");
        gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : " ") << "3 - Modulo de Lista Simplemente Enlazada" << (opcion == 3 ? " <<" : "");
        gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : " ") << "4 - Modulo de Lista Doblemente Enlazada" << (opcion == 4 ? " <<" : "");
        gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : " ") << "5 - Modulo de Lista Simplemente Enlazada Circular" << (opcion == 5 ? " <<" : "");
        gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : " ") << "6 - Ingresar datos en arbol ABB" << (opcion == 6 ? " <<" : "");
        gotoxy(centroX, inicioY + 10); cout << (opcion == 7 ? ">> " : " ") << "7 - Modulo de Arbol AVL (Rutas)" << (opcion == 7 ? " <<" : "");
        gotoxy(centroX, inicioY + 11); cout << (opcion == 8 ? ">> " : " ") << "8 - Salida" << (opcion == 8 ? " <<" : "");
        gotoxy(centroX, inicioY + 13); cout << "Use las flechas para navegar y Enter para seleccionar.";
        NavegarMenu(opcion, 8, "PRINCIPAL"); // Aseg�rate de que maxOpcion sea 8
        
        switch (opcion) {
        case 1:
            MostrarSubMenuPila();
            break;
        case 2:
            MostrarSubMenuCola();
            break;
        case 3:
            MostrarSubMenuListaSimple();
            break;
        case 4:
            MostrarSubMenuListaDoble();
            break;
        case 5:
            MostrarSubMenuListaCircular();
            break;
        case 6:
            MostrarSubMenuABB();
            break;
        case 7:
            MostrarSubMenuArbolAVL(); 
            break;
        case 8:
            gotoxy(centroX, inicioY + 14); cout << "Saliendo del sistema...";
            break;
        default:
            break;
        }
    } while (opcion != 8); // El bucle debe continuar hasta que se seleccione la opci�n 8 (Salir)
}
// Funci�n para mostrar el submen� del m�dulo de ABB
void MostrarSubMenuABB() {
    int opcion = 1;
    do {
        system("cls");
        int centroX = 40;
        int inicioY = 5;
        gotoxy(centroX, inicioY); cout << "===============================";
        gotoxy(centroX, inicioY + 1); cout << " Modulo de datos en arbol ABB ";
        gotoxy(centroX, inicioY + 2); cout << "===============================";
        gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : " ") << "1 - Ingresar datos" << (opcion == 1 ? " <<" : "");
        gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : " ") << "2 - Mostrar arbol (IDs)" << (opcion == 2 ? " <<" : "");
        gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : " ") << "3 - Buscar proveedor por ID" << (opcion == 3 ? " <<" : "");
        gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : " ") << "4 - Eliminar proveedor" << (opcion == 4 ? " <<" : "");
        gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : " ") << "5 - Recorrer arbol (Preorden)" << (opcion == 5 ? " <<" : "");
        gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : " ") << "6 - Recorrer arbol (Inorden)" << (opcion == 6 ? " <<" : "");
        gotoxy(centroX, inicioY + 10); cout << (opcion == 7 ? ">> " : " ") << "7 - Recorrer arbol (Postorden)" << (opcion == 7 ? " <<" : "");
        gotoxy(centroX, inicioY + 11); cout << (opcion == 8 ? ">> " : " ") << "8 - Vaciar arbol ABB" << (opcion == 8 ? " <<" : "");
        gotoxy(centroX, inicioY + 12); cout << (opcion == 9 ? ">> " : " ") << "9 - Regresar al menu principal" << (opcion == 9 ? " <<" : "");
        gotoxy(centroX, inicioY + 14); cout << "Use las flechas para navegar y Enter para seleccionar.";
        NavegarMenu(opcion, 9, "ABB");
        switch (opcion) {
        case 1:
            IngresarDatosABB();
            break;
        case 2:
            system("cls");
            MostrarArbolABB(raiz);
            system("pause");
            break;
        case 3: {
            int id;
            system("cls");
            centrarTexto("Ingrese el ID del proveedor a buscar: ", 10);
            gotoxy(40 + 25, 10);
            cin >> id;
            Proveedor* proveedor = BuscarProveedor(raiz, id);
            system("pause");
            break;
        }
        case 4: {
            int id;
            system("cls");
            centrarTexto("Ingrese el ID del proveedor a eliminar: ", 10);
            gotoxy(40 + 25, 10);
            cin >> id;
            raiz = EliminarProveedor(raiz, id);
            centrarTexto("Proveedor eliminado (si existia).", 42);
            system("pause");
            break;
        }
        case 5:
            system("cls");
            centrarTexto("Recorrido en Preorden", 10);
            RecorrerPreorden(raiz);
            system("pause");
            break;
        case 6:
            system("cls");
            centrarTexto("Recorrido en Inorden", 10);
            RecorrerInorden(raiz);
            system("pause");
            break;
        case 7:
            system("cls");
            centrarTexto("Recorrido en Postorden", 10);
            RecorrerPostorden(raiz);
            system("pause");
            break;
        case 8:
            VaciarArbolABB(raiz);
            centrarTexto("Arbol ABB vaciado.", 10);
            system("pause");
            break;
        case 9:
            return;
        default:
            break;
        }
    } while (opcion != 9);
}
//Funcion para mostrar el submenu del modulo de arbol AVL
void MostrarSubMenuArbolAVL() {
    int opcion = 1;
    do {
        system("cls");
        int centroX = 40;
        int inicioY = 5;
        gotoxy(centroX, inicioY); cout << "===================================";
        gotoxy(centroX, inicioY + 1); cout << " Modulo de datos en arbol AVL (Rutas) ";
        gotoxy(centroX, inicioY + 2); cout << "===================================";
        gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "    ") << "1 - Ingresar datos de Ruta" << (opcion == 1 ? " <<" : "");
        gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "    ") << "2 - Mostrar arbol (IDs)" << (opcion == 2 ? " <<" : "");
        gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "    ") << "3 - Buscar Ruta por ID" << (opcion == 3 ? " <<" : "");
        gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "    ") << "4 - Eliminar Ruta" << (opcion == 4 ? " <<" : "");
        gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "    ") << "5 - Recorrer arbol (Preorden)" << (opcion == 5 ? " <<" : "");
        gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : "    ") << "6 - Recorrer arbol (Inorden)" << (opcion == 6 ? " <<" : "");
        gotoxy(centroX, inicioY + 10); cout << (opcion == 7 ? ">> " : "    ") << "7 - Recorrer arbol (Postorden)" << (opcion == 7 ? " <<" : "");
        gotoxy(centroX, inicioY + 11); cout << (opcion == 8 ? ">> " : "    ") << "8 - Vaciar arbol AVL" << (opcion == 8 ? " <<" : "");
        gotoxy(centroX, inicioY + 12); cout << (opcion == 9 ? ">> " : "    ") << "9 - Regresar al menu principal" << (opcion == 9 ? " <<" : "");
        gotoxy(centroX, inicioY + 14); cout << "Use las flechas para navegar y Enter para seleccionar.";
        NavegarMenu(opcion, 9, "AVL");
        switch (opcion) {
        case 1:
            IngresarDatosRutaAVL();
            break;
        case 2:
            system("cls");
            mostrarArbolAVL(raizAVL); 
            system("pause");
            break;
        case 3: {
            int idBusqueda;
            system("cls");
            centrarTexto("Ingrese el ID de la Ruta a buscar: ", 10);
            gotoxy(centroX + 25, 10);
            cin >> idBusqueda;
            RutaRecoleccionAVL* rutaEncontrada = buscarRutaAVL(raizAVL, idBusqueda); // Debes implementar esta funci�n
            system("pause");
            break;
        }
        case 4: {
            int idEliminar;
            system("cls");
            centrarTexto("Ingrese el ID de la Ruta a eliminar: ", 10);
            gotoxy(centroX + 25, 10);
            cin >> idEliminar;
            raizAVL = eliminarAVL(raizAVL, idEliminar); 
            centrarTexto("Ruta eliminada (si existia).", 12);
            system("pause");
            break;
        }
        case 5:
            system("cls");
            centrarTexto("Recorrido en Preorden", 10);
            recorrerPreordenAVL(raizAVL);
            system("pause");
            break;
        case 6:
            system("cls");
            centrarTexto("Recorrido en Inorden", 10);
            recorrerInordenAVL(raizAVL);
            system("pause");
            break;
        case 7:
            system("cls");
            centrarTexto("Recorrido en Postorden", 10);
            recorrerPostordenAVL(raizAVL);
            system("pause");
            break;
        case 8:
            vaciarArbolAVL(raizAVL); 
            centrarTexto("Arbol AVL de Rutas vaciado.", 10);
            system("pause");
            break;
        case 9:
            return;
        default:
            break;
        }
    } while (opcion != 9);
}

// Funcion para mostrar el submenu del modulo de PILA
void MostrarSubMenuPila() {
    int opcion = 1;
    do {
        system("cls");
        int centroX = 40; // Centrar horizontalmente
        int inicioY = 5;  // Posici�n inicial vertical

        gotoxy(centroX, inicioY);     cout << "===============================";
        gotoxy(centroX, inicioY + 1); cout << " Modulo de datos de Lotes de Basura (PILA) ";
        gotoxy(centroX, inicioY + 2); cout << "===============================";
        gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "   ") << "1 - Ingreso de datos de Lotes de Basura" << (opcion == 1 ? " <<" : "");
        gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "   ") << "2 - Ver datos en forma de PILA" << (opcion == 2 ? " <<" : "");
        gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "   ") << "3 - Modificar un dato" << (opcion == 3 ? " <<" : "");
        gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "   ") << "4 - Buscar un dato" << (opcion == 4 ? " <<" : "");
        gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "   ") << "5 - Eliminar un dato" << (opcion == 5 ? " <<" : "");
        gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : "   ") << "6 - Regresar al menu principal" << (opcion == 6 ? " <<" : "");
        gotoxy(centroX, inicioY + 11); cout << "Use las flechas para navegar y Enter para seleccionar.";

        NavegarMenu(opcion, 6, "PILA");

        switch (opcion) {
        case 1:
            IngresarDatosPila();
            break;
        case 2:
            VerDatosPila();
            break;
        case 3:
            ModificarDatoPila();
            break;
        case 4:
            BuscarDatoPila();
            break;
        case 5:
            EliminarDatoPila();
            break;
        case 6:
            return; // Salir del submen�
        default:
            break;
        }
    } while (opcion != 6);
}


// Funci�n para mostrar el submen� del m�dulo de COLA
void MostrarSubMenuCola() {
    int opcion = 1;
    do {
        system("cls");
        int centroX = 40; // Centrar horizontalmente
        int inicioY = 5;  // Posici�n inicial vertical

        gotoxy(centroX, inicioY);     cout << "===============================";
        gotoxy(centroX, inicioY + 1); cout << " Modulo de datos de Vehiculos (COLA) ";
        gotoxy(centroX, inicioY + 2); cout << "===============================";
        gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "   ") << "1 - Ingreso de datos de Vehiculos" << (opcion == 1 ? " <<" : "");
        gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "   ") << "2 - Ver datos en forma de COLA" << (opcion == 2 ? " <<" : "");
        gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "   ") << "3 - Modificar un dato" << (opcion == 3 ? " <<" : "");
        gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "   ") << "4 - Buscar un dato" << (opcion == 4 ? " <<" : "");
        gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "   ") << "5 - Eliminar un dato" << (opcion == 5 ? " <<" : "");
        gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : "   ") << "6 - Regresar al menu principal" << (opcion == 6 ? " <<" : "");
        gotoxy(centroX, inicioY + 11); cout << "Use las flechas para navegar y Enter para seleccionar.";

        NavegarMenu(opcion, 6, "COLA");

        switch (opcion) {
        case 1:
            IngresarDatosCola();
            break;
        case 2:
            VerDatosCola();
            break;
        case 3:
            ModificarDatoCola();
            break;
        case 4:
            BuscarDatoCola();
            break;
        case 5:
            EliminarDatoCola();
            break;
        case 6:
            return; // Salir del submen�
        default:
            break;
        }
    } while (opcion != 6);
}
void NavegarMenu(int& opcion, int maxOpcion, const string& menuType) {
    char tecla;
    int centroX = 40; // Coordenada para centrar horizontalmente
    int inicioY = 5;  // Coordenada para iniciar el texto verticalmente

    while (true) {
        tecla = _getch();
        if (tecla == 72) { // Flecha arriba
            opcion = (opcion == 1) ? maxOpcion : opcion - 1;
        }
        else if (tecla == 80) { // Flecha abajo
            opcion = (opcion == maxOpcion) ? 1 : opcion + 1;
        }
        else if (tecla == 13) { // Enter
            return; // Selecci�n con Enter
        }

        system("cls");
        gotoxy(centroX, inicioY); cout << "=======================================";
        gotoxy(centroX, inicioY + 1); cout << "   RECICLADORA LOS GIRASOLES       ";
        gotoxy(centroX, inicioY + 2); cout << "=======================================";

        if (menuType == "PRINCIPAL") {
            gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "   ") << "1 - Modulo de datos de lotes de basura (PILA)" << (opcion == 1 ? " <<" : "");
            gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "   ") << "2 - Modulo de datos de vehiculos (COLA)" << (opcion == 2 ? " <<" : "");
            gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "   ") << "3 - Modulo de Lista Simplemente Enlazada" << (opcion == 3 ? " <<" : "");
            gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "   ") << "4 - Modulo de Lista Doblemente Enlazada" << (opcion == 4 ? " <<" : "");
            gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "   ") << "5 - Modulo de Lista Simplemente Enlazada Circular" << (opcion == 5 ? " <<" : "");
            gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : "   ") << "6 - Modulo de Arbol ABB" << (opcion == 6 ? " <<" : "");
            gotoxy(centroX, inicioY + 10); cout << (opcion == 7 ? ">> " : "   ") << "7 - Modulo de Arbol AVL (Rutas)" << (opcion == 7 ? " <<" : "");
            gotoxy(centroX, inicioY + 11); cout << (opcion == 8 ? ">> " : "   ") << "8 - Salir" << (opcion == 8 ? " <<" : "");
        }
        else if (menuType == "PILA") {
            gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "   ") << "1 - Ingreso de datos de Lotes de Basura" << (opcion == 1 ? " <<" : "");
            gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "   ") << "2 - Ver datos en forma de PILA" << (opcion == 2 ? " <<" : "");
            gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "   ") << "3 - Modificar un dato" << (opcion == 3 ? " <<" : "");
            gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "   ") << "4 - Buscar un dato" << (opcion == 4 ? " <<" : "");
            gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "   ") << "5 - Eliminar un dato" << (opcion == 5 ? " <<" : "");
            gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : "   ") << "6 - Atras (menu principal)" << (opcion == 6 ? " <<" : "");
        }
        else if (menuType == "COLA") {
            gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "   ") << "1 - Ingreso de datos de Vehiculos" << (opcion == 1 ? " <<" : "");
            gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "   ") << "2 - Ver datos en forma de COLA" << (opcion == 2 ? " <<" : "");
            gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "   ") << "3 - Modificar un dato" << (opcion == 3 ? " <<" : "");
            gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "   ") << "4 - Buscar un dato" << (opcion == 4 ? " <<" : "");
            gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "   ") << "5 - Eliminar un dato" << (opcion == 5 ? " <<" : "");
            gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : "   ") << "6 - Atras (menu principal)" << (opcion == 6 ? " <<" : "");
        }
        else if (menuType == "LISTA SIMPLE") {
            gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "   ") << "1 - Insertar dato en la lista" << (opcion == 1 ? " <<" : "");
            gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "   ") << "2 - Eliminar dato de la lista" << (opcion == 2 ? " <<" : "");
            gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "   ") << "3 - Vaciar la lista" << (opcion == 3 ? " <<" : "");
            gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "   ") << "4 - Ver lista" << (opcion == 4 ? " <<" : "");
            gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "   ") << "5 - Regresar al menu principal" << (opcion == 5 ? " <<" : "");
        }
        else if (menuType == "LISTA DOBLE") {
            gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "   ") << "1 - Insertar dato en la lista" << (opcion == 1 ? " <<" : "");
            gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "   ") << "2 - Eliminar dato de la lista" << (opcion == 2 ? " <<" : "");
            gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "   ") << "3 - Vaciar la lista" << (opcion == 3 ? " <<" : "");
            gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "   ") << "4 - Ver lista" << (opcion == 4 ? " <<" : "");
            gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "   ") << "5 - Regresar al menu principal" << (opcion == 5 ? " <<" : "");

        }
        else if (menuType == "LISTA CIRCULAR") {
            gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "   ") << "1 - Insertar dato en la lista" << (opcion == 1 ? " <<" : "");
            gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "   ") << "2 - Eliminar dato de la lista" << (opcion == 2 ? " <<" : "");
            gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "   ") << "3 - Vaciar la lista" << (opcion == 3 ? " <<" : "");
            gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "   ") << "4 - Ver lista" << (opcion == 4 ? " <<" : "");
            gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "   ") << "5 - Regresar al menu principal" << (opcion == 5 ? " <<" : "");
        }
        else if (menuType == "ABB") {
            gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "   ") << "1 - Ingresar datos" << (opcion == 1 ? " <<" : "");
            gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "   ") << "2 - Mostrar arbol (IDs)" << (opcion == 2 ? " <<" : "");
            gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "   ") << "3 - Buscar proveedor por ID" << (opcion == 3 ? " <<" : "");
            gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "   ") << "4 - Eliminar proveedor" << (opcion == 4 ? " <<" : "");
            gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "   ") << "5 - Recorrer arbol (Preorden)" << (opcion == 5 ? " <<" : "");
            gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : "   ") << "6 - Recorrer arbol (Inorden)" << (opcion == 6 ? " <<" : "");
            gotoxy(centroX, inicioY + 10); cout << (opcion == 7 ? ">> " : "   ") << "7 - Recorrer arbol (Postorden)" << (opcion == 7 ? " <<" : "");
            gotoxy(centroX, inicioY + 11); cout << (opcion == 8 ? ">> " : "   ") << "8 - Vaciar arbol ABB" << (opcion == 8 ? " <<" : "");
            gotoxy(centroX, inicioY + 12); cout << (opcion == 9 ? ">> " : "   ") << "9 - Regresar al menu principal" << (opcion == 9 ? " <<" : "");
        }
        else if (menuType == "AVL") {
            gotoxy(centroX, inicioY + 4); cout << (opcion == 1 ? ">> " : "    ") << "1 - Ingresar datos de Ruta" << (opcion == 1 ? " <<" : "");
            gotoxy(centroX, inicioY + 5); cout << (opcion == 2 ? ">> " : "    ") << "2 - Mostrar arbol (IDs)" << (opcion == 2 ? " <<" : "");
            gotoxy(centroX, inicioY + 6); cout << (opcion == 3 ? ">> " : "    ") << "3 - Buscar Ruta por ID" << (opcion == 3 ? " <<" : "");
            gotoxy(centroX, inicioY + 7); cout << (opcion == 4 ? ">> " : "    ") << "4 - Eliminar Ruta" << (opcion == 4 ? " <<" : "");
            gotoxy(centroX, inicioY + 8); cout << (opcion == 5 ? ">> " : "    ") << "5 - Recorrer arbol (Preorden)" << (opcion == 5 ? " <<" : "");
            gotoxy(centroX, inicioY + 9); cout << (opcion == 6 ? ">> " : "    ") << "6 - Recorrer arbol (Inorden)" << (opcion == 6 ? " <<" : "");
            gotoxy(centroX, inicioY + 10); cout << (opcion == 7 ? ">> " : "    ") << "7 - Recorrer arbol (Postorden)" << (opcion == 7 ? " <<" : "");
            gotoxy(centroX, inicioY + 11); cout << (opcion == 8 ? ">> " : "    ") << "8 - Vaciar arbol AVL" << (opcion == 8 ? " <<" : "");
            gotoxy(centroX, inicioY + 12); cout << (opcion == 9 ? ">> " : "    ") << "9 - Regresar al menu principal" << (opcion == 9 ? " <<" : "");
        }

    }
}
void IngresarDatosPila() {
    static int idC = 1; //contador estatico para tener ID unicosl 
    Nodo* Nodo1 = new Nodo;
    Nodo1->id = idC++; //asignacion del ID unico al nuevo nodo
    cout << "----Ingreso de datos del lote de basura----" << endl;
    cout << "ID: " << Nodo1->id << " | Mem: " << &Nodo1->id << endl;
    cout << "Tipo de material: "; cin.ignore();
    getline(cin, Nodo1->lote.material.tipoMaterial); //funci�n se usa para leer una l�nea completa de entrada, cin es recibir datos del usuario desde la consola.
    cout << "Mem: " << &Nodo1->lote.material.tipoMaterial << endl;
    cout << "Es reciclable? (1=si, 0=no): "; cin >> Nodo1->lote.material.esReciclable; cout << "Mem: " << &Nodo1->lote.material.esReciclable << endl;
    cout << "Cantidad (kg): "; cin >> Nodo1->lote.cantidad; cout << "Mem: " << &Nodo1->lote.cantidad << endl;
    cout << "Fecha de recoleccion" << endl;
    cout << "Dia: "; cin >> Nodo1->lote.fechaRecoleccion.dia; cout << "Mem: " << &Nodo1->lote.fechaRecoleccion.dia << endl;
    cout << "Mes: "; cin >> Nodo1->lote.fechaRecoleccion.mes; cout << "Mem: " << &Nodo1->lote.fechaRecoleccion.mes << endl;
    cout << "Anio: "; cin >> Nodo1->lote.fechaRecoleccion.anio; cout << "Mem: " << &Nodo1->lote.fechaRecoleccion.anio << endl;
    cout << "Origen: "; cin.ignore();
    getline(cin, Nodo1->lote.origen);
    cout << "Mem: " << &Nodo1->lote.origen << endl;
    cout << "Estado de clasificacion: ";
    getline(cin, Nodo1->lote.estadoClasificacion);
    cout << "Mem: " << &Nodo1->lote.estadoClasificacion << endl;
    cout << "Metodo de recoleccion: ";
    getline(cin, Nodo1->lote.metodoRecoleccion);
    cout << "Mem: " << &Nodo1->lote.metodoRecoleccion << endl;
    cout << "Tiempo de recoleccion: ";
    getline(cin, Nodo1->lote.tiempoRecoleccion);
    cout << "Mem: " << &Nodo1->lote.tiempoRecoleccion << endl;
    cout << "Empresa transportista: ";
    getline(cin, Nodo1->lote.empresaTransportista);
    cout << "Mem: " << &Nodo1->lote.empresaTransportista << endl;
    cout << "Destino final: ";
    getline(cin, Nodo1->lote.destinoFinal);
    cout << "Mem: " << &Nodo1->lote.destinoFinal << endl;
    // Insertar el nuevo nodo en la cima de la pila
    Nodo1->siguiente = cimaPila;
    cimaPila = Nodo1;
    cout << "Datos de lote de basura ingresados correctamente." << endl;
    system("pause");
}
void VerDatosPila() {
    if (cimaPila == nullptr) {
        cout << "La PILA est� vac�a." << endl;
    }
    else {
        Nodo* temp = cimaPila;
        while (temp != nullptr) {
            cout << "----Datos del Lote de Basura----" << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Tipo de material: " << temp->lote.material.tipoMaterial << " | Mem: " << &temp->lote.material.tipoMaterial << endl;
            cout << "Es reciclable: " << (temp->lote.material.esReciclable ? "1 = Si" : "2 = No") << " | Mem: " << &temp->lote.material.esReciclable << endl;
            cout << "Cantidad (kg): " << temp->lote.cantidad << " | Mem: " << &temp->lote.cantidad << endl;
            cout << "Fecha de recoleccion: " << temp->lote.fechaRecoleccion.dia << "/"
                << temp->lote.fechaRecoleccion.mes << "/"
                << temp->lote.fechaRecoleccion.anio << " | Mem: " << &temp->lote.fechaRecoleccion << endl;
            cout << "Origen: " << temp->lote.origen << " | Mem: " << &temp->lote.origen << endl;
            cout << "Estado de clasificacion: " << temp->lote.estadoClasificacion << " | Mem: " << &temp->lote.estadoClasificacion << endl;
            cout << "Metodo de recoleccion: " << temp->lote.metodoRecoleccion << " | Mem: " << &temp->lote.metodoRecoleccion << endl;
            cout << "Tiempo de recoleccion: " << temp->lote.tiempoRecoleccion << " | Mem: " << &temp->lote.tiempoRecoleccion << endl;
            cout << "Empresa transportista: " << temp->lote.empresaTransportista << " | Mem: " << &temp->lote.empresaTransportista << endl;
            cout << "Destino final: " << temp->lote.destinoFinal << " | Mem: " << &temp->lote.destinoFinal << endl;
            // Mostrar saltos de memoria
            cout << "--- Saltos de Memoria ---" << endl;
            cout << "Salto entre tipoMaterial y esReciclable: " << (intptr_t)&temp->lote.material.esReciclable - (intptr_t)&temp->lote.material.tipoMaterial << " bytes" << endl;
            cout << "Salto entre esReciclable y cantidad: " << (intptr_t)&temp->lote.cantidad - (intptr_t)&temp->lote.material.esReciclable << " bytes" << endl;
            cout << "Salto entre cantidad y fechaRecoleccion: " << (intptr_t)&temp->lote.fechaRecoleccion - (intptr_t)&temp->lote.cantidad << " bytes" << endl;
            cout << "Salto entre fechaRecolecci�n y origen: " << (intptr_t)&temp->lote.origen - (intptr_t)&temp->lote.fechaRecoleccion << " bytes" << endl;
            cout << "Salto entre origen y estadoClasificaci�n: " << (intptr_t)&temp->lote.estadoClasificacion - (intptr_t)&temp->lote.origen << " bytes" << endl;
            cout << "Salto entre estadoClasificacion y metodoRecoleccion: " << (intptr_t)&temp->lote.metodoRecoleccion - (intptr_t)&temp->lote.estadoClasificacion << " bytes" << endl;
            cout << "Salto entre metodoRecoleccio y tiempoRecoleccion: " << (intptr_t)&temp->lote.tiempoRecoleccion - (intptr_t)&temp->lote.metodoRecoleccion << " bytes" << endl;
            cout << "Salto entre tiempoRecoleccion y empresaTransportista: " << (intptr_t)&temp->lote.empresaTransportista - (intptr_t)&temp->lote.tiempoRecoleccion << " bytes" << endl;
            cout << "Salto entre empresaTransportista y destinoFinal: " << (intptr_t)&temp->lote.destinoFinal - (intptr_t)&temp->lote.empresaTransportista << " bytes" << endl;
            cout << "-----------------------------" << endl;
            temp = temp->siguiente;
        }
    }
    system("pause"); // Pausa la ejecuci�n

}
void ModificarDatoPila() {
    if (cimaPila == nullptr) {
        cout << "La pila est� vacia" << endl;
        return;
    }
    int idBusqueda;
    cout << "Ingrese el ID del lote que quiere hacer las modificaciones: ";
    cin >> idBusqueda;
    cin.ignore();

    Nodo* temp = cimaPila;
    bool encontrado = false;

    while (temp != nullptr) {
        if (temp->id == idBusqueda) {
            encontrado = true;
            cout << "----Modificacion de lotes de basura----" << endl;
            cout << "Nuevo tipo de material: ";
            getline(cin, temp->lote.material.tipoMaterial);
            cout << "Mem: " << &temp->lote.material.tipoMaterial << endl;
            cout << "Es reciclable? (1 = si, 0 = no): ";
            cin >> temp->lote.material.esReciclable;
            cout << "Mem: " << &temp->lote.material.esReciclable << endl;
            cout << "Cantidad (kg): ";
            cin >> temp->lote.cantidad;
            cout << "Mem: " << &temp->lote.cantidad << endl;
            cout << "Fecha de recolecci�n: " << endl;
            cout << "Dia: ";
            cin >> temp->lote.fechaRecoleccion.dia;
            cout << "Mem: " << &temp->lote.fechaRecoleccion.dia << endl;
            cout << "Mes: ";
            cin >> temp->lote.fechaRecoleccion.mes;
            cout << "Mem: " << &temp->lote.fechaRecoleccion.mes << endl;
            cout << "Anio: ";
            cin >> temp->lote.fechaRecoleccion.anio;
            cout << "Mem: " << &temp->lote.fechaRecoleccion.anio << endl;
            cout << "Origen: ";
            cin.ignore();
            getline(cin, temp->lote.origen);
            cout << "Mem: " << &temp->lote.origen << endl;
            cout << "Estado de clasificacion: ";
            getline(cin, temp->lote.estadoClasificacion);
            cout << "Mem: " << &temp->lote.estadoClasificacion << endl;
            cout << "Metodo de recoleccion: ";
            getline(cin, temp->lote.metodoRecoleccion);
            cout << "Mem: " << &temp->lote.metodoRecoleccion << endl;
            cout << "Tiempo de recoleccion: ";
            getline(cin, temp->lote.tiempoRecoleccion);
            cout << "Mem: " << &temp->lote.tiempoRecoleccion << endl;
            cout << "Empresa transportista: ";
            getline(cin, temp->lote.empresaTransportista);
            cout << "Mem: " << &temp->lote.empresaTransportista << endl;
            cout << "Destino final: ";
            getline(cin, temp->lote.destinoFinal);
            cout << "Mem: " << &temp->lote.destinoFinal << endl;
            cout << "Datos de lote de basura modificados satisfactoriamente." << endl;
            system("PAUSE");
        }
        temp = temp->siguiente;
    }
    if (!encontrado) {
        cout << "No se encontro el lote de basura con el ID ingresado" << endl;
    }
    system("PAUSE");

}
void BuscarDatoPila() {
    if (cimaPila == nullptr) {
        cout << "La pila esta vacia" << endl;
        return;
    }

    int idBusqueda;
    cout << "Ingrese el ID del lote que quiere buscar: ";
    cin >> idBusqueda;
    Nodo* temp = cimaPila;
    bool encontrado = false;

    while (temp != nullptr) {
        if (temp->id == idBusqueda) {
            encontrado = true;
            cout << "----Datos del Lote de Basura----" << endl;
            cout << "ID: " << temp->id << " | Mem: " << &temp->id << endl;
            cout << "Tipo de material: " << temp->lote.material.tipoMaterial << " | Mem: " << &temp->lote.material.tipoMaterial << endl;
            cout << "Es reciclable: " << (temp->lote.material.esReciclable ? "1 = Si" : "2 = No") << " | Mem: " << &temp->lote.material.esReciclable << endl;
            cout << "Cantidad (kg): " << temp->lote.cantidad << " | Mem: " << &temp->lote.cantidad << endl;
            cout << "Fecha de recoleccion: " << temp->lote.fechaRecoleccion.dia << "/"
                << temp->lote.fechaRecoleccion.mes << "/"
                << temp->lote.fechaRecoleccion.anio << " | Mem: " << &temp->lote.fechaRecoleccion << endl;
            cout << "Origen: " << temp->lote.origen << " | Mem: " << &temp->lote.origen << endl;
            cout << "Estado de clasificacion: " << temp->lote.estadoClasificacion << " | Mem: " << &temp->lote.estadoClasificacion << endl;
            cout << "Metodo de recoleccion: " << temp->lote.metodoRecoleccion << " | Mem: " << &temp->lote.metodoRecoleccion << endl;
            cout << "Tiempo de recoleccion: " << temp->lote.tiempoRecoleccion << " | Mem: " << &temp->lote.tiempoRecoleccion << endl;
            cout << "Empresa transportista: " << temp->lote.empresaTransportista << " | Mem: " << &temp->lote.empresaTransportista << endl;
            cout << "Destino final: " << temp->lote.destinoFinal << " | Mem: " << &temp->lote.destinoFinal << endl;

            // Mostrar saltos de memoria
            cout << "--- Saltos de Memoria ---" << endl;
            cout << "Salto entre tipoMaterial y esReciclable: " << (intptr_t)&temp->lote.material.esReciclable - (intptr_t)&temp->lote.material.tipoMaterial << " bytes" << endl;
            cout << "Salto entre esReciclable y cantidad: " << (intptr_t)&temp->lote.cantidad - (intptr_t)&temp->lote.material.esReciclable << " bytes" << endl;
            cout << "Salto entre cantidad y fechaRecoleccion: " << (intptr_t)&temp->lote.fechaRecoleccion - (intptr_t)&temp->lote.cantidad << " bytes" << endl;
            cout << "Salto entre fechaRecolecci�n y origen: " << (intptr_t)&temp->lote.origen - (intptr_t)&temp->lote.fechaRecoleccion << " bytes" << endl;
            cout << "Salto entre origen y estadoClasificacion: " << (intptr_t)&temp->lote.estadoClasificacion - (intptr_t)&temp->lote.origen << " bytes" << endl;
            cout << "Salto entre estadoClasificacion y metodoRecoleccion: " << (intptr_t)&temp->lote.metodoRecoleccion - (intptr_t)&temp->lote.estadoClasificacion << " bytes" << endl;
            cout << "Salto entre metodoRecoleccion y tiempoRecoleccion: " << (intptr_t)&temp->lote.tiempoRecoleccion - (intptr_t)&temp->lote.metodoRecoleccion << " bytes" << endl;
            cout << "Salto entre tiempoRecoleccion y empresaTransportista: " << (intptr_t)&temp->lote.empresaTransportista - (intptr_t)&temp->lote.tiempoRecoleccion << " bytes" << endl;
            cout << "Salto entre empresaTransportista y destinoFinal: " << (intptr_t)&temp->lote.destinoFinal - (intptr_t)&temp->lote.empresaTransportista << " bytes" << endl;

            system("PAUSE");
            break;
        }
        temp = temp->siguiente;
    }
    if (!encontrado) {
        cout << "No se encontro el lote de basura con el ID ingresado" << endl;
    }
    system("PAUSE");
}
void EliminarDatoPila() {
    if (cimaPila == nullptr) {
        cout << "La pila esta vacia. No se puede eliminar nada." << endl;
        return;
    }

    // Muestra los datos antes de eliminar.
    cout << "---Estado actual de la PILA---" << endl;
    VerDatosPila();

    // Eliminar el nodo en la cima
    Nodo* temp = cimaPila;
    cimaPila = cimaPila->siguiente;

    // Mostrar direcciones de memoria y saltos antes de eliminar
    cout << "--- Direcciones de Memoria del Nodo a Eliminar ---" << endl;
    cout << "Direccion de memoria ID: " << &temp->id << endl;
    cout << "Direccion de memoria tipoMaterial: " << &temp->lote.material.tipoMaterial << endl;
    cout << "Direccion de memoria esReciclable: " << &temp->lote.material.esReciclable << endl;
    cout << "Direccion de memoria cantidad: " << &temp->lote.cantidad << endl;
    cout << "Direccion de memoria fechaRecoleccion: " << &temp->lote.fechaRecoleccion << endl;
    cout << "Direccion de memoria origen: " << &temp->lote.origen << endl;
    cout << "Direccion de memoria estadoClasificacion: " << &temp->lote.estadoClasificacion << endl;
    cout << "Direccion de memoria metodoRecoleccion: " << &temp->lote.metodoRecoleccion << endl;
    cout << "Direccion de memoria tiempoRecoleccion: " << &temp->lote.tiempoRecoleccion << endl;
    cout << "Direccion de memoria empresaTransportista: " << &temp->lote.empresaTransportista << endl;
    cout << "Direccion de memoria destinoFinal: " << &temp->lote.destinoFinal << endl;

    // Calcular y mostrar saltos de memoria
    cout << "--- Saltos de Memoria ---" << endl;
    cout << "Salto entre ID y tipoMaterial: " << (intptr_t)&temp->lote.material.tipoMaterial - (intptr_t)&temp->id << " bytes" << endl;
    cout << "Salto entre tipoMaterial y esReciclable: " << (intptr_t)&temp->lote.material.esReciclable - (intptr_t)&temp->lote.material.tipoMaterial << " bytes" << endl;
    cout << "Salto entre esReciclable y cantidad: " << (intptr_t)&temp->lote.cantidad - (intptr_t)&temp->lote.material.esReciclable << " bytes" << endl;
    cout << "Salto entre cantidad y fechaRecoleccion: " << (intptr_t)&temp->lote.fechaRecoleccion - (intptr_t)&temp->lote.cantidad << " bytes" << endl;
    cout << "Salto entre fechaRecoleccion y origen: " << (intptr_t)&temp->lote.origen - (intptr_t)&temp->lote.fechaRecoleccion << " bytes" << endl;
    cout << "Salto entre origen y estadoClasificacion: " << (intptr_t)&temp->lote.estadoClasificacion - (intptr_t)&temp->lote.origen << " bytes" << endl;
    cout << "Salto entre estadoClasificacion y metodoRecoleccion: " << (intptr_t)&temp->lote.metodoRecoleccion - (intptr_t)&temp->lote.estadoClasificacion << " bytes" << endl;
    cout << "Salto entre metodoRecoleccion y tiempoRecoleccion: " << (intptr_t)&temp->lote.tiempoRecoleccion - (intptr_t)&temp->lote.metodoRecoleccion << " bytes" << endl;
    cout << "Salto entre tiempoRecoleccion y empresaTransportista: " << (intptr_t)&temp->lote.empresaTransportista - (intptr_t)&temp->lote.tiempoRecoleccion << " bytes" << endl;
    cout << "Salto entre empresaTransportista y destinoFinal: " << (intptr_t)&temp->lote.destinoFinal - (intptr_t)&temp->lote.empresaTransportista << " bytes" << endl;

    delete temp;

    cout << "Nodo eliminado correctamente." << endl;

    // Mostrar todos los datos despu�s de haberse eliminado
    cout << "---Estado de la PILA despus de eliminacion---" << endl;
    VerDatosPila();
    system("PAUSE");
}
void IngresarDatosCola() {
    static int idC = 1; //contador estatico para tener ID unicosl 
    Nodo* Nodo1 = new Nodo;
    Nodo1->id = idC++; //asignacion del ID unico al nuevo nodo
    cout << "----Ingreso de datos de los vehiculos----" << endl;
    cout << "Matricula: "; cin.ignore();
    getline(cin, Nodo1->vehiculo.matricula);
    cout << "Tipo de vehiculo: ";
    getline(cin, Nodo1->vehiculo.tipo);
    cout << "Capacidad de carga (kg): ";
    cin >> Nodo1->vehiculo.capacidadCarga;
    cin.ignore();
    cout << "Marca: ";
    getline(cin, Nodo1->vehiculo.marca);
    cout << "Modelo: ";
    getline(cin, Nodo1->vehiculo.modelo);
    cout << "Anio de fabricacion" << endl;
    cout << "Dia: ";
    cin >> Nodo1->vehiculo.anioFabricacion.dia;
    cout << "Mes: ";
    cin >> Nodo1->vehiculo.anioFabricacion.mes;
    cout << "Anio: ";
    cin >> Nodo1->vehiculo.anioFabricacion.anio;
    cin.ignore();
    cout << "Color: ";
    getline(cin, Nodo1->vehiculo.color);
    cout << "Numero de chasis: ";
    getline(cin, Nodo1->vehiculo.numeroChasis);

    // Datos del motor
    cout << "--- Datos del motor ---" << endl;
    cout << "Numero de motor: ";
    getline(cin, Nodo1->vehiculo.motor.numeroMotor);
    cout << "Tipo de motor: ";
    getline(cin, Nodo1->vehiculo.motor.tipo);
    cout << "Capacidad del motor (L): ";
    cin >> Nodo1->vehiculo.motor.capacidad;
    cin.ignore();

    // Datos del conductor
    cout << "--- Datos del conductor ---" << endl;
    cout << "Nombre: ";
    getline(cin, Nodo1->vehiculo.conductor.nombre);
    cout << "Apellido: ";
    getline(cin, Nodo1->vehiculo.conductor.apellido);
    cout << "Edad: ";
    cin >> Nodo1->vehiculo.conductor.edad;
    cin.ignore();
    cout << "Tipo de licencia: ";
    getline(cin, Nodo1->vehiculo.conductor.tipoLicencia);
    cout << "Anios de experiencia: ";
    cin >> Nodo1->vehiculo.conductor.anosExperiencia;
    cin.ignore();
    cout << "Estado civil: ";
    getline(cin, Nodo1->vehiculo.conductor.estadoCivil);
    cout << "Telefono: ";
    getline(cin, Nodo1->vehiculo.conductor.contacto.telefono);
    cout << "Correo: ";
    getline(cin, Nodo1->vehiculo.conductor.contacto.correo);
    cout << "Direccion: ";
    getline(cin, Nodo1->vehiculo.conductor.direccion.direccion);
    cout << "Ciudad: ";
    getline(cin, Nodo1->vehiculo.conductor.direccion.ciudad);
    cout << "Codigo postal: ";
    getline(cin, Nodo1->vehiculo.conductor.direccion.codigoPostal);

    // Insertar el nuevo nodo en la cola
    Nodo1->siguiente = nullptr;
    if (finalCola == nullptr) {
        frenteCola = Nodo1;
    }
    else {
        finalCola->siguiente = Nodo1;
    }
    finalCola = Nodo1;

    cout << "Datos del vehiculo ingresados correctamente." << endl;
    system("pause");
}
void VerDatosCola() {
    system("cls");
    if (frenteCola == nullptr) {
        cout << "La cola esta vacia. No hay vehiculos registrados." << endl;
        system("pause");
        return;
    }
    cout << "---- Lista de Vehiculos en Cola ----" << endl;
    Nodo* actual = frenteCola;
    int x = 2, y = 2;  // Posiciones iniciales
    while (actual != nullptr) {
        gotoxy(x, y);
        cout << "Matricula: " << actual->vehiculo.matricula << " | Mem: " << &actual->vehiculo.matricula;
        gotoxy(x, y + 1);
        cout << "Tipo de veh�culo: " << actual->vehiculo.tipo << " | Mem: " << &actual->vehiculo.tipo;
        gotoxy(x, y + 2);
        cout << "Capacidad de carga: " << actual->vehiculo.capacidadCarga << "kg | Mem: " << &actual->vehiculo.capacidadCarga;
        gotoxy(x, y + 3);
        cout << "Marca: " << actual->vehiculo.marca << " | Mem: " << &actual->vehiculo.marca;
        gotoxy(x, y + 4);
        cout << "Modelo: " << actual->vehiculo.modelo << " | Mem: " << &actual->vehiculo.modelo;
        gotoxy(x, y + 5);
        cout << "Anio de fabricacion: " << actual->vehiculo.anioFabricacion.dia << "/"
            << actual->vehiculo.anioFabricacion.mes << "/"
            << actual->vehiculo.anioFabricacion.anio;
        gotoxy(x, y + 6);
        cout << "Mem: " << &actual->vehiculo.anioFabricacion; // Muestra la direcci�n de la estructura completa
        gotoxy(x, y + 7);
        cout << "Color: " << actual->vehiculo.color << " | Mem: " << &actual->vehiculo.color;
        gotoxy(x, y + 8);
        cout << "Numero de chasis: " << actual->vehiculo.numeroChasis << " | Mem: " << &actual->vehiculo.numeroChasis;
        // Datos del motor
        gotoxy(x, y + 10);
        cout << "--- Datos del motor ---";
        gotoxy(x, y + 11);
        cout << "Numero de motor: " << actual->vehiculo.motor.numeroMotor << " | Mem: " << &actual->vehiculo.motor.numeroMotor;
        gotoxy(x, y + 12);
        cout << "Tipo de motor: " << actual->vehiculo.motor.tipo << " | Mem: " << &actual->vehiculo.motor.tipo;
        gotoxy(x, y + 13);
        cout << "Capacidad del motor: " << actual->vehiculo.motor.capacidad << " L | Mem: " << &actual->vehiculo.motor.capacidad;
        // Datos del conductor
        gotoxy(x, y + 15);
        cout << "--- Datos del conductor ---";
        gotoxy(x, y + 16);
        cout << "Nombre: " << actual->vehiculo.conductor.nombre << " | Mem: " << &actual->vehiculo.conductor.nombre;
        gotoxy(x, y + 17);
        cout << "Apellido: " << actual->vehiculo.conductor.apellido << " | Mem: " << &actual->vehiculo.conductor.apellido;
        gotoxy(x, y + 18);
        cout << "Edad: " << actual->vehiculo.conductor.edad << " | Mem: " << &actual->vehiculo.conductor.edad;
        gotoxy(x, y + 19);
        cout << "Tipo de licencia: " << actual->vehiculo.conductor.tipoLicencia << " | Mem: " << &actual->vehiculo.conductor.tipoLicencia;
        gotoxy(x, y + 20);
        cout << "Anios de experiencia: " << actual->vehiculo.conductor.anosExperiencia << " | Mem: " << &actual->vehiculo.conductor.anosExperiencia;
        gotoxy(x, y + 21);
        cout << "Estado civil: " << actual->vehiculo.conductor.estadoCivil << " | Mem: " << &actual->vehiculo.conductor.estadoCivil;
        // Datos de contacto
        gotoxy(x, y + 23);
        cout << "--- Contacto ---";
        gotoxy(x, y + 24);
        cout << "Telefono: " << actual->vehiculo.conductor.contacto.telefono << " | Mem: " << &actual->vehiculo.conductor.contacto.telefono;
        gotoxy(x, y + 25);
        cout << "Correo: " << actual->vehiculo.conductor.contacto.correo << " | Mem: " << &actual->vehiculo.conductor.contacto.correo;
        gotoxy(x, y + 26);
        cout << "Direccion: " << actual->vehiculo.conductor.direccion.direccion << " | Mem: " << &actual->vehiculo.conductor.direccion.direccion;
        gotoxy(x, y + 27);
        cout << endl << "Ciudad: " << actual->vehiculo.conductor.direccion.ciudad << " | Mem: " << &actual->vehiculo.conductor.direccion.ciudad;
        gotoxy(x, y + 28);
        cout << endl << "Codigo postal: " << actual->vehiculo.conductor.direccion.codigoPostal << " | Mem: " << &actual->vehiculo.conductor.direccion.codigoPostal;
        // Moverse a la siguiente columna
        x += 60;
        if (x > 100) {  // Si se llena el ancho de la consola, bajar de fila
            x = 5;
            y += 32;
        }

        actual = actual->siguiente;
    }

    // Mover el cursor para no sobreescribir el mensaje de pausa
    y += 30;
    gotoxy(0, y + 10);
    cout << endl << endl;
    system("pause");
}


void ModificarDatoCola() {
    if (frenteCola == nullptr) {
        cout << "La cola esta vacia." << endl;
        return;
    }

    int idBusqueda;
    cout << "Ingrese el ID del vehiculo que quiere modificar: ";
    cin >> idBusqueda;
    cin.ignore();

    Nodo* temp = frenteCola;
    bool encontrado = false;

    while (temp != nullptr) {
        if (temp->id == idBusqueda) {
            encontrado = true;
            cout << "----Modificaci�n de datos de veh�culo----" << endl;
            cout << "Nueva matricula: ";
            getline(cin, temp->vehiculo.matricula);
            cout << "Nuevo tipo de vehiculo: ";
            getline(cin, temp->vehiculo.tipo);
            cout << "Nueva capacidad de carga (kg): ";
            cin >> temp->vehiculo.capacidadCarga;
            cin.ignore();
            cout << "Nueva marca: ";
            getline(cin, temp->vehiculo.marca);
            cout << "Nuevo modelo: ";
            getline(cin, temp->vehiculo.modelo);
            cout << "Nueva fecha de fabricacion" << endl;
            cout << "Dia: ";
            cin >> temp->vehiculo.anioFabricacion.dia;
            cout << "Mes: ";
            cin >> temp->vehiculo.anioFabricacion.mes;
            cout << "Anio: ";
            cin >> temp->vehiculo.anioFabricacion.anio;
            cin.ignore();
            cout << "Nuevo color: ";
            getline(cin, temp->vehiculo.color);
            cout << "Nuevo numero de chasis: ";
            getline(cin, temp->vehiculo.numeroChasis);

            // Datos del motor
            cout << "--- Datos del motor ---" << endl;
            cout << "Nuevo numero de motor: ";
            getline(cin, temp->vehiculo.motor.numeroMotor);
            cout << "Nuevo tipo de motor: ";
            getline(cin, temp->vehiculo.motor.tipo);
            cout << "Nueva capacidad del motor (L): ";
            cin >> temp->vehiculo.motor.capacidad;
            cin.ignore();

            // Datos del conductor
            cout << "--- Datos del conductor ---" << endl;
            cout << "Nuevo nombre: ";
            getline(cin, temp->vehiculo.conductor.nombre);
            cout << "Nuevo apellido: ";
            getline(cin, temp->vehiculo.conductor.apellido);
            cout << "Nueva edad: ";
            cin >> temp->vehiculo.conductor.edad;
            cin.ignore();
            cout << "Nuevo tipo de licencia: ";
            getline(cin, temp->vehiculo.conductor.tipoLicencia);
            cout << "Nuevos anios de experiencia: ";
            cin >> temp->vehiculo.conductor.anosExperiencia;
            cin.ignore();
            cout << "Nuevo estado civil: ";
            getline(cin, temp->vehiculo.conductor.estadoCivil);
            cout << "Nuevo telefono: ";
            getline(cin, temp->vehiculo.conductor.contacto.telefono);
            cout << "Nuevo correo: ";
            getline(cin, temp->vehiculo.conductor.contacto.correo);
            cout << "Nueva direccion: ";
            getline(cin, temp->vehiculo.conductor.direccion.direccion);
            cout << "Nueva ciudad: ";
            getline(cin, temp->vehiculo.conductor.direccion.ciudad);
            cout << "Nuevo codigo postal: ";
            getline(cin, temp->vehiculo.conductor.direccion.codigoPostal);

            cout << "Datos del vehiculo modificados satisfactoriamente." << endl;
            system("PAUSE");
            break;
        }
        temp = temp->siguiente;
    }
    if (!encontrado) {
        cout << "No se encontro el vehiculo con el ID ingresado." << endl;
    }
    system("PAUSE");
}

void BuscarDatoCola() {
    if (frenteCola == nullptr) {
        cout << "La cola esta vacia." << endl;
        return;
    }

    int idBusqueda;
    cout << "Ingrese el ID del vehiculo que quiere buscar: ";
    cin >> idBusqueda;

    Nodo* temp = frenteCola;
    bool encontrado = false;

    while (temp != nullptr) {
        if (temp->id == idBusqueda) {
            encontrado = true;
            cout << "----Datos del veh�culo----" << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Matricula: " << temp->vehiculo.matricula << endl;
            cout << "Tipo: " << temp->vehiculo.tipo << endl;
            cout << "Capacidad de carga (kg): " << temp->vehiculo.capacidadCarga << endl;
            cout << "Marca: " << temp->vehiculo.marca << endl;
            cout << "Modelo: " << temp->vehiculo.modelo << endl;
            cout << "Fecha de fabricacion: " << temp->vehiculo.anioFabricacion.dia << "/" << temp->vehiculo.anioFabricacion.mes << "/" << temp->vehiculo.anioFabricacion.anio << endl;
            cout << "Color: " << temp->vehiculo.color << endl;
            cout << "Numero de chasis: " << temp->vehiculo.numeroChasis << endl;

            // Datos del motor
            cout << "--- Datos del motor ---" << endl;
            cout << "Numero de motor: " << temp->vehiculo.motor.numeroMotor << endl;
            cout << "Tipo de motor: " << temp->vehiculo.motor.tipo << endl;
            cout << "Capacidad del motor (L): " << temp->vehiculo.motor.capacidad << endl;

            // Datos del conductor
            cout << "--- Datos del conductor ---" << endl;
            cout << "Nombre: " << temp->vehiculo.conductor.nombre << endl;
            cout << "Apellido: " << temp->vehiculo.conductor.apellido << endl;
            cout << "Edad: " << temp->vehiculo.conductor.edad << endl;
            cout << "Tipo de licencia: " << temp->vehiculo.conductor.tipoLicencia << endl;
            cout << "Anios de experiencia: " << temp->vehiculo.conductor.anosExperiencia << endl;
            cout << "Estado civil: " << temp->vehiculo.conductor.estadoCivil << endl;
            cout << "Telefono: " << temp->vehiculo.conductor.contacto.telefono << endl;
            cout << "Correo: " << temp->vehiculo.conductor.contacto.correo << endl;
            cout << "Direccion: " << temp->vehiculo.conductor.direccion.direccion << endl;
            cout << "Ciudad: " << temp->vehiculo.conductor.direccion.ciudad << endl;
            cout << "Codigo postal: " << temp->vehiculo.conductor.direccion.codigoPostal << endl;

            // Calcular y mostrar saltos de memoria
            cout << "--- Saltos de Memoria ---" << endl;
            cout << "Salto entre ID y matr�cula: " << reinterpret_cast<intptr_t>(&temp->vehiculo.matricula) - reinterpret_cast<intptr_t>(&temp->id) << " bytes" << endl;
            cout << "Salto entre matr�cula y tipo: " << reinterpret_cast<intptr_t>(&temp->vehiculo.tipo) - reinterpret_cast<intptr_t>(&temp->vehiculo.matricula) << " bytes" << endl;
            cout << "Salto entre tipo y capacidadCarga: " << reinterpret_cast<intptr_t>(&temp->vehiculo.capacidadCarga) - reinterpret_cast<intptr_t>(&temp->vehiculo.tipo) << " bytes" << endl;
            cout << "Salto entre capacidadCarga y marca: " << reinterpret_cast<intptr_t>(&temp->vehiculo.marca) - reinterpret_cast<intptr_t>(&temp->vehiculo.capacidadCarga) << " bytes" << endl;
            cout << "Salto entre marca y modelo: " << reinterpret_cast<intptr_t>(&temp->vehiculo.modelo) - reinterpret_cast<intptr_t>(&temp->vehiculo.marca) << " bytes" << endl;
            cout << "Salto entre modelo y anioFabricacion: " << reinterpret_cast<intptr_t>(&temp->vehiculo.anioFabricacion) - reinterpret_cast<intptr_t>(&temp->vehiculo.modelo) << " bytes" << endl;
            cout << "Salto entre anioFabricacion y color: " << reinterpret_cast<intptr_t>(&temp->vehiculo.color) - reinterpret_cast<intptr_t>(&temp->vehiculo.anioFabricacion) << " bytes" << endl;
            cout << "Salto entre color y numeroChasis: " << reinterpret_cast<intptr_t>(&temp->vehiculo.numeroChasis) - reinterpret_cast<intptr_t>(&temp->vehiculo.color) << " bytes" << endl;
            cout << "Salto entre numeroChasis y motor: " << reinterpret_cast<intptr_t>(&temp->vehiculo.motor) - reinterpret_cast<intptr_t>(&temp->vehiculo.numeroChasis) << " bytes" << endl;
            cout << "Salto entre motor y conductor: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor) - reinterpret_cast<intptr_t>(&temp->vehiculo.motor) << " bytes" << endl;

            // Saltos en Datos del motor
            cout << "Salto entre numeroMotor y tipo: " << reinterpret_cast<intptr_t>(&temp->vehiculo.motor.tipo) - reinterpret_cast<intptr_t>(&temp->vehiculo.motor.numeroMotor) << " bytes" << endl;
            cout << "Salto entre tipo y capacidad: " << reinterpret_cast<intptr_t>(&temp->vehiculo.motor.capacidad) - reinterpret_cast<intptr_t>(&temp->vehiculo.motor.tipo) << " bytes" << endl;

            // Saltos en Datos del conductor
            cout << "Salto entre nombre y apellido: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.apellido) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.nombre) << " bytes" << endl;
            cout << "Salto entre apellido y edad: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.edad) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.apellido) << " bytes" << endl;
            cout << "Salto entre edad y tipoLicencia: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.tipoLicencia) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.edad) << " bytes" << endl;
            cout << "Salto entre tipoLicencia y anosExperiencia: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.anosExperiencia) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.tipoLicencia) << " bytes" << endl;
            cout << "Salto entre anosExperiencia y estadoCivil: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.estadoCivil) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.anosExperiencia) << " bytes" << endl;
            cout << "Salto entre estadoCivil y telefono: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.contacto.telefono) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.estadoCivil) << " bytes" << endl;
            cout << "Salto entre telefono y correo: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.contacto.correo) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.contacto.telefono) << " bytes" << endl;
            cout << "Salto entre correo y direccion: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.direccion.direccion) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.contacto.correo) << " bytes" << endl;
            cout << "Salto entre direccion y ciudad: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.direccion.ciudad) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.direccion.direccion) << " bytes" << endl;
            cout << "Salto entre ciudad y codigoPostal: " << reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.direccion.codigoPostal) - reinterpret_cast<intptr_t>(&temp->vehiculo.conductor.direccion.ciudad) << " bytes" << endl;


            system("PAUSE");
            break;
        }
        temp = temp->siguiente;
    }
    if (!encontrado) {
        cout << "No se encontro el vehiculo con el ID ingresado." << endl;
    }
    system("PAUSE");
}

void EliminarDatoCola() {
    if (frenteCola == nullptr) {
        cout << "La cola esta vacia." << endl;
        return;
    }

    Nodo* temp = frenteCola;
    frenteCola = frenteCola->siguiente;

    if (frenteCola == nullptr) {
        finalCola = nullptr; // Si la cola queda vac�a, actualizamos finalCola tambi�n
    }

    delete temp;
    cout << "El vehiculo en la cola ha sido eliminado correctamente." << endl;
    system("PAUSE");
}


// Funciones para insertar elementos en las listas
void InsertarProductoGenerado(ProductoGenerado producto) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->producto = producto;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = nullptr;

    if (cabezaDoble == nullptr || cabezaDoble->producto.iD >= producto.iD) {
        nuevoNodo->siguiente = cabezaDoble;
        if (cabezaDoble != nullptr) {
            cabezaDoble->anterior = nuevoNodo;
        }
        cabezaDoble = nuevoNodo;
        if (colaDoble == nullptr) {
            colaDoble = nuevoNodo;
        }
    }
    else {
        Nodo* actual = cabezaDoble;
        while (actual->siguiente != nullptr && actual->siguiente->producto.iD < producto.iD) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        if (actual->siguiente != nullptr) {
            actual->siguiente->anterior = nuevoNodo;
        }
        nuevoNodo->anterior = actual;
        actual->siguiente = nuevoNodo;
        if (nuevoNodo->siguiente == nullptr) {
            colaDoble = nuevoNodo;
        }
    }
    cout << "Producto generado insertado en lista doblemente enlazada." << endl;
}
void InsertarEmpleado(Empleado empleado) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->empleado = empleado;
    nuevoNodo->siguiente = nullptr;

    if (cabezaSimple == nullptr || cabezaSimple->empleado.iD >= empleado.iD) {
        nuevoNodo->siguiente = cabezaSimple;
        cabezaSimple = nuevoNodo;
    }
    else {
        Nodo* actual = cabezaSimple;
        while (actual->siguiente != nullptr && actual->siguiente->empleado.iD < empleado.iD) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
    cout << "Empleado insertado en lista simplemente enlazada." << endl;
}

void InsertarTurno(Turno turno) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->turno = turno;
    nuevoNodo->siguiente = nullptr;

    if (cabezaCircular == nullptr) {
        nuevoNodo->siguiente = nuevoNodo;
        cabezaCircular = nuevoNodo;
    }
    else if (turno.iD <= cabezaCircular->turno.iD) {
        Nodo* temp = cabezaCircular;
        while (temp->siguiente != cabezaCircular) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->siguiente = cabezaCircular;
        cabezaCircular = nuevoNodo;
    }
    else {
        Nodo* actual = cabezaCircular;
        while (actual->siguiente != cabezaCircular && actual->siguiente->turno.iD < turno.iD) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
    cout << "Turno insertado en lista simplemente enlazada circular." << endl;
}

void VerListaSimple() {
    system("cls");
    if (cabezaSimple == nullptr) {
        cout << "La lista simplemente enlazada est� vac�a." << endl;
        return;
    }
    Nodo* actual = cabezaSimple;
    while (actual != nullptr) {
        cout << "ID: " << actual->empleado.iD << ", Nombre: " << actual->empleado.nombre << ", Puesto: " << actual->empleado.puesto << endl;
        actual = actual->siguiente;
    }
    cout << "Fin de la lista simplemente enlazada." << endl;
    system("pause");
}

void VerListaDoble() {
    system("cls");
    if (cabezaDoble == nullptr) {
        cout << "La lista doblemente enlazada est� vac�a." << endl;
        return;
    }
    Nodo* actual = cabezaDoble;
    while (actual != nullptr) {
        cout << "ID: " << actual->producto.iD << ", Nombre: " << actual->producto.nombre << ", Peso: " << actual->producto.peso << endl;
        actual = actual->siguiente;
    }
    cout << "Fin de la lista doblemente enlazada." << endl;
    system("pause");
}

void VerListaCircular() {
    system("cls");
    if (cabezaCircular == nullptr) {
        cout << "La lista simplemente enlazada circular est� vac�a." << endl;
        return;
    }
    Nodo* actual = cabezaCircular;
    do {
        cout << "ID: " << actual->turno.iD << ", Nombre: " << actual->turno.nombre << ", Horario: " << actual->turno.horario << endl;
        actual = actual->siguiente;
    } while (actual != cabezaCircular);
    cout << "Fin de la lista simplemente enlazada circular." << endl;
    system("pause");
}

void EliminarEnListaSimple(int datoEliminar) {
    if (cabezaSimple == nullptr) {
        cout << "La lista simplemente enlazada est� vac�a. No hay datos para eliminar." << endl;
        return;
    }

    // Caso especial: Eliminar el primer nodo
    if (cabezaSimple->empleado.iD == datoEliminar) {
        Nodo* temp = cabezaSimple;
        cabezaSimple = cabezaSimple->siguiente;
        delete temp;
        cout << "El empleado con ID " << datoEliminar << " ha sido eliminado." << endl;
        return;
    }

    // Buscar el nodo a eliminar
    Nodo* actual = cabezaSimple;
    Nodo* anterior = nullptr;
    while (actual != nullptr && actual->empleado.iD != datoEliminar) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        cout << "No se encontr� un empleado con el ID " << datoEliminar << " en la lista." << endl;
        return;
    }

    // Eliminar el nodo encontrado
    anterior->siguiente = actual->siguiente;
    delete actual;
    cout << "El empleado con ID " << datoEliminar << " ha sido eliminado." << endl;
}
void EliminarEnListaDoble(int datoEliminar) {
    if (cabezaDoble == nullptr) {
        cout << "La lista doblemente enlazada est� vac�a. No hay datos para eliminar." << endl;
        return;
    }

    Nodo* actual = cabezaDoble;

    // Caso especial: Eliminar el primer nodo
    if (actual->producto.iD == datoEliminar) {
        cabezaDoble = actual->siguiente;
        if (cabezaDoble != nullptr) {
            cabezaDoble->anterior = nullptr;
        }
        else {
            colaDoble = nullptr; // Si la lista queda vac�a
        }
        delete actual;
        cout << "El producto con ID " << datoEliminar << " ha sido eliminado." << endl;
        return;
    }

    // Buscar el nodo a eliminar
    while (actual != nullptr && actual->producto.iD != datoEliminar) {
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        cout << "No se encontr� un producto con el ID " << datoEliminar << " en la lista." << endl;
        return;
    }

    // Eliminar el nodo encontrado
    if (actual->siguiente != nullptr) {
        actual->siguiente->anterior = actual->anterior;
    }
    else {
        colaDoble = actual->anterior; // Si es el �ltimo nodo
    }
    if (actual->anterior != nullptr) {
        actual->anterior->siguiente = actual->siguiente;
    }

    delete actual;
    cout << "El producto con ID " << datoEliminar << " ha sido eliminado." << endl;
}


void EliminarEnListaCircular(int datoEliminar) {
    if (cabezaCircular == nullptr) {
        cout << "La lista circular est� vac�a. No hay datos para eliminar." << endl;
        return;
    }

    Nodo* actual = cabezaCircular;
    Nodo* anterior = nullptr;

    // Caso especial: Eliminar el primer nodo
    do {
        if (actual->turno.iD == datoEliminar) {
            if (anterior == nullptr) { // Primer nodo
                if (actual->siguiente == cabezaCircular) {
                    delete cabezaCircular;
                    cabezaCircular = nullptr; // Si es el �nico nodo
                }
                else {
                    Nodo* temp = cabezaCircular;
                    anterior = cabezaCircular;
                    while (anterior->siguiente != cabezaCircular) {
                        anterior = anterior->siguiente;
                    }
                    cabezaCircular = cabezaCircular->siguiente;
                    anterior->siguiente = cabezaCircular;
                    delete temp;
                }
            }
            else {
                anterior->siguiente = actual->siguiente;
                delete actual;
            }
            cout << "El turno con ID " << datoEliminar << " ha sido eliminado." << endl;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != cabezaCircular);

    cout << "No se encontr� un turno con el ID " << datoEliminar << " en la lista." << endl;
}
void VaciarListaSimple() {
    while (cabezaSimple != nullptr) {
        Nodo* temp = cabezaSimple;
        cabezaSimple = cabezaSimple->siguiente;
        delete temp;
    }
    cout << "\nLa lista simplemente enlazada ha sido vaciada." << endl;
    system("pause");
}

void VaciarListaDoble() {
    while (cabezaDoble != nullptr) {
        Nodo* temp = cabezaDoble;
        cabezaDoble = cabezaDoble->siguiente;
        delete temp;
    }
    colaDoble = nullptr;
    cout << "\nLa lista doblemente enlazada ha sido vaciada." << endl;
    system("pause");
}
void VaciarListaCircular() {
    if (cabezaCircular == nullptr) {
        cout << "\nLa lista circular ya est� vac�a." << endl;
        return;
    }

    Nodo* actual = cabezaCircular;
    Nodo* siguienteNodo;

    do {
        siguienteNodo = actual->siguiente;
        delete actual;
        actual = siguienteNodo;
    } while (actual != cabezaCircular);

    cabezaCircular = nullptr;
    cout << "La lista circular ha sido vaciada." << endl;
    system("pause");

}
// Funci�n para ingresar datos en el �rbol ABB
void IngresarDatosABB() {
    system("cls");
    Proveedor* nuevoProveedor = new Proveedor;
    int y = 2; // Posici�n inicial vertical
    centrarTexto("---- Ingreso de Datos del Proveedor ----", y);
    y += 2;
    centrarTexto("Ingrese ID del proveedor: ", y);
    gotoxy(40 + 25, y); // Ajusta la posici�n para el ingreso de datos
    cin >> nuevoProveedor->id;
    cin.ignore();
    y += 2;
    centrarTexto("Ingrese nombre del proveedor: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevoProveedor->nombre);
    y += 2;
    centrarTexto("Ingrese direccion del proveedor: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevoProveedor->direccion);
    y += 2;
    centrarTexto("Ingrese telefono del proveedor: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevoProveedor->telefono);
    y += 2;
    centrarTexto("Ingrese email del proveedor: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevoProveedor->email);
    y += 2;
    centrarTexto("Ingrese empresa del proveedor: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevoProveedor->empresa);
    y += 2;
    centrarTexto("Ingrese tipo de producto del proveedor: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevoProveedor->tipoProducto);
    y += 2;
    centrarTexto("Ingrese pais del proveedor: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevoProveedor->pais);
    nuevoProveedor->izquierda = nullptr;
    nuevoProveedor->derecha = nullptr;
    if (raiz == nullptr) {
        raiz = nuevoProveedor;
    }
    else {
        Proveedor* actual = raiz;
        Proveedor* padre;
        while (true) {
            padre = actual;
            if (nuevoProveedor->id < actual->id) {
                actual = actual->izquierda;
                if (actual == nullptr) {
                    padre->izquierda = nuevoProveedor;
                    return;
                }
            }
            else {
                actual = actual->derecha;
                if (actual == nullptr) {
                    padre->derecha = nuevoProveedor;
                    return;
                }
            }
        }
    }
    centrarTexto("Proveedor ingresado correctamente.", y + 2);
    system("pause");
}

void MostrarArbolABB(Proveedor* nodo, int x, int y, int nivel) {
    if (nodo != nullptr) {
        // Mostrar el valor del nodo en la posici�n especificada
        gotoxy(x, y);
        cout << nodo->id;

        // Aumentamos la distancia entre los nodos para que no se sobrepongan
        int espacio = 6;  // Ajuste la distancia entre nodos para mayor claridad

        // Mostrar la rama hacia la izquierda si existe
        if (nodo->izquierda != nullptr) {
            gotoxy(x - espacio, y + 2);
            cout << "//";  // Representaci�n visual de la rama hacia la izquierda
            MostrarArbolABB(nodo->izquierda, x - espacio * 2, y + 4, nivel + 1);  // Llamada recursiva para el hijo izquierdo
        }

        // Mostrar la rama hacia la derecha si existe
        if (nodo->derecha != nullptr) {
            gotoxy(x + espacio, y + 2);
            cout << "\\\\";  // Representaci�n visual de la rama hacia la derecha
            MostrarArbolABB(nodo->derecha, x + espacio * 2, y + 4, nivel + 1);  // Llamada recursiva para el hijo derecho
        }
    }
    cout << "\n";
}



void VaciarArbolABB(Proveedor*& nodo) {
    if (nodo != nullptr) {
        VaciarArbolABB(nodo->izquierda);
        VaciarArbolABB(nodo->derecha);
        delete nodo;
        nodo = nullptr;
    }
}
void RecorrerPreorden(Proveedor* nodo) {
    if (nodo != nullptr) {
        cout << nodo->id << " ";
        RecorrerPreorden(nodo->izquierda);
        RecorrerPreorden(nodo->derecha);
    }
}

void RecorrerInorden(Proveedor* nodo) {
    if (nodo != nullptr) {
        RecorrerInorden(nodo->izquierda);
        cout << nodo->id << " ";
        RecorrerInorden(nodo->derecha);
    }
}

void RecorrerPostorden(Proveedor* nodo) {
    if (nodo != nullptr) {
        RecorrerPostorden(nodo->izquierda);
        RecorrerPostorden(nodo->derecha);
        cout << nodo->id << " ";
    }
}
// Funci�n para buscar un proveedor por ID en el �rbol ABB
Proveedor* BuscarProveedor(Proveedor* nodo, int id) {
    system("cls"); // Limpiar pantalla
    if (nodo == nullptr) {
        centrarTexto("Proveedor no encontrado.", 10);
        return nullptr;
    }
    if (nodo->id == id) {
        int y = 2; // Posici�n inicial vertical
        centrarTexto("---- Informacion del Proveedor ----", y);
        y += 2;
        centrarTexto("ID: " + to_string(nodo->id), y);
        y += 2;
        centrarTexto("Nombre: " + nodo->nombre, y);
        y += 2;
        centrarTexto("Direccion: " + nodo->direccion, y);
        y += 2;
        centrarTexto("Telefono: " + nodo->telefono, y);
        y += 2;
        centrarTexto("Email: " + nodo->email, y);
        y += 2;
        centrarTexto("Empresa: " + nodo->empresa, y);
        y += 2;
        centrarTexto("Tipo de Producto: " + nodo->tipoProducto, y);
        y += 2;
        centrarTexto("Pais: " + nodo->pais, y);
        return nodo;
    }
    if (id < nodo->id) {
        return BuscarProveedor(nodo->izquierda, id);
    }
    else {
        return BuscarProveedor(nodo->derecha, id);
    }
}
// Funci�n para eliminar un proveedor por ID en el �rbol ABB
Proveedor* EliminarProveedor(Proveedor* nodo, int id) {
    system("cls"); // Limpiar pantalla
    if (nodo == nullptr) {
        centrarTexto("Proveedor no encontrado.", 10);
        return nodo;
    }
    if (id < nodo->id) {
        nodo->izquierda = EliminarProveedor(nodo->izquierda, id);
    }
    else if (id > nodo->id) {
        nodo->derecha = EliminarProveedor(nodo->derecha, id);
    }
    else {
        int y = 2; // Posici�n inicial vertical
        centrarTexto("Eliminando proveedor con ID: " + to_string(nodo->id), y);
        y += 2;
        centrarTexto("Nombre: " + nodo->nombre, y);
        y += 2;
        centrarTexto("Direccion: " + nodo->direccion, y);
        y += 2;
        centrarTexto("Telefono: " + nodo->telefono, y);
        y += 2;
        centrarTexto("Email: " + nodo->email, y);
        y += 2;
        centrarTexto("Empresa: " + nodo->empresa, y);
        y += 2;
        centrarTexto("Tipo de Producto: " + nodo->tipoProducto, y);
        y += 2;
        centrarTexto("Pais: " + nodo->pais, y);

        if (nodo->izquierda == nullptr) {
            Proveedor* temp = nodo->derecha;
            delete nodo;
            return temp;
        }
        else if (nodo->derecha == nullptr) {
            Proveedor* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }
        Proveedor* temp = MinimoValorNodo(nodo->derecha);
        nodo->id = temp->id;
        nodo->nombre = temp->nombre;
        nodo->direccion = temp->direccion;
        nodo->telefono = temp->telefono;
        nodo->email = temp->email;
        nodo->empresa = temp->empresa;
        nodo->tipoProducto = temp->tipoProducto;
        nodo->pais = temp->pais;
        nodo->derecha = EliminarProveedor(nodo->derecha, temp->id);
    }
    return nodo;
}

// Funci�n para encontrar el nodo con el valor m�nimo (el m�s a la izquierda)
Proveedor* MinimoValorNodo(Proveedor* nodo) {
    Proveedor* actual = nodo;
    // Recorrer el �rbol hasta encontrar el nodo m�s a la izquierda
    while (actual && actual->izquierda != nullptr) {
        actual = actual->izquierda;
    }
    return actual;
}
//CODIGOS DEL ARBOL AVL

int alturaAVL(RutaRecoleccionAVL* nodo) {
    if (!nodo) {
        return 0; // Un nodo nulo tiene altura 0
    }
    return nodo->altura;
}
int obtenerFactorEquilibrioAVL(RutaRecoleccionAVL* nodo) {
    if (!nodo) {
        return 0; // El factor de equilibrio de un nodo nulo es 0
    }
    return alturaAVL(nodo->izquierda) - alturaAVL(nodo->derecha);
}
RutaRecoleccionAVL* rotacionDerechaAVL(RutaRecoleccionAVL* y) {
    RutaRecoleccionAVL* x = y->izquierda;
    RutaRecoleccionAVL* T2 = x->derecha;

    // Realizar la rotaci�n
    x->derecha = y;
    y->izquierda = T2;

    // Actualizar alturas
    y->altura = max(alturaAVL(y->izquierda), alturaAVL(y->derecha)) + 1;
    x->altura = max(alturaAVL(x->izquierda), alturaAVL(x->derecha)) + 1;

    // Devolver la nueva ra�z
    return x;
}
RutaRecoleccionAVL* rotacionIzquierdaAVL(RutaRecoleccionAVL* x) {
    RutaRecoleccionAVL* y = x->derecha;
    RutaRecoleccionAVL* T2 = y->izquierda;

    // Realizar la rotaci�n
    y->izquierda = x;
    x->derecha = T2;

    // Actualizar alturas
    x->altura = max(alturaAVL(x->izquierda), alturaAVL(x->derecha)) + 1;
    y->altura = max(alturaAVL(y->izquierda), alturaAVL(y->derecha)) + 1;

    // Devolver la nueva ra�z
    return y;
}
RutaRecoleccionAVL* rotacionIzquierdaDerechaAVL(RutaRecoleccionAVL* z) {
    z->izquierda = rotacionIzquierdaAVL(z->izquierda);
    return rotacionDerechaAVL(z);
}
RutaRecoleccionAVL* rotacionDerechaIzquierdaAVL(RutaRecoleccionAVL* z) {
    z->derecha = rotacionDerechaAVL(z->derecha);
    return rotacionIzquierdaAVL(z);
}
RutaRecoleccionAVL* insertarAVL(RutaRecoleccionAVL* nodo, int idRuta, const string& nombreRuta, const string& conductorAsignado, const string& camionAsignado, const string& frecuenciaRecoleccion, const string& diaOperacion, const string& horaInicioEstimada, const string& horaFinEstimada) {
    // 1. Realizar la inserci�n est�ndar del BST
    if (!nodo) {
        return new RutaRecoleccionAVL{ idRuta, nombreRuta, conductorAsignado, camionAsignado, frecuenciaRecoleccion, diaOperacion, horaInicioEstimada, horaFinEstimada, nullptr, nullptr, 1 };
    }

    if (idRuta < nodo->idRuta)
        nodo->izquierda = insertarAVL(nodo->izquierda, idRuta, nombreRuta, conductorAsignado, camionAsignado, frecuenciaRecoleccion, diaOperacion, horaInicioEstimada, horaFinEstimada);
    else if (idRuta > nodo->idRuta)
        nodo->derecha = insertarAVL(nodo->derecha, idRuta, nombreRuta, conductorAsignado, camionAsignado, frecuenciaRecoleccion, diaOperacion, horaInicioEstimada, horaFinEstimada);
    else // No se permiten claves duplicadas
        return nodo;

    // 2. Actualizar la altura del nodo actual
    nodo->altura = max(alturaAVL(nodo->izquierda), alturaAVL(nodo->derecha)) + 1;

    // 3. Obtener el factor de equilibrio de este nodo para verificar si est� desbalanceado
    int factorEquilibrio = obtenerFactorEquilibrioAVL(nodo);

    // Si el nodo est� desbalanceado, entonces hay 4 casos

    // Caso Izquierda Izquierda (LL)
    if (factorEquilibrio > 1 && idRuta < nodo->izquierda->idRuta)
        return rotacionDerechaAVL(nodo);

    // Caso Derecha Derecha (RR)
    if (factorEquilibrio < -1 && idRuta > nodo->derecha->idRuta)
        return rotacionIzquierdaAVL(nodo);

    // Caso Izquierda Derecha (LR)
    if (factorEquilibrio > 1 && idRuta > nodo->izquierda->idRuta) {
        return rotacionIzquierdaDerechaAVL(nodo);
    }

    // Caso Derecha Izquierda (RL)
    if (factorEquilibrio < -1 && idRuta < nodo->derecha->idRuta) {
        return rotacionDerechaIzquierdaAVL(nodo);
    }

    // Devolver el puntero del nodo (si no hubo desbalanceo)
    return nodo;
}
RutaRecoleccionAVL* eliminarAVL(RutaRecoleccionAVL* raiz, int idRuta) {
    if (!raiz) {
        return raiz; // El ID no se encontr�
    }

    // Realizar la eliminaci�n est�ndar del BST
    if (idRuta < raiz->idRuta) {
        raiz->izquierda = eliminarAVL(raiz->izquierda, idRuta);
    }
    else if (idRuta > raiz->idRuta) {
        raiz->derecha = eliminarAVL(raiz->derecha, idRuta);
    }
    else { // Se encontr� el nodo a eliminar
        // Nodo con solo un hijo o sin hijos
        if (!raiz->izquierda || !raiz->derecha) {
            RutaRecoleccionAVL* temp = raiz->izquierda ? raiz->izquierda : raiz->derecha;
            delete raiz;
            return temp;
        }
        else {
            // Nodo con dos hijos: obtener el sucesor inorden (el menor en el sub�rbol derecho)
            RutaRecoleccionAVL* temp = minimoValorNodoAVL(raiz->derecha);

            // Copiar el ID del sucesor inorden a este nodo
            raiz->idRuta = temp->idRuta;
            raiz->nombreRuta = temp->nombreRuta;
            raiz->conductorAsignado = temp->conductorAsignado;
            raiz->camionAsignado = temp->camionAsignado;
            raiz->frecuenciaRecoleccion = temp->frecuenciaRecoleccion;
            raiz->diaOperacion = temp->diaOperacion;
            raiz->horaInicioEstimada = temp->horaInicioEstimada;
            raiz->horaFinEstimada = temp->horaFinEstimada;

            // Eliminar el sucesor inorden
            raiz->derecha = eliminarAVL(raiz->derecha, temp->idRuta);
        }
    }

    // Si el �rbol ten�a solo un nodo, o el nodo eliminado era una hoja, no hay necesidad de balancear
    if (!raiz) {
        return raiz;
    }

    // 2. Actualizar la altura del nodo actual
    raiz->altura = 1 + max(alturaAVL(raiz->izquierda), alturaAVL(raiz->derecha));

    // 3. Obtener el factor de equilibrio de este nodo para verificar si est� desbalanceado
    int factorEquilibrio = obtenerFactorEquilibrioAVL(raiz);

    // Si el nodo est� desbalanceado, entonces hay 4 casos

    // Caso Izquierda Izquierda
    if (factorEquilibrio > 1 && obtenerFactorEquilibrioAVL(raiz->izquierda) >= 0) {
        return rotacionDerechaAVL(raiz);
    }

    // Caso Izquierda Derecha
    if (factorEquilibrio > 1 && obtenerFactorEquilibrioAVL(raiz->izquierda) < 0) {
        raiz->izquierda = rotacionIzquierdaAVL(raiz->izquierda);
        return rotacionDerechaAVL(raiz);
    }

    // Caso Derecha Derecha
    if (factorEquilibrio < -1 && obtenerFactorEquilibrioAVL(raiz->derecha) <= 0) {
        return rotacionIzquierdaAVL(raiz);
    }

    // Caso Derecha Izquierda
    if (factorEquilibrio < -1 && obtenerFactorEquilibrioAVL(raiz->derecha) > 0) {
        raiz->derecha = rotacionDerechaAVL(raiz->derecha);
        return rotacionIzquierdaAVL(raiz);
    }

    return raiz;
}
RutaRecoleccionAVL* minimoValorNodoAVL(RutaRecoleccionAVL* nodo) {
    RutaRecoleccionAVL* actual = nodo;
    while (actual && actual->izquierda != nullptr) {
        actual = actual->izquierda;
    }
    return actual;
}
RutaRecoleccionAVL* buscarRutaAVL(RutaRecoleccionAVL* raiz, int idRuta) {
    if (!raiz || raiz->idRuta == idRuta) {
        return raiz;
    }

    if (idRuta < raiz->idRuta) {
        return buscarRutaAVL(raiz->izquierda, idRuta);
    }
    else {
        return buscarRutaAVL(raiz->derecha, idRuta);
    }
}
void mostrarArbolAVL(RutaRecoleccionAVL* nodo, int x, int y, int nivel) {
    if (nodo) {
        int espacio = 5; // Espacio horizontal entre nodos en el mismo nivel

        // Mostrar el sub�rbol derecho (primero para que aparezca a la derecha)
        mostrarArbolAVL(nodo->derecha, x + espacio * (1 << nivel), y + 2, nivel + 1);

        // Mostrar el nodo actual
        gotoxy(x, y);
        cout << nodo->idRuta;

        // Mostrar l�neas de conexi�n (opcional, puede complicar la visualizaci�n para �rboles grandes)
        if (nodo->izquierda) {
            gotoxy(x - 1, y + 1);
            cout << "/";
        }
        if (nodo->derecha) {
            gotoxy(x + 1, y + 1);
            cout << "\\";
        }

        // Mostrar el sub�rbol izquierdo
        mostrarArbolAVL(nodo->izquierda, x - espacio * (1 << nivel), y + 2, nivel + 1);
    }
}
void vaciarArbolAVL(RutaRecoleccionAVL*& raiz) {
    if (raiz) {
        vaciarArbolAVL(raiz->izquierda);
        vaciarArbolAVL(raiz->derecha);
        delete raiz;
        raiz = nullptr; // Importante: actualizar el puntero a la ra�z
    }
}
bool modificarRutaAVL(RutaRecoleccionAVL* raiz, int idRuta, const string& nuevoNombreRuta, const string& nuevoConductorAsignado, const string& nuevoCamionAsignado, const string& nuevaFrecuenciaRecoleccion, const string& nuevoDiaOperacion, const string& nuevaHoraInicioEstimada, const string& nuevaHoraFinEstimada) {
    if (!raiz) {
        return false; // El �rbol est� vac�o o el ID no se encontr�
    }

    if (idRuta < raiz->idRuta) {
        return modificarRutaAVL(raiz->izquierda, idRuta, nuevoNombreRuta, nuevoConductorAsignado, nuevoCamionAsignado, nuevaFrecuenciaRecoleccion, nuevoDiaOperacion, nuevaHoraInicioEstimada, nuevaHoraFinEstimada);
    }
    else if (idRuta > raiz->idRuta) {
        return modificarRutaAVL(raiz->derecha, idRuta, nuevoNombreRuta, nuevoConductorAsignado, nuevoCamionAsignado, nuevaFrecuenciaRecoleccion, nuevoDiaOperacion, nuevaHoraInicioEstimada, nuevaHoraFinEstimada);
    }
    else { // Se encontr� el nodo con el ID a modificar
        raiz->nombreRuta = nuevoNombreRuta;
        raiz->conductorAsignado = nuevoConductorAsignado;
        raiz->camionAsignado = nuevoCamionAsignado;
        raiz->frecuenciaRecoleccion = nuevaFrecuenciaRecoleccion;
        raiz->diaOperacion = nuevoDiaOperacion;
        raiz->horaInicioEstimada = nuevaHoraInicioEstimada;
        raiz->horaFinEstimada = nuevaHoraFinEstimada;
        return true; // Modificaci�n exitosa
    }
}
void recorrerPreordenAVL(RutaRecoleccionAVL* nodo) {
    if (nodo) {
        cout << "ID: " << nodo->idRuta << ", Nombre: " << nodo->nombreRuta << std::endl;
        recorrerPreordenAVL(nodo->izquierda);
        recorrerPreordenAVL(nodo->derecha);
    }
}
void recorrerInordenAVL(RutaRecoleccionAVL* nodo) {
    if (nodo) {
        recorrerInordenAVL(nodo->izquierda);
        cout << "ID: " << nodo->idRuta << ", Nombre: " << nodo->nombreRuta << std::endl;
        recorrerInordenAVL(nodo->derecha);
    }
}
void recorrerPostordenAVL(RutaRecoleccionAVL* nodo) {
    if (nodo) {
        recorrerPostordenAVL(nodo->izquierda);
        recorrerPostordenAVL(nodo->derecha);
        cout << "ID: " << nodo->idRuta << ", Nombre: " << nodo->nombreRuta << std::endl;
    }
}
void IngresarDatosRutaAVL() {
    system("cls");
    RutaRecoleccionAVL* nuevaRuta = new RutaRecoleccionAVL;
    int y = 2; // Posici�n inicial vertical
    centrarTexto("---- Ingreso de Datos de la Ruta de Recoleccion ----", y);
    y += 2;
    centrarTexto("Ingrese ID de Ruta: ", y);
    gotoxy(40 + 25, y);
    cin >> nuevaRuta->idRuta;
    cin.ignore();
    y += 2;
    centrarTexto("Ingrese Nombre de la Ruta: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevaRuta->nombreRuta);
    y += 2;
    centrarTexto("Ingrese Conductor Asignado: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevaRuta->conductorAsignado);
    y += 2;
    centrarTexto("Ingrese Camion Asignado: ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevaRuta->camionAsignado);
    y += 2;
    centrarTexto("Ingrese Frecuencia de Recoleccion (diaria, semanal): ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevaRuta->frecuenciaRecoleccion);
    y += 2;
    centrarTexto("Ingrese Dia de Operacion (ej. Lunes, Martes-Viernes): ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevaRuta->diaOperacion);
    y += 2;
    centrarTexto("Ingrese Hora de Inicio Estimada (ej. 08:00): ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevaRuta->horaInicioEstimada);
    y += 2;
    centrarTexto("Ingrese Hora de Fin Estimada (ej. 17:00): ", y);
    gotoxy(40 + 25, y);
    getline(cin, nuevaRuta->horaFinEstimada);

    nuevaRuta->izquierda = nullptr;
    nuevaRuta->derecha = nullptr;
    nuevaRuta->altura = 1;

    raizAVL = insertarAVL(raizAVL, nuevaRuta->idRuta, nuevaRuta->nombreRuta, nuevaRuta->conductorAsignado, nuevaRuta->camionAsignado, nuevaRuta->frecuenciaRecoleccion, nuevaRuta->diaOperacion, nuevaRuta->horaInicioEstimada, nuevaRuta->horaFinEstimada);

    centrarTexto("Ruta de Recoleccion ingresada correctamente.", y + 2);
    system("pause");
    delete nuevaRuta;
}

void centrarTexto(const string& texto, int y) {
    int anchoPantalla = 80; // Ajusta seg�n el ancho de tu consola
    int posicionX = (anchoPantalla - texto.length()) / 2;
    gotoxy(posicionX, y);
    cout << texto << endl;
}


void imagen1() {
    system("color 2F");
    gotoxy(45, 1); cout << "******RECICLADORA******" << endl;
    gotoxy(45, 2); cout << "\n" << endl;

    gotoxy(35, 3); cout << "MMMMMMMMMMMMWNNWNK0000000000KNMMMMMMMMMM" << endl;
    gotoxy(35, 4); cout << "MMMMMMMMMW0dlcclll:,;;;;;;;;;lKWMMMMMMMM" << endl;
    gotoxy(35, 5); cout << "MMMMMMMMWk:,;;;;,;c:;;;;;;;;;,cONXXWMMMM" << endl;
    gotoxy(35, 6); cout << "MMMMMMMNx:,;;;;;;,:xOo;;;;;;;;,:clOWMMMM" << endl;
    gotoxy(35, 7); cout << "MMMMMMNd;,;;;;;;,:kNMXd;;;;;;;;,:OWMMMMM" << endl;
    gotoxy(35, 8); cout << "MMMMMMKo;,;;;;;,:OWMMMXl,,;;;;,c0WMMMMMM" << endl;
    gotoxy(35, 9); cout << "MWMWWWWNKkoc;,,c0WMMWXkolooooldKN0kkXMMM" << endl;
    gotoxy(35, 10); cout << "XkoooooooxKXOdxKMMMMMMWWWWWWNKOdc;,,lKWM" << endl;
    gotoxy(35, 11); cout << "WXl,,;;;;,l0WMMMMMMMMMMMMMMKo:;,;;;;,c0W" << endl;
    gotoxy(35, 12); cout << "Nx;,;;;;;;,cOWMMMMMMMMMMMMMXo;;;;;;;;,:O" << endl;
    gotoxy(35, 13); cout << "0:,;;;;;;,;cckWMMMMMMMMMMMMMXd;,;;;;;;,c" << endl;
    gotoxy(35, 14); cout << "Xo,;;;;;,cONKKWMMMMMMMMMMNXWMNk:,;;;;;;o" << endl;
    gotoxy(35, 15); cout << "MXd:;;;;cONWWWWWWWWMMMMMKloXWWNkc;::;cxX" << endl;
    gotoxy(35, 16); cout << "MMXo;;;;:llllllllcdXMMW0c,;cllll:::;:xNM" << endl;
    gotoxy(35, 17); cout << "MMMKl;;;;;;;;;;;;,cKMWO:,;;;;;;;;;,;dXMM" << endl;
    gotoxy(35, 18); cout << "MMMMXo;;;;;;;;;;;,c0W0c,;;;;;;;;;;:xNMMM" << endl;
    gotoxy(35, 19); cout << "MMMMMXd;,;;;;;;;;,cKMNx:,;;;;;;;,:kNMMMM" << endl;
    gotoxy(35, 20); cout << "MMMMMMNklcccccccccoXMMWO:,;:ccccoOWMMMMM" << endl;
    gotoxy(35, 21); cout << "MMMMMMMWNXXXXXXXXXNWMMMWk,l0XXXXNWMMMMMM" << endl;

    gotoxy(45, 24); cout << "******GRUPO 7******" << endl;
    gotoxy(45, 24); cout << "\n" << endl;
}

void imagen2() {
    system("color 2F");
    gotoxy(45, 1); cout << "******RECICLADORA******" << endl;
    gotoxy(45, 2); cout << "\n" << endl;

    gotoxy(35, 3); cout << "MMMMMMMMMMMMWNNWNK0000000000KNMMMMMMMMMM" << endl;
    gotoxy(35, 4); cout << "MMMMMMMMMW0dlcclll:,;;;;;;;;;lKWMMMMMMMM" << endl;
    gotoxy(35, 5); cout << "MMMMMMMMMMMMMMMMMWk:;;;;;;;;;,cONXXWMMMM" << endl;
    gotoxy(35, 6); cout << "MMMMMMMMMMMMMMMMMMNxOo;;;;;;;;,:clOWMMMM" << endl;
    gotoxy(35, 7); cout << "MMMMMWXl,,;;;;,l0WMMMMM:;,;;;;,c0WMMMMMM" << endl;
    gotoxy(35, 8); cout << "MMMMNx;,;;;;;;,cOWMMMMMM;;;;;;;;,:OMMMMM" << endl;
    gotoxy(35, 9); cout << "MMMM0:,;;;;;;,;cckWMMMMMW;;;;;;;;;;,MMMM" << endl;
    gotoxy(35, 10); cout << "Xkoo;;;;;;;;,OdxKMMMMMMMMW;;;;;;;;;,MMMM" << endl;
    gotoxy(35, 11); cout << "WXl,,;;;;;;,l0WMMMMMMMMMMOo;;;;;;;;,:clO" << endl;
    gotoxy(35, 12); cout << "Nx;,;;;;;cOWMMMMMMMMMMMMMMXd;;;;;;;;,:OW" << endl;
    gotoxy(35, 13); cout << "0:,;;;;;;cckWMMMMMMMMMMMMMMXl,,;;;;,cOWM" << endl;
    gotoxy(35, 14); cout << "Xo,;;;;;,cONKKWMMMMMMMMWXkolooooldKN0kkX" << endl;
    gotoxy(35, 15); cout << "MXd:;;;;cONWWWWWWWWMMMMMMMMMMMMMMMMMMMMM" << endl;
    gotoxy(35, 16); cout << "MMXo;;;;:cdXMMW0c,;cllllllllllll:::;:xNM" << endl;
    gotoxy(35, 17); cout << "MMMKl;;;;,cKMWO:,;;;;;;;;;;;;;;;;;,;dXMM" << endl;
    gotoxy(35, 18); cout << "MMMMXo;;;,c0W0c,;;;;;;;;;;;;;;;;;;:xNMMM" << endl;
    gotoxy(35, 19); cout << "MMMMMXd;,,cKMNx:,;;;;;;;;;;;;;;;,:kNMMMM" << endl;
    gotoxy(35, 20); cout << "MMMMMMNklcoXMMWO:,;:ccccoOWMMMMMMMMMMMMM" << endl;
    gotoxy(35, 21); cout << "MMMMMMMWNXX MMMWk,l0XXXXNWMMMMMMMMMMMMMM" << endl;

    gotoxy(45, 24); cout << "******GRUPO 7******" << endl;
    gotoxy(45, 24); cout << "\n" << endl;
}