// src/functions.c
#include <math.h>
#include "../include/functions.h"

double calcularRetorno(double precioActual, double precioAnterior) {
    return (precioActual - precioAnterior) / precioAnterior;
}

double calcularMedia(double datos[], int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += datos[i];
    }
    return suma / n;
}

double calcularVolatilidad(double datos[], int n) {
    double media = calcularMedia(datos, n);
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = datos[i] - media;
        suma += diff * diff;
    }
    return sqrt(suma / n);
}