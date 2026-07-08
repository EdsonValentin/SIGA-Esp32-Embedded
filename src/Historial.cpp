#include "Historial.h"

Historial::Historial() {
    reiniciarDia();
}

void Historial::reiniciarDia() {
    contadorRiegos = 0;
    tempMaxima = -100.0;
    sueloMinimo = 100;
}

void Historial::registrarRiego() {
    contadorRiegos++;
}

void Historial::verificarTemperatura(float tActual) {
    if (tActual > tempMaxima) tempMaxima = tActual;
}

void Historial::verificarSuelo(int sActual) {
    if (sActual < sueloMinimo) sueloMinimo = sActual;
}

int Historial::obtenerRiegos() const { return contadorRiegos; }
float Historial::obtenerTempMax() const { return tempMaxima; }
int Historial::obtenerSueloMin() const { return sueloMinimo; }