#ifndef BOTON_H
#define BOTON_H

class Boton {
private:
    int pin;
    bool ultimoEstado;
    // Simulamos las variables de tiempo para el control de rebotes (Debounce) en la PC
    unsigned long ultimoTiempoRebote;
    unsigned long tiempoDebounce;

public:
    Boton(int p); // Constructor que recibe el pin físico
    
    // Método profesional para detectar si el botón fue presionado (flanco de bajada)
    // Recibe la lectura física simulada de la PC (1 suelto, 0 presionado)
    bool fuePresionado(bool lecturaSimulada); 
};

#endif