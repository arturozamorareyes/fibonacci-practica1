// Práctica 1: Minimum Fibonacci Terms with Sum Equal to K
// Autor: Arturo Zamora Reyes

#include <stdio.h>
#include <stdbool.h>

// Función que determina si un número es primo
bool esPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Generación de la secuencia de Fibonacci sin posiciones primas
int generarFibonacciFiltrado(int fib[], int K) {
    int a = 0, b = 1, c;
    int index = 1, count = 0;
    if (!esPrimo(index)) fib[count++] = a;
    index++;
    if (!esPrimo(index)) fib[count++] = b;
    index++;

    while (1) {
        c = a + b;
        a = b;
        b = c;
        if (c > K) break;
        if (!esPrimo(index)) fib[count++] = c;
        index++;
    }
    return count;
}

// Algoritmo voraz para encontrar el mínimo número de términos que sumen K
int fibonacciMinimos(int fib[], int count, int K, int solucion[]) {
    int i = count - 1;
    int usados = 0;

    while (K > 0 && i >= 0) {
        if (fib[i] <= K) {
            K -= fib[i];
            solucion[usados++] = fib[i];
        }
        i--;
    }
    return usados;
}

int main() {
    int dia = 4, mes = 2, anio = 1995;
    int K = dia * 100 + mes * 10 + (anio % 100); // K = 515

    int fib[100];
    int solucion[100];

    int count = generarFibonacciFiltrado(fib, K);

    printf("Secuencia de Fibonacci filtrada:\\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", fib[i]);
    }
    printf("\\n\\n");

    int usados = fibonacciMinimos(fib, count, K, solucion);

    printf("Términos usados para formar K = %d:\\n", K);
    for (int i = 0; i < usados; i++) {
        printf("%d ", solucion[i]);
    }
    printf("\\nTotal de términos usados: %d\\n", usados);

    return 0;
}
