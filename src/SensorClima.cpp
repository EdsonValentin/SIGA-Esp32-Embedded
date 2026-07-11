#include "SensorClima.h"
#include <iostream>

SensorClima::SensorClima(int p) {
    pin = p;
}

SensorDHT11::SensorDHT11(int p) : SensorClima(p) {}

float SensorDHT11::leerTemperatura() {
    std::cout << "[HARDWARE - PIN " << pin << "]: Leyendo pulsos digitales del DHT11..." << std::endl;
    return 26.8; // Devolvemos una temperatura simulada estable de prueba
}