#ifndef PANTALLAVISTA_H
#define PANTALLAVISTA_H

#include <string>

// Clase Base Abstracta (El contrato)
class PantallaVista {
public:
    virtual void dibujar() const = 0; // Método virtual puro (Polimorfismo)
    virtual ~PantallaVista() {}       // Destructor virtual obligatorio
};

// Clase Hija 1: Pantalla de Monitoreo en tiempo real
class VistaMonitoreo : public PantallaVista {
public:
    void dibujar() const override; // Sobreescritura del método
};

// Clase Hija 2: Pantalla de Diagnóstico / Historial
class VistaHistorial : public PantallaVista {
private:
    // Le pasamos estos datos simulados para mostrar estadísticas en la PC
    int riegos;
    float tMax;
    int sMin;
public:
    VistaHistorial(int r, float t, int s);
    void dibujar() const override; 
};

#endif