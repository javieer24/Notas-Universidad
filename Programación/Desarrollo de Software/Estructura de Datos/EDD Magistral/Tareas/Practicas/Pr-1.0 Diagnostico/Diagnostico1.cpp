#include <stdio.h>

int potencia(int x, int n) {
    // Caso base: si el exponente es 0, el resultado es 1
    if (n == 0)
        return 1;
    // Caso base: si el exponente es 1, el resultado es el propio número
    else if (n == 1)
        return x;
    // Si el exponente es par, se puede dividir el problema en mitades
    else if (n % 2 == 0) {
        int temp = potencia(x, n / 2);
        return temp * temp;
    }
    // Si el exponente es impar, se puede dividir el problema en mitades y multiplicar por x
    else {
        int temp = potencia(x, (n - 1) / 2);
        return temp * temp * x;
    }
}

int main() {
    int base, exponente;
    printf("Ingrese la base: ");
    scanf("%d", &base);
    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);

    int resultado = potencia(base, exponente);
    printf("El resultado de %d elevado a la %d es: %d\n", base, exponente, resultado);

    return 0;
}
