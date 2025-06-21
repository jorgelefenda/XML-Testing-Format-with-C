#include <stdio.h>
#include "../include/functions.h"

int main() {
    double precios[] = {100, 102, 101, 105, 107};
    int n = sizeof(precios)/sizeof(precios[0]);
    double retornos[n-1];

    for (int i = 1; i < n; i++) {
        retornos[i-1] = calcularRetorno(precios[i], precios[i-1]);
    }

    double media = calcularMedia(retornos, n-1);
    double volatilidad = calcularVolatilidad(retornos, n-1);

    printf("Media retornos: %.6f\n", media);
    printf("Volatilidad retornos: %.6f\n", volatilidad);

    return 0;
}