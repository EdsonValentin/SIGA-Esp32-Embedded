#ifndef HISTORIAL_H
#define HISTORIAL_H

class Historial {
private:
    int contadorRiegos;
    float tempMaxima;
    int sueloMinimo;

public:
    Historial();
    void reiniciarDia();
    void registrarRiego();
    void verificarTemperatura(float tActual);
    void verificarSuelo(int sActual);

    int obtenerRiegos() const;
    float obtenerTempMax() const;
    int obtenerSueloMin() const;
};

#endif