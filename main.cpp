#include <iostream>
#include "Historial.h"

using namespace std;

int main() {
    cout << "=== PROBANDO NUEVA ARQUITECTURA LIMPIADA ===" << endl;

    Historial historialRiego;
    historialRiego.verificarTemperatura(28.9); 
    historialRiego.verificarSuelo(22); 
    historialRiego.registrarRiego();

    cout << "Total Riegos Hoy: " << historialRiego.obtenerRiegos() << endl;
    cout << "Temperatura Maxima: " << historialRiego.obtenerTempMax() << " C" << endl;
    cout << "Humedad de Suelo Minima: " << historialRiego.obtenerSueloMin() << "%" << endl;

    return 0;
}