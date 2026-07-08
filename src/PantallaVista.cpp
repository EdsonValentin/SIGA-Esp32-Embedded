#include "PantallaVista.h"
#include <iostream>

using namespace std;

// Lógica de la Pantalla de Monitoreo
void VistaMonitoreo::dibujar() const {
    cout << "\n===============================" << endl;
    cout << "     --- PANTALLA OLED ---     " << endl;
    cout << "===============================" << endl;
    cout << " STATUS: MONITOREO EN VIVO     " << endl;
    cout << " Temp: 26.5C  | Humedad: 68%   " << endl;
    cout << " Suelo: 42%   | Modo: AUTO     " << endl;
    cout << "===============================" << endl;
}

// Constructor de la Pantalla de Historial
VistaHistorial::VistaHistorial(int r, float t, int s) : riegos(r), tMax(t), sMin(s) {}

// Lógica de la Pantalla de Historial
void VistaHistorial::dibujar() const {
    cout << "\n===============================" << endl;
    cout << "     --- PANTALLA OLED ---     " << endl;
    cout << "===============================" << endl;
    cout << " STATUS: HISTORIAL DIARIO      " << endl;
    cout << " Riegos Ejecutados: " << riegos << endl;
    cout << " Temperatura Maxima: " << tMax << "C" << endl;
    cout << " Humedad Suelo Min: " << sMin << "%" << endl;
    cout << "===============================" << endl;
}