#ifndef SENSORCLIMA_H
#define SENSORCLIMA_H

class SensorClima {
protected:
    int pin;

public:
    SensorClima(int p);
    virtual float leerTemperatura() = 0; // Polimorfismo puro
    virtual ~SensorClima() {}
};

class SensorDHT11 : public SensorClima {
public:
    SensorDHT11(int p);
    float leerTemperatura() override; 
};

#endif