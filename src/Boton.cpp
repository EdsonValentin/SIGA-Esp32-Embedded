#include "Boton.h"

Boton::Boton(int p) {
    pin = p;
    ultimoEstado = true; // HIGH por defecto (INPUT_PULLUP)
    ultimoTiempoRebote = 0;
    tiempoDebounce = 50; // 50 milisegundos de filtro
}

bool Boton::fuePresionado(bool lecturaSimulada) {
    bool retorno = false;

    // Si el estado físico cambió por ruido o presión, reiniciamos el temporizador
    if (lecturaSimulada != ultimoEstado) {
        ultimoEstado = lecturaSimulada;
        // Simulamos un flanco de bajada: pasó de HIGH (1) a LOW (0)
        if (lecturaSimulada == false) {
            retorno = true; // Detectamos la pulsación inmediata
        }
    }
    
    return retorno;
}