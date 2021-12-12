#include "main.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Se requiere evaluar las funciones f(x), g(x) y z(x) para
 * todos los valores de x en el intervalo 0 <= x <= 3.5 con
 * incremento de 0.2. Escribir un programa que evalue dichas
 * funciones, utilizar un arreglo de apuntadores a funcion.
 * Las funciones son las siguientes:
 *
 * f(x) = 3 * e^(x -1) - 2x
 * g(x) = -x * sin(x) + 1.5
 * z(x) = x^2 - 2x + 3
 *
 */


int main() {
    const double start_value = 0;
    const double end_value = 3.5;
    const double step = 0.2;

    double (*mathematical_functions[])(double) = {f, g, z};
    const unsigned int n_mathematical_functions = sizeof(mathematical_functions) / sizeof(mathematical_functions[0]);

    double n = start_value;
    while (n <= end_value) {
        char *result_str = malloc(30 * sizeof(char));
        for (int i = 0; i < n_mathematical_functions; i++) {
            sprintf(result_str, "Function %d: %lf", i, mathematical_functions[i](n));
            puts(result_str);
            n += step;
        }
        free(result_str);
    }
}

double f(double x) {
    return 3 * exp(x - 1) - (2 * x);
}

double g(double x) {
    return -x * sin(x) + 1.5;
}

double z(double x) {
    return (x * x) - (2 * x) + 3;
}
