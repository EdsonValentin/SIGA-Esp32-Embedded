#include <iostream>
#include "SensorLDR.h"
#include "Historial.h"
#include "Boton.h" // Importamos la nueva herramienta

using namespace std;

int main() {
    cout << "=== INTEGRANDO BOTONES MODULARES SIGA ===" << endl;

    // 1. Instanciamos el botón de modo en el pin 13 y la bandera de control
    Boton botonModo(13);
    bool modoAuto = true;

    cout << "Estado Inicial -> MODO: " << (modoAuto ? "AUTO" : "MANUAL") << endl;

    // 2. Simulamos escenarios de pulsación
    // En INPUT_PULLUP: true = suelto (1), false = presionado (0)
    bool lectura1 = true;  // Botón suelto
    bool lectura2 = false; // El usuario presiona el botón físicamente

    cout << "\n[Simulando: Usuario presiona el boton de Modo...]" << endl;
    if (botonModo.fuePresionado(lectura2)) {
        modoAuto = !modoAuto; // Cambiamos el modo del sistema
    }
    cout << "Nuevo Estado -> MODO: " << (modoAuto ? "AUTO" : "MANUAL") << endl;

    cout << "\n[Simulando: Boton se queda suelto...]" << endl;
    if (botonModo.fuePresionado(lectura1)) {
        modoAuto = !modoAuto;
    }
    cout << "Estado Actual -> MODO: " << (modoAuto ? "AUTO" : "MANUAL") << endl;

    return 0;
}