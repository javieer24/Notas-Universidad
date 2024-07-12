#include "CriptografO.h"
#include <iostream>
#include <fstream>

string obtenerLlavePublica(const string& usuario) {
    ifstream file(usuario + "_publica.txt");
    string llave;
    getline(file, llave);
    return llave;
}

string obtenerLlavePrivada(const string& usuario) {
    ifstream file(usuario + "_privada.txt");
    string llave;
    getline(file, llave);
    return llave;
}

string recibirDeCliente(const string& cliente) {
    ifstream file(cliente + "_mensaje_encriptado.txt");
    string mensaje;
    getline(file, mensaje);
    return mensaje;
}

int main() {
    string llvPubY = obtenerLlavePublica("Y");
    string llvPrivY = obtenerLlavePrivada("Y");
    Criptografo criptoY(llvPubY, llvPrivY);

    string llvPubX = obtenerLlavePublica("X");
    string criptograma = recibirDeCliente("X");

    string mensaje = criptoY.recibir(llvPubX, criptograma);

    cout << "Mensaje recibido: " << mensaje << endl;
    return 0;
}
