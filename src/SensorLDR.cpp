#include "SensorLDR.h"

SensorLDR::SensorLDR(int p) {
    pin = p;
    umbralOscuridad = 1000; // El umbral calibrado en tu habitación
}

bool SensorLDR::esNoche(int lecturaSimulada) const {
    // Recuerda que cambiamos el signo a '<' porque tu circuito lee al revés
    return (lecturaSimulada < umbralOscuridad);
}