#include <iostream>

int busca(char *P, char *S) {
    int m = 0, n = 0;

    // Calcular la longitud de P
    while (P[m] != '\0') {
        m++;
    }

    // Calcular la longitud de S
    while (S[n] != '\0') {
        n++;
    }

    // Si el patrón es más largo que el texto, retornar -1
    if (m > n) {
        return -1;
    }

    // Buscar el patrón en el texto
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && S[i + j] == P[j]) {
            j++;
        }
        if (j == m) {
            return i;  // Patrón encontrado en la posición i
        }
    }

    // Si no se encuentra el patrón, retornar -1
    return -1;
}

int main() {
    char S[] = "este es un ejemplo de texto";
    char P[] = "ejemplo";

    int pos = busca(P, S);

    if (pos != -1) {
        std::cout << "El patrón se encontró en la posición: " << pos << std::endl;
    } else {
        std::cout << "El patrón no se encontró en el texto." << std::endl;
    }

    return 0;
}
