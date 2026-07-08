#include <iostream>
#include "SensorLDR.h"
#include "Historial.h"
#include "Boton.h"
#include "PantallaVista.h" // Importamos el nuevo plano de pantallas

using namespace std;

int main() {
    cout << "=== INTEGRANDO POLIMORFISMO DE PANTALLA SIGA ===" << endl;

    // 1. Instanciamos las dos pantallas fijas en la memoria
    VistaMonitoreo pantallaMonitoreo;
    VistaHistorial pantallaHistorial(3, 29.5, 21); // Pasamos estadísticas de prueba

    // 2. Creamos el PUNTERO POLIMÓRFICO de la clase base abstracta
    PantallaVista* vistaActiva = nullptr;

    // --- ESCENARIO 1: El sistema arranca mostrando el Monitoreo ---
    cout << "\n[Cambiando puntero a Vista Monitoreo...]" << endl;
    vistaActiva = &pantallaMonitoreo; 
    vistaActiva->dibujar(); // Llama al dibujo de Monitoreo de forma dinámica

    // --- ESCENARIO 2: El usuario cambia al menú de estadísticas ---
    cout << "\n[Cambiando puntero a Vista Historial/Diagnostico...]" << endl;
    vistaActiva = &pantallaHistorial; 
    vistaActiva->dibujar(); // Llama al dibujo de Historial con la misma instrucción

    return 0;
}