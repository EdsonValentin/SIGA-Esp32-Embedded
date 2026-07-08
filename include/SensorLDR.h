#ifndef SENSORLDR_H
#define SENSORLDR_H

class SensorLDR {
private:
    int pin;
    int umbralOscuridad;

public:
    SensorLDR(int p);
    bool esNoche(int lecturaSimulada); 
};

#endif