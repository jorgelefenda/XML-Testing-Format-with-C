#include <assert.h>
#include <stdio.h>
#include "../include/functions.h"
#include "../include/xml_reader.h"

int main() {
    float precios[100];  // tamaño máximo asumido
    int n = parse_prices_from_xml("tests/test_data.xml", precios, 100);

    if (n <= 0) {
        printf("❌ Error leyendo datos desde XML\n");
        return 1;
    }

    double retornos[n-1];
    for (int i = 1; i < n; i++) {
        retornos[i-1] = calcularRetorno(precios[i], precios[i-1]);
    }

    double media = calcularMedia(retornos, n-1);
    double volatilidad = calcularVolatilidad(retornos, n-1);

    assert(media > 0);
    assert(volatilidad > 0);

    printf("✅ Test de integración exitoso. Media: %.6f, Volatilidad: %.6f\n", media, volatilidad);
    return 0;
}