#include <stdio.h>
#include <assert.h>
#include "../include/functions.h"
#include "../include/xml_reader.h"

int main() {
    float precios[100];   // arreglo con tamaño máximo asumido
    int count = parse_prices_from_xml("tests/test_data.xml", precios, 100);
    if (count <= 0) {
        printf("Error leyendo datos del XML\n");
        return 1;
    }

    double retornos[count-1];
    for (int i = 1; i < count; i++) {
        retornos[i-1] = calcularRetorno(precios[i], precios[i-1]);
    }

    double media = calcularMedia(retornos, count-1);
    double volatilidad = calcularVolatilidad(retornos, count-1);

    if (media > 0 && volatilidad > 0) {
        printf("Test funcional OK\n");
        return 0;
    } else {
        printf("Test funcional FALLIDO\n");
        return 1;
    }
}