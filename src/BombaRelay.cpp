#include "BombaRelay.h"
#include <iostream>

BombaRelay::BombaRelay(int p) {
    pin = p;
    encendida = false;
}

void BombaRelay::encender() {
    encendida = true;
    std::cout << "[BOMBA - PIN " << pin << "]: Enviando pulso LOW. ¡Motobomba ENCENDIDA! 💧" << std::endl;
}

void BombaRelay::apagar() {
    encendida = false;
    std::cout << "[BOMBA - PIN " << pin << "]: Enviando pulso HIGH. ¡Motobomba APAGADA!" << std::endl;
}

bool BombaRelay::estaActiva() const {
    return encendida;
}