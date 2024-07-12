import java.util.Scanner;

public class Palindromo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingresa una cadena: ");
        String cadena = scanner.nextLine();

        if (Palindromo.esPalindromoRecursivo(cadena)) {
            System.out.println(cadena + " es un palíndromo (recursivo)");
        } else {
            System.out.println(cadena + " no es un palíndromo (recursivo)");
        }

        if (Palindromo.esPalindromoIterativo(cadena)) {
            System.out.println(cadena + " es un palíndromo (iterativo)");
        } else {
            System.out.println(cadena + " no es un palíndromo (iterativo)");
        }
    }

    public static boolean esPalindromoRecursivo(String cadena) {
        if (cadena.length() <= 1) {
            return true;
        }
        if (cadena.charAt(0) == cadena.charAt(cadena.length() - 1)) {
            return esPalindromoRecursivo(cadena.substring(1, cadena.length() - 1));
        } else {
            return false;
        }
    }

    public static boolean esPalindromoIterativo(String cadena) {
        for (int i = 0; i < cadena.length() / 2; i++) {
            if (cadena.charAt(i) != cadena.charAt(cadena.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }
}