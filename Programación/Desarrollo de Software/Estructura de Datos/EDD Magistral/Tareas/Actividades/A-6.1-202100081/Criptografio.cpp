#include "Criptografo.h"
#include <sstream>

Criptografo::Criptografo(string llvPub, string llvPriv) {
    llvPublica = llvPub;
    llvPrivada = llvPriv;
}

string Criptografo::enviar(string llvDestinatario, string mensaje) {
    // Generate a random session key
    string llaveSesion = sesion();

    // Encrypt the message with the session key using AES
    string mensajeEncriptado = encriptaAES(llaveSesion, &mensaje[0]);

    // Encrypt the session key with the recipient's public key using RSA
    string llaveSesionEncriptada = encriptaRSA(llvDestinatario, &llaveSesion[0]);

    // Sign the encrypted message with the sender's private key using RSA
    string mensajeFirmado = encriptaRSA(llvPrivada, &mensajeEncriptado[0]);

    // Combine the encrypted session key and signed encrypted message
    stringstream ss;
    ss << llaveSesionEncriptada << "||" << mensajeFirmado;

    return ss.str();
}

string Criptografo::recibir(string llvRemitente, string criptograma) {
    // Split the encrypted session key and signed encrypted message
    size_t pos = criptograma.find("||");
    string llaveSesionEncriptada = criptograma.substr(0, pos);
    string mensajeFirmado = criptograma.substr(pos + 2);

    // Decrypt the session key with the recipient's private key using RSA
    string llaveSesion = desencriptaRSA(llvPrivada, llaveSesionEncriptada);

    // Decrypt the signed encrypted message with the sender's public key using RSA
    string mensajeEncriptado = desencriptaRSA(llvRemitente, mensajeFirmado);

    // Decrypt the message with the session key using AES
    return desencriptaAES(llaveSesion, mensajeEncriptado);
}
