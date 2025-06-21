// tests/test_unit.c
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "../include/functions.h"  // Ajustá la ruta si es necesario

int casiIgual(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}

void test_calcularRetorno() {
    double resultado = calcularRetorno(110.0, 100.0);  // Usa 110.0 y 100.0
    printf("Resultado calcularRetorno(110, 100): %.15f\n", resultado);
    assert(casiIgual(resultado, 0.10, 0.00001));
}    

void test_calcularMedia() {
    double datos[] = {0.1, 0.2, 0.3};
    double media = calcularMedia(datos, 3);
    assert(casiIgual(media, 0.2, 0.00001));
}

void test_calcularVolatilidad() {
    double datos[] = {0.1, 0.2, 0.3};
    double vol = calcularVolatilidad(datos, 3);
    // Volatilidad = desviación estándar simple, calculada previamente
    assert(casiIgual(vol, 0.08164966, 0.00001));
}

int main() {
    test_calcularRetorno();
    test_calcularMedia();
    test_calcularVolatilidad();

    printf("Todos los tests unitarios pasaron!\n");
    return 0;
}
