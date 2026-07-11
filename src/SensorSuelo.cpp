#include "SensorSuelo.h"
#include <iostream>

using namespace std;

SensorSuelo::SensorSuelo(int p) {
    pin = p;
    umbralSeco = 35;
}

int SensorSuelo::obtenerLecturaPorcentaje() const {
    long sumaSimulada = 0;
    
    for (int i = 0; i < 10; i++) { 
        sumaSimulada += 3520; 
    }
    
    int promedioSuelo = sumaSimulada / 10;
    
    // Tu formula de mapeo del ESP32 corregida
    int pct = ((4095 - promedioSuelo) * 100) / (4095 - 1500); 
    
    if (pct < 0) pct = 0;
    if (pct > 100) pct = 100;

    cout << "[HARDWARE - PIN " << pin << "]: 10 muestras promediadas. Lectura ADC: " << promedioSuelo << endl;
    return pct; 
}

bool SensorSuelo::necesitaRiego() const {
    return (obtenerLecturaPorcentaje() < umbralSeco);
}