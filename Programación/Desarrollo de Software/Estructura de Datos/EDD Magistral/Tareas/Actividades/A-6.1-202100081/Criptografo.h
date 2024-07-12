#ifndef CRIPTOGRAFO_H
#define CRIPTOGRAFO_H

#include <string>
using namespace std;

class Criptografo {
public:
    Criptografo(string llvPub, string llvPriv);
    string enviar(string llvDestinatario, string mensaje);
    string recibir(string llvRemitente, string criptograma);
private:
    string llvPublica, llvPrivada;
    string encriptaRSA(string llv, char *mensaje);
    string desencriptaRSA(string llv, string criptograma);
    string encriptaAES(string llv, char *mensaje);
    string desencriptaAES(string llv, string criptograma);
    string sesion();
};

#endif // CRIPTOGRAFO_H
