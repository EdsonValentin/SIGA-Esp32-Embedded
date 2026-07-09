#include <iostream>
#include <memory> // Librería para Smart Pointers (Memoria segura)
#include "SensorLDR.h"
#include "Historial.h"
#include "Boton.h"
#include "PantallaVista.h"

using namespace std;

int main() {
    cout << "====================================================" << endl;
    cout << "===   SISTEMA DE RIEGO INTELIGENTE SIGA COMPLETO  ===" << endl;
    cout << "====================================================" << endl;

    // 1. INSTANCIACIÓN DE COMPONENTES HARDWARE MODULARES
    SensorLDR sensorLuz(32);
    Historial historialRiego;
    Boton botonModo(13);
    Boton botonMenu(14);

    // 2. CREACIÓN DE SMART POINTERS PARA GESTIÓN SEGURA DE RAM
    // 'make_unique' reserva la habitación limpia en la memoria de forma automatizada
    auto pantallaMonitoreo = make_unique<VistaMonitoreo>();
    // Inicializamos la vista del historial pasándole los datos iniciales (0 riegos, temp máx, suelo mín)
    auto pantallaHistorial = make_unique<VistaHistorial>(0, 0.0, 100);

    // 3. VARIABLES DE ESTADO GLOBALES
    bool modoAuto = true;
    int pantallaActual = 0; // 0 = Monitoreo, 1 = Historial
    unique_ptr<PantallaVista> vistaActiva = nullptr; // Puntero Polimórfico Inteligente

    // =================================================================
    // SIMULACIÓN: ESCENARIO DE OPERACIÓN REAL DEL ENTORNO
    // =================================================================
    
    cout << "\n>>> [ESCENARIO 1: OPERACIÓN AUTOMÁTICA DE DÍA - SUELO SECO] <<<" << endl;
    int lecturaLDR_Dia = 1500;      // 1500 > 1000 = Es de Día
    float temperaturaActual = 28.5; // Temperatura alta registrada
    int humedadSueloActual = 22;    // 22% < 35% = ¡Alerta de Suelo Seco!

    // El sistema procesa los sensores y alimenta el Historial en la RAM
    historialRiego.verificarTemperatura(temperaturaActual);
    historialRiego.verificarSuelo(humedadSueloActual);

    if (modoAuto && humedadSueloActual < 35) {
        cout << "[ALERTA AUTOMÁTICA]: Humedad crítica en " << humedadSueloActual << "%. ¡Activando Bomba y registrando riego!" << endl;
        historialRiego.registrarRiego();
    }

    // Cargamos de forma segura la vista de Monitoreo inicial usando 'std::move'
    vistaActiva = move(pantallaMonitoreo);
    vistaActiva->dibujar(); // Dibuja la pantalla de monitoreo


    cout << "\n>>> [ESCENARIO 2: USUARIO PRESIONA BOTÓN DE MENÚ PARA VER DIAGNÓSTICO] <<<" << endl;
    // Simulamos que el usuario presiona físicamente el botón del pin 14 (false = presionado en INPUT_PULLUP)
    bool pulsacionMenu = false; 

    if (botonMenu.fuePresionado(pulsacionMenu)) {
        cout << "[EVENTO]: Boton Menu detectado. Liberando memoria anterior y cambiando a Historial..." << endl;
        pantallaActual = 1;
        
        // Actualizamos los datos reales acumulados del historial antes de renderizar la pantalla
        pantallaHistorial = make_unique<VistaHistorial>(
            historialRiego.obtenerRiegos(), 
            historialRiego.obtenerTempMax(), 
            historialRiego.obtenerSueloMin()
        );

        // El puntero inteligente transfiere la propiedad a la pantalla de estadísticas
        vistaActiva = move(pantallaHistorial);
    }

    // La misma instrucción dibuja ahora la pantalla de estadísticas de forma polimórfica e inteligente
    vistaActiva->dibujar();


    cout << "\n>>> [ESCENARIO 3: USUARIO CAMBIA A MODO MANUAL] <<<" << endl;
    // Simulamos que el usuario presiona el botón del pin 13 (false = presionado)
    bool pulsacionModo = false;

    if (botonModo.fuePresionado(pulsacionModo)) {
        modoAuto = !modoAuto; // Invertimos la bandera global
        cout << "[EVENTO]: Boton Modo presionado. El sistema pasa a MODO: " << (modoAuto ? "AUTOMATICO" : "MANUAL") << endl;
    }

    cout << "\n[FIN DE SIMULACIÓN]: C++ destruye los Smart Pointers y limpia la RAM automáticamente." << endl;
    return 0;
}