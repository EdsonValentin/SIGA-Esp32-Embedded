#ifndef SENSORLDR_H
#define SENSORLDR_H

class SensorLDR {
private:
    int pin;
    int umbralOscuridad;

public:
    SensorLDR(int p);
    int obtenerLecturaCruda() const;
    bool esNoche(int lecturaSimulada) const; 
};

#endif