#include "SensorLDR.h"

SensorLDR::SensorLDR(int p) {
    pin = p;
    umbralOscuridad = 1000; 
}

bool SensorLDR::esNoche(int lecturaSimulada) {
    return (lecturaSimulada < umbralOscuridad);
}