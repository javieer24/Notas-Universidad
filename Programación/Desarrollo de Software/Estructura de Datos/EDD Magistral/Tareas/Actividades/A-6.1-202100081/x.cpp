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

void enviarACliente(const string& cliente, const string& mensaje) {
    ofstream file(cliente + "_mensaje_encriptado.txt");
    file << mensaje;
}

int main() {
    string llvPubX = obtenerLlavePublica("X");
    string llvPrivX = obtenerLlavePrivada("X");
    Criptografo criptoX(llvPubX, llvPrivX);

    string llvPubY = obtenerLlavePublica("Y");
    string mensaje = "Hola Y, soy X.";
    string criptograma = criptoX.enviar(llvPubY, mensaje);

    enviarACliente("Y", criptograma);
    return 0;
}
