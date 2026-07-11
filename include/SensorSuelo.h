#ifndef SENSORSUELO_H
#define SENSORSUELO_H

class SensorSuelo {
private:
    int pin;
    int umbralSeco;

public:
    SensorSuelo(int p);
    int obtenerLecturaPorcentaje() const; // Convierte la lectura analógica a % (0-100)
    bool necesitaRiego() const;           // Devuelve true si está por debajo del umbral
};

#endif